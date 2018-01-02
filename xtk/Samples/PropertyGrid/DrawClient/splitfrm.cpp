
// splitfrm.cpp : implementation file
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

#include "stdafx.h"
#include "drawcli.h"
#include "splitfrm.h"
#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitFrame

IMPLEMENT_DYNCREATE(CSplitFrame, CMDIChildWnd)

static int nColor = xtpTabColorBlue;

CSplitFrame::CSplitFrame()
{
	m_nColor = nColor++;
	if (nColor > xtpTabColorMagenta)
		nColor = xtpTabColorBlue;

}

CSplitFrame::~CSplitFrame()
{
}

BOOL CSplitFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,       // TODO: adjust the number of rows, columns
		CSize(10, 10),  // TODO: adjust the minimum pane size
		pContext);
}

BOOL CSplitFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// make sure view is maximum size to eliminate
	// flicker when switching tabs.
	cs.x =
	cs.y = 0;

	cs.cx =
	cs.cy = 32767;

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.style |= WS_CLIPCHILDREN;

	return TRUE;
}

void CSplitFrame::ActivateFrame(int nCmdShow)
{
	// first window should be maximized
	if (GetParent()->GetWindow(GW_CHILD) == this)
	{
		nCmdShow = SW_SHOWMAXIMIZED;
	}

	CMDIChildWnd::ActivateFrame(nCmdShow);
}

BEGIN_MESSAGE_MAP(CSplitFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CSplitFrame)
	ON_WM_MDIACTIVATE()
	//}}AFX_MSG_MAP

	ON_MESSAGE(WM_XTP_GETTABCOLOR, OnGetTabColor)
	ON_COMMAND_RANGE(ID_COLOR_BLUE, ID_COLOR_MAGENTA, OnSelectColor)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLOR_BLUE, ID_COLOR_MAGENTA, OnUpdateSelectColor)

	ON_COMMAND(ID_COLOR_NONE, OnSelectColorNone)
	ON_UPDATE_COMMAND_UI(ID_COLOR_NONE, OnUpdateSelectColorNone)

END_MESSAGE_MAP()

void CSplitFrame::OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pWnd)
{
	if (!bActivate)
	{
		COleClientItem* pActiveItem = ((COleDocument*)GetActiveDocument())->GetInPlaceActiveItem(this);
		if (pActiveItem != NULL)
		{
			pActiveItem->Deactivate();
		} 
	}
	else
	{
		((CMainFrame*)AfxGetMainWnd())->UpdatePropertyGridContent((CDrawView*)GetActiveView());
	}
	CMDIChildWnd::OnMDIActivate(bActivate, pActivateWnd, pWnd);
}

/////////////////////////////////////////////////////////////////////////////
// CSplitFrame message handlers


LRESULT CSplitFrame::OnGetTabColor(WPARAM, LPARAM)
{
	// Can return any one of the XTPTabOneNoteColor RGB color values or any
	// valid COLORREF value for example:
	//
	// return CXTPTabPaintManager::GetOneNoteColor(xtpTabColorOrange);

	return m_nColor;
}

void CSplitFrame::OnSelectColor(UINT nColor)
{
	m_nColor = nColor - ID_COLOR_BLUE + xtpTabColorBlue;
}

void CSplitFrame::OnUpdateSelectColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck((int)pCmdUI->m_nID - ID_COLOR_BLUE == m_nColor - xtpTabColorBlue);

}

void CSplitFrame::OnSelectColorNone()
{
	m_nColor = RGB(255, 255, 255);
}

void CSplitFrame::OnUpdateSelectColorNone(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nColor == RGB(255, 255, 255));

}

