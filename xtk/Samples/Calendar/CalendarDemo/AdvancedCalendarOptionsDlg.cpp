// AdvancedCalendarOptionsDlg.cpp : implementation file
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
#include "calendardemo.h"
#include "AdvancedCalendarOptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdvancedCalendarOptionsDlg dialog


CAdvancedCalendarOptionsDlg::CAdvancedCalendarOptionsDlg(CXTPCalendarControl* pCalendar, CWnd* pParent /*=NULL*/)
	: CDialog(CAdvancedCalendarOptionsDlg::IDD, pParent)
{
	ASSERT(pCalendar);
	m_pCalendar = pCalendar;

	//{{AFX_DATA_INIT(CAdvancedCalendarOptionsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAdvancedCalendarOptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdvancedCalendarOptionsDlg)
	DDX_Control(pDX, IDC_RADIO_THEME_OFFICE_2007, m_ctrlThemeOffice2007);
	DDX_Control(pDX, IDC_RADIO_THEME_OFFICE_2003, m_ctrlThemeOffice2003);
	DDX_Control(pDX, IDC_COMBO_THEME_DEFAULT_COLOR, m_ctrlThemeColor);
	DDX_Control(pDX, IDC_STATIC_THEME_DEFAULT_COLOR, m_ctrlThemeColorLable);
	DDX_Control(pDX, IDC_CHECK_ENABLE_THEMES, m_ctrlEnableThemes);
	DDX_Control(pDX, IDC_CHECK_EDIT_SUBJECT_BY_TAB, m_ctrlEditSubject_ByTAB);
	DDX_Control(pDX, IDC_CHECK_EDIT_SUBJECT_BY_MOUSE_CLICK, m_ctrlEditSubject_ByMouseClick);
	DDX_Control(pDX, IDC_CHECK_EDIT_SUBJECT_BY_F2, m_ctrlEditSubject_ByF2);
	DDX_Control(pDX, IDC_CHECK_EDIT_SUBJECT_AFTER_RESIZE, m_ctrlEditSubject_AfterResize);
	DDX_Control(pDX, IDC_CHECK_CREATE_EVENT, m_ctrlInPlaceCreateEvent);
	DDX_Control(pDX, IDC_CHECK_OUTLOOKFONTGLYPHS, m_ctrlUseOutlookFontGlyphs);
	DDX_Control(pDX, IDC_CHECK_SHOW_TSMINUTES, m_ctrlShowTSMinutes);
	DDX_Control(pDX, IDC_CHECK_REMINDERS, m_ctrlReminders);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdvancedCalendarOptionsDlg, CDialog)
	//{{AFX_MSG_MAP(CAdvancedCalendarOptionsDlg)
	ON_BN_CLICKED(IDC_CHECK_ENABLE_THEMES, OnCheckEnableThemes)
	ON_BN_CLICKED(IDC_RADIO_THEME_OFFICE_2007, OnRadioThemeOffice2007)
	ON_BN_CLICKED(IDC_RADIO_THEME_OFFICE_2003, OnRadioThemeOffice2003)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvancedCalendarOptionsDlg message handlers

void CAdvancedCalendarOptionsDlg::OnOK() 
{
	CXTPCalendarOptions* pOptions = m_pCalendar ? m_pCalendar->GetCalendarOptions() : NULL;
	if (!m_pCalendar || !pOptions) {
		ASSERT(FALSE);
		return;
	}

	pOptions->bUseOutlookFontGlyphs = m_ctrlUseOutlookFontGlyphs.GetCheck() ? TRUE : FALSE;
	pOptions->bDayView_TimeScaleShowMinutes = m_ctrlShowTSMinutes.GetCheck() ? TRUE : FALSE;

	pOptions->bEnableInPlaceCreateEvent = m_ctrlInPlaceCreateEvent.GetCheck() ? TRUE : FALSE;

	pOptions->bEnableInPlaceEditEventSubject_ByF2 = m_ctrlEditSubject_ByF2.GetCheck() ? TRUE : FALSE;
	pOptions->bEnableInPlaceEditEventSubject_ByMouseClick = m_ctrlEditSubject_ByMouseClick.GetCheck() ? TRUE : FALSE;
	pOptions->bEnableInPlaceEditEventSubject_ByTab = m_ctrlEditSubject_ByTAB.GetCheck() ? TRUE : FALSE;
	pOptions->bEnableInPlaceEditEventSubject_AfterEventResize = m_ctrlEditSubject_AfterResize.GetCheck() ? TRUE : FALSE;

	pOptions->OnOptionsChanged();

	m_pCalendar->EnableReminders(m_ctrlReminders.GetCheck() ? TRUE : FALSE);

	//===========================
	int nEnableThemes = m_ctrlEnableThemes.GetCheck();

	if (nEnableThemes)
	{
		if (m_ctrlThemeOffice2007.GetCheck())
		{
			CXTPCalendarThemeOffice2007* pTheme2007 = new CXTPCalendarThemeOffice2007();
			if (pTheme2007) {
				pTheme2007->m_clrBaseColor = m_ctrlThemeColor.GetSelectedColor();
			}
			m_pCalendar->SetTheme(pTheme2007);

			UINT arIDs[5];
			arIDs[0] = (UINT)xtpCalendarEventIconIDReminder;
			arIDs[1] = (UINT)xtpCalendarEventIconIDOccurrence;
			arIDs[2] = (UINT)xtpCalendarEventIconIDException;
			arIDs[3] = (UINT)xtpCalendarEventIconIDMeeting;
			arIDs[4] = (UINT)xtpCalendarEventIconIDPrivate;			

			pTheme2007->GetCustomIconsList()->SetIcons(XTP_IDB_CALENDAR_EVENT_GLYPHS, 
							arIDs, 5, CSize(16, 11), xtpImageNormal);
		}
		//else if (m_ctrlThemeOffice2003.GetCheck())
		//{
		//	CXTPCalendarThemeOffice2003* pTheme2003 = new CXTPCalendarThemeOffice2003();
		//	if (pTheme2003) {
		//		pTheme2003->m_clrBaseColor = m_ctrlThemeColor.GetSelectedColor();
		//	}
		//	m_pCalendar->SetTheme(pTheme2003);
		//}
		else {
			ASSERT(FALSE);
		}
	}
	else {
		m_pCalendar->SetTheme(NULL);
	}
			
	//---------------------------
	m_pCalendar->Populate();
	
	CDialog::OnOK();
}

BOOL CAdvancedCalendarOptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CXTPCalendarOptions* pOptions = m_pCalendar ? m_pCalendar->GetCalendarOptions() : NULL;
	if (!m_pCalendar || !pOptions) {
		ASSERT(FALSE);
		return FALSE;
	}

	m_ctrlReminders					.SetCheck(m_pCalendar->IsRemindersEnabled() ? 1:0);
	m_ctrlUseOutlookFontGlyphs		.SetCheck(pOptions->bUseOutlookFontGlyphs ? 1:0);
	m_ctrlShowTSMinutes				.SetCheck(pOptions->bDayView_TimeScaleShowMinutes ? 1:0);

	m_ctrlInPlaceCreateEvent		.SetCheck(pOptions->bEnableInPlaceCreateEvent?1:0);

	m_ctrlEditSubject_ByF2			.SetCheck(pOptions->bEnableInPlaceEditEventSubject_ByF2?1:0);
	m_ctrlEditSubject_ByMouseClick	.SetCheck(pOptions->bEnableInPlaceEditEventSubject_ByMouseClick?1:0);
	m_ctrlEditSubject_ByTAB			.SetCheck(pOptions->bEnableInPlaceEditEventSubject_ByTab?1:0);
	m_ctrlEditSubject_AfterResize	.SetCheck(pOptions->bEnableInPlaceEditEventSubject_AfterEventResize?1:0);

	// Themes 
	CXTPCalendarTheme* pTheme = m_pCalendar->GetTheme();
	//CXTPCalendarThemeOffice2007* pTheme2007 = DYNAMIC_DOWNCAST(CXTPCalendarThemeOffice2007, pTheme);

	m_ctrlEnableThemes.SetCheck(pTheme != NULL);
	
	InitThemeColors();
	
	OnCheckEnableThemes();
	
	if (pTheme)
	{
		m_ctrlThemeColor.SelectColor(pTheme->m_clrBaseColor);
	}
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdvancedCalendarOptionsDlg::OnCheckEnableThemes() 
{
	CXTPCalendarTheme* pTheme = m_pCalendar->GetTheme();
	//CXTPCalendarThemeOffice2003* pTheme2003 = DYNAMIC_DOWNCAST(CXTPCalendarThemeOffice2003, pTheme);
	CXTPCalendarTheme* pTheme2003 = NULL;
	CXTPCalendarThemeOffice2007* pTheme2007 = DYNAMIC_DOWNCAST(CXTPCalendarThemeOffice2007, pTheme);	

	int nEnable = m_ctrlEnableThemes.GetCheck();

	m_ctrlThemeOffice2003.EnableWindow(FALSE); //nEnable != 0);
	m_ctrlThemeOffice2007.EnableWindow(nEnable != 0);
	m_ctrlThemeColor	 .EnableWindow(nEnable != 0);
	m_ctrlThemeColorLable.EnableWindow(nEnable != 0);
	
	m_ctrlThemeOffice2003.SetCheck(pTheme2003 != NULL);
	m_ctrlThemeOffice2007.SetCheck(pTheme2007 != NULL || !pTheme2003 && !pTheme2007);
}

void CAdvancedCalendarOptionsDlg::OnRadioThemeOffice2007() 
{
	// TODO: Add your control notification handler code here
	
}

void CAdvancedCalendarOptionsDlg::OnRadioThemeOffice2003() 
{
	// TODO: Add your control notification handler code here
	
}

void CAdvancedCalendarOptionsDlg::InitThemeColors() 
{
	for (int i = 0; i < 15; i++) 
	{
		m_ctrlThemeColor.AddString(_T(""));
	}
	
	m_ctrlThemeColor.SetItemData(0, RGB(93, 140, 201));
	m_ctrlThemeColor.SetItemData(1, RGB(114, 164, 90));
	m_ctrlThemeColor.SetItemData(2, RGB(190, 104, 134));
	m_ctrlThemeColor.SetItemData(3, RGB(90, 164, 164));
	m_ctrlThemeColor.SetItemData(4, RGB(113, 113, 205));
	m_ctrlThemeColor.SetItemData(5, RGB(92, 166, 116));
	m_ctrlThemeColor.SetItemData(6, RGB(93, 105, 105));
	m_ctrlThemeColor.SetItemData(7, RGB(157, 157, 87));
	m_ctrlThemeColor.SetItemData(8, RGB(140, 110, 200));
	m_ctrlThemeColor.SetItemData(9, RGB(169, 143, 93));
	m_ctrlThemeColor.SetItemData(10, RGB(90, 164, 140));
	m_ctrlThemeColor.SetItemData(11, RGB(97, 151, 177));
	m_ctrlThemeColor.SetItemData(12, RGB(139, 139, 139));
	m_ctrlThemeColor.SetItemData(13, RGB(255, 209, 81));
	m_ctrlThemeColor.SetItemData(14, RGB(105, 133, 189));	

	m_ctrlThemeColor.SetCurSel(0);
}

void CComboBoxColors::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	ASSERT(lpDrawItemStruct->CtlType == ODT_COMBOBOX);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	COLORREF clrBk = (COLORREF)lpDrawItemStruct->itemData;
	dc.FillSolidRect(&lpDrawItemStruct->rcItem, clrBk);

	if ((lpDrawItemStruct->itemAction | ODA_SELECT) &&
	  (lpDrawItemStruct->itemState  & ODS_SELECTED))
	{
		CBrush brFrame(RGB(0,0,0));
		dc.FrameRect(&lpDrawItemStruct->rcItem, &brFrame);
	}

	dc.Detach();
}

void CComboBoxColors::SelectColor(COLORREF clrColor)
{
	for (int i = 0; i < GetCount(); i++)
	{
		if (clrColor == (COLORREF)GetItemData(i)) {
			SetCurSel(i);
			return;
		}
	}
}

COLORREF CComboBoxColors::GetSelectedColor(int nDefaultColorIndex)
{
	COLORREF clrColor = (COLORREF)-1;

	int nSel = GetCurSel();
	if (nSel == CB_ERR) {
		nSel = nDefaultColorIndex;		
	}
	if (nSel >= 0 && nSel < GetCount()) {
		clrColor = (COLORREF)GetItemData(nSel);
	}

	return clrColor;
}
