// PropertiesDialog.h : header file
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

#if !defined(AFX_PROPERTIESDIALOG_H__8F513D92_0E1D_4D1C_BCD5_25243217C07C__INCLUDED_)
#define AFX_PROPERTIESDIALOG_H__8F513D92_0E1D_4D1C_BCD5_25243217C07C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDialog dialog

class CPropertiesDialog : public CDialog
{
// Construction
public:
	CPropertiesDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPropertiesDialog)
	enum { IDD = IDD_DIALOG_PROPERTIES };
	BOOL	m_bPopupBarTips;
	BOOL	m_bShowDescription;
	int     m_nToolTipStyle;
	BOOL	m_bToolBarScreenTips;
	BOOL	m_bToolBarAccelTips;
	BOOL	m_bShowIcons;
	BOOL	m_bShowShadow;
	BOOL	m_bShowOfficeBorder;
	//}}AFX_DATA

	CXTPToolTipContext m_moduleContext;

	void UpdateCommandBarToolTips();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertiesDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertiesDialog)
	afx_msg void OnCheckPopupBarTips();
	afx_msg void OnCheckShowDescription();
	afx_msg void OnRadioTooltipStyle();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckShowTips();
	afx_msg void OnCheckShowshortcuts();
	afx_msg void OnCheckShowIcons();
	afx_msg void OnCheckShowShadow();
	afx_msg void OnCheckShowOfficeBorder();
	//}}AFX_MSG
	void ToggleStyle(DWORD dwStyle);
	void UpdateControls();
	CXTPToolTipContext* GetToolTipContext();

	afx_msg BOOL OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIESDIALOG_H__8F513D92_0E1D_4D1C_BCD5_25243217C07C__INCLUDED_)
