// MDITabWindowsView.h : interface of the CMDITabWindowsView class
//
// This file is a part of the XTREME TOOLKIT MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO 
// BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED 
// WRITTEN CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS 
// OUTLINED IN THE XTREME TOOLKIT LICENSE AGREEMENT.  CODEJOCK SOFTWARE 
// GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE 
// THIS SOFTWARE ON A SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDITABWINDOWSVIEW_H__2ADACD5E_6BCD_4B4D_B562_8D1E19A61C30__INCLUDED_)
#define AFX_MDITABWINDOWSVIEW_H__2ADACD5E_6BCD_4B4D_B562_8D1E19A61C30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDITabWindowsView : public CEditView
{
protected: // create from serialization only
	CMDITabWindowsView();
	DECLARE_DYNCREATE(CMDITabWindowsView)

// Attributes
public:
	CMDITabWindowsDoc* GetDocument();

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDITabWindowsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDITabWindowsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDITabWindowsView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFilePrintPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDITabWindowsView.cpp
inline CMDITabWindowsDoc* CMDITabWindowsView::GetDocument()
   { return (CMDITabWindowsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDITABWINDOWSVIEW_H__2ADACD5E_6BCD_4B4D_B562_8D1E19A61C30__INCLUDED_)
