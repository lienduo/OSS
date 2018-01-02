// XTEListBox.cpp : implementation of the CXTListBox class.
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
#include "Common/XTPColorManager.h"
#include "Common/XTPDrawHelpers.h"
#include "Common/XTPOffice2007Image.h"

#include "XTGlobal.h"
#include "XTListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CXTListBox
/////////////////////////////////////////////////////////////////////////////
CXTListBox::CXTListBox()
: m_bPreSubclassInit(true)
{
	m_nStyle = xtListBoxStandard;
}

CXTListBox::~CXTListBox()
{

}

IMPLEMENT_DYNAMIC(CXTListBox, CListBox)

BEGIN_MESSAGE_MAP(CXTListBox, CListBox)
	//{{AFX_MSG_MAP(CXTListBox)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_MESSAGE(WM_PRINTCLIENT, OnPrintClient)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CXTListBox::Initialize(bool bAutoFont/*= true*/)
{
	// set the font for the list box.
	if (bAutoFont)
	{
		SetFont(&XTAuxData().font);
	}
}

void CXTListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	CRect rcItem = lpDIS->rcItem;

	if ((lpDIS->itemID != (UINT)-1) && (lpDIS->itemAction & (ODA_DRAWENTIRE | ODA_SELECT)))
	{
		COLORREF clrWindow = GetBackColor();
		COLORREF clrWindowText = IsWindowEnabled() ? GetXtremeColor(COLOR_WINDOWTEXT) : GetXtremeColor(COLOR_GRAYTEXT);
		BOOL bSelected = ((lpDIS->itemState & ODS_SELECTED) != 0);
		CRect rcText(rcItem);
		rcText.DeflateRect(2, 0);

		if (bSelected)
		{
			clrWindow = IsWindowEnabled() ? GetXtremeColor(COLOR_HIGHLIGHT) : GetXtremeColor(COLOR_GRAYTEXT);
			clrWindowText = GetXtremeColor(COLOR_HIGHLIGHTTEXT);
		}

		if (m_nStyle == xtListBoxOfficeXP && bSelected && IsWindowEnabled())
		{
			clrWindowText = GetXtremeColor(XPCOLOR_HIGHLIGHT_TEXT);
			clrWindow = GetXtremeColor(XPCOLOR_HIGHLIGHT);
			pDC->Draw3dRect(rcItem, GetXtremeColor(XPCOLOR_HIGHLIGHT_BORDER), GetXtremeColor(XPCOLOR_HIGHLIGHT_BORDER));
			rcItem.DeflateRect(1, 1);
		}

		if (m_nStyle == xtListBoxOffice2007 && bSelected && IsWindowEnabled())
		{
			CXTPOffice2007Image* pImage = XTPOffice2007Images()->LoadFile(_T("TOOLBARBUTTONS22"));
			if (pImage)
			{
				pImage->DrawImage(pDC, rcItem, pImage->GetSource(3, 4), CRect(8, 8, 8, 8), COLORREF_NULL);
				clrWindow = COLORREF_NULL;
				pDC->SetBkMode(TRANSPARENT);
				clrWindowText = GetXtremeColor(COLOR_WINDOWTEXT);
			}

		}

		// set the text and text background colors, then repaint the item.
		pDC->SetBkColor(clrWindow);
		pDC->SetTextColor(clrWindowText);
		if (clrWindow != COLORREF_NULL) pDC->FillSolidRect(&rcItem, clrWindow);

		CString strText;
		GetText(lpDIS->itemID, strText);

		pDC->DrawText(strText, &rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_EXPANDTABS);
	}
	if (lpDIS->itemAction & ODA_FOCUS)
		pDC->DrawFocusRect(&lpDIS->rcItem);
}

void CXTListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{
	lpMIS->itemHeight = ::GetSystemMetrics(SM_CYMENU)-2;
}

BOOL CXTListBox::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

COLORREF CXTListBox::GetBackColor()
{
	return GetXtremeColor(COLOR_WINDOW);
}

void CXTListBox::OnPaint()
{
	CPaintDC dc(this);

	// Get the client rect.
	CRect r;
	GetClientRect(&r);

	// Paint to a memory device context to reduce screen flicker.
	CXTPBufferDC memDC(dc, r);
	memDC.FillSolidRect(r, GetBackColor());

	CPoint ptOrg = memDC.GetWindowOrg();

	// Let the window do its default painting   ...
	CListBox::DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, 0);
	memDC.SetWindowOrg(ptOrg);
}

LRESULT CXTListBox::OnPrintClient(WPARAM wParam, LPARAM lParam)
{
	CListBox::DefWindowProc(WM_ERASEBKGND, wParam, 0);
	return CListBox::DefWindowProc(WM_PRINTCLIENT, wParam, lParam);
}

bool CXTListBox::Init()
{
	// make sure the style is set to LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS.
	DWORD dwStyle = ::GetWindowLong(GetSafeHwnd(), GWL_STYLE);

	if ((dwStyle & LBS_OWNERDRAWVARIABLE) == 0)
		dwStyle |= LBS_OWNERDRAWVARIABLE;

	if ((dwStyle & LBS_HASSTRINGS) == 0)
		dwStyle |= LBS_HASSTRINGS;

	::SetWindowLong(m_hWnd, GWL_STYLE, dwStyle);

	return true;
}

void CXTListBox::PreSubclassWindow()
{
	CListBox::PreSubclassWindow();

	if (m_bPreSubclassInit)
		Init();
}

BOOL CXTListBox::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CListBox::PreCreateWindow(cs))
		return FALSE;

	m_bPreSubclassInit = false;

	return TRUE;
}

int CXTListBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListBox::OnCreate(lpCreateStruct) == -1)
		return -1;

	Init();

	return 0;
}
