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
#include "CalendarDemo.h"

#include "MainFrm.h"
#include "CalendarDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_COMMAND_EX(ID_VIEW_DATEPICKER, OnBarCheck)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DATEPICKER, OnUpdateControlBarMenu)

	ON_COMMAND_EX(ID_VIEW_PROPERTIES, OnBarCheck)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PROPERTIES, OnUpdateControlBarMenu)

	ON_XTP_CREATECONTROL()
	ON_XTP_EXECUTE(ID_VIEW_OFFICE_THEME, OnOfficeThemeChanged)

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
	m_nOfficeTheme = -1;
	
}

CMainFrame::~CMainFrame()
{
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

	CXTPPaintManager::SetTheme(xtpThemeOffice2003);

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

	EnableDocking(CBRS_ALIGN_ANY);
		
	SetOfficeTheme(xtpThemeRibbon);
	

	// Initialize dialog bar
	if (!m_dlgDatePicker.Create(this, IDD_DATEPICKER,
		CBRS_LEFT|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_HIDE_INPLACE, ID_VIEW_DATEPICKER))
		return -1;		// fail to create

	// Initialize dialog bar
	if (!m_dlgOptions.Create(this, IDD_CALENDAR_DEMO_VIEW,
		CBRS_ALIGN_TOP|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_HIDE_INPLACE, ID_VIEW_PROPERTIES))
		return -1;		// fail to create

	//m_dlgOptions.EnableDocking(CBRS_ALIGN_ANY);
	m_dlgOptions.EnableDocking(0);
	m_dlgOptions.SetWindowText(_T("Options"));
	
	ShowControlBar(&m_dlgOptions, FALSE, FALSE);
	
	FloatControlBar(&m_dlgOptions, CPoint(100, 200));

	// docking for DatePicker
	m_dlgDatePicker.EnableDocking(CBRS_ALIGN_LEFT);
	m_dlgDatePicker.SetWindowText(_T("Date Picker"));
	
	ShowControlBar(&m_dlgDatePicker, TRUE, FALSE);
	//FloatControlBar(&m_dlgDatePicker, CPoint(100, GetSystemMetrics(SM_CYSCREEN) / 3));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.lpszClass = _T("XTPMainFrame");
	CXTPDrawHelpers::RegisterWndClass(AfxGetInstanceHandle(), cs.lpszClass, 
		CS_DBLCLKS, AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE|WS_EX_STATICEDGE;

	return TRUE;
}

int CMainFrame::OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl)
{
	if (lpCreateControl->nID == ID_VIEW_OFFICE_THEME)
	{
		CXTPControlComboBox* pComboTheme = (CXTPControlComboBox*)CXTPControlComboBox::CreateObject();

		pComboTheme->SetCaption(_T("Theme:"));
		pComboTheme->AssignDocTemplate(IDR_MAINFRAME);

		pComboTheme->SetStyle(xtpComboLabel);
		
		pComboTheme->SetWidth(200);
		//pComboTheme->SetDropDownWidth(pComboTheme->GetWidth());
		pComboTheme->SetFlags(xtpFlagManualUpdate);

		int nIndex = pComboTheme->AddString(_T("Office 2000"));
		pComboTheme->SetItemData(nIndex, xtpThemeOffice2000);
		
		CString strTheme = _T("Office 2003");
		if (!XTPColorManager()->IsLunaColorsDisabled())
			strTheme += _T(" (WinXP)");
		nIndex = pComboTheme->AddString(strTheme);
		pComboTheme->SetItemData(nIndex, xtpThemeOffice2003);
				
		nIndex = pComboTheme->AddString(_T("Office 2007"));
		pComboTheme->SetItemData(nIndex, xtpThemeRibbon);
			
		lpCreateControl->pControl = pComboTheme;

		pComboTheme->SetCurSel(nIndex);

		return TRUE;
	}

	return FALSE;
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
	int nTheme = (int)pControl->GetItemData(nCurSel);

	SetOfficeTheme(nTheme);

	*pResult = 1;
}


void CMainFrame::SetOfficeTheme(int nTheme)
{	


#ifdef _XTP_INCLUDE_RIBBON
	CXTPPaintManager::SetTheme((XTPPaintTheme)nTheme);

	if (nTheme == xtpThemeRibbon)
		EnableOffice2007Frame(GetCommandBars());
	else
		EnableOffice2007Frame(0);
#else
	CXTPPaintManager::SetTheme((XTPPaintTheme)min(nTheme, xtpThemeOffice2003));
#endif	// _XTP_INCLUDE_RIBBON
	
	XTPColorManager()->SetLunaTheme((nTheme == xtpThemeOffice2000) ? xtpSystemThemeUnknown : xtpSystemThemeAuto);
	
	RecalcLayout(FALSE);
	GetCommandBars()->RedrawCommandBars();
	RedrawWindow();	

	m_nOfficeTheme = nTheme;
	CCalendarDemoView *pView = DYNAMIC_DOWNCAST(CCalendarDemoView, GetActiveView());
	if (pView)
		pView->OnOfficeThemeChanged(nTheme);
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
CDatePickerDialogBar::CDatePickerDialogBar()
{
}
BEGIN_MESSAGE_MAP(CDatePickerDialogBar, CDialogBar)
	ON_WM_SIZE()
	ON_MESSAGE_VOID(WM_INITDIALOG, OnInitDialog)
END_MESSAGE_MAP()

void CDatePickerDialogBar::OnInitDialog() 
{
	Default();

	VERIFY(m_wndDatePicker.SubclassDlgItem(IDC_DATEPICKER, this));
	
	m_wndDatePicker.SetBorderStyle(xtpDatePickerBorderStatic);
	m_wndDatePicker.SetShowWeekNumbers(TRUE);
}

void CDatePickerDialogBar::OnSize(UINT nType, int cx, int cy)
{
	CDialogBar::OnSize(nType, cx, cy);

	if (!m_wndDatePicker.m_hWnd)
		return;
		
	CXTPClientRect rcClient(this);
	CXTPWindowRect rcDatePicker(&m_wndDatePicker);
	ScreenToClient(&rcDatePicker);
	rcDatePicker.top = rcClient.top;
	rcDatePicker.bottom = rcClient.bottom;
	
	m_wndDatePicker.MoveWindow(&rcDatePicker);
}
