// TreeCtrlDlg.h : header file
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

#if !defined(AFX_TreeCtrlDLG_H__D52D23D4_9130_11D3_9983_00500487D199__INCLUDED_)
#define AFX_TreeCtrlDLG_H__D52D23D4_9130_11D3_9983_00500487D199__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "PropertiesDlg.h"
#include "SelectTreeCtrl.h"
#include "StateTreeCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlDlg dialog

class CTreeCtrlDlg : public CXTResizeDialog
{
	DECLARE_DYNAMIC(CTreeCtrlDlg)
		
// Construction
public:
	CTreeCtrlDlg(CWnd* pParent = NULL); // standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeCtrlDlg)
	enum { IDD = IDD_TREECTRL_DIALOG };
	CButton	m_btnProperties;
	CStateTreeCtrl	m_treeState;
	CSelectTreeCtrl     m_treeSelect;
	//}}AFX_DATA

	CXTTreeCtrl* m_pTreeFocus;
	void SetTreeFocus(CXTTreeCtrl* pTreeFocus);
	void EnableProperties();

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtrlDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON       m_hIcon;
	CPropertiesDlg m_dlg;

	// Generated message map functions
	//{{AFX_MSG(CTreeCtrlDlg)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRclickTreeCtrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnEndlabeleditTreeCtrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnBtnProperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TreeCtrlDLG_H__D52D23D4_9130_11D3_9983_00500487D199__INCLUDED_)
