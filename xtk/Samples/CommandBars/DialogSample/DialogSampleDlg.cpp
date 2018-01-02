// DialogSampleDlg.cpp : implementation file
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
#include "DialogSample.h"
#include "DialogSampleDlg.h"

#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDialogSampleDlg dialog

CDialogSampleDlg::CDialogSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogSampleDlgBase(CDialogSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_rcBorders.SetRectEmpty();
	m_bInRepositionControls = FALSE;
	m_bInitDone = FALSE;
}

void CDialogSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogSampleDlgBase::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogSampleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogSampleDlg, CDialogSampleDlgBase)
	//{{AFX_MSG_MAP(CDialogSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_COMMAND(ID_APP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_NEW, OnEmptyCommand)
	ON_COMMAND(ID_FILE_OPEN, OnEmptyCommand)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_BUTTON_PLAY, ID_BUTTON_BACKWARD, OnEmptyCommandRange)

	ON_COMMAND_RANGE(ID_THEME_OFFICE2000, ID_THEME_WHIDBEY, OnTheme)
	ON_UPDATE_COMMAND_UI_RANGE(ID_THEME_OFFICE2000, ID_THEME_WHIDBEY, OnUpdateTheme)

	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_COMMAND(XTP_ID_CUSTOMIZE, OnCustomize)

	ON_UPDATE_COMMAND_UI(ID_INDICATOR_CAPS, OnUpdateKeyIndicator)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_NUM, OnUpdateKeyIndicator)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_SCRL, OnUpdateKeyIndicator)
	ON_MESSAGE(WM_POPMESSAGESTRING, OnSetMessageString)
	ON_MESSAGE(WM_SETMESSAGESTRING, OnSetMessageString)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
/////////////////////////////////////////////////////////////////////////////
// CDialogSampleDlg message handlers

BOOL CDialogSampleDlg::OnInitDialog()
{
	SetFlag(xtResizeNoSizeIcon);
	
	CDialogSampleDlgBase::OnInitDialog();

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
	SetIcon(m_hIcon, TRUE);         // Set big icon
	SetIcon(m_hIcon, FALSE);        // Set small icon


	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetPaneInfo(0, ID_SEPARATOR, SBPS_STRETCH, 100);

	VERIFY(InitCommandBars());

	OnTheme(ID_THEME_WHIDBEY);


	CXTPCommandBars* pCommandBars = GetCommandBars();
	pCommandBars->SetMenu(_T("Menu Bar"), IDR_MENU);

	CXTPToolBar* pToolBar = pCommandBars->Add(_T("Standard"), xtpBarTop);
	pToolBar->LoadToolBar(IDR_TOOLBAR);

	((CXTPControlButton*)pToolBar->GetControls()->FindControl(xtpControlButton, ID_BUTTON_PLAY, TRUE, FALSE))->SetStyle(xtpButtonIconAndCaption);
	((CXTPControlButton*)pToolBar->GetControls()->FindControl(xtpControlButton, ID_BUTTON_STOP, TRUE, FALSE))->SetStyle(xtpButtonIconAndCaption);
	((CXTPControlButton*)pToolBar->GetControls()->FindControl(xtpControlButton, ID_BUTTON_PAUSE, TRUE, FALSE))->SetStyle(xtpButtonIconAndCaption);
	pToolBar->GetControls()->CreateOriginalControls();

	XTPImageManager()->SetIcons(IDR_MAINFRAME);
	pCommandBars->GetCommandBarsOptions()->ShowKeyboardCues(xtpKeyboardCuesShowWindowsDefault);
	pCommandBars->GetToolTipContext()->SetStyle(xtpToolTipOffice);

	pCommandBars->GetShortcutManager()->SetAccelerators(IDR_ACCELERATOR);


	LoadCommandBars(_T("CommandBars"));

	SetResize(IDC_SLIDER1,         SZ_BOTTOM_LEFT, SZ_BOTTOM_RIGHT );	
	SetResize(IDC_STATIC_POSITION, SZ_TOP_LEFT, CXTResizePoint( 0.3f, 1) );
	SetResize(IDC_STATIC_RECT,     CXTResizePoint( 0.3f, 0), CXTResizePoint( 0.6f, 1) );
	SetResize(IDC_STATIC_LENGTH,   CXTResizePoint( 0.6f, 0), CXTResizePoint( 1, 1) );

	m_bInitDone = TRUE;
	RepositionControls();


	m_szMin = m_szWindow;
	AutoLoadPlacement(_T("Placement"));



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialogSampleDlg::RepositionControls()
{
	if (m_bInRepositionControls || !m_bInitDone)
		return;

	CRect rcClientStart;
	CRect rcClientNow;
	GetClientRect(rcClientStart);

	if ((GetStyle() & WS_MINIMIZE) || (rcClientStart.IsRectEmpty()))
		return;

	m_bInRepositionControls = TRUE;

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0, reposQuery, rcClientNow);

	CRect rcBorders(rcClientNow.left - rcClientStart.left, rcClientNow.top - rcClientStart.top,  rcClientStart.right - rcClientNow.right, 
		rcClientStart.bottom - rcClientNow.bottom);

	if (rcBorders != m_rcBorders)
	{
		
		CPoint ptOffset(rcBorders.left - m_rcBorders.left, rcBorders.top - m_rcBorders.top);
		CSize szOffset(rcBorders.left + rcBorders.right - m_rcBorders.left - m_rcBorders.right,
			rcBorders.top + rcBorders.bottom - m_rcBorders.top - m_rcBorders.bottom);

		CRect rcWindow;
		GetWindowRect(rcWindow);
		rcWindow.BottomRight() += szOffset;

		Offset(ptOffset);
		m_szWindow += szOffset;
		m_szMin += szOffset;
	
		MoveWindow(rcWindow, TRUE);
	}

	m_rcBorders = rcBorders;

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	m_bInRepositionControls = FALSE;
}


void CDialogSampleDlg::OnDestroy()
{
	SaveCommandBars(_T("CommandBars"));
	
	CDialogSampleDlgBase::OnDestroy();
}

void CDialogSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogSampleDlgBase::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogSampleDlg::OnPaint()
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
		CDialogSampleDlgBase::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

LRESULT CDialogSampleDlg::OnKickIdle(WPARAM, LPARAM)
{
	if (GetCommandBars()) GetCommandBars()->UpdateCommandBars();
	if (m_wndStatusBar.GetSafeHwnd()) m_wndStatusBar.SendMessage(WM_IDLEUPDATECMDUI, TRUE);
	return 0;
}


BOOL CDialogSampleDlg::PreTranslateMessage(MSG* pMsg)
{
	return CDialogSampleDlgBase::PreTranslateMessage(pMsg);
}



void CDialogSampleDlg::OnHelpAbout()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CDialogSampleDlg::OnEmptyCommandRange(UINT)
{
}

void CDialogSampleDlg::OnEmptyCommand()
{
}

void CDialogSampleDlg::OnTheme(UINT nTheme)
{
	m_eTheme = (XTPPaintTheme)(nTheme - ID_THEME_OFFICE2000);
	CXTPPaintManager::SetTheme(m_eTheme);
	RedrawWindow(0, 0, RDW_ALLCHILDREN|RDW_INVALIDATE);
}

void CDialogSampleDlg::OnUpdateTheme(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_eTheme == (XTPPaintTheme)(pCmdUI->m_nID - ID_THEME_OFFICE2000)? TRUE: FALSE);
}

void CDialogSampleDlg::OnFileExit()
{

	OnCancel();
}

void CDialogSampleDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialogSampleDlgBase::OnSize(nType, cx, cy);
	RepositionControls();
}



void CDialogSampleDlg::OnCustomize()
{
	CXTPCustomizeSheet cs(GetCommandBars());

	CXTPCustomizeKeyboardPage pageKeyboard(&cs);
	cs.AddPage(&pageKeyboard);
	pageKeyboard.AddCategories(IDR_MENU);

	CXTPCustomizeOptionsPage pageOptions(&cs);
	cs.AddPage(&pageOptions);

	CXTPCustomizeCommandsPage* pCommands = cs.GetCommandsPage();
	pCommands->AddCategories(IDR_MENU);

	pCommands->InsertAllCommandsCategory();
	pCommands->InsertBuiltInMenus(IDR_MENU);
	pCommands->InsertNewMenuCategory();

	cs.DoModal();
}



/////////////////////////////////////////////////////////////////////////////
// Support for standard status bar

void CDialogSampleDlg::OnUpdateKeyIndicator(CCmdUI* pCmdUI)
{
	UINT nVK;
	UINT flag = 0x0001;

	switch (pCmdUI->m_nID)
	{
	case ID_INDICATOR_CAPS:
		nVK = VK_CAPITAL;
		break;

	case ID_INDICATOR_NUM:
		nVK = VK_NUMLOCK;
		break;

	case ID_INDICATOR_SCRL:
		nVK = VK_SCROLL;
		break;

	default:
		TRACE1("Warning: OnUpdateKeyIndicator - unknown indicator 0x%04X.\n",
			pCmdUI->m_nID);
		pCmdUI->ContinueRouting();
		return; // not for us
	}

	pCmdUI->Enable(::GetKeyState(nVK) & flag);
		// enable static text based on toggled key state
	ASSERT(pCmdUI->m_bEnableChanged);
}


void CDialogSampleDlg::GetMessageString(UINT nID, CString& rMessage) const
{
	// load appropriate string
	LPTSTR lpsz = rMessage.GetBuffer(255);
	if (AfxLoadString(nID, lpsz) != 0)
	{
		// first newline terminates actual string
		lpsz = _tcschr(lpsz, _T('\n'));
		if (lpsz != NULL)
			*lpsz = '\0';
	}
	else
	{
		// not found
		TRACE1("Warning: no message line prompt for ID 0x%04X.\n", nID);
	}
	rMessage.ReleaseBuffer();
}


LRESULT CDialogSampleDlg::OnSetMessageString(WPARAM wParam, LPARAM lParam)
{
	LPCTSTR lpsz = NULL;
	CString strMessage;
	
	// set the message bar text
	if (lParam != 0)
	{
		ASSERT(wParam == 0);    // can't have both an ID and a string
		lpsz = (LPCTSTR)lParam; // set an explicit string
	}
	else if (wParam != 0)
	{
		// get message associated with the ID indicated by wParam
		GetMessageString((UINT)wParam, strMessage);
		lpsz = strMessage;
	}
	m_wndStatusBar.SetWindowText(lpsz);
	return 0;
}
