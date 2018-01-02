// convDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mschart.h"
//}}AFX_INCLUDES

#if !defined(AFX_CONVDLG_H__A9E65AE8_A24F_4E55_AE66_766C03760382__INCLUDED_)
#define AFX_CONVDLG_H__A9E65AE8_A24F_4E55_AE66_766C03760382__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CConvDlg dialog

class CConvDlg : public CDialog
{
// Construction
public:
	CConvDlg(CWnd* pParent = NULL);	// standard constructor
	CString do2CStr(double variable);

	

// Dialog Data
	//{{AFX_DATA(CConvDlg)
	enum { IDD = IDD_CONV_DIALOG };
	CMSChart	m_Chart;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConvDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVDLG_H__A9E65AE8_A24F_4E55_AE66_766C03760382__INCLUDED_)
