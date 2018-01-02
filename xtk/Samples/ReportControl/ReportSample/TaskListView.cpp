// TaskListView.cpp : implementation file
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "reportsample.h"
#include "TaskListView.h"
#include "ReportSampleView.h"

#if _MSC_VER >= 1200 // MFC 6.0
#include <afxdtctl.h>       // MFC support for Internet Explorer 4 Common Controls
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if _MSC_VER >= 1200 // MFC 6.0
//////////////////////////////////////////////////////////////////////////
class CMonthCalCtrlEx : public CMonthCalCtrl
{
public:
	BOOL GoModal(const CPoint& pt, CWnd* pParentWnd, COleDateTime& rdtDate);

protected:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);	
	afx_msg void OnSelChange(NMHDR* pNMHdr, LRESULT* pResult);
	
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMonthCalCtrlEx, CMonthCalCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_NOTIFY_REFLECT(MCN_SELECT, OnSelChange)
END_MESSAGE_MAP()	

#endif

//////////////////////////////////////////////////////////////////////////
// CTaskListFrame


BEGIN_MESSAGE_MAP(CTaskListFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CTaskListFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP    
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

#define COLUMN_TYPE             0
#define COLUMN_IMPORTANCE       1
#define COLUMN_ATTACHMENT       2
#define COLUMN_STATUS           3
#define COLUMN_SUBJECT          4
#define COLUMN_DUE_DATE         5
#define COLUMN_COMPLETE         6
#define COLUMN_CATEGORIES       7


int CTaskListFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}



	if (!InitCommandBars())
		return -1;

	CXTPCommandBars* pCommandBars = GetCommandBars();

	pCommandBars->SetMenu(_T("Menu Bar"), IDR_TASKLIST);


	return 0;
}

void CTaskListFrame::OnDestroy()
{
	((CReportSampleView*)m_pOwnerView)->m_pTaskFrame = NULL;

	CFrameWnd::OnDestroy();
}

//////////////////////////////////////////////////////////////////////////
// CTaskRecord

CTaskRecord::CTaskRecord(
		BOOL bSharedTask, TaskImportance taskImportance, BOOL bHasAttachment,
		TaskStatus taskStatus, CString strSubject,
		COleDateTime odtDueDate, int nComplete, CString strCategories)
{
	AddItem(new CTaskItemType(bSharedTask));
	AddItem(new CTaskItemImportance(taskImportance));
	AddItem(new CTaskItemAttachment(bHasAttachment));
	AddItem(new CTaskItemStatus(taskStatus));
	AddItem(new CXTPReportRecordItemText(strSubject));
	AddItem(new CTaskItemDueDate(odtDueDate));
	AddItem(new CTaskItemComplete(nComplete));
	AddItem(new CXTPReportRecordItemText(strCategories));
}

void CTaskRecord::GetItemMetrics(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pItemMetrics)
{
	if (((CTaskItemStatus*)GetItem(3))->m_taskStatus == taskStatusCompleted)
	{

		static CFont m_fontStriked;

		if (!m_fontStriked.GetSafeHandle())
		{
			LOGFONT lf;
			pDrawArgs->pControl->GetPaintManager()->m_fontText.GetLogFont(&lf);
			lf.lfStrikeOut = TRUE;

			m_fontStriked.CreateFontIndirect(&lf);
		}

		pItemMetrics->clrForeground = RGB(128, 128, 128);
		pItemMetrics->pFont = &m_fontStriked;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTaskListView

IMPLEMENT_DYNCREATE(CTaskListView, CXTPReportView)

CTaskListView::CTaskListView()
{
}

CTaskListView::~CTaskListView()
{
}


BEGIN_MESSAGE_MAP(CTaskListView, CXTPReportView)
	//{{AFX_MSG_MAP(CTaskListView)
	ON_WM_CREATE()
	ON_COMMAND(ID_REPORTCONTROL_ALLOWEDIT, OnReportcontrolAllowedit)
	ON_UPDATE_COMMAND_UI(ID_REPORTCONTROL_ALLOWEDIT, OnUpdateReportcontrolAllowedit)
	ON_COMMAND(ID_REPORTCONTROL_EDITONCLICK, OnReportcontrolEditonclick)
	ON_UPDATE_COMMAND_UI(ID_REPORTCONTROL_EDITONCLICK, OnUpdateReportcontrolEditonclick)
	ON_COMMAND(ID_REPORTCONTROL_FOCUSSUBITEMS, OnReportcontrolFocussubitems)
	ON_UPDATE_COMMAND_UI(ID_REPORTCONTROL_FOCUSSUBITEMS, OnUpdateReportcontrolFocussubitems)
	ON_COMMAND(ID_EDIT_ADDTASK, OnAddTask)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_NOTIFY(XTP_NM_REPORT_INPLACEBUTTONDOWN, XTP_ID_REPORT_CONTROL, OnReportButtonClick)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskListView drawing

/////////////////////////////////////////////////////////////////////////////
// CTaskListView diagnostics

#ifdef _DEBUG
void CTaskListView::AssertValid() const
{
	CView::AssertValid();
}

void CTaskListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskListView message handlers

int CTaskListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CXTPReportView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CXTPReportControl& wndReport = GetReportCtrl();

	wndReport.GetImageManager()->SetIcons(IDB_BMREPORT, 0, 0, CSize(16, 16));

	wndReport.AddColumn(new CXTPReportColumn(COLUMN_TYPE, _T("Type"), 18, FALSE, 0));
	CXTPReportColumn* pColumnImportance = wndReport.AddColumn(new CXTPReportColumn(COLUMN_IMPORTANCE, _T("Importants"), 18, FALSE, 1));
	wndReport.AddColumn(new CXTPReportColumn(COLUMN_ATTACHMENT, _T("Attachments"), 18, FALSE, 7));
	CXTPReportColumn* pColumnStatus = wndReport.AddColumn(new CXTPReportColumn(COLUMN_STATUS, _T("Status"), 100));
	wndReport.AddColumn(new CXTPReportColumn(COLUMN_SUBJECT, _T("Subject"), 200));
	CXTPReportColumn* pColumnDueDate = wndReport.AddColumn(new CXTPReportColumn(COLUMN_DUE_DATE, _T("Due Date"), 100));
	wndReport.AddColumn(new CXTPReportColumn(COLUMN_COMPLETE, _T("% Complete"), 100));
	wndReport.AddColumn(new CXTPReportColumn(COLUMN_CATEGORIES, _T("Categories"), 80));

	pColumnStatus->GetEditOptions()->AddConstraint(_T("Not Started"), taskStatusNotStarted);
	pColumnStatus->GetEditOptions()->AddConstraint(_T("In Progress"), taskStatusInProgress);
	pColumnStatus->GetEditOptions()->AddConstraint(_T("Completed"), taskStatusCompleted);
	pColumnStatus->GetEditOptions()->AddConstraint(_T("Waiting on someone else"), taskStatusWaiting);
	pColumnStatus->GetEditOptions()->AddConstraint(_T("Deferred"), taskStatusDeferred);
	pColumnStatus->GetEditOptions()->m_bConstraintEdit = TRUE;
	pColumnStatus->GetEditOptions()->m_bAllowEdit = TRUE;
	pColumnStatus->GetEditOptions()->AddComboButton();

	pColumnImportance->GetEditOptions()->AddConstraint(_T("Low"), taskImportanceLow);
	pColumnImportance->GetEditOptions()->AddConstraint(_T("Normal"), taskImportanceNormal);
	pColumnImportance->GetEditOptions()->AddConstraint(_T("High"), taskImportanceHigh);
	pColumnImportance->GetEditOptions()->m_bAllowEdit = FALSE;
	pColumnImportance->GetEditOptions()->AddComboButton();

	pColumnDueDate->GetEditOptions()->AddComboButton();

	COleDateTime dtNone;
	COleDateTime dtNow = COleDateTime::GetCurrentTime();

	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, TRUE, taskStatusInProgress, _T("Support Email: About tooltips"), dtNone, 70, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, TRUE, taskStatusNotStarted, _T("Support Email: Docking Pane ToggleDocking"), dtNone, 0, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceHigh, TRUE, taskStatusNotStarted, _T("Feature Request: New Event for CommandBars"), dtNow, 0, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceHigh, TRUE, taskStatusCompleted, _T("Support Email: Help Taskpanel And ShortcutBar"), dtNow, 100, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, FALSE, taskStatusCompleted, _T("Support Email: RE: Docking Pane Window Overlapping Issues"), dtNow, 100, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, FALSE, taskStatusCompleted, _T("Support Email: CXTPPropertyGridItem"), dtNone, 100, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, TRUE, taskStatusCompleted, _T("Support Email: Toolbar Oddity"), dtNone, 100, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, TRUE, taskStatusCompleted, _T("Support Email: CXTPTabControl"), dtNone, 100, _T("")));
	wndReport.AddRecord(new CTaskRecord(FALSE, taskImportanceNormal, TRUE, taskStatusInProgress, _T("Support Email: Menus go wrong if another form has topmost setting"), dtNone, 10, _T("")));
	wndReport.AddRecord(new CTaskRecord(FALSE, taskImportanceNormal, TRUE, taskStatusInProgress, _T("Support Email: Update Xtreme Suite from 8.6 to 8.7"), dtNone, 0, _T("")));
	wndReport.AddRecord(new CTaskRecord(TRUE, taskImportanceLow, TRUE, taskStatusInProgress, _T("Support Email: Bug in Tree-View on Label Edit"), dtNone, 0, _T("")));


	wndReport.GetReportHeader()->AllowColumnRemove(FALSE);
	wndReport.AllowEdit(TRUE);
	wndReport.FocusSubItems(TRUE);
	wndReport.Populate();
	wndReport.GetPaintManager()->SetGridStyle(TRUE, xtpReportGridSolid);

	wndReport.SetFocus();

	return 0;
}


void CTaskListView::OnReportcontrolAllowedit()
{
	GetReportCtrl().AllowEdit(!GetReportCtrl().IsAllowEdit());

}

void CTaskListView::OnUpdateReportcontrolAllowedit(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetReportCtrl().IsAllowEdit()? TRUE: FALSE);

}

void CTaskListView::OnReportcontrolEditonclick()
{
	GetReportCtrl().EditOnClick(!GetReportCtrl().IsEditOnClick());

}

void CTaskListView::OnUpdateReportcontrolEditonclick(CCmdUI* pCmdUI)
{

	pCmdUI->SetCheck(GetReportCtrl().IsAllowEdit() && GetReportCtrl().IsEditOnClick()? TRUE: FALSE);

	if (!GetReportCtrl().IsAllowEdit())
		pCmdUI->Enable(FALSE);

}

void CTaskListView::OnReportcontrolFocussubitems()
{
	GetReportCtrl().FocusSubItems(!GetReportCtrl().IsFocusSubItems());

}

void CTaskListView::OnUpdateReportcontrolFocussubitems(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetReportCtrl().IsFocusSubItems()? TRUE: FALSE);
}

void CTaskListView::OnAddTask() 
{
	CTaskRecord* pRecord = (CTaskRecord*)GetReportCtrl().AddRecord(new CTaskRecord(TRUE, taskImportanceNormal, FALSE, taskStatusNotStarted, _T(""), COleDateTime(), 0, _T("")));
	GetReportCtrl().Populate();

	CXTPReportRow* pRow = GetReportCtrl().GetRows()->Find(pRecord);
	if (pRow)
	{			
		XTP_REPORTRECORDITEM_ARGS itemArgs(&GetReportCtrl(), pRow, GetReportCtrl().GetColumns()->Find(COLUMN_SUBJECT));
		GetReportCtrl().EditItem(&itemArgs);
	}
}

void CTaskListView::OnReportButtonClick(NMHDR * pNotifyStruct, LRESULT* pResult)
{
    XTP_NM_REPORTINPLACEBUTTON* pItemNotify = (XTP_NM_REPORTINPLACEBUTTON*) pNotifyStruct;
    ASSERT(pItemNotify->pButton);

	if (!pItemNotify->pButton->pColumn || pItemNotify->pButton->pColumn->GetItemIndex() != COLUMN_DUE_DATE)
		return;
	

	CRect rcRow = pItemNotify->pButton->pRow->GetRect();
	CRect rcCol = pItemNotify->pButton->pColumn->GetRect();
	CRect rcItem = rcRow;
	rcItem.left = rcCol.left;
	rcItem.right = rcCol.right;
	
	CXTPReportRecordItemDateTime* pItemDateTime = DYNAMIC_DOWNCAST(CXTPReportRecordItemDateTime, pItemNotify->pItem);
	if (!pItemDateTime) {
		ASSERT(FALSE);
		return;
	}

	COleDateTime dtDateValue = pItemDateTime->GetValue();
	if (dtDateValue.GetStatus() != COleDateTime::valid || dtDateValue == 0) 
	{
		dtDateValue = COleDateTime::GetCurrentTime();

#ifdef _XTP_INCLUDE_CALENDAR
		dtDateValue = CXTPCalendarUtils::ResetTime(dtDateValue);
#endif
	}

	CXTPReportControl* pControl = pItemNotify->pButton->pControl;

	BOOL bResult = -1; // -1 means that XTP DatePicker is not supported in this build.

//#define DBG_DATE_PICKERS
#ifdef DBG_DATE_PICKERS
	static int s_nRotator = 0;
	s_nRotator++;
	if(s_nRotator % 2 == 0)
#endif
	bResult = Show_XTPDatePicker(pControl, rcItem, dtDateValue);
		
	if(bResult < 0) {		
		bResult = Show_MFCDatePicker(pControl, rcItem, dtDateValue);
	}

	if(!bResult) {
		return;
	}
	
	CString strNewVal = dtDateValue.Format();
	//pItemNotify->pButton->pControl->GetInplaceEdit()->SetWindowText(strNewVal);
	pItemNotify->pItem->OnEditChanged(NULL, strNewVal);
	
	// uncomment to end editing after pop-up date picker closed.
	//pItemNotify->pButton->pControl->EditItem(NULL);

	pItemNotify->pButton->pControl->RedrawControl();
	*pResult = (LRESULT)TRUE;
}

BOOL CTaskListView::Show_XTPDatePicker(CXTPReportControl* pControl, 
										const CRect& rcItem,
										COleDateTime& rdtDate)
{
#ifdef _XTP_INCLUDE_CALENDAR
	CXTPDatePickerControl wndDatePicker;

	if(!wndDatePicker.GetSelectedDays()) {
		ASSERT(FALSE);
		return FALSE;
	}

	wndDatePicker.SetMaxSelCount(1);
	wndDatePicker.GetSelectedDays()->Select(rdtDate);
	wndDatePicker.EnsureVisible(rdtDate);

	CRect rcSize;
	if(!wndDatePicker.GetMinReqRect(&rcSize, 1, 1) ) {
		ASSERT(FALSE);
		return FALSE;
	}
	rcSize.InflateRect(5, 5);
	
	CRect rcPopUp = rcItem;
	pControl->ClientToScreen(&rcPopUp);

	rcPopUp.right = rcPopUp.left + rcSize.Width();
	rcPopUp.top = rcPopUp.bottom;
	rcPopUp.bottom = rcPopUp.bottom + rcSize.Height();

	BOOL bResult = wndDatePicker.GoModal(rcPopUp, pControl);

	if(bResult) 
	{
		int nSelCount = wndDatePicker.GetSelectedDays()->GetSelectedBlocksCount();
		if(nSelCount) 
		{
			rdtDate = (DATE)wndDatePicker.GetSelectedDays()->GetSelectedBlock(0).nDateBegin;
		}
	}
	return bResult;

#else 
	return -1; 
#endif
}

BOOL CTaskListView::Show_MFCDatePicker(CXTPReportControl* pControl, 
										const CRect& rcItem,
										COleDateTime& rdtDate)
{
#if _MSC_VER >= 1200 // MFC 6.0

	CMonthCalCtrlEx wndMFCDatePicker;
	
	CPoint pt(rcItem.left, rcItem.bottom);
	pControl->ClientToScreen(&pt);

	BOOL bResult = wndMFCDatePicker.GoModal(pt, pControl, rdtDate);
	
	return bResult;
#else
	return FALSE;
#endif
}

#if _MSC_VER >= 1200 // MFC 6.0

#ifndef AfxDeferRegisterClass
#define AfxDeferRegisterClass(fClass) AfxEndDeferRegisterClass(fClass)
BOOL AFXAPI AfxEndDeferRegisterClass(LONG fToRegister);
#define AFX_WNDCOMMCTL_DATE_REG 0x20000
#endif

BOOL CMonthCalCtrlEx::GoModal(const CPoint& pt, CWnd* pParentWnd, 
							  COleDateTime& rdtDate)
{
	if (::IsWindow(m_hWnd)) {
		ASSERT(FALSE);
		return FALSE;
	}

	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_DATE_REG));

	CRect rcRect(pt.x, pt.y, 0, 0);
	BOOL bCreate = CreateEx(WS_EX_TOPMOST|WS_EX_DLGMODALFRAME, 
							MONTHCAL_CLASS, NULL, 
							WS_POPUP, rcRect, pParentWnd, 0);

	ASSERT(bCreate);

	if(!bCreate) {		
		return FALSE;
	}

	CRect rect;
	
	if (GetMinReqRect(rect))
	{
		rect.InflateRect(5, 5);
		DWORD dwFlags = SWP_NOZORDER | SWP_NOREPOSITION | SWP_NOMOVE | SWP_NOACTIVATE;		
		SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), dwFlags);		
	}
	else 
	{
		ASSERT(FALSE);

		DestroyWindow();		
		return FALSE;
	}

	SetCurSel(rdtDate);

	// Enable this window
	EnableWindow(TRUE);

	CWnd* pFocusWnd = SetFocus();
	SetCapture();

	ShowWindow(SW_SHOWNA);

	m_nFlags |= WF_CONTINUEMODAL;
	int nResult = m_nModalResult;
	if (ContinueModal())
	{
		// enter modal loop
		DWORD dwFlags = MLF_SHOWONIDLE;
		if (GetStyle() & DS_NOIDLEMSG)
			dwFlags |= MLF_NOIDLEMSG;
		nResult = RunModalLoop(dwFlags);
	}

	ReleaseCapture();

	SYSTEMTIME sysTime;
	::ZeroMemory(&sysTime, sizeof(sysTime));
	BOOL bSelResult = GetCurSel(&sysTime);
	if (bSelResult) {
		rdtDate = COleDateTime(sysTime.wYear, sysTime.wMonth, sysTime.wDay, 0, 0, 0);
	}

	DestroyWindow();

	if (pFocusWnd && ::IsWindow(pFocusWnd->GetSafeHwnd()))
		pFocusWnd->SetFocus();

	return (nResult == IDOK) && bSelResult;
}

void CMonthCalCtrlEx::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RETURN || nChar == VK_ESCAPE)
	{
		EndModalLoop(nChar == VK_RETURN ? IDOK : IDCANCEL);
		return;
	}

	CMonthCalCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMonthCalCtrlEx::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect rcClient;
	GetClientRect(&rcClient);

	if (!rcClient.PtInRect(point))
	{
		EndModalLoop(IDOK);
		return;
	}

	CMonthCalCtrl::OnLButtonDown(nFlags, point);
}

void CMonthCalCtrlEx::OnSelChange(NMHDR* /*pNMHdr*/, LRESULT* /*pResult*/)
{
	EndModalLoop(IDOK);
}

#endif
