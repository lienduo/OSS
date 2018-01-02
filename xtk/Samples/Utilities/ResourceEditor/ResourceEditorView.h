// ResourceEditorView.h : interface of the CResourceEditorView class
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

#if !defined(AFX_RESOURCEEDITORVIEW_H__A62B9FEA_8999_4102_9673_F37906068799__INCLUDED_)
#define AFX_RESOURCEEDITORVIEW_H__A62B9FEA_8999_4102_9673_F37906068799__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CResourceViewRecord;


class CResourceEditorView : public CXTPReportView
{
protected: // create from serialization only
	CResourceEditorView();
	DECLARE_DYNCREATE(CResourceEditorView)

// Attributes
public:
	CResourceEditorDoc* GetDocument();

// Operations
public:
	BOOL PreCreateWindow(CREATESTRUCT& cs);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResourceEditorView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CResourceEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void PopulateResources();
	void PopulateStringResources(CTreeCtrl& wndResourceTree, CXTPPropExchange* pResources, HTREEITEM hItemStrings);
	void PopulateMenuResources(CTreeCtrl& wndResourceTree, CXTPPropExchange* pResources, HTREEITEM hItemMenus);
	void PopulateDialogResources(CTreeCtrl& wndResourceTree, CXTPPropExchange* pResources, HTREEITEM hItemDialogs);
	void PopulateDialogControlsResources(CResourceViewRecord* pDialogRecord, CXTPPropExchange* pResourceDialog);
	void PopulateMenuItemsResources(CXTPReportRecord* pMenuBase, CXTPReportRecord* pMenuRecord, CXTPPropExchange* pResourceMenu);

	void LoadXMLString(CXTPPropExchange* pPX, LPCTSTR pszPropName, CString& strValue);

// Generated message map functions
protected:
	//{{AFX_MSG(CResourceEditorView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	void OnReportValueChanged(NMHDR * pNotifyStruct, LRESULT * /*result*/);
	void OnReportSelectionChanged(NMHDR * pNotifyStruct, LRESULT * /*result*/);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ResourceEditorView.cpp
inline CResourceEditorDoc* CResourceEditorView::GetDocument()
   { return (CResourceEditorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESOURCEEDITORVIEW_H__A62B9FEA_8999_4102_9673_F37906068799__INCLUDED_)
