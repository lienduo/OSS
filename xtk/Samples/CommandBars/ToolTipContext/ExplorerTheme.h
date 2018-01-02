// ExplorerTheme.h: interface for the CExplorerTheme class.
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

#if !defined(AFX_EXPLORERTHEME_H__399784D6_F29C_40B0_85D6_719BDE6313EC__INCLUDED_)
#define AFX_EXPLORERTHEME_H__399784D6_F29C_40B0_85D6_719BDE6313EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CExplorerTheme : public CXTPNativeXPTheme  
{
public:
	CExplorerTheme();
	virtual ~CExplorerTheme();

	void FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar);
	void RefreshMetrics();	

	CRect GetCommandBarBorders(CXTPCommandBar* pBar);
	void AdjustExcludeRect(CRect& rc, CXTPControl* pControl, BOOL bVertical);
	void DrawControlEntry(CDC* pDC, CXTPControl* pButton);
	COLORREF GetControlTextColor(CXTPControl* pButton);

protected:
	COLORREF m_clrPopupBarBorder;
	COLORREF m_clrPopupBarFace;
	COLORREF m_clrPopupBarGripperShadow;
	BOOL m_bLunaTheme;

};

#endif // !defined(AFX_EXPLORERTHEME_H__399784D6_F29C_40B0_85D6_719BDE6313EC__INCLUDED_)
