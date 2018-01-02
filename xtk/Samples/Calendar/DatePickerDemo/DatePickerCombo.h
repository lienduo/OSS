// DatePickerCombo.h : header file
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

#if !defined(AFX_DATEPICKERCOMBO_H__E9EBF9BB_09DB_480A_8161_718BB52156E9__INCLUDED_)
#define AFX_DATEPICKERCOMBO_H__E9EBF9BB_09DB_480A_8161_718BB52156E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDatePickerCombo window

//////////////////////////////////////////////////////////////////////////
//
// This combobox class overrides standard DropDown functionality, allowing
// to pickup a specific date or a range of dates with CXTPDatePickerControl
//
class CDatePickerCombo : public CComboBox
{
// Construction
public:
	CDatePickerCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatePickerCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDatePickerCombo();

	LRESULT OnCtlColorListBox(WPARAM wParam, LPARAM lParam) ;

	// Generated message map functions
protected:
	//{{AFX_MSG(CDatePickerCombo)
	afx_msg void OnDropDown();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATEPICKERCOMBO_H__E9EBF9BB_09DB_480A_8161_718BB52156E9__INCLUDED_)
