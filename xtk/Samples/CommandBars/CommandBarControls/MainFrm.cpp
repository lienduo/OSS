// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "CommandBarControls.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CXTPMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_VIEW_THEME_OFFICE2000, ID_VIEW_THEME_RIBBON, OnViewTheme)
	ON_COMMAND(XTP_ID_CUSTOMIZE, OnCustomize)
	ON_XTP_CREATECONTROL()

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

	// Initialize the command bars
	if (!InitCommandBars())
		return -1;

	// Get a pointer to the command bars object.
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if(pCommandBars == NULL)
	{
		TRACE0("Failed to create command bars object.\n");
		return -1;      // fail to create
	}

	pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME);
	pCommandBars->GetImageManager()->SetIcons(IDR_TOOLBAR_COLOR);

	// Set Office 2003 Theme
	CXTPPaintManager::SetTheme(xtpThemeOffice2003);

	// Add the menu bar
	CXTPMenuBar* pMenuBar = pCommandBars->SetMenu(
		_T("Menu Bar"), IDR_MAINFRAME);
	if(pMenuBar == NULL)
	{
		TRACE0("Failed to create menu bar.\n");
		return -1;      // fail to create
	}

	CXTPToolBar* pToolBarButtons = (CXTPToolBar*) pCommandBars->Add(_T("Buttons"), xtpBarTop);
	pToolBarButtons->SetBarID(IDR_MAINFRAME);

	pToolBarButtons->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlButton:"));
	pToolBarButtons->GetControls()->Add(xtpControlButton, ID_FILE_OPEN);
	pToolBarButtons->GetControls()->Add(xtpControlButton, ID_FILE_SAVE)->SetStyle(xtpButtonCaption);
	pToolBarButtons->GetControls()->Add(xtpControlButton, ID_FILE_PRINT)->SetStyle(xtpButtonIconAndCaption);


	CXTPToolBar* pToolBarPopups = pCommandBars->Add(_T("Popups"), xtpBarTop);
	pToolBarPopups->SetBarID(IDR_MAINFRAME + 2);

	pToolBarPopups->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlPopup:"));
	pToolBarPopups->GetControls()->Add(xtpControlPopup, ID_EDIT_PASTE);
	pToolBarPopups->GetControls()->Add(xtpControlPopup, ID_EDIT_COPY)->SetStyle(xtpButtonIcon);
	pToolBarPopups->GetControls()->Add(xtpControlButtonPopup, ID_EDIT_CUT)->SetStyle(xtpButtonIconAndCaption);
	pToolBarPopups->GetControls()->Add(xtpControlSplitButtonPopup, ID_EDIT_SELECT_ALL)->SetStyle(xtpButtonIconAndCaption);

	DockRightOf(pToolBarPopups, pToolBarButtons);

	CXTPToolBar* pToolBarCombo = pCommandBars->Add(_T("Combo"), xtpBarTop);
	pToolBarCombo->SetBarID(IDR_MAINFRAME + 3);
	pToolBarCombo->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlComboBox:"));
	pToolBarCombo->GetControls()->Add(xtpControlComboBox, ID_FILE_NEW);
	CXTPControlComboBox* pControlCombo = (CXTPControlComboBox*)pToolBarCombo->GetControls()->Add(xtpControlComboBox, ID_FILE_NEW);
	pControlCombo->SetDropDownListStyle();
	DockRightOf(pToolBarCombo, pToolBarPopups);


	CXTPToolBar* pToolBarEdit = pCommandBars->Add(_T("Edit"), xtpBarTop);
	pToolBarEdit->SetBarID(IDR_MAINFRAME + 4);
	pToolBarEdit->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlEdit:"));
	CXTPControlEdit* pControlEdit = (CXTPControlEdit*)pToolBarEdit->GetControls()->Add(xtpControlEdit, ID_FILE_NEW);
	pControlEdit->ShowSpinButtons(TRUE);

	CXTPToolBar* pToolBarRadio = pCommandBars->Add(_T("Radio"), xtpBarTop);
	pToolBarRadio->SetBarID(IDR_MAINFRAME + 5);
	pToolBarRadio->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlRadioButton:"));
	pToolBarRadio->GetControls()->Add(xtpControlRadioButton, 0);
	DockRightOf(pToolBarRadio, pToolBarEdit);

	CXTPToolBar* pToolBarCheckBox = pCommandBars->Add(_T("CheckBox"), xtpBarTop);
	pToolBarCheckBox->SetBarID(IDR_MAINFRAME + 7);
	pToolBarCheckBox->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlCheckBox:"));
	pToolBarCheckBox->GetControls()->Add(xtpControlCheckBox, 0);
	DockRightOf(pToolBarCheckBox, pToolBarRadio);


	CXTPToolBar* pToolBarListBox = pCommandBars->Add(_T("ListBox"), xtpBarTop);
	pToolBarListBox->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlListBox:"));
	CXTPControlPopup* pPopup = (CXTPControlPopup*)pToolBarListBox->GetControls()->Add(xtpControlPopup, 0);
	pPopup->SetCaption(_T("ListBox"));
	CXTPControlListBox* pListBox = (CXTPControlListBox*)pPopup->GetCommandBar()->GetControls()->Add(new CXTPControlListBox, 0);
	pListBox->GetListCtrl()->AddString(_T("Item 1"));
	pListBox->GetListCtrl()->AddString(_T("Item 2"));

	CXTPToolBar* pToolBarGallery = pCommandBars->Add(_T("Gallery"), xtpBarTop);
	pToolBarGallery->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlGallery:"));

	CXTPControlGalleryItems* pGalleryItems = CXTPControlGalleryItems::CreateItems(GetCommandBars(), ID_CONTROL_GALLERY);

	CXTPControlGallery* pControlGallery = (CXTPControlGallery*)pToolBarGallery->GetControls()->Add(new CXTPControlGallery(), ID_CONTROL_GALLERY);
	pGalleryItems->AddItem(_T("Item 1"));
	pGalleryItems->AddItem(_T("Item 2"));
	pGalleryItems->AddItem(_T("Item 3"));
	pGalleryItems->AddItem(_T("Item 4"));
	pGalleryItems->AddItem(_T("Item 5"));
	pGalleryItems->SetItemSize(CSize(40, 22));

	pControlGallery->SetHeight(22);
	pControlGallery->SetWidth(140);
	pControlGallery->SetItems(pGalleryItems);
	pControlGallery->SetFlags(xtpFlagManualUpdate);
	
	DockRightOf(pToolBarGallery, pToolBarListBox);


	CXTPToolBar* pToolBarColor = pCommandBars->Add(_T("ColorButton"), xtpBarTop);
	pToolBarColor->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlColorSelector:"));

	CXTPControlPopupColor* pControlButtonColor = (CXTPControlPopupColor*)
		pToolBarColor->GetControls()->Add(new CXTPControlPopupColor(), ID_COLOR_FORE);
	pControlButtonColor->SetColor(0xFF);
	CXTPPopupToolBar* pPopupToolBar = CXTPPopupToolBar::CreatePopupToolBar(pCommandBars);
	pControlButtonColor->SetCommandBar(pPopupToolBar);
	pPopupToolBar->GetControls()->Add(new CXTPControlColorSelector());
	pPopupToolBar->InternalRelease();
	pControlButtonColor->SetFlags(xtpFlagManualUpdate);

	DockRightOf(pToolBarColor, pToolBarGallery);

	CXTPToolBar* pToolBarSlider = pCommandBars->Add(_T("Slider"), xtpBarTop);
	pToolBarSlider->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlSlider:"));
	pToolBarSlider->GetControls()->Add(new CXTPControlSlider());

	CXTPToolBar* pToolBarScrollBar = pCommandBars->Add(_T("ScrollBar"), xtpBarTop);
	pToolBarScrollBar->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlScrollBar:"));
	pToolBarScrollBar->GetControls()->Add(new CXTPControlScrollBar());
	DockRightOf(pToolBarScrollBar, pToolBarSlider);
	
	CXTPToolBar* pWorkspaceBar = (CXTPToolBar*)
		pCommandBars->Add(_T("WorkspaceBar"), xtpBarTop);
	if (!pWorkspaceBar)
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	pWorkspaceBar->EnableCustomization(FALSE);

	pCommandBars->GetShortcutManager()->SetAccelerators(IDR_MAINFRAME);

	pWorkspaceBar->GetControls()->Add(xtpControlLabel, 0)->SetCaption(_T("CXTPControlTabWorkspace:"));
	CXTPControlTabWorkspace* pControl = (CXTPControlTabWorkspace*)pWorkspaceBar->GetControls()->Add(new CXTPControlTabWorkspace());
	
	m_wndClient.Attach(this);

	m_wndClient.SetTabWorkspace(pControl);

	pControl->GetPaintManager()->m_bFillBackground = FALSE;
	//pControl->GetPaintManager()->GetAppearanceSet()->m_rcHeaderMargin.top = 1;
	pControl->GetPaintManager()->SetLayout(xtpTabLayoutSizeToFit);
	pControl->SetWidth(400);

	pControl->SetFlags(pControl->GetFlags() | xtpFlagControlStretched);
	pWorkspaceBar->EnableDocking(xtpFlagAlignAny | xtpFlagFloating | xtpFlagStretched);

	m_wndClient.SetFlags(xtpWorkspaceHideAll);

	pWorkspaceBar->SetBarID(IDR_MAINFRAME + 1);
	pWorkspaceBar->GetControls()->CreateOriginalControls();

	return 0;
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

	
void CMainFrame::OnCustomize()
{
	CXTPCustomizeSheet cs(GetCommandBars());

	CXTPCustomizeKeyboardPage pageKeyboard(&cs);
	cs.AddPage(&pageKeyboard);
	pageKeyboard.AddCategories(IDR_COMMANTYPE);

	CXTPCustomizeMenusPage pageMenus(&cs);
	cs.AddPage(&pageMenus);

	CXTPCustomizeOptionsPage pageOptions(&cs);
	cs.AddPage(&pageOptions);



	CXTPCustomizeCommandsPage* pCommands = cs.GetCommandsPage();
	pCommands->AddCategories(IDR_COMMANTYPE);

	pCommands->InsertAllCommandsCategory();
	pCommands->InsertBuiltInMenus(IDR_COMMANTYPE);
	pCommands->InsertNewMenuCategory();


	cs.DoModal();
}

int CMainFrame::OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl)
{
	UNREFERENCED_PARAMETER(lpCreateControl);
	return FALSE;
}

void CMainFrame::OnViewTheme(UINT nID) 
{
	XTPPaintManager()->SetTheme(XTPPaintTheme(nID - ID_VIEW_THEME_OFFICE2000));

	GetCommandBars()->RedrawCommandBars();
	
}
