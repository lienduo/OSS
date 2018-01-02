// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "RibbonMDISample.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_FULLSCREEN, OnViewFullscreen)
	ON_COMMAND(ID_VIEW_NORMAL, OnViewNormal)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NORMAL, OnUpdateViewNormal)
	ON_COMMAND(ID_WINDOW_ARRANGE, OnWindowArrange)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_SWITCH, OnUpdateWindowSwitch)

	ON_COMMAND(ID_VIEW_WORKSPACE, OnViewWorkspace)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WORKSPACE, OnUpdateViewWorkspace)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(XTP_ID_RIBBONCONTROLTAB, OnUpdateRibbonTab)


END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
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

	pCommandBars->SetTheme(xtpThemeRibbon);
	
	m_wndStatusBar.SetFont(pCommandBars->GetPaintManager()->GetIconFont());
	m_wndStatusBar.SetDrawDisabledText(FALSE);
	m_wndStatusBar.SetCommandBars(pCommandBars);
	m_wndStatusBar.GetStatusBarCtrl().SetMinHeight(22);
	m_wndStatusBar.GetPane(0)->SetMargins(8, 1, 2, 1);

	//////////////////////////////////////////////////////////////////////////	
	// IMPORTANT:
	// Ribbon bitmaps resources by default located in application executable. 
	//
	// You also can specify handle to find ribbon resources:
	//((CXTPOffice2007Theme*)XTPPaintManager())->SetImageHandle(hHandle);

	//HMODULE hModule = LoadLibrary(m_csStylesPath + _T("Office2007Blue.dll"));
	//((CXTPOffice2007Theme*)pCommandBars->GetPaintManager())->SetImageHandle(hModule);

	CXTPToolTipContext* pToolTipContext = GetCommandBars()->GetToolTipContext();
	pToolTipContext->SetStyle(xtpToolTipOffice2007);
	pToolTipContext->ShowTitleAndDescription();
	pToolTipContext->SetMargin(CRect(2, 2, 2, 2));
	pToolTipContext->SetMaxTipWidth(180);
	pToolTipContext->SetFont(pCommandBars->GetPaintManager()->GetIconFont());

	pCommandBars->GetCommandBarsOptions()->ShowKeyboardCues(xtpKeyboardCuesShowWindowsDefault);
	pCommandBars->GetCommandBarsOptions()->bToolBarAccelTips = TRUE;

	pCommandBars->GetShortcutManager()->SetAccelerators(IDR_MAINFRAME);

	LoadIcons();

	if (!CreateRibbonBar())
	{
		TRACE0("Failed to create ribbon\n");
		return -1;
	}

	m_wndClient.Attach(this, FALSE);
	m_wndClient.GetToolTipContext()->SetStyle(xtpToolTipOffice2007);

	m_bShowWorkspace = FALSE;
	m_wndClient.ShowWorkspace(m_bShowWorkspace);


	LoadCommandBars(_T("CommandBars"));


	return 0;
}

void CMainFrame::LoadIcons()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();

	pCommandBars->GetImageManager()->SetIcons(IDR_SMALLICONS);
	pCommandBars->GetImageManager()->SetIcons(IDR_LARGEICONS);

	UINT uiGroupClipboard[] = {ID_EDIT_PASTE, ID_EDIT_CUT, ID_EDIT_COPY, ID_FORMAT_PAINTER};
	pCommandBars->GetImageManager()->SetIcons(ID_GROUP_CLIPBOARD, uiGroupClipboard, _countof(uiGroupClipboard), CSize(16, 16));

	UINT uiGroupFind[] = {ID_EDIT_FIND, ID_EDIT_REPLACE, ID_EDIT_GOTO, ID_EDIT_SELECT};
	pCommandBars->GetImageManager()->SetIcons(ID_GROUP_EDITING, uiGroupFind, _countof(uiGroupFind), CSize(16, 16));

	UINT uCommand = {IDB_GEAR};
	pCommandBars->GetImageManager()->SetIcons(IDB_GEAR, &uCommand, 1, CSize(0, 0), xtpImageNormal);


}

//#define CREATE_FROM_XML

BOOL CMainFrame::CreateRibbonBar()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();

	CMenu menu;
	menu.Attach(::GetMenu(m_hWnd));
	SetMenu(NULL);

#ifndef CREATE_FROM_XML
	CXTPRibbonBar* pRibbonBar = (CXTPRibbonBar*)pCommandBars->Add(_T("The Ribbon"), xtpBarTop, RUNTIME_CLASS(CXTPRibbonBar));
	if (!pRibbonBar)
	{
		return FALSE;
	}


	pRibbonBar->EnableDocking(0);

	CXTPControlPopup* pControlFile = (CXTPControlPopup*)pRibbonBar->AddSystemButton(0);
	pControlFile->SetCommandBar(menu.GetSubMenu(0));
	
	pControlFile->SetIconId(IDB_GEAR);

	CXTPRibbonTab* pTabHome = pRibbonBar->AddTab(ID_TAB_HOME);

	CXTPRibbonGroup* pGroupFile = pTabHome->AddGroup(ID_GROUP_FILE);
	pGroupFile->Add(xtpControlButton, ID_FILE_NEW);
	pGroupFile->Add(xtpControlButton, ID_FILE_OPEN);
	pGroupFile->Add(xtpControlButton, ID_FILE_CLOSE);
	CXTPControlPopup* pControlSave = (CXTPControlPopup*)pGroupFile->Add(xtpControlSplitButtonPopup, ID_FILE_SAVE);
	pControlSave->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_FILE_SAVE);
	pControlSave->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_FILE_SAVE_AS);

	CXTPControlPopup* pControlPrint = (CXTPControlPopup*)pGroupFile->Add(xtpControlSplitButtonPopup, ID_FILE_PRINT);
	pControlPrint->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_FILE_PRINT);
	pControlPrint->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_FILE_PRINT_SETUP);
	pControlPrint->SetBeginGroup(TRUE);


	CXTPRibbonTab* pTabEdit = pRibbonBar->AddTab(ID_TAB_EDIT);


	CXTPRibbonGroup* pGroupClipborad = pTabEdit->AddGroup(ID_GROUP_CLIPBOARD);
	pGroupClipborad->ShowOptionButton();
	
	CXTPControlPopup* pControlPaste = (CXTPControlPopup*)pGroupClipborad->Add(xtpControlSplitButtonPopup, ID_EDIT_PASTE);
	pControlPaste->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_EDIT_PASTE);
	pControlPaste->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_EDIT_PASTE_SPECIAL);
	pGroupClipborad->Add(xtpControlButton, ID_EDIT_CUT);
	pGroupClipborad->Add(xtpControlButton, ID_EDIT_COPY);	
	pGroupClipborad->Add(xtpControlButton, ID_FORMAT_PAINTER);

	CXTPRibbonGroup* pGroupEditing = pTabEdit->AddGroup(ID_GROUP_EDITING);
	pGroupEditing->Add(xtpControlButton, ID_EDIT_FIND);
	pGroupEditing->Add(xtpControlButton, ID_EDIT_REPLACE);
	pGroupEditing->Add(xtpControlButton, ID_EDIT_GOTO);
	CXTPControlPopup* pControlSelect = (CXTPControlPopup*)pGroupEditing->Add(xtpControlPopup, ID_EDIT_SELECT);
	pControlSelect->GetCommandBar()->GetControls()->Add(xtpControlButton, ID_EDIT_SELECT_ALL);
	pControlSelect->SetFlags(xtpFlagManualUpdate);
	

	
	
	CXTPRibbonTab* pTabView = pRibbonBar->AddTab(ID_TAB_VIEW);

	CXTPRibbonGroup* pGroupDocumentView = pTabView->AddGroup(ID_GROUP_DOCUMENTVIEWS);
	pGroupDocumentView->Add(xtpControlButton, ID_VIEW_NORMAL);
	pGroupDocumentView->Add(xtpControlButton, ID_FILE_PRINT_PREVIEW);
	pGroupDocumentView->Add(xtpControlButton, ID_VIEW_FULLSCREEN);

	CXTPRibbonGroup* pGroupShowHide = pTabView->AddGroup(ID_GROUP_SHOWHIDE);
	pGroupShowHide->Add(xtpControlCheckBox, ID_VIEW_STATUS_BAR);
	pGroupShowHide->Add(xtpControlCheckBox, ID_VIEW_WORKSPACE);

	CXTPRibbonGroup* pGroupWindow = pTabView->AddGroup(ID_GROUP_WINDOW);
	pGroupWindow->Add(xtpControlButton, ID_WINDOW_NEW);
	pGroupWindow->Add(xtpControlButton, ID_WINDOW_ARRANGE);
	CXTPControlPopup* pControlSwitchWindows = (CXTPControlPopup*)pGroupWindow->Add(xtpControlPopup, ID_WINDOW_SWITCH);
	pControlSwitchWindows->GetCommandBar()->GetControls()->Add(xtpControlButton, XTP_ID_WINDOWLIST);


	CXTPControl* pControlAbout = pRibbonBar->GetControls()->Add(xtpControlButton, ID_APP_ABOUT);
	pControlAbout->SetFlags(xtpFlagRightAlign);

	pRibbonBar->GetQuickAccessControls()->Add(xtpControlButton, ID_FILE_SAVE);
	pRibbonBar->GetQuickAccessControls()->Add(xtpControlButton, ID_EDIT_UNDO);
	pRibbonBar->GetQuickAccessControls()->Add(xtpControlButton, ID_FILE_PRINT);
	pRibbonBar->GetQuickAccessControls()->CreateOriginalControls();

#else
	CXTPPropExchangeXMLNode px(TRUE, 0, _T("Settings"));

	if (px.LoadFromResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_LAYOUT), RT_HTML))
	{
		CXTPPropExchangeSection pxCommandBars(px.GetSection(_T("CommandBars")));
		XTP_COMMANDBARS_PROPEXCHANGE_PARAM param; 
		param.bSerializeControls = TRUE;
		GetCommandBars()->DoPropExchange(&pxCommandBars, &param);
	}
	else
	{
		AfxMessageBox(_T("Can't load Layout"));
		return FALSE;
	}
	CXTPRibbonBar* pRibbonBar = (CXTPRibbonBar*)GetCommandBars()->GetMenuBar();
	pRibbonBar->EnableCustomization(FALSE);

	pRibbonBar->GetQuickAccessControls()->SetOriginalControls(new CXTPOriginalControls());
	pRibbonBar->GetQuickAccessControls()->GetOriginalControls()->Add(xtpControlButton, ID_FILE_SAVE);
	pRibbonBar->GetQuickAccessControls()->GetOriginalControls()->Add(xtpControlButton, ID_EDIT_UNDO);
	pRibbonBar->GetQuickAccessControls()->GetOriginalControls()->Add(xtpControlButton, ID_FILE_PRINT);

#endif


	pRibbonBar->EnableFrameTheme();
	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.lpszClass = _T("XTPMainFrame");
	CXTPDrawHelpers::RegisterWndClass(AfxGetInstanceHandle(), cs.lpszClass, 
		CS_DBLCLKS, AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnUpdateRibbonTab(CCmdUI* pCmdUI)
{
	CXTPRibbonControlTab* pControl = DYNAMIC_DOWNCAST(CXTPRibbonControlTab, CXTPControl::FromUI(pCmdUI));
	if (!pControl)
		return;

	CXTPRibbonTab* pTab = pControl->FindTab(ID_TAB_EDIT);
	if (!pTab)
		return;

	pTab->SetVisible(MDIGetActive() != NULL);
}

void CMainFrame::OnViewFullscreen() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnViewNormal() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateViewNormal(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(1);	
}

void CMainFrame::OnWindowArrange() 
{
	::SendMessage(m_hWndMDIClient, WM_MDITILE, MDITILE_HORIZONTAL, 0);

	
}

void CMainFrame::OnUpdateWindowSwitch(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(MDIGetActive() != NULL ? TRUE : FALSE);
	
}

void CMainFrame::OnViewWorkspace()
{
	m_bShowWorkspace ^= 1;
	m_wndClient.ShowWorkspace(m_bShowWorkspace);
}

void CMainFrame::OnUpdateViewWorkspace(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bShowWorkspace);
}

void CMainFrame::OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState)
{
// Toggle CommandBars
	GetCommandBars()->OnSetPreviewMode(bPreview);

// Toggle Tab Client
	m_wndClient.ShowWorkspace(!bPreview);

	CMDIFrameWnd::OnSetPreviewMode(bPreview, pState);
}

void CMainFrame::OnClose() 
{	
/*	CXTPPropExchangeXMLNode px(FALSE, 0, _T("Settings"));

	if (px.OnBeforeExchange()) 
	{
		CXTPPropExchangeSection pxCommandBars(px.GetSection(_T("CommandBars")));
		XTP_COMMANDBARS_PROPEXCHANGE_PARAM param; 
		param.bSerializeControls = TRUE; 
		param.bSaveOriginalControls = FALSE;
		param.bSerializeOptions = TRUE;
		GetCommandBars()->DoPropExchange(&pxCommandBars, &param);

		px.SaveToFile(_T("C:\\save.xml"));
	}*/
	
	CXTPMDIFrameWnd::OnClose();
}
