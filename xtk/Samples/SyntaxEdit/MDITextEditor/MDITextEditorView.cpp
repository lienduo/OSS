// MDITextEditorView.cpp : implementation of the CMDITextEditorView class
//

#include "stdafx.h"
#include "MDITextEditor.h"

#include "MDITextEditorDoc.h"
#include "MDITextEditorView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef enum SyntaxEditUpdateViewHint
{
	xtpHintWhiteSpace = (xtpEditHintLast + 1),
};

/////////////////////////////////////////////////////////////////////////////
// CMDITextEditorView

IMPLEMENT_DYNCREATE(CMDITextEditorView, CViewBase)

BEGIN_MESSAGE_MAP(CMDITextEditorView, CViewBase)
	//{{AFX_MSG_MAP(CMDITextEditorView)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_FIND_SILENT, OnEditFindSilent)
	ON_COMMAND(ID_EDIT_TABIFY, OnEditTabify)
	ON_COMMAND(ID_EDIT_UNTABIFY, OnEditUnTabify)
	ON_COMMAND(ID_EDIT_UPPERCASE, OnEditUppercase)
	ON_COMMAND(ID_EDIT_LOWERCASE, OnEditLowercase)
	ON_COMMAND(ID_EDIT_WHITESPACE, OnEditWhiteSpace)
	ON_UPDATE_COMMAND_UI(ID_EDIT_WHITESPACE, OnUpdateEditWhiteSpace)
	ON_COMMAND(ID_EDIT_COLLAPSEALL, OnEditCollapseAll)
	ON_COMMAND(ID_EDIT_EXPANDALL, OnEditExpandAll)
	ON_COMMAND(ID_TOOLS_BOOKMARK, OnToolsBookmark)
	ON_COMMAND(ID_TOOLS_BREAKPOINT, OnToolsBreakpoint)
	ON_COMMAND(ID_TOOLS_NEXT_BOOKMARK, OnToolsNextBookmark)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_NEXT_BOOKMARK, OnUpdateToolsNextBookmark)
	ON_COMMAND(ID_TOOLS_PREV_BOOKMARK, OnToolsPrevBookmark)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_PREV_BOOKMARK, OnUpdateToolsPrevBookmark)
	ON_COMMAND(ID_TOOLS_OPTIONS, OnToolsOptions)
	ON_COMMAND(ID_FILE_GOTO, OnFileGoTo)
	ON_COMMAND(ID_FILE_PAGE_SETUP, CViewBase::OnFilePageSetup)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CViewBase::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CViewBase::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CViewBase::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDITextEditorView construction/destruction

CMDITextEditorView::CMDITextEditorView()
: m_dwLastUpdate(0)
, m_dwParserStart(0)
{
	m_rcMargin.left   = 25;
	m_rcMargin.right  = 25;
	m_rcMargin.top    = 50;
	m_rcMargin.bottom = 50;

	GetEditCtrl().SetConfigFile(CXTPSyntaxEditCtrl::GetModulePath() + _T("EditConfig\\SyntaxEdit.ini"));
}

CMDITextEditorView::~CMDITextEditorView()
{
}

BOOL CMDITextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CViewBase::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMDITextEditorView printing

BOOL CMDITextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return CViewBase::OnPreparePrinting(pInfo);
}

void CMDITextEditorView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	CViewBase::OnBeginPrinting(pDC, pInfo);
}

void CMDITextEditorView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	CViewBase::OnEndPrinting(pDC, pInfo);
}

void CMDITextEditorView::OnPrintHeader(CDC* pDC, CPrintInfo* pInfo)
{
	CXTPFontDC fontDC(pDC, GetEditCtrl().GetPaintManager()->GetFont(),
		::GetSysColor(COLOR_WINDOWTEXT));

	CPoint ptFrom;
	ptFrom.x = m_rcMargin.left;
	ptFrom.y = m_rcMargin.top - 5;
	pDC->MoveTo(ptFrom);

	CPoint ptTo;
	ptTo.x = pInfo->m_rectDraw.right - m_rcMargin.right;
	ptTo.y = m_rcMargin.top - 5;
	pDC->LineTo(ptTo);

	CString csPathName = GetDocument()->GetPathName();
	CString csFileName = csPathName.Right(csPathName.GetLength()-(csPathName.ReverseFind('\\')+1));

	if (csFileName.IsEmpty())
    {
		csFileName = GetDocument()->GetTitle();
		csFileName.Remove('*');
    }

	CSize sizeText = pDC->GetTextExtent(csFileName);
	int x = m_rcMargin.left;
	int y = m_rcMargin.top - 10 - sizeText.cy;
	pDC->TextOut(x, y, csFileName);

	CTime tmCurrent = CTime::GetCurrentTime();
	CString csTime = tmCurrent.Format(_T("%m-%d-%Y %I:%M%p"));
	sizeText = pDC->GetTextExtent(csTime);

	pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));
	pDC->TextOut((ptTo.x - sizeText.cx), y, csTime);
}

void CMDITextEditorView::OnPrintFooter(CDC* pDC, CPrintInfo* pInfo)
{
	CXTPFontDC fontDC(pDC, GetEditCtrl().GetPaintManager()->GetFont(),
		::GetSysColor(COLOR_WINDOWTEXT));

	int iBottomPos = (pInfo->m_rectDraw.Height() - m_rcMargin.bottom + 5);

	CPoint ptFrom;
	ptFrom.x = m_rcMargin.left;
	ptFrom.y = iBottomPos;
	pDC->MoveTo(ptFrom);

	CPoint ptTo;
	ptTo.x = pInfo->m_rectDraw.right - m_rcMargin.right;
	ptTo.y = iBottomPos;
	pDC->LineTo(ptTo);

	CString csPageNo;
	csPageNo.Format(_T("Page %d of %d"), pInfo->m_nCurPage, pInfo->GetMaxPage());

	pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));
	pDC->TextOut(m_rcMargin.left, iBottomPos + 5, csPageNo);
}

void CMDITextEditorView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// Print header in application-customized mode
//	OnPrintHeader(pDC, pInfo);

//	CRect rcDraw_orig = pInfo->m_rectDraw;

//	pInfo->m_rectDraw.top += m_rcMargin.top;
//	pInfo->m_rectDraw.bottom -= m_rcMargin.bottom;

	// Print body
	CViewBase::OnPrint(pDC, pInfo);

//	pInfo->m_rectDraw = rcDraw_orig;
	// Print footer
//	OnPrintFooter(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CMDITextEditorView diagnostics

#ifdef _DEBUG
void CMDITextEditorView::AssertValid() const
{
	CViewBase::AssertValid();
}

void CMDITextEditorView::Dump(CDumpContext& dc) const
{
	CViewBase::Dump(dc);
}

CMDITextEditorDoc* CMDITextEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDITextEditorDoc)));
	return (CMDITextEditorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDITextEditorView message handlers

BOOL CMDITextEditorView::OnRowColChanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (!CViewBase::OnRowColChanged(pNMHDR, pResult))
		return FALSE;

	XTP_EDIT_NMHDR_ROWCOLCHANGED* pNMHDR_RCC = (XTP_EDIT_NMHDR_ROWCOLCHANGED*)pNMHDR;
	if (!pNMHDR_RCC)
		return FALSE;

	theApp.m_pMainFrame->SetRowCol(pNMHDR_RCC->nRow, pNMHDR_RCC->nCol);

	*pResult = 0;
	return TRUE;
}

BOOL CMDITextEditorView::OnParseEvent(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (!CViewBase::OnParseEvent(pNMHDR, pResult))
		return FALSE;

	XTP_EDIT_NMHDR_PARSEEVENT* pNMParseEvent = (XTP_EDIT_NMHDR_PARSEEVENT*)pNMHDR;
	if (!pNMParseEvent)
		return FALSE;

	CDocument* pDoc = GetDocument();
	if (!pDoc)
		return FALSE;

	const int cnUpdateTimeOut = 500;
	CString strMsg;
	BOOL bUpdate = TRUE;

	if (pNMParseEvent->code == xtpEditOnTextBlockParsed) 
	{
		DWORD dwTime = ::GetTickCount();
		bUpdate = labs(dwTime - m_dwLastUpdate) >= cnUpdateTimeOut;

		CXTPSyntaxEditLexTextBlock* pTBended = (CXTPSyntaxEditLexTextBlock*)pNMParseEvent->wParam;
		if (pTBended && bUpdate)
		{
			m_dwLastUpdate = dwTime;

			DWORD dwTime1 = GetTickCount();//DEBUG
			double dTime = labs(dwTime1-m_dwParserStart)/1000.0;

			strMsg.Format(_T(" Parsing time(%.1f sec). Line(%d)."), dTime, pTBended->m_PosEndLC.nLine);

//			strMsg.Format(_T(" Parsing time(%.3f sec). Last parsed block: (%d,%d - %d,%d)::%s"), 
//				dTime,
//				pTBended->m_PosStartLC.nLine, pTBended->m_PosStartLC.nCol, 
//				pTBended->m_PosEndLC.nLine, pTBended->m_PosEndLC.nCol, 
//				pTBended->m_ptrLexClass ? pTBended->m_ptrLexClass->GetClassName() 
//				: _T("?<NULL>") );
		}
	}
	
	else if (pNMParseEvent->code == xtpEditOnParserStarted) 
	{		
		strMsg = _T("*** Parser Started");

		m_dwParserStart = GetTickCount();
	}
	
	else if (pNMParseEvent->code == xtpEditOnParserEnded) 
	{	
		if(!pNMParseEvent->wParam || (pNMParseEvent->wParam & xtpEditLPR_RunFinished)) 
		{
			DWORD dwTime1 = GetTickCount();
			double dTime = labs(dwTime1-m_dwParserStart)/1000.0;
			strMsg.Format(_T(" Parsing time(%.3f sec)."), dTime);
		}
	}

	if (bUpdate)	
	{		
		CString strTitle = pDoc->GetTitle();
		int nFIdx = strTitle.Find(_T(" :.: "));
		if(nFIdx >= 0) {
			strTitle = strTitle.Left(nFIdx);

			nFIdx = strTitle.Find(_T("*"));
			if(nFIdx >= 0) {
				strTitle = strTitle.Left(nFIdx);
			}
			strTitle.TrimRight();
		}
		
		if (pDoc->IsModified()) {
			strTitle += _T(" * ");
		}

		if(strMsg.GetLength() > 0) {
			strTitle += _T(" :.: ");
			strTitle += strMsg;		
		}		
        				
		pDoc->SetTitle(strTitle);
	}

	*pResult = 0;
	return TRUE;
}

void CMDITextEditorView::OnContextMenu(CWnd* /*pWnd*/, CPoint point) 
{
	if (point.x == -1 && point.y == -1)
	{
		// keystroke invocation
		CRect rect;
		GetClientRect(rect);
		ClientToScreen(rect);
		
		point = rect.TopLeft();
		point.Offset(5, 5);
	}
	
	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_MDITEXTYPE));
	
	CMenu* pPopup = menu.GetSubMenu(1);
	ASSERT(pPopup != NULL);

	CWnd* pWndPopupOwner = this;
	while (pWndPopupOwner->GetStyle() & WS_CHILD)
		pWndPopupOwner = pWndPopupOwner->GetParent();

	((CXTPMDIFrameWnd*)AfxGetMainWnd())->GetCommandBars()->
		TrackPopupMenuEx(pPopup, TPM_RIGHTBUTTON, point.x, point.y);
}

void CMDITextEditorView::OnEditFindSilent() 
{
	if (!GetFindReplaceDlg())
		return;

	CString csSelText;
	GetEditCtrl().GetSelectionText(csSelText);

	if (csSelText.IsEmpty()) 
	{
		CPoint pt(GetCaretPos());
		pt.y += 2;

		GetEditCtrl().SelectWord(pt);
		GetEditCtrl().GetSelectionText(csSelText);
	}

	csSelText = csSelText.SpanExcluding(_T("\r\n"));
	csSelText.Replace(_T("\t"), _T("    "));

	if (csSelText.IsEmpty()) 
	{
		csSelText = _T(" ");
	}
	else
	{
		GetFindReplaceDlg()->m_csFindText = csSelText;
	}
    
	BOOL bShiftKey  = (::GetKeyState(VK_SHIFT) & KF_UP) != 0;

	if (GetEditCtrl().Find(csSelText,
		GetFindReplaceDlg()->m_bMatchWholeWord,
		GetFindReplaceDlg()->m_bMatchCase, !bShiftKey))
	{
		SetDirty();		
	}
}

void CMDITextEditorView::OnEditTabify() 
{
	GetEditCtrl().TabifySelection();
}

void CMDITextEditorView::OnEditUnTabify() 
{
	GetEditCtrl().UnTabifySelection();
}

void CMDITextEditorView::OnEditUppercase() 
{
	GetEditCtrl().UppercaseSelection();
}

void CMDITextEditorView::OnEditLowercase() 
{
	GetEditCtrl().LowercaseSelection();
}

void CMDITextEditorView::OnEditWhiteSpace() 
{
	// toggle whitespace.
	GetEditCtrl().EnableWhiteSpace(
		!GetEditCtrl().IsEnabledWhiteSpace());

	CDocument* pDoc = GetDocument();
	if (pDoc)
	{
		pDoc->UpdateAllViews(this, xtpHintWhiteSpace,
			GetEditCtrl().IsEnabledWhiteSpace() ? (CObject*)1 : NULL);
	}
}

void CMDITextEditorView::OnUpdateEditWhiteSpace(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(GetEditCtrl().IsEnabledWhiteSpace());
}

void CMDITextEditorView::OnEditCollapseAll() 
{
	GetEditCtrl().CollapseAll();
}

void CMDITextEditorView::OnEditExpandAll() 
{
	GetEditCtrl().ExpandAll();
}

void CMDITextEditorView::OnToolsBookmark() 
{
	int iRow = GetEditCtrl().GetCurRow();
	GetEditCtrl().AddRemoveBookmark(iRow);
	UpdateAllViews();
}

void CMDITextEditorView::OnToolsBreakpoint() 
{
	int iRow = GetEditCtrl().GetCurRow();
	GetEditCtrl().AddRemoveBreakPoint(iRow);
	UpdateAllViews();
}

void CMDITextEditorView::OnToolsNextBookmark() 
{
	GetEditCtrl().NextBookmark();
}

void CMDITextEditorView::OnUpdateToolsNextBookmark(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetEditCtrl().HasBookmarks());
}

void CMDITextEditorView::OnToolsPrevBookmark() 
{
	GetEditCtrl().PrevBookmark();	
}

void CMDITextEditorView::OnUpdateToolsPrevBookmark(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetEditCtrl().HasBookmarks());
}

void CMDITextEditorView::OnToolsOptions() 
{
	// Create dialog object
	CXTPSyntaxEditPropertiesDlg dlg(this);

	// Instantiate dialog
	if (dlg.DoModal() == IDOK)
	{
		// Copy settings to remaining views.
		theApp.UpdateAllViews(this);
	}
}

void CMDITextEditorView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CViewBase::OnUpdate(pSender, lHint, pHint);

	if(pSender == this) {
		return;
	}

	switch (lHint)
	{
	case xtpHintWhiteSpace:
		GetEditCtrl().EnableWhiteSpace(pHint != NULL);
		break;

	case xtpEditHintInitView:
		GetEditCtrl().SetOverwriteMode(theApp.m_bInsertKey);
		break;
	}
}

void CMDITextEditorView::OnFileGoTo() 
{
	m_dlgGoTo.ShowDialog(&GetEditCtrl(),
		FALSE/*select line*/, TRUE/*hide after search*/);
}
