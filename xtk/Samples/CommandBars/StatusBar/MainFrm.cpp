// MainFrm.cpp : implementation of the CMainFrame class
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
#include "StatusBar.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define INT2THEME(i) (XTPPaintTheme)(i)

AFX_STATIC XTPPaintTheme ThemeFromCommand(UINT nID)
{
	switch (nID)
	{
	case ID_VIEW_THEME_OFFICE2000: return xtpThemeOffice2000;
	case ID_VIEW_THEME_OFFICEXP:   return xtpThemeOfficeXP;
	case ID_VIEW_THEME_OFFICE2003: return xtpThemeOffice2003;
	case ID_VIEW_THEME_OFFICE2007: return xtpThemeRibbon;
	}
	return xtpThemeOffice2000;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_STATUSBAR_SHOWBUTTONS, OnStatusBarShowButtons)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_SHOWBUTTONS, OnUpdateStatusBarShowButtons)
	ON_COMMAND(ID_STATUSBAR_SHOWAVIANIMATION, OnStatusBarShowAviAnimation)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_SHOWAVIANIMATION, OnUpdateStatusBarShowAviAnimation)
	ON_COMMAND(ID_STATUSBAR_SHOWPROGRESSBAR, OnStatusBarShowProgressBar)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_SHOWPROGRESSBAR, OnUpdateStatusBarShowProgressBar)
	ON_COMMAND(ID_STATUSBAR_SHOWEDITCONTROL, OnStatusBarShowEditControl)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_SHOWEDITCONTROL, OnUpdateStatusBarShowEditControl)
	ON_COMMAND(ID_STATUSBAR_SHOWCOMPANYLOGO, OnStatusBarShowCompanyLogo)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_SHOWCOMPANYLOGO, OnUpdateStatusBarShowCompanyLogo)
	ON_COMMAND(ID_STATUSBAR_PLAYANIMATION, OnStatusBarPlayAnimation)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_PLAYANIMATION, OnUpdateStatusBarPlayAnimation)
	ON_COMMAND(ID_STATUSBAR_TESTPROGRESS, OnStatusBarTestProgress)
	ON_UPDATE_COMMAND_UI(ID_STATUSBAR_TESTPROGRESS, OnUpdateStatusBarTestProgress)
	//}}AFX_MSG_MAP

	ON_XTP_CREATECONTROL()
	ON_XTP_EXECUTE(ID_VIEW_OFFICE_THEME, OnOfficeThemeChanged)

	ON_COMMAND(XTP_ID_CUSTOMIZE, OnCustomize)

	ON_COMMAND_RANGE(ID_VIEW_THEME_OFFICE2000, ID_VIEW_THEME_OFFICE2007, OnViewTheme)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_THEME_OFFICE2000, ID_VIEW_THEME_OFFICE2007, OnUpdateViewTheme)

	ON_COMMAND_RANGE(ID_INDICATOR_PRINT, ID_INDICATOR_DRAFT, OnIndicatorButton)
	ON_UPDATE_COMMAND_UI_RANGE(ID_INDICATOR_PRINT, ID_INDICATOR_DRAFT, OnUpdateIndicatorButton)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
: m_bAnimation(FALSE)
, m_bPlayAnimation(FALSE)
, m_bButtons(FALSE)
, m_bEdit(FALSE)
, m_bProgress(FALSE)
, m_bLogo(FALSE)
{
	m_eOfficeTheme = INT2THEME(AfxGetApp()->GetProfileInt(
		_T("Settings"), _T("OfficeTheme"), xtpThemeOffice2007));

	m_nPaneID = 0;
}

CMainFrame::~CMainFrame()
{
	AfxGetApp()->WriteProfileInt(
		_T("Settings"), _T("OfficeTheme"), m_eOfficeTheme);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
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
	pCommandBars->SetMenu(_T("Menu Bar"), IDR_MAINFRAME);

	CXTPToolBar* pCommandBar = (CXTPToolBar*)pCommandBars->Add(_T("Standard"), xtpBarTop);
	if (!pCommandBar ||
		!pCommandBar->LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}
	
	pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, IDR_TOOLBAR_ALPHA);
	pCommandBars->GetShortcutManager()->SetAccelerators(IDR_MAINFRAME);
	
	// Load the previous state for command bars.
	LoadCommandBars(_T("CommandBars"));
	SetOfficeTheme(xtpThemeRibbon);

	OnStatusBarShowButtons();

	return 0;
}

int CMainFrame::OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl)
{
	if (lpCreateControl->nID == ID_VIEW_OFFICE_THEME)
	{
		CXTPControlComboBox* pComboTheme = (CXTPControlComboBox*)CXTPControlComboBox::CreateObject();
		if (pComboTheme != NULL)
		{
			pComboTheme->SetWidth(200);
			pComboTheme->SetCaption(_T("Theme:"));
			pComboTheme->SetStyle(xtpComboLabel);
			pComboTheme->SetFlags(xtpFlagManualUpdate);
			
			pComboTheme->SetItemData(pComboTheme->AddString(_T("Office 2007")), xtpThemeRibbon);
			pComboTheme->SetItemData(pComboTheme->AddString(_T("Office 2003")), xtpThemeOffice2003);
			pComboTheme->SetItemData(pComboTheme->AddString(_T("Office XP")),   xtpThemeOfficeXP);
			pComboTheme->SetItemData(pComboTheme->AddString(_T("Office 2000")), xtpThemeOffice2000);
			
			lpCreateControl->pControl = pComboTheme;
			UpdateThemeCombo(xtpThemeRibbon, pComboTheme);
			
			return TRUE;
		}
	}
	
	return FALSE;
}

BOOL CMainFrame::UpdateThemeCombo(XTPPaintTheme eOfficeTheme, CXTPControlComboBox* pComboTheme /*=NULL*/)
{
	if (pComboTheme == NULL)
	{
		CXTPCommandBars* pCommandBars = GetCommandBars();
		if (pCommandBars)
		{
			pComboTheme = (CXTPControlComboBox*)pCommandBars->FindControl(
				xtpControlComboBox, ID_VIEW_OFFICE_THEME, TRUE, FALSE);
		}
		
		if (pComboTheme == NULL)
			return FALSE;
	}
	
	switch (eOfficeTheme)
	{
	case xtpThemeOffice2000: pComboTheme->SetCurSel(3); break;
	case xtpThemeOfficeXP:   pComboTheme->SetCurSel(2); break;
	case xtpThemeOffice2003: pComboTheme->SetCurSel(1); break;
	case xtpThemeRibbon:     pComboTheme->SetCurSel(0); break;
	}

	return TRUE;
}

void CMainFrame::OnOfficeThemeChanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	
	CXTPControlComboBox* pControl = (CXTPControlComboBox*)tagNMCONTROL->pControl;
	ASSERT(pControl->GetType() == xtpControlComboBox);
	if (pControl->GetType() != xtpControlComboBox)
	{
		ASSERT(FALSE);
		return;
	}

	int nCurSel = pControl->GetCurSel();
	if (nCurSel < 0 || nCurSel >= pControl->GetCount())
	{
		ASSERT(FALSE);
		return;
	}

	SetOfficeTheme(INT2THEME(pControl->GetItemData(nCurSel)));
	
	*pResult = 1;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
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
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::AddAnimation()
{
	int iIndex = m_wndStatusBar.GetPaneCount();

	if (!m_wndAnimCtrl.Create(WS_CHILD|WS_VISIBLE|ACS_CENTER,
		CRect(0,0,0,0), &m_wndStatusBar, 0))
	{
		TRACE0("Failed to create avi control.\n");
		return;
	}

	m_wndAnimCtrl.Open(IDR_HEARTBEAT);

	// add the indicator to the status bar.
	m_wndStatusBar.AddIndicator(ID_INDICATOR_ANIM, iIndex);

	// Initialize the pane info and add the control.
	int nIndex = m_wndStatusBar.CommandToIndex(ID_INDICATOR_ANIM);
	ASSERT (nIndex != -1);

	m_wndStatusBar.SetPaneWidth(nIndex, 14);
	m_wndStatusBar.SetPaneStyle(nIndex, m_wndStatusBar.GetPaneStyle(nIndex) | SBPS_POPOUT);
	m_wndStatusBar.AddControl(&m_wndAnimCtrl, ID_INDICATOR_ANIM, FALSE);
}

void CMainFrame::RemoveAnimation()
{
	m_wndStatusBar.RemoveIndicator(ID_INDICATOR_ANIM);
}

void CMainFrame::AddButton(int nIcon, int nID)
{
	XTPImageManager()->SetIcon(nIcon, nIcon);
	
	int iIndex = m_wndStatusBar.GetPaneCount();
	
	CXTPStatusBarPane* pPane = m_wndStatusBar.AddIndicator(nID, iIndex);
	pPane->SetIconIndex(nIcon);
	pPane->SetText(_T(""));
	pPane->SetButton(TRUE); // push button;
	pPane->SetWidth(16);

	CString strToolTip;
	strToolTip.LoadString(nID);
	pPane->SetTooltip(strToolTip);
}

void CMainFrame::AddButtons()
{
	AddButton(IDI_PRINT,      ID_INDICATOR_PRINT);
	AddButton(IDI_FULLSCREEN, ID_INDICATOR_FULLSCREEN);
	AddButton(IDI_WEB,        ID_INDICATOR_WEB);
	AddButton(IDI_OUTLINE,    ID_INDICATOR_OUTLINE);
	AddButton(IDI_DRAFT,      ID_INDICATOR_DRAFT);
}

void CMainFrame::RemoveButtons()
{
	for (int nID = ID_INDICATOR_PRINT; nID <= ID_INDICATOR_DRAFT; ++nID)
		m_wndStatusBar.RemoveIndicator(nID);

	m_strMessage.Empty();

	CView* pView = GetActiveView();
	if (pView)
	{
		pView->RedrawWindow();
	}
}

void CMainFrame::AddEdit()
{
	int iIndex = m_wndStatusBar.GetPaneCount();

	// Create the edit control and add it to the status bar
	if (!m_wndEditCtrl.CreateEx(WS_EX_STATICEDGE, _T("edit"), _T("Hello World"),
		WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), &m_wndStatusBar, 0))
	{
		TRACE0("Failed to create edit control.\n");
		return;
	}

	m_wndEditCtrl.SetFont(m_wndStatusBar.GetFont());

	// add the indicator to the status bar.
	m_wndStatusBar.AddIndicator(ID_INDICATOR_EDIT, iIndex);

	// Initialize the pane info and add the control.
	int nIndex = m_wndStatusBar.CommandToIndex(ID_INDICATOR_EDIT);
	ASSERT (nIndex != -1);

	m_wndStatusBar.SetPaneWidth(nIndex, 75);
	m_wndStatusBar.SetPaneStyle(nIndex, m_wndStatusBar.GetPaneStyle(nIndex) | SBPS_NOBORDERS);
	m_wndStatusBar.AddControl(&m_wndEditCtrl, ID_INDICATOR_EDIT, FALSE);
}

void CMainFrame::RemoveEdit()
{
	m_wndStatusBar.RemoveIndicator(ID_INDICATOR_EDIT);
}

void CMainFrame::AddLogo()
{
#if 0 // Obsolete 

	if (!m_wndLogoPane.Create(_T("Codejock Software"), &m_wndStatusBar))
	{
		TRACE0("Failed to create logo control.\n");
		return;
	}

	int nWidth = m_wndLogoPane.GetTextSize().cx;

	// add the indicator to the status bar.
	m_wndStatusBar.AddIndicator(ID_INDICATOR_LOGO, 0);

	// Initialize the pane info and add the control.
	int nIndex = m_wndStatusBar.CommandToIndex(ID_INDICATOR_LOGO);
	ASSERT (nIndex != -1);

	m_wndStatusBar.SetPaneWidth(nIndex, nWidth);
	m_wndStatusBar.SetPaneStyle(nIndex, m_wndStatusBar.GetPaneStyle(nIndex) | SBPS_POPOUT);
	m_wndStatusBar.AddControl(&m_wndLogoPane, ID_INDICATOR_LOGO, FALSE);
#else
	CXTPStatusBarPane* pPane = m_wndStatusBar.AddIndicator(ID_INDICATOR_LOGO, 0);
	pPane->SetText(_T("Codejock Software"));
	pPane->SetStyle(pPane->GetStyle() | SBPS_POPOUT);

	CXTPPaintManager::CNonClientMetrics ncm;
	ncm.lfMenuFont.lfWeight = FW_BOLD;
	pPane->SetTextFont(&ncm.lfMenuFont);

	pPane->SetTextColor(GetXtremeColor(COLOR_3DSHADOW));

	pPane->SetWidth(0); // Best Fit
	m_wndStatusBar.SetRibbonDividerIndex(1);
#endif
}

void CMainFrame::RemoveLogo()
{
	m_wndStatusBar.RemoveIndicator(ID_INDICATOR_LOGO);
	m_wndStatusBar.SetRibbonDividerIndex(0);
}

void CMainFrame::AddProgress()
{
	int iIndex = m_wndStatusBar.GetPaneCount();

	// Create the edit control and add it to the status bar
	if (!m_wndProgCtrl.Create(WS_CHILD|WS_VISIBLE|PBS_SMOOTH,
		CRect(0,0,0,0), &m_wndStatusBar, 0))
	{
		TRACE0("Failed to create edit control.\n");
		return;
	}

	// add the indicator to the status bar.
	m_wndStatusBar.AddIndicator(ID_INDICATOR_PROG, iIndex);

	// Initialize the pane info and add the control.
	int nIndex = m_wndStatusBar.CommandToIndex(ID_INDICATOR_PROG);
	ASSERT (nIndex != -1);

	m_wndStatusBar.SetPaneWidth(nIndex, 150);
	m_wndStatusBar.SetPaneStyle(nIndex, m_wndStatusBar.GetPaneStyle(nIndex) | SBPS_NOBORDERS);
	m_wndStatusBar.AddControl(&m_wndProgCtrl, ID_INDICATOR_PROG, FALSE);

	// initialize progress control.
	m_wndProgCtrl.SetRange (0, 5000);
	m_wndProgCtrl.SetPos (0);
	m_wndProgCtrl.SetStep (1);
}

void CMainFrame::RemoveProgress()
{
	m_wndStatusBar.RemoveIndicator(ID_INDICATOR_PROG);
}

void CMainFrame::TestProgress()
{
	m_wndProgCtrl.SetPos (0);

	int i;
	for (i = 0; i <= 5000; i++)
	{
		m_wndProgCtrl.StepIt();
	}
}

void CMainFrame::SetOfficeTheme(XTPPaintTheme eOfficeTheme)
{
	m_eOfficeTheme = eOfficeTheme;

	XTPPaintManager()->SetTheme(eOfficeTheme);

	EnableOffice2007Frame((eOfficeTheme == xtpThemeRibbon)?
		GetCommandBars(): NULL);
	
	XTPColorManager()->SetLunaTheme((eOfficeTheme == xtpThemeOffice2000)?
		xtpSystemThemeUnknown: xtpSystemThemeAuto);
	
	GetCommandBars()->RedrawCommandBars();

	RedrawWindow( NULL, NULL,
		RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN );
}

void CMainFrame::OnViewTheme(UINT nID)
{
	SetOfficeTheme(
		ThemeFromCommand(nID));

	UpdateThemeCombo(
		ThemeFromCommand(nID));
}

void CMainFrame::OnUpdateViewTheme(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_eOfficeTheme == 
		ThemeFromCommand(pCmdUI->m_nID));
}

void CMainFrame::OnIndicatorButton(UINT nID)
{
	m_nPaneID = nID;
	m_strMessage.LoadString(nID);

	CView* pView = GetActiveView();
	if (pView)
	{
		pView->RedrawWindow();
	}
};

void CMainFrame::OnUpdateIndicatorButton(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nPaneID);
};

void CMainFrame::OnClose()
{
	// Save the current state for command bars.
	SaveCommandBars(_T("CommandBars"));
	// TODO: Add your message handler code here and/or call default

	CFrameWnd::OnClose();
}

void CMainFrame::OnCustomize()
{
	// get a pointer to the command bars object.
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if (pCommandBars == NULL)
		return;

	// instantiate the customize dialog
	CXTPCustomizeSheet dlg(pCommandBars);

	// add the options page to the customize dialog.
	CXTPCustomizeOptionsPage pageOptions(&dlg);
	dlg.AddPage(&pageOptions);

	// add the commands page to the customize dialog.
	CXTPCustomizeCommandsPage* pPageCommands = dlg.GetCommandsPage();
	pPageCommands->AddCategories(IDR_STATUSTYPE);

	// initialize the commands page page.
	pPageCommands->InsertAllCommandsCategory();
	pPageCommands->InsertBuiltInMenus(IDR_STATUSTYPE);
	pPageCommands->InsertNewMenuCategory();

	// display the customize dialog.
	dlg.DoModal();
}

void CMainFrame::OnStatusBarShowButtons() 
{
	m_bButtons = !m_bButtons;
	
	if (m_bButtons)
	{
		AddButtons();
	}
	else
	{
		RemoveButtons();
	}
}

void CMainFrame::OnUpdateStatusBarShowButtons(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bButtons);
}

void CMainFrame::OnStatusBarShowAviAnimation() 
{
	m_bAnimation = !m_bAnimation;

	if (m_bAnimation)
	{
		AddAnimation();
		OnStatusBarPlayAnimation();
	}
	else
	{
		RemoveAnimation();
	}
}

void CMainFrame::OnUpdateStatusBarShowAviAnimation(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bAnimation);
}

void CMainFrame::OnStatusBarShowProgressBar() 
{
	m_bProgress = !m_bProgress;

	if (m_bProgress)
	{
		AddProgress();
	}
	else
	{
		RemoveProgress();
	}
}

void CMainFrame::OnUpdateStatusBarShowProgressBar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bProgress);
}

void CMainFrame::OnStatusBarShowEditControl() 
{
	m_bEdit = !m_bEdit;

	if (m_bEdit)
	{
		AddEdit();
	}
	else
	{
		RemoveEdit();
	}
}

void CMainFrame::OnUpdateStatusBarShowEditControl(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bEdit);
}

void CMainFrame::OnStatusBarShowCompanyLogo() 
{
	m_bLogo = !m_bLogo;

	if (m_bLogo)
	{
		AddLogo();
	}
	else
	{
		RemoveLogo();
	}
}

void CMainFrame::OnUpdateStatusBarShowCompanyLogo(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bLogo);
}

void CMainFrame::OnStatusBarPlayAnimation() 
{
	m_bPlayAnimation = !m_bPlayAnimation;

	if (m_bPlayAnimation)
	{
		m_wndAnimCtrl.Play(0, (UINT)-1, (UINT)-1);
	}
	else
	{
		m_wndAnimCtrl.Stop();
	}
}

void CMainFrame::OnUpdateStatusBarPlayAnimation(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bAnimation);
	pCmdUI->SetText(m_bPlayAnimation? _T("S&top Animation"): _T("P&lay Animation"));
}

void CMainFrame::OnStatusBarTestProgress() 
{
	TestProgress();
}

void CMainFrame::OnUpdateStatusBarTestProgress(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bProgress);
}
