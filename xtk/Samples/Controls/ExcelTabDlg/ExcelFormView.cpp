// ExcelFormView.cpp : implementation file
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
#include "ExcelFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExcelFormView

IMPLEMENT_DYNCREATE(CExcelFormView, CFormView)

CExcelFormView::CExcelFormView()
	: CFormView(CExcelFormView::IDD)
{
	//{{AFX_DATA_INIT(CExcelFormView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CExcelFormView::~CExcelFormView()
{
}

void CExcelFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExcelFormView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExcelFormView, CFormView)
	//{{AFX_MSG_MAP(CExcelFormView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExcelFormView diagnostics

#ifdef _DEBUG
void CExcelFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CExcelFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExcelFormView message handlers

CScrollBar* CExcelFormView::GetScrollBarCtrl(int nBar) const
{
	if (nBar == SB_HORZ)
	{
		return (CScrollBar *)&m_ScrollBarH;
	}

	return CFormView::GetScrollBarCtrl(nBar);
}

int CExcelFormView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_ScrollBarH.Create(WS_CHILD, CRect(0, 0, 0, 0), this, 0);

	return 0;
}

BOOL CExcelFormView::OnEraseBkgnd(CDC* pDC)
{
	UNREFERENCED_PARAMETER(pDC);
	return TRUE;
}

void CExcelFormView::OnPaint()
{
	CPaintDC dc(this);

	// Get the client rect, and paint to a memory device context.  This will
	// help reduce screen flicker. Pass the memory device context to the
	// default window procedure do default painting.

	CRect r;
	GetClientRect(&r);
	CXTMemDC memDC(&dc, r);

	CFormView::DefWindowProc( WM_PAINT, (WPARAM)memDC.m_hDC, 0 );
}
