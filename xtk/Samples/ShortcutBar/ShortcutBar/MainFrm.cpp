// MainFrm.cpp : implementation of the CMainFrame class
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
#include "ShortcutBar.h"
#include "MainFrm.h"

#include "ShortcutBarDoc.h"
#include "ShortcutBarView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_THEME_OFFICE2000, OnThemeOffice2000)
	ON_UPDATE_COMMAND_UI(ID_THEME_OFFICE2000, OnUpdateThemeOffice2000)
	ON_COMMAND(ID_THEME_OFFICEXP, OnThemeOfficexp)
	ON_UPDATE_COMMAND_UI(ID_THEME_OFFICEXP, OnUpdateThemeOfficexp)
	ON_COMMAND(ID_THEME_OFFICE2003, OnThemeOffice2003)
	ON_UPDATE_COMMAND_UI(ID_THEME_OFFICE2003, OnUpdateThemeOffice2003)
	ON_COMMAND(ID_THEME_OFFICE2007, OnThemeOffice2007)
	ON_UPDATE_COMMAND_UI(ID_THEME_OFFICE2007, OnUpdateThemeOffice2007)
	ON_WM_CLOSE()
	ON_COMMAND(ID_THEME_CLIENTPANE, OnThemeClientpane)
	ON_UPDATE_COMMAND_UI(ID_THEME_CLIENTPANE, OnUpdateThemeClientpane)
	ON_COMMAND(ID_THEME_SHOWEXPANDBUTTON, OnThemeShowexpandbutton)
	ON_UPDATE_COMMAND_UI(ID_THEME_SHOWEXPANDBUTTON, OnUpdateThemeShowexpandbutton)
	ON_COMMAND(ID_THEME_SHOWACTIVEITEMONTOP, OnThemeShowactiveitemontop)
	ON_UPDATE_COMMAND_UI(ID_THEME_SHOWACTIVEITEMONTOP, OnUpdateThemeShowactiveitemontop)
	ON_MESSAGE(XTPWM_SHORTCUTBAR_NOTIFY, OnShortcutBarNotify)
	ON_COMMAND(ID_THEME_ALLOWFREERESIZE, OnThemeAllowfreeresize)
	ON_UPDATE_COMMAND_UI(ID_THEME_ALLOWFREERESIZE, OnUpdateThemeAllowfreeresize)
	//}}AFX_MSG_MAP

	ON_COMMAND(XTP_ID_CUSTOMIZE, OnCustomize)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

static UINT shortcuts[] =
{
	ID_SHORTCUT_MAIL,
	ID_SHORTCUT_CALENDAR,
	ID_SHORTCUT_CONTACTS,
	ID_SHORTCUT_TASKS,
	ID_SHORTCUT_NOTES,
	ID_SHORTCUT_FOLDERS,
	ID_SHORTCUT_SHORTCUTS,
	ID_SHORTCUT_JOURNAL
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bClientPane = TRUE;

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	if (!InitCommandBars())
		return -1;

	CXTPCommandBars* pCommandBars = GetCommandBars();

	pCommandBars->SetMenu(_T("Menu Bar"), IDR_MAINFRAME);


	CXTPToolBar* pStandardBar = (CXTPToolBar*)pCommandBars->Add(_T("Standard"), xtpBarTop);
	if (!pStandardBar ||
		!pStandardBar->LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
	}

	pCommandBars->GetToolTipContext()->SetStyle(xtpToolTipOffice);

	// Load the previous state for command bars.
	LoadCommandBars(_T("CommandBars"));

	CXTPPaintManager::SetTheme(xtpThemeRibbon);
	m_wndShortcutBar.SetTheme(xtpShortcutThemeOffice2007);
	EnableOffice2007Frame(GetCommandBars());

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.lpszClass = _T("XTPMainFrame");
	CXTPDrawHelpers::RegisterWndClass(AfxGetInstanceHandle(), cs.lpszClass, 
		CS_DBLCLKS, AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	cs.style |= WS_CLIPSIBLINGS|WS_CLIPCHILDREN;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::CreateShortcutBar()
{
	m_wndShortcutBar.Create(WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CRect(0, 0, 0, 0),
		&m_wndSplitter,  m_wndSplitter.IdFromRowCol(0, 0));

	m_wndShortcutBar.SetOwner(this);
	m_wndShortcutBar.GetToolTipContext()->SetStyle(xtpToolTipOffice);

	BOOL bUseAlphaIcons = XTPImageManager()->IsAlphaIconsSupported();

	XTPImageManager()->SetIcons(bUseAlphaIcons ? IDB_SHORTCUTS_SMALL_ALPHA : IDB_SHORTCUTS_SMALL, 
		shortcuts, sizeof(shortcuts)/sizeof(UINT), CSize(16, 16));

	XTPImageManager()->SetIcons(bUseAlphaIcons ? IDB_SHORTCUTS_BIG_ALPHA : IDB_SHORTCUTS_BIG, 
		shortcuts, sizeof(shortcuts)/sizeof(UINT), CSize(24, 24));


	VERIFY(m_paneMail.Create(_T("Mail"), &m_wndShortcutBar));
	VERIFY(m_paneCalendar.Create(_T("Calendar"), &m_wndShortcutBar));
	VERIFY(m_paneFolders.Create(_T("Folders"), &m_wndShortcutBar));
	VERIFY(m_paneContacts.Create(_T("Contacts"), &m_wndShortcutBar));

	CXTPShortcutBarItem* pItemMail = m_wndShortcutBar.AddItem(ID_SHORTCUT_MAIL, &m_paneMail);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_CALENDAR, &m_paneCalendar);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_CONTACTS, &m_paneContacts);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_TASKS);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_NOTES);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_FOLDERS, &m_paneFolders);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_SHORTCUTS);
	m_wndShortcutBar.AddItem(ID_SHORTCUT_JOURNAL);


	m_wndShortcutBar.SelectItem(pItemMail);
	m_wndShortcutBar.LoadState(_T("ShortcutBar"));

}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	m_wndSplitter.CreateStatic(this, 1, 2);

	CreateShortcutBar();

	m_wndSplitter.SetColumnInfo(0, 250,50);

	m_wndSplitter2.CreateStatic(&m_wndSplitter, 2, 1, WS_CHILD|WS_VISIBLE, m_wndSplitter.IdFromRowCol(0, 1));

	m_wndSplitter2.CreateView(0, 0, RUNTIME_CLASS(CShortcutBarView), CSize(0, 200), pContext);
	m_wndSplitter2.CreateView(1, 0, RUNTIME_CLASS(CShortcutBarView), CSize(0, 0), pContext);

	XTThemeManager()->SetTheme(xtThemeOffice2003);


	return TRUE;
}

void CMainFrame::OnThemeOffice2000()
{
	EnableOffice2007Frame(NULL);
	XTPPaintManager()->SetTheme(xtpThemeOffice2000);
	XTThemeManager()->SetTheme(xtThemeDefault);
	GetCommandBars()->RedrawCommandBars();
	m_wndShortcutBar.SetTheme(xtpShortcutThemeOffice2000);
	RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);

}

void CMainFrame::OnUpdateThemeOffice2000(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndShortcutBar.GetCurrentTheme() == xtpShortcutThemeOffice2000);

}

void CMainFrame::OnThemeOfficexp()
{
	EnableOffice2007Frame(NULL);
	XTPPaintManager()->SetTheme(xtpThemeOfficeXP);
	XTThemeManager()->SetTheme(xtThemeOfficeXP);
	GetCommandBars()->RedrawCommandBars();
	m_wndShortcutBar.SetTheme(xtpShortcutThemeOfficeXP);
	RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
}

void CMainFrame::OnUpdateThemeOfficexp(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndShortcutBar.GetCurrentTheme() == xtpShortcutThemeOfficeXP);

}

void CMainFrame::OnThemeOffice2003()
{
	EnableOffice2007Frame(NULL);
	XTPPaintManager()->SetTheme(xtpThemeOffice2003);
	XTThemeManager()->SetTheme(xtThemeOffice2003);
	GetCommandBars()->RedrawCommandBars();
	m_wndShortcutBar.SetTheme(xtpShortcutThemeOffice2003);
	RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
}

void CMainFrame::OnUpdateThemeOffice2003(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndShortcutBar.GetCurrentTheme() == xtpShortcutThemeOffice2003);

}

void CMainFrame::OnThemeOffice2007()
{
	XTPPaintManager()->SetTheme(xtpThemeOffice2007);
	EnableOffice2007Frame(GetCommandBars());
	XTThemeManager()->SetTheme(xtThemeOffice2003);
	GetCommandBars()->RedrawCommandBars();
	m_wndShortcutBar.SetTheme(xtpShortcutThemeOffice2007);
	RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
}

void CMainFrame::OnUpdateThemeOffice2007(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndShortcutBar.GetCurrentTheme() == xtpShortcutThemeOffice2007);

}

void CMainFrame::OnClose()
{
	// Save the current state for command bars.
	SaveCommandBars(_T("CommandBars"));

	m_wndShortcutBar.SaveState(_T("ShortcutBar"));

	CFrameWnd::OnClose();
}

LRESULT CMainFrame::OnShortcutBarNotify(WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
		case XTP_SBN_SELECTION_CHANGING:
			{
				CXTPShortcutBarItem* pItem = (CXTPShortcutBarItem*)lParam;
				TRACE(_T("Selection Changing. Item.Caption = %s\n"), pItem->GetCaption());

				// TODO: You can return -1 to ignore changing

			}
			return TRUE;
		case XTP_SBN_RCLICK:
			{
				CPoint point(lParam);
				CXTPShortcutBarItem* pItem = m_wndShortcutBar.HitTest(point);
				if (pItem)
				{
					TRACE(_T("RClick. Item.ID = %i\n"), pItem->GetID());

					CMenu mnu;
					mnu.LoadMenu(IDR_POPUP_MENU);

					m_wndShortcutBar.ClientToScreen(&point);

					CXTPCommandBars::TrackPopupMenu(mnu.GetSubMenu(0), 0, point.x, point.y, AfxGetMainWnd());

				}
			}
			return TRUE;


	}
	return 0;
}

void CMainFrame::OnThemeClientpane()
{
	m_bClientPane = !m_bClientPane;

	m_wndShortcutBar.SetClientPaneVisible(m_bClientPane);

}

void CMainFrame::OnUpdateThemeClientpane(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bClientPane);

}
void CMainFrame::OnCustomize()
{
	// get a pointer to the command bars object.
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if (pCommandBars == NULL)
		return;

	// instanciate the customize dialog
	CXTPCustomizeSheet dlg(pCommandBars);

	// add the options page to the customize dialog.
	CXTPCustomizeOptionsPage pageOptions(&dlg);
	dlg.AddPage(&pageOptions);

	// add the commands page to the customize dialog.
	CXTPCustomizeCommandsPage* pPageCommands = dlg.GetCommandsPage();
	pPageCommands->AddCategories(IDR_MAINFRAME);

	// initialize the commands page page.
	pPageCommands->InsertAllCommandsCategory();
	pPageCommands->InsertBuiltInMenus(IDR_MAINFRAME);
	pPageCommands->InsertNewMenuCategory();

	// display the customize dialog.
	dlg.DoModal();
}

void CMainFrame::OnThemeShowexpandbutton() 
{
	m_wndShortcutBar.ShowExpandButton(!m_wndShortcutBar.IsExpandButtonVisible());
	
}

void CMainFrame::OnUpdateThemeShowexpandbutton(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndShortcutBar.IsExpandButtonVisible()? TRUE: FALSE);	
}

void CMainFrame::OnThemeShowactiveitemontop() 
{
	BOOL bShowActiveItemOnTop = !m_wndShortcutBar.IsShowActiveItemOnTop();

	m_paneMail.ShowCaption(!bShowActiveItemOnTop);
	m_paneCalendar.ShowCaption(!bShowActiveItemOnTop);
	m_paneFolders.ShowCaption(!bShowActiveItemOnTop);
	m_paneMail.ShowCaption(!bShowActiveItemOnTop);
	m_paneContacts.ShowCaption(!bShowActiveItemOnTop);
	
	m_wndShortcutBar.ShowActiveItemOnTop(bShowActiveItemOnTop);	
}

void CMainFrame::OnUpdateThemeShowactiveitemontop(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndShortcutBar.IsShowActiveItemOnTop()? TRUE: FALSE);		
}

void CMainFrame::OnThemeAllowfreeresize() 
{
	m_wndShortcutBar.AllowFreeResize(!m_wndShortcutBar.IsAllowFreeResize());		
	
}

void CMainFrame::OnUpdateThemeAllowfreeresize(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndShortcutBar.IsAllowFreeResize()? TRUE: FALSE);		
	
}
