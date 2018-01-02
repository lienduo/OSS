
#include "stdafx.h"
#include "styler.h"
#include "IndicatorStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CIndicatorStatusBar::CIndicatorStatusBar()
{
	m_nProgress = 0;
}

CIndicatorStatusBar::~CIndicatorStatusBar()
{
}


/////////////////////////////////////////////////////////////////////////////
// CIndicatorStatusBar message handlers

void CIndicatorStatusBar::DrawPaneEntry(CDC* pDC, int nIndex, CRect rcItem)
{
	CXTPStatusBar::DrawPaneEntry(pDC, nIndex, rcItem);
	
	if (nIndex == 1 && m_nProgress != 0)
	{
		rcItem.DeflateRect(3, 3);
		rcItem.right = rcItem.left + (rcItem.right - rcItem.left) * m_nProgress / 100;
		if (rcItem.right > rcItem.left)
		{				
			COLORREF clr = GetSysColor(COLOR_HIGHLIGHT);
			pDC->FillSolidRect(rcItem, clr);
		}
	}
}

void CIndicatorStatusBar::SetProgress(int nProgress)
{
	if (m_nProgress != nProgress)
	{
		m_nProgress = nProgress;
		Invalidate(FALSE);
	}

}

