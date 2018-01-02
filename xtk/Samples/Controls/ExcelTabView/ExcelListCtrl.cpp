// ExcelListCtrl.cpp : implementation file
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
#include "ExcelListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExcelListCtrl

CExcelListCtrl::CExcelListCtrl()
{
}

CExcelListCtrl::~CExcelListCtrl()
{
}

BEGIN_MESSAGE_MAP(CExcelListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CExcelListCtrl)
	ON_WM_WINDOWPOSCHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExcelListCtrl message handlers

void CExcelListCtrl::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos)
{
	CListCtrl::OnWindowPosChanged(lpwndpos);

	ShowScrollBar(SB_HORZ, FALSE);
	ModifyStyle(WS_HSCROLL, 0, SWP_DRAWFRAME);
}
