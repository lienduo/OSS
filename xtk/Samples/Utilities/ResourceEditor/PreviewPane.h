// PreviewPane.h : header file
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

#if !defined(AFX_PREVIEWPANE_H__5537005A_AF75_417D_8C61_F0A52B6439AA__INCLUDED_)
#define AFX_PREVIEWPANE_H__5537005A_AF75_417D_8C61_F0A52B6439AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPreviewPane window

class CPreviewPane : public CWnd
{
public:
	class CMenuBar : public CXTPMenuBar
	{
	public:
		CMenuBar()
		{
			m_bIgnoreUpdateHandler = TRUE;
		}
	};

// Construction
public:
	CPreviewPane();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreviewPane)
	//}}AFX_VIRTUAL

	void ShowDialog(LPCDLGTEMPLATE pTemplate);
	void ShowMenu(CMenu* pMenu, XTP_RESOURCEMANAGER_LANGINFO* pLangInfo);
	void ClearPreview();

// Implementation
public:
	virtual ~CPreviewPane();

	CMenuBar m_wndMenuBar;

	// Generated message map functions
protected:
	//{{AFX_MSG(CPreviewPane)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CDialog* m_pPreviewDialog;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEWPANE_H__5537005A_AF75_417D_8C61_F0A52B6439AA__INCLUDED_)
