// ToolTipContextView.h : interface of the CToolTipContextView class
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

#if !defined(AFX_TOOLTIPCONTEXTVIEW_H__FFC01DB7_7092_4123_9506_ACD3DCFF8E8F__INCLUDED_)
#define AFX_TOOLTIPCONTEXTVIEW_H__FFC01DB7_7092_4123_9506_ACD3DCFF8E8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCircle
{
public:
	CCircle(CPoint ptCenter, int nRadius, COLORREF clr)
	{
		m_ptCenter = ptCenter;
		m_nRadius = nRadius;
		m_clr = clr;
	}
public:
	BOOL HitTest(CPoint pt)
	{
		CPoint Diff = m_ptCenter - pt;
		return ((pow((double)Diff.x, 2) + pow((double)Diff.y, 2)) <= pow((double)m_nRadius, 2));
	}

	void Draw(CDC* pDC)
	{
		CXTPBrushDC brush(*pDC, m_clr);
		CXTPPenDC pen(*pDC, RGB(128, 128, 128));
		pDC->Ellipse(GetRect());
	}
	CRect GetRect() const
	{
		return CRect(m_ptCenter.x - m_nRadius, m_ptCenter.y - m_nRadius, m_ptCenter.x + m_nRadius, m_ptCenter.y + m_nRadius);
	}

	CString GetTooltip();

protected:
	CPoint m_ptCenter;
	int m_nRadius;
	COLORREF m_clr;
};

class CToolTipContextView : public CView
{
protected: // create from serialization only
	CToolTipContextView();
	DECLARE_DYNCREATE(CToolTipContextView)

// Attributes
public:
	CToolTipContextDoc* GetDocument();
	CXTPToolTipContext* m_pTooltipContext;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolTipContextView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolTipContextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CArray<CCircle*, CCircle*> m_arrCircles;
	CCircle* HitTest(const CPoint& Point) const;
	INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;

// Generated message map functions
protected:
	//{{AFX_MSG(CToolTipContextView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolTipContextView.cpp
inline CToolTipContextDoc* CToolTipContextView::GetDocument()
   { return (CToolTipContextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIPCONTEXTVIEW_H__FFC01DB7_7092_4123_9506_ACD3DCFF8E8F__INCLUDED_)
