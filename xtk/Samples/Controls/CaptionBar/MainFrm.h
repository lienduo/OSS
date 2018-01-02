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

#if !defined(AFX_MAINFRM_H__8BCE75FE_E9EE_4DDD_9955_711F4299135C__INCLUDED_)
#define AFX_MAINFRM_H__8BCE75FE_E9EE_4DDD_9955_711F4299135C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CListViewEx;
class CTreeViewEx;

#define CMainFrameBase CXTPFrameWnd

class CMainFrame : public CMainFrameBase
{	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:
	CListViewEx* m_pListView;
	CTreeViewEx* m_pTreeView;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
	CListViewEx* GetRightPane();
	CTreeViewEx* GetLeftPane();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members

	int            m_nColumn;
	
	CXTPStatusBar   m_wndStatusBar;
	CXTCaption     m_wndCaption;
	CXTSplitterWnd m_wndSplitter;
	CXTSplitterWnd m_wndSplitter2;
	CXTTreeCtrl*   m_pwndTreeCtrl;
	CXTRegistryManager m_regMgr;
	int            m_iTheme;

public:

	void SetTheme(int iTheme);
	void CloseTreeViewPane();
	void UpdateButtonStyle(CXTCaptionButton& btnCaption);

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewThemeDefault();
	afx_msg void OnUpdateViewThemeDefault(CCmdUI* pCmdUI);
	afx_msg void OnViewThemeOfficeXP();
	afx_msg void OnUpdateViewThemeOfficeXP(CCmdUI* pCmdUI);
	afx_msg void OnViewThemeOffice2003();
	afx_msg void OnUpdateViewThemeOffice2003(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnUpdateViewStyles(CCmdUI* pCmdUI);
	afx_msg void OnViewStyle(UINT nCommandID);
	afx_msg void OnPushPinButton();
	afx_msg void OnPushPinCancel();
	afx_msg void OnClose();
	afx_msg void OnCustomize();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__8BCE75FE_E9EE_4DDD_9955_711F4299135C__INCLUDED_)
