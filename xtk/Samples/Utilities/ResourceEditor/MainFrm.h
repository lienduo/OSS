// MainFrm.h : interface of the CMainFrame class
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

#if !defined(AFX_MAINFRM_H__D8EC0467_62F7_4494_9693_DD859E80E680__INCLUDED_)
#define AFX_MAINFRM_H__D8EC0467_62F7_4494_9693_DD859E80E680__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PreviewPane.h"

struct CResourceInfo
{
	CString strLanguage;
	CString strPath;
};

class CMainFrame : public CXTPMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:

// Operations
public:
	void ShowDialogPreview(CXTPPropExchangeXMLNode* pResource, DWORD dwId);
	void ShowMenuPreview(CXTPPropExchangeXMLNode* pResource, DWORD dwId, XTP_RESOURCEMANAGER_LANGINFO* pLangInfo);
	void ClearPreview();
	void ScanResources();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CXTPStatusBar  m_wndStatusBar;
	CXTPDockingPaneManager m_paneManager;

	CPreviewPane m_wndPreview;
	CXTPTabClientWnd m_MTIClientWnd;

	CArray<CResourceInfo, CResourceInfo&> m_arrResources;


	
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateFileOpen(CCmdUI* pCmdUI);
	afx_msg void OnFileChangelocation();
	afx_msg void OnFileExportAll();
	//}}AFX_MSG

	void OnFileImportAll();
	void OnFileImportDll();
	LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);
	int OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl);
	void OnFileOpen(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState);
	
	DECLARE_MESSAGE_MAP()
};
 
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__D8EC0467_62F7_4494_9693_DD859E80E680__INCLUDED_)
