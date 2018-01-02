// ExcelScrollView.h : header file
//
// This file is a part of the XTREME CONTROLS MFC class library.
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

#if !defined(__EXCELSCROLLVIEW_H__)
#define __EXCELSCROLLVIEW_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CExcelScrollView : public CScrollView
{
protected: // create from serialization only
	CExcelScrollView();
	DECLARE_DYNCREATE(CExcelScrollView)

// Attributes
public:
	CDocument* GetDocument();
	BOOL SyncScrollBar();

// Operations
public:
	CScrollBar m_ScrollBarH;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExcelScrollView)
	public:
	virtual CScrollBar* GetScrollBarCtrl(int nBar)const;
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExcelScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void ResizeParentToFit(BOOL bShrinkOnly = TRUE);

// Generated message map functions
protected:
	//{{AFX_MSG(CExcelScrollView)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/*
#ifndef _DEBUG  // debug version in TestScrollView.cpp
inline CTestScrollDoc* CExcelScrollView::GetDocument()
	{ return (CTestScrollDoc*)m_pDocument; }
#endif
*/
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(__EXCELSCROLLVIEW_H__)
