// StateTreeCtrl.h : header file
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

#if !defined(__STATETREECTRL_H__)
#define __STATETREECTRL_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStateTreeCtrl window

typedef enum TREE_STATE 
{
	STATE_NONE,
	STATE_UNCHECKED,
	STATE_CHECKED,
	STATE_INTERMEDIATE,
	STATE_DISABLED
};

class CStateTreeCtrl : public CSelectTreeCtrl
{
// Construction
public:
	CStateTreeCtrl();

// Attributes
public:

// Operations
public:
	int GetItemCheck(HTREEITEM hItem) const;
	BOOL SetItemCheck(HTREEITEM hItem, int nState);
	HTREEITEM InsertItemState(LPCTSTR lpszItem, int nImage, int nSelectedImage, int nState=STATE_DISABLED, HTREEITEM hParent=TVI_ROOT, HTREEITEM hInsertAfter=TVI_LAST);
	BOOL ToggleCheckState(HTREEITEM hItem, UINT uFlags);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStateTreeCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStateTreeCtrl();

	// Generated message map functions
protected:
	CImageList m_ilStateImages;
	HCURSOR    m_hCursor;
	HCURSOR    m_hCursorNone;

	//{{AFX_MSG(CStateTreeCtrl)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(__STATETREECTRL_H__)
