// AdvancedCalendarOptionsDlg.h : header file
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

#if !defined(AFX_ADVANCEDCALENDAROPTIONS_H__4BE24FF6_4722_464D_8A62_913CA3CDA7B2__INCLUDED_)
#define AFX_ADVANCEDCALENDAROPTIONS_H__4BE24FF6_4722_464D_8A62_913CA3CDA7B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXTPCalendarControl;
/////////////////////////////////////////////////////////////////////////////
// CAdvancedCalendarOptionsDlg dialog
//
// This dialog allows you to modify some advanced Calendar options like the
// following: allow/disallow in-place event subject editing with Mouse click, 
// by F2 button, by TAB button, automatically after resizing.
//
// Also: enable/disable drawing of some icons like a key, a head, etc as 
// a regular bitmap or as an Outlook font glyph (note that "Outlook font" 
// drawing could be useful in order to "smooth" font edges, especially when 
// ClearType option is enabled).
//
// Also it allows to enable/disable Reminders Manager window.
//
class CComboBoxColors : public CComboBox
{
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	
	void SelectColor(COLORREF clrColor);
	COLORREF GetSelectedColor(int nDefaultColorIndex = 0);

	virtual int CompareItem(LPCOMPAREITEMSTRUCT) { return 0; }

};
class CAdvancedCalendarOptionsDlg : public CDialog
{
// Construction
public:
	CAdvancedCalendarOptionsDlg(CXTPCalendarControl* pCalendar, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdvancedCalendarOptionsDlg)
	enum { IDD = IDD_ADVANCED_OPTIONS };
	CButton	m_ctrlThemeOffice2007;
	CButton	m_ctrlThemeOffice2003;
	CComboBoxColors	m_ctrlThemeColor;
	CStatic	m_ctrlThemeColorLable;
	CButton	m_ctrlEnableThemes;
	CButton	m_ctrlEditSubject_ByTAB;
	CButton	m_ctrlEditSubject_ByMouseClick;
	CButton	m_ctrlEditSubject_ByF2;
	CButton	m_ctrlEditSubject_AfterResize;
	CButton	m_ctrlInPlaceCreateEvent;
	CButton	m_ctrlUseOutlookFontGlyphs;
	CButton	m_ctrlShowTSMinutes;
	CButton	m_ctrlReminders;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedCalendarOptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdvancedCalendarOptionsDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckEnableThemes();
	afx_msg void OnRadioThemeOffice2007();
	afx_msg void OnRadioThemeOffice2003();
	//}}AFX_MSG
	void InitThemeColors() ;

	DECLARE_MESSAGE_MAP()

	CXTPCalendarControl* m_pCalendar;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDCALENDAROPTIONS_H__4BE24FF6_4722_464D_8A62_913CA3CDA7B2__INCLUDED_)
