// mainfrm.h : interface of the CMainFrame class
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

#if !defined(AFX_MAINFRM_H__4CCF8A15_BE48_4C19_9F2B_8C1AA1EB4A2C__INCLUDED_)
#define AFX_MAINFRM_H__4CCF8A15_BE48_4C19_9F2B_8C1AA1EB4A2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "drawobj.h"
#include "PanePropertyGrid.h"



CXTPPropertyGrid& GetPropertyGrid(CWnd* pFrame = 0);



class CMainFrame : public CXTPMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();


// Attributes
public:
	CXTPDockingPaneManager m_paneManager;

// Operations
public:
	CXTPDockingPaneManager* GetDockingPaneManager() {
		return &m_paneManager;
	}

	CPanePropertyGrid m_panePropertyGrid;




// Operations
public:
	void UpdatePropertyGridContent(CDrawView* pView);
	CDrawView* m_pView;
	BOOL m_bInUpdate;

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	// control bar embedded members
	CToolBar    m_wndToolBar;


	CXTPStatusBar  m_wndStatusBar;
	CXTPTabClientWnd m_MTIClientWnd;


	CXTPPropertyGridUpdateContext m_stateExpanding;


	BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

// Generated message map functions
protected:
	BOOL PreCreateWindow(CREATESTRUCT& cs);

	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGridNotify(WPARAM wParam, LPARAM lParam);
	afx_msg void OnProperties();
	//}}AFX_MSG
	afx_msg void OnClose();
	afx_msg void OnCustomize();
	void OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState);
	afx_msg LRESULT OnTabbarMouseMsg(WPARAM wParam,LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

inline CXTPPropertyGrid& GetPropertyGrid(CWnd* pFrame) {
	if (pFrame == 0) pFrame = AfxGetMainWnd();
	return ((CMainFrame*)pFrame)->m_panePropertyGrid.m_wndPropertyGrid;

}


/////////////////////////////////////////////////////////////////////////////
#endif // !defined(AFX_MAINFRM_H__4CCF8A15_BE48_4C19_9F2B_8C1AA1EB4A2C__INCLUDED_)
