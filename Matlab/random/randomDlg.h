// randomDlg.h : header file
//

#if !defined(AFX_RANDOMDLG_H__C8FBB2CF_C76B_412C_9A87_583B3C3831DF__INCLUDED_)
#define AFX_RANDOMDLG_H__C8FBB2CF_C76B_412C_9A87_583B3C3831DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRandomDlg dialog
#include "Scope.h"
class CRandomDlg : public CDialog
{
// Construction
public:
	CRandomDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRandomDlg)
	enum { IDD = IDD_RANDOM_DIALOG };
	CScope	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRandomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRandomDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAverage();
	afx_msg void OnZhengtai();
	afx_msg void OnRuili();
	afx_msg void OnNormalStat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANDOMDLG_H__C8FBB2CF_C76B_412C_9A87_583B3C3831DF__INCLUDED_)
