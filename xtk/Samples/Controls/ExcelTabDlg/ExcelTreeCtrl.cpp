// ExcelTreeCtrl.cpp : implementation file
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

#include "stdafx.h"
#include "ExcelTab.h"
#include "ExcelTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExcelTreeCtrl

CExcelTreeCtrl::CExcelTreeCtrl()
{
}

CExcelTreeCtrl::~CExcelTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CExcelTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CExcelTreeCtrl)
	ON_WM_WINDOWPOSCHANGED()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExcelTreeCtrl message handlers

void CExcelTreeCtrl::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos)
{
	// for the tree control, we'll call ShowScrollBar(SB_HORZ, FALSE) both
	// before and after CTreeCtrl::OnWindowPosChanged() - this seems to
	// reduce flicker much more
	ShowScrollBar(SB_HORZ, FALSE);
	CTreeCtrl::OnWindowPosChanged(lpwndpos);
	ShowScrollBar(SB_HORZ, FALSE);
	ModifyStyle(WS_HSCROLL, 0, SWP_DRAWFRAME);
}

void CExcelTreeCtrl::OnItemexpanded(NMHDR* /*pNMHDR*/, LRESULT* pResult)
{
	// since the newly expanded / collapsed item could affect the horz.
	// scroll bar, we'll force a resync here
	((CXTExcelTabCtrl *)GetParent())->SyncScrollBar();

	*pResult = 0;
}

void CExcelTreeCtrl::PreSubclassWindow()
{
	CTreeCtrl::PreSubclassWindow();
	CommonInit();
}

int CExcelTreeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	CommonInit();

	return 0;
}

void CExcelTreeCtrl::CommonInit()
{
	// make tooltips "top-most" so they don't get obscured by the flat tab
	// when floating in a dock bar
	CToolTipCtrl *pTTCtrl =
#if _MSC_VER >= 1200  // VC6
		GetToolTips();
#else
		(CToolTipCtrl*)CWnd::FromHandle((HWND)::SendMessage(m_hWnd, TVM_GETTOOLTIPS, 0, 0L));
#endif

	if (pTTCtrl->GetSafeHwnd())
	{
		pTTCtrl->SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0,
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}
}
