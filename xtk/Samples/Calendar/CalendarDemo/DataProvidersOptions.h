// DataProvidersOptions.h : header file
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

#if !defined(AFX_DATAPROVIDERSOPTIONS_H__9B7BA3B9_84AF_425E_9155_1885179FBF51__INCLUDED_)
#define AFX_DATAPROVIDERSOPTIONS_H__9B7BA3B9_84AF_425E_9155_1885179FBF51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDataProvidersOptions dialog

class CDataProvidersOptions : public CDialog
{
// Construction
public:
	CDataProvidersOptions(CWnd* pParent = NULL);   // standard constructor

/// Input 
/// dialog settings

	enum {modeMemOnly, modeDBOnly, modeAll};
	int		m_eMode;
    	
	BOOL	m_bWarnIfExist;	// = FALSE
	BOOL	m_bOpenMode;	// = FALSE
	CString m_strTitle;		// = "Select data provider and data file"

// Data Parameters
	BOOL m_bInitFromProfile;	// = TRUE
	BOOL m_bSaveToProfile;		// = TRUE
	
// Input-Output
	CString m_strConnectionString; // = ""

/// Results
	BOOL IsDPWasChanged() const;
	BOOL IsFileWasChanged() const;


protected:	
// Dialog Data
	//{{AFX_DATA(CDataProvidersOptions)
	enum { IDD = IDD_DATA_PROVIDER_OPTIONS };
	CButton	m_ctrlOK;
	
	CButton	m_ctrlUseMemDP;
	CButton	m_ctrlMemFrame;	
	CStatic	m_ctrlMemFileLabel;
	CEdit	m_ctrlMemFile;
	CButton	m_ctrlMemFileBrowse;
	CStatic	m_ctrlMemFileHelp;
	
	CButton	m_ctrlUseDBDP;
	CButton	m_ctrlDBFrame;
	CStatic	m_ctrlDBFileLabel;
	CEdit	m_ctrlDBFile;
	CButton	m_ctrlDBFileBrowse;	
	CStatic	m_ctrlDBFileHelp;

	CButton	m_ctrlUseMAPIDP;
	CButton	m_ctrlMAPIFrame;
	CStatic	m_ctrlMAPILabel;
	//}}AFX_DATA

	BOOL m_bIsDPWasChanged;
	BOOL m_bIsFileWasChanged;

	CString m_strUseDP_Prev;
	CString m_strMemDPFile_Prev;
	CString m_strDBDPFile_Prev;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataProvidersOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	BOOL CheckExist(LPCTSTR pcszFile);

	void EnableDBDPcontrols(BOOL bEnable);
	void EnableMemDPcontrols(BOOL bEnable);
	void EnableMAPIDPcontrols(BOOL bEnable);

	CString FileBrowse(const CString& strFileName, const CString& strDefExt, 
						const CString& strFilter);

	// Generated message map functions
	//{{AFX_MSG(CDataProvidersOptions)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnMemDPFileBrowse();
	afx_msg void OnDBDPFileBrowse();
	afx_msg void OnUseDBDP();
	afx_msg void OnUseMemDP();
	afx_msg void OnUseMAPIDP();
	virtual void OnCancel();	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAPROVIDERSOPTIONS_H__9B7BA3B9_84AF_425E_9155_1885179FBF51__INCLUDED_)
