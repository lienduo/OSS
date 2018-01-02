// HeroesView.cpp : implementation file
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
#include "advanced.h"
#include "HeroesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHeroesView

IMPLEMENT_DYNCREATE(CHeroesView, CWnd)

CHeroesView::CHeroesView()
{
	m_nFilter = 0;
}

CHeroesView::~CHeroesView()
{
}


BEGIN_MESSAGE_MAP(CHeroesView, CWnd)
	//{{AFX_MSG_MAP(CHeroesView)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_BUTTON_BLUE, ID_FAMILY_HAWKS, OnFilterColor)
	ON_UPDATE_COMMAND_UI_RANGE(ID_BUTTON_BLUE, ID_FAMILY_HAWKS, OnUpdateFilterColor)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHeroesView drawing

void CHeroesView::OnDraw(CDC* /*pDC*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CHeroesView diagnostics

#ifdef _DEBUG
void CHeroesView::AssertValid() const
{
	CWnd::AssertValid();
}

void CHeroesView::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHeroesView message handlers

void CHeroesView::OnInitialUpdate()
{
	VERIFY(InitCommandBars());
	CXTPCommandBars* pCommandBars = GetCommandBars();

	CXTPToolBar* pToolBar = pCommandBars->Add(_T("Heroes Bar"), xtpBarTop);
	VERIFY(pToolBar->LoadToolBar(IDR_TOOLBAR_HEROES));
	pToolBar->GetControls()->Remove(pToolBar->GetControl(0));
	CXTPControl* pControl = pToolBar->GetControls()->Add(xtpControlButtonPopup, IDR_HEROES_FAMILY, _T(""), 0);
	pControl->SetFlags(xtpFlagManualUpdate);
	pControl->SetStyle(xtpButtonIconAndCaption);

	pToolBar->EnableDocking(xtpFlagAlignTop);
	
	pCommandBars->GetCommandBarsOptions()->ShowKeyboardCues(xtpKeyboardCuesShowWindowsDefault);
	pCommandBars->GetCommandBarsOptions()->bShowExpandButtonAlways = FALSE;


	CRect rc;
	GetClientRect(&rc);

	if (!m_listCtrl.CWnd::CreateEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, NULL,
		WS_CHILD|WS_VISIBLE|LVS_AUTOARRANGE,
		rc, this, AFX_IDW_PANE_FIRST))
	{
		TRACE0("Failed to create tree control.\n");
		return;
	}


	if (!m_imageList.Create (32, 32, ILC_COLOR24 | ILC_MASK, 1, 20))
	{
		TRACE0 ("Failed to create image list.\n");
		return;
	}

	CWinApp* pWinApp = AfxGetApp();
	ASSERT_VALID(pWinApp);

	m_imageList.Add (pWinApp->LoadIcon (IDI_AQUAMAN));
	m_imageList.Add (pWinApp->LoadIcon (IDI_ATOM));
	m_imageList.Add (pWinApp->LoadIcon (IDI_BATMAN));
	m_imageList.Add (pWinApp->LoadIcon (IDI_FIRESTORM));
	m_imageList.Add (pWinApp->LoadIcon (IDI_FLASH));
	m_imageList.Add (pWinApp->LoadIcon (IDI_GREENARROW));
	m_imageList.Add (pWinApp->LoadIcon (IDI_GREENLANTERN));
	m_imageList.Add (pWinApp->LoadIcon (IDI_HAWKMAN));
	m_imageList.Add (pWinApp->LoadIcon (IDI_HAWKWOMAN));
	m_imageList.Add (pWinApp->LoadIcon (IDI_REDTORNADO));
	m_imageList.Add (pWinApp->LoadIcon (IDI_SUPERMAN));
	m_imageList.Add (pWinApp->LoadIcon (IDI_WONDERWOMAN));

	m_listCtrl.SetImageList (&m_imageList, LVSIL_NORMAL);


	for (int i = 0; i < 11; i++) InsertItem(i);

	RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposDefault);

}

void CHeroesView::InsertItem(int nItem)
{
	switch (nItem)
	{
		case 0: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Aquaman"), 0); break;
		case 1: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Atom"), 1); break;
		case 2: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Batman"),        2); break;
		case 3: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Firestorm"),     3); break;
		case 4: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Flash"),         4); break;
		case 5: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Green Arrow"),   5); break;
		case 6: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Green Lantern"), 6); break;
		case 7: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Hawkman"),       7); break;
		case 8: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Hawkwoman"),     8); break;
		case 9: m_listCtrl.InsertItem ( m_listCtrl.GetItemCount(), _T("Red Tornado"),   9); break;
		case 10: m_listCtrl.InsertItem (m_listCtrl.GetItemCount(), _T("Superman"),     10); break;
		case 11: m_listCtrl.InsertItem (m_listCtrl.GetItemCount(), _T("Wonder Woman"), 11); break;
	}
}

void CHeroesView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposDefault);
}

BOOL CHeroesView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= WS_CLIPSIBLINGS| WS_CLIPCHILDREN;

	return CWnd::PreCreateWindow(cs);
}

BOOL CHeroesView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

void CHeroesView::OnSetFocus(CWnd* /*pOldWnd*/)
{
	if (m_listCtrl.GetSafeHwnd())
	{
		m_listCtrl.SetFocus();
	}
}

void CHeroesView::OnFilterColor(UINT nID)
{
	m_listCtrl.DeleteAllItems();
	if (m_nFilter == (int)nID)
	{
		m_nFilter = 0;
		for (int i = 0; i < 11; i++) InsertItem(i);
		return;
	}
	m_nFilter = nID;
	switch (m_nFilter)
	{
		case ID_BUTTON_RED:
			InsertItem(0);
			InsertItem(3);
			InsertItem(4);
			break;
		case ID_BUTTON_BLUE:
			InsertItem(1);
			InsertItem(2);
			InsertItem(10);
			break;
		case ID_BUTTON_GREEN:
			InsertItem(5);
			InsertItem(6);
			break;
		case ID_FAMILY_HAWKS:
			InsertItem(7);
			InsertItem(8);
			break;
	}
}

void CHeroesView::OnUpdateFilterColor(CCmdUI* pCmd)
{
	pCmd->SetCheck(pCmd->m_nID == (UINT)m_nFilter);

}
