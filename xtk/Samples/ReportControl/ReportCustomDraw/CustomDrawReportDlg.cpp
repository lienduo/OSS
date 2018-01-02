// CustomDrawReportDlg.cpp : implementation file
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
#include "CustomDrawReport.h"
#include "CustomDrawReportDlg.h"
#include "MessageRecord.h"
#include "XTPCustomDrawReportPaintManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomDrawReportDlg dialog

CCustomDrawReportDlg::CCustomDrawReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomDrawReportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomDrawReportDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nDrawingMethod = 1;
}

void CCustomDrawReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomDrawReportDlg)
	DDX_Control(pDX, IDC_REPORTCTRL, m_wndReportCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomDrawReportDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomDrawReportDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_COMMAND(IDM_USE_DRAWFRAMECONTROL, OnUseDrawframecontrol)
	ON_COMMAND(IDM_USE_DRAWSTATE, OnUseDrawstate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomDrawReportDlg message handlers

enum
{
	REPORTCOLUMN_NAME,
	REPORTCOLUMN_ATTR1,
	REPORTCOLUMN_ATTR2,
};

const int COLUMN_MAIL_ICON   =  0;
const int COLUMN_CHECK_ICON  =  2;

BOOL CCustomDrawReportDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//
	// create main menu.
	//
	CMenu* pMenu = GetMenu();
	if(pMenu)
	{
		CMenu* pSubMenu = pMenu->GetSubMenu(0);
		if(pSubMenu)
			pSubMenu->CheckMenuRadioItem(IDM_USE_DRAWFRAMECONTROL, IDM_USE_DRAWSTATE, IDM_USE_DRAWFRAMECONTROL, MF_BYCOMMAND);
	}

	//
	// create the image lists used by the report control.
	//

	if (!m_ilControls.Create(14, 14, ILC_COLOR24 | ILC_MASK, 0, 1))
		return -1;

	//
	// load the image bitmap and set the image list for the 
	// report control.
	//

	CBitmap bitmap;
	VERIFY(bitmap.LoadBitmap(IDB_CONTROLS));
	m_ilControls.Add(&bitmap, RGB(255, 0, 255));	

	//
	//  Add sample columns
	//

	m_wndReportCtrl.AddColumn(new CXTPReportColumn(REPORTCOLUMN_NAME, _T("Name"), 150));
	m_wndReportCtrl.AddColumn(new CXTPReportColumn(REPORTCOLUMN_ATTR1, _T("Attribute 1"), 150));
	m_wndReportCtrl.AddColumn(new CXTPReportColumn(REPORTCOLUMN_ATTR2, _T("Attribute 2"), 150));

	//
	//  Add sample records in tree
	//

	CString strName;
	for(int i = 0; i < 10; i++)
	{
		strName.Format(_T("%s %d"), _T("Parameter"), i);
		m_wndReportCtrl.AddRecord(new CMessageRecord(strName, 4, i, 4, 1 << (i & 3)));
	}

	//
	// define style attributes for the report control.
	//

	m_wndReportCtrl.GetColumns()->Find(REPORTCOLUMN_NAME)->SetTreeColumn(TRUE);
	m_PaintManager.SetCustomDrawParent(this);
	m_wndReportCtrl.SetPaintManager(&m_PaintManager);

	//
	// after columns and data have been added call Populate to 
	// populate all of the date for the control.
	//

	m_wndReportCtrl.Populate();

	m_wndReportCtrl.EnableDragDrop(_T("CustomDrawReport"), xtpReportAllowDrag | xtpReportAllowDrop);


	// Set control resizing.
	SetResize(IDC_REPORTCTRL, SZ_TOP_LEFT, SZ_BOTTOM_RIGHT);
	SetResize(IDCANCEL, SZ_BOTTOM_RIGHT, SZ_BOTTOM_RIGHT);
	SetResize(IDOK, SZ_BOTTOM_RIGHT, SZ_BOTTOM_RIGHT);

	// Load window placement
	LoadPlacement(_T("CCustomDrawReportDlg"));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCustomDrawReportDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCustomDrawReportDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCustomDrawReportDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCustomDrawReportDlg::OnDestroy() 
{
	CDialog::OnDestroy();


	// Save window placement
	SavePlacement(_T("CCustomDrawReportDlg"));

}

unsigned int CCustomDrawReportDlg::GetControlsNumber(CXTPReportRecordItem* pItem)
{
	if(pItem && pItem->GetIndex() == 1)
		return ((CMessageRecordItemCheckGroup*)pItem)->GetControlsNumber();
	else if(pItem && pItem->GetIndex() == 2)
		return ((CMessageRecordItemRadioGroup*)pItem)->GetControlsNumber();

	return 0;
}

unsigned int CCustomDrawReportDlg::GetControlsNumber(CXTPReportRow* pRow)
{
	if(!pRow)
		return 0;

	unsigned int unControls = 0;

	CXTPReportRecordItem* pItem = pRow->GetRecord()->GetItem(1);
	unControls = GetControlsNumber(pItem);
	pItem = pRow->GetRecord()->GetItem(2);
	unControls = max(unControls, GetControlsNumber(pItem));

	return unControls;
}

int CCustomDrawReportDlg::GetRowHeight(CDC* /*pDC*/, CXTPReportRow* pRow)
{
	unsigned int unControls = 0;
	CXTPReportRecordItem* pItem = pRow->GetRecord()->GetItem(1);
	if(pItem)
		unControls = max(unControls, ((CMessageRecordItemCheckGroup*)pItem)->GetControlsNumber());
	pItem = pRow->GetRecord()->GetItem(2);
	if(pItem)
		unControls = max(unControls, ((CMessageRecordItemRadioGroup*)pItem)->GetControlsNumber());

	if (!pRow->IsGroupRow())
	{
		return unControls * 15 + (m_PaintManager.IsGridVisible(FALSE) ? 1 : 0);
	}

	if (m_PaintManager.m_bShadeGroupHeadings)
		return unControls * 15 + 6;

	return unControls * 15 + 16;
}

BOOL CCustomDrawReportDlg::DrawItem(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* /*pMetrics*/)
{
	if(pDrawArgs->pColumn->GetIndex() < 1)
		return FALSE;

	CRect rc = pDrawArgs->pRow->GetItemRect(pDrawArgs->pItem);
	rc.left += 5;
    rc.right = rc.left + 14;
    rc.bottom = rc.top + 14;
	for(unsigned int i = 0; i < GetControlsNumber(pDrawArgs->pItem); i++)
	{
		UINT unFlags;
		UINT unIconId;
		CString strText;

		if(pDrawArgs->pColumn->GetIndex() == 1)
		{
			strText.Format(_T("%s%d"), _T("T"), i + 1);
            unFlags = DFCS_BUTTONCHECK;
			CMessageRecordItemCheckGroup* pRecord = (CMessageRecordItemCheckGroup*)pDrawArgs->pItem;
			if(pRecord->GetValue() & (1 << i))
			{
				unFlags |= DFCS_CHECKED;
                unIconId = 1;
			}
			else
			{
				unFlags &= ~DFCS_CHECKED;
                unIconId = 0;
			}
		}
		else
		{
			strText.Format(_T("%s%d"), _T("V"), i + 1);
            unFlags = DFCS_BUTTONRADIO;
			CMessageRecordItemRadioGroup* pRecord = (CMessageRecordItemRadioGroup*)pDrawArgs->pItem;
			if(pRecord->GetValue() & (1 << i))
			{
				unFlags |= DFCS_CHECKED;
                unIconId = 3;
			}
			else
			{
				unFlags &= ~DFCS_CHECKED;
                unIconId = 2;
			}
		}
		if(m_nDrawingMethod == 1)
			::DrawFrameControl(pDrawArgs->pDC->GetSafeHdc(), rc, DFC_BUTTON, unFlags);
		else
			m_ilControls.Draw(pDrawArgs->pDC, unIconId, rc.TopLeft(), ILD_NORMAL);
        TextOut(pDrawArgs->pDC->GetSafeHdc(), rc.left + 20, rc.top, strText, strText.GetLength());
        rc.top += 15;
        rc.bottom += 15;
	}

	return TRUE;
}
BOOL CCustomDrawReportDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_LBUTTONDOWN)
	{
		CPoint pt = pMsg->pt;
		m_wndReportCtrl.ScreenToClient(&pt);
		CXTPReportRow* pRow = m_wndReportCtrl.HitTest(pt);
		if(pRow)
		{
			CXTPReportRecordItem* pItem = pRow->HitTest(pt);
			if(pItem)
			{
				if(pItem->GetIndex() < 1)
					return 0;
				unsigned int unControls = GetControlsNumber(pItem);
				if(unControls == 0)
					return 0;
				CRect rc = pRow->GetItemRect(pItem);
				rc.right = rc.left + 14 + 25;
				rc.bottom = rc.top + 14;
				for(unsigned int i = 0; i < unControls; i++)
				{
					if(rc.PtInRect(pt))
					{
						if(pItem->GetIndex() == 1)
						{
							((CMessageRecordItemCheckGroup*)pItem)->ToggleBit(i);
						}
						else
						{
							((CMessageRecordItemRadioGroup*)pItem)->SetValue(1 << i);
						}
					}
					rc.OffsetRect(0, 15);
				}
			}
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CCustomDrawReportDlg::OnUseDrawframecontrol() 
{
	if(m_nDrawingMethod == 1)
		return;
	m_nDrawingMethod = 1;
	CMenu* pMenu = GetMenu();
	if(pMenu)
	{
		CMenu* pSubMenu = pMenu->GetSubMenu(0);
		if(pSubMenu)
			pSubMenu->CheckMenuRadioItem(IDM_USE_DRAWFRAMECONTROL, IDM_USE_DRAWSTATE, IDM_USE_DRAWFRAMECONTROL, MF_BYCOMMAND);
	}
	m_wndReportCtrl.RedrawControl();
}

void CCustomDrawReportDlg::OnUseDrawstate() 
{
	if(m_nDrawingMethod == 2)
		return;
	m_nDrawingMethod = 2;
	CMenu* pMenu = GetMenu();
	if(pMenu)
	{
		CMenu* pSubMenu = pMenu->GetSubMenu(0);
		if(pSubMenu)
			pSubMenu->CheckMenuRadioItem(IDM_USE_DRAWFRAMECONTROL, IDM_USE_DRAWSTATE, IDM_USE_DRAWSTATE, MF_BYCOMMAND);
	}
	m_wndReportCtrl.RedrawControl();
}
