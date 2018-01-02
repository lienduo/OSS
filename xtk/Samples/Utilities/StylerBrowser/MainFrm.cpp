// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Styler.h"



#include "ComboBoxSearch.h"

#include "InetTools.h"

#include "MainFrm.h"
#include "StylerView.h"
#include "ChildFrm.h"
#include "FilterDialog.h"
#include "PopupFilter.h"
#include "MouseManager.h"

#include "OptionsDialog.h"
#include "CWebBrowser2.h"
 

#include "ControlFavorites.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif  

using namespace XTPPaintThemes;

CStringArray CMainFrame::m_arrEncodingPage;

BOOL	CMainFrame::m_bConfirmCloseAll = FALSE;
BOOL	CMainFrame::m_bConfirmExit = FALSE;
BOOL	CMainFrame::m_bOneInstance = FALSE;
int		CMainFrame::m_nStartup = STARTUP_HOME;
BOOL	CMainFrame::m_bRestoreWindowPos = FALSE;

XTPPaintTheme  CMainFrame::m_themeCurrent = xtpThemeRibbon;

#define ID_TOGGLE_DOCK 0xDDEE
 
 
// CMainFrame   
  
IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	 
	ON_XTP_EXECUTE(ID_GOTO_URL, OnGotoUrl)
	ON_UPDATE_COMMAND_UI(ID_GOTO_URL, OnUpdateGotoUrl)

	ON_XTP_EXECUTE(ID_FAVORITE_LINK, OnFavorite)



	ON_XTP_EXECUTE(ID_OPENALLFOLDERITEMS, OnOpenAllItems)

	ON_COMMAND(ID_ORGANIZE_FAV, OnOrganizeFavorites)

	ON_COMMAND(ID_FILE_WORKOFFLINE, OnFileWorkoffline)
	ON_UPDATE_COMMAND_UI(ID_FILE_WORKOFFLINE, OnUpdateFileWorkoffline)


	ON_COMMAND(ID_WINDOW_CLOSE_ALL, OnWindowCloseAll)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_CLOSE_ALL, OnUpdateWindowCloseAll)
	ON_COMMAND(ID_TOOLS_IMAGESFILTER, OnToolsImagesfilter)
	ON_COMMAND(ID_TOOLS_POPUPFILTER, OnToolsPopupfilter)

	ON_COMMAND(ID_TOGGLE_DOCK, OnToggleDock)
	ON_COMMAND(ID_TOOLS_SWITCHTHEME, OnSwitchTheme)
	
	ON_UPDATE_COMMAND_UI(ID_WINDOW_CASCADE, OnDisableMenu)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_TILE_HORZ, OnDisableMenu)

	ON_COMMAND(ID_VIEW_FULLSCREEN, OnViewFullscreen)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSCREEN, OnUpdateViewFullscreen)

	ON_COMMAND(ID_FILE_NEW_CURRENT, OnFileNewCurrent)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW_CURRENT, OnUpdateFileNewCurrent)

	ON_COMMAND(ID_FILE_NEW_BLANK, OnFileNewBlank)

	ON_WM_SETTINGCHANGE()
	
	ON_COMMAND(ID_EXPLORER_SEARCH, OnExploreSearch)
	ON_COMMAND(ID_EXPLORER_HISTORY, OnExploreHistory)
	ON_COMMAND(ID_EXPLORER_SOURCE, OnExploreSource)
	ON_COMMAND(ID_EXPLORER_FOLDER, OnExploreFolder)
	ON_COMMAND(ID_EXPLORER_NOTEPAD, OnExploreNotepad)

	
	ON_COMMAND(ID_TOOLS_STRUCTURE, OnToolsStructure)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_STRUCTURE, OnUpdateToolsStructure)

	ON_COMMAND(ID_VIEW_ENCODING_AUTOSELECT, OnViewEncodingAuto)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ENCODING_AUTOSELECT, OnUpdateViewEncodingAuto)

	//ON_COMMAND(ID_TOOLBAR_GO, OnGotoUrl)
	ON_WM_CLOSE()
	ON_COMMAND(ID_TOOLS_DEFAULTBROWSER, OnSetDefault)
	ON_COMMAND(ID_TOOLS_STYLEROPTIONS, OnStylerOptions)

	ON_MESSAGE(WM_USER_SHELL_OPEN, OnShellOpen) 

	ON_XTP_EXECUTE(ID_GOTO_SEARCH, OnGotoSearch)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR, OnUpdateIndicator)

	ON_WM_DESTROY()

	ON_MESSAGE(WM_XTP_PRETRANSLATEMOUSEMSG, OnTabbarMouseMsg)

	ON_COMMAND(ID_SEARCH_LIST, OnSearchList)

	ON_MESSAGE(XTPWM_DOCKINGPANE_NOTIFY, OnDockingPaneNotify)

	ON_COMMAND_RANGE(ID_THEME_DEFAULT, ID_THEME_RIBBON, OnTheme)
	ON_UPDATE_COMMAND_UI_RANGE(ID_THEME_DEFAULT, ID_THEME_RIBBON, OnUpdateTheme)


	
	ON_COMMAND(XTP_ID_CUSTOMIZE, OnCustomize)
	ON_XTP_CREATECONTROL()
	ON_MESSAGE(WM_XTP_CONTROLRBUTTONUP, OnControlRButtonUp)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,
	ID_INDICATOR,
	ID_EMPTY
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_pSession = NULL;
	m_bShowStructure = FALSE;
	m_hEncoding = 0;
	m_hFavorites = 0;
	m_bFullScreen = FALSE;
	
	XTAuxData().UpdateSysMetrics();

	TCHAR szStylesPath[_MAX_PATH];

	VERIFY(::GetModuleFileName(
		AfxGetApp()->m_hInstance, szStylesPath, _MAX_PATH));		
	
	m_strStylesPath = szStylesPath;
	int nIndex  = m_strStylesPath.ReverseFind(_T('\\'));
	if (nIndex > 0) {
		m_strStylesPath = m_strStylesPath.Left(nIndex);
	}
	else {
		m_strStylesPath.Empty();
	}
	
	m_strStylesPath += _T("\\Styles\\");	
}



CMainFrame::~CMainFrame()
{
	if (m_bShowStructure)
	{
		CInetTools::SetStyleSheet(FALSE, FALSE);	
	}

	UninitialNameSpace();
}

static UINT uHideCmds[] =
{
	ID_FILE_PRINT,
	ID_FILE_PRINT_PREVIEW,
	ID_FILE_PRINT_SETUP,
	ID_FILE_PROPERTIES,
	ID_VIEW_SOURCE,
	ID_VIEW_FULLSCREEN,
	ID_TOOLS_STRUCTURE,
	ID_TOOLS_DEFAULTBROWSER,
	ID_SHOWIMAGES
};  
 
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetPaneStyle(0, SBPS_STRETCH);
	m_wndStatusBar.SetPaneInfo(1, ID_INDICATOR, SBPS_NORMAL, 95);
	m_wndStatusBar.SetPaneInfo(2, ID_EMPTY, SBPS_NORMAL, 245);

	if (!InitCommandBars())
		return -1;

	//XTPOffice2007Images()->SetHandle(_T("Styles\\Office2007Gray.dll"));

	XTPImageManager()->SetMaskColor(RGB(0, 255, 0));
	
	XTPImageManager()->SetIcons(IDR_MENUBAR);
	
	CXTPCommandBars* pCommandBars = GetCommandBars();
	
	CXTPCommandBar* pMenuBar = pCommandBars->SetMenu(_T("Menu Bar"), IDR_MAINFRAME);
	pMenuBar->SetFlags(xtpFlagHideMinimizeBox | xtpFlagHideMaximizeBox | xtpFlagIgnoreSetMenuMessage);

	//SetMenu(0);
	
	CXTPToolBar* pCommandBar = (CXTPToolBar*)pCommandBars->Add(_T("Standard"), xtpBarTop);
	if (!pCommandBar ||
		!pCommandBar->LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	CXTPToolBar* pSearchBar = (CXTPToolBar*)pCommandBars->Add(_T("Search"), xtpBarTop);
	if (!pSearchBar ||
		!pSearchBar->LoadToolBar(IDR_SEARCH))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	DockRightOf(pSearchBar, pCommandBar);

	pCommandBar = (CXTPToolBar*)pCommandBars->Add(_T("Switch Theme"), xtpBarTop);
	if (!pCommandBar ||
		!pCommandBar->LoadToolBar(IDR_SWITCH))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}
	DockRightOf(pCommandBar, pSearchBar);

	m_paneManager.InstallDockingPanes(this);

	CXTPDockingPane* A = m_paneManager.CreatePane(IDS_TITLE_HIS, CRect(0, 0,200, 120), xtpPaneDockLeft);
	CXTPDockingPane* B = m_paneManager.CreatePane(IDS_TITLE_SHELL, CRect(0, 0,200, 120), xtpPaneDockBottom, A);
	CXTPDockingPane* C = m_paneManager.CreatePane(IDS_TITLE_NOTEPAD, CRect(0, 0,200, 120), xtpPaneDockRight);
	CXTPDockingPane* D = m_paneManager.CreatePane(IDS_TITLE_SOURCE, CRect(0, 0,200, 120), xtpPaneDockBottom, C);
	CXTPDockingPane* E = m_paneManager.CreatePane(IDS_TITLE_SEARCH, CRect(0, 0,200, 120), xtpPaneDockBottom, D);
	
	m_paneManager.AttachPane(B, A);
	m_paneManager.AttachPane(C, A);
	m_paneManager.AttachPane(D, A);
	m_paneManager.AttachPane(E, A);
	
	A->Hide();

	CXTPDockingPaneLayout layout(&m_paneManager);
	if (layout.Load(_T("Standard")))
		m_paneManager.SetLayout(&layout);


	SetTheme(m_themeCurrent);
	
	VERIFY(m_MTIClientWnd.Attach(this, TRUE));
	m_MTIClientWnd.LoadState();
	m_MTIClientWnd.EnableToolTips();
	m_MTIClientWnd.SetFlags(xtpWorkspaceHideClose | xtpWorkspaceHideArrows | xtpWorkspaceShowCloseSelectedTab);
	
	InitialNameSpace();	
	BuildEncodingMenu();

	XTPPaintManager()->RefreshMetrics();

	RefreshIcons();


	CXTPCommandBarsOptions* pOptions = pCommandBars->GetCommandBarsOptions();
	pOptions->bAlwaysShowFullMenus = FALSE;
	pCommandBars->HideCommands(uHideCmds, _countof(uHideCmds));
	pOptions->ShowKeyboardCues(xtpKeyboardCuesShowWindowsDefault);
	pCommandBars->GetToolTipContext()->SetStyle(xtpToolTipOffice); 
	pCommandBars->GetShortcutManager()->SetAccelerators(IDR_MAINFRAME);


	LoadCommandBars(_T("CommandBarsv2"));

	return 0;
}

static LPCTSTR RegisterSimilarClass(LPCTSTR lpszNewClassName,
	LPCTSTR lpszOldClassName, UINT nIDResource)
{
	
	HINSTANCE hInst = AfxGetInstanceHandle();
	WNDCLASS wc;
	if (!::GetClassInfo(hInst, lpszOldClassName, &wc)) 
	{
		TRACE(_T("Can't find window class %s\n"), lpszOldClassName);
		return NULL;
	}

	wc.lpszClassName = lpszNewClassName;
	wc.hIcon = ::LoadIcon(hInst, MAKEINTRESOURCE(nIDResource));
	if (!AfxRegisterClass(&wc)) 
	{
		TRACE(_T("Unable to register window class%s\n"), lpszNewClassName);
		return NULL;
	}
	return lpszNewClassName;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CMDIFrameWnd::PreCreateWindow(cs))
		return FALSE;

	static LPCTSTR lpszClass = NULL;
	
	if (lpszClass == NULL) 
		lpszClass = RegisterSimilarClass(_T("StylerMainWindow"), cs.lpszClass, IDR_MAINFRAME);

	if (lpszClass == NULL)
		return FALSE;
	
	cs.lpszClass = lpszClass;

	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG


void CMainFrame::SetAddress(LPCTSTR lpszUrl)
{
	CXTPControlComboBox* pCombo = GetAddressCombo();
	if (pCombo)
	{
		pCombo->SetEditText(lpszUrl);

	}
}

void OpenWindow(CString strUrl, BOOL bActivate, BOOL bReplaceBlank)
{
	if (bReplaceBlank)
	{
		CChildFrame* pFrame = (CChildFrame*)((CMainFrame*)AfxGetMainWnd())->MDIGetActive();
		if (pFrame)
		{
			CStylerView* pView = (CStylerView*)pFrame->GetActiveView();
			if (pView->GetDocument()->GetCurrentUrl() == ABOUTBLANK)
			{
				pView->GetDocument()->SetUrl(strUrl);
				pView->Navigate(strUrl);
				return;
			}
		}

	}
	

	CWinApp* pApp = AfxGetApp();

	// Get the correct document template.
	POSITION pos = pApp->GetFirstDocTemplatePosition();
	CDocTemplate* pDocTemplate = pApp->GetNextDocTemplate( pos );

	CStylerDoc* pStylerDoc = (CStylerDoc*)pDocTemplate->CreateNewDocument();
	pStylerDoc->SetUrl(strUrl);
	// Create a new frame.
	
	CFrameWnd* pFrame = pDocTemplate->CreateNewFrame(
		pStylerDoc,
		(CFrameWnd*)AfxGetMainWnd() );

	// Activate the frame.
	if (!bActivate) ((CChildFrame*)pFrame)->m_bActivate = FALSE;	
	pDocTemplate->InitialUpdateFrame( pFrame, NULL );
	CStylerView* pView = (CStylerView*)pFrame->GetActiveView();

	// Pass pointer of WebBrowser object.
	pView->SetRegisterAsBrowser( TRUE );
	pView->GetDocument()->SetUrl(strUrl);
	pView->Navigate(strUrl);
}

void CommonNavigate(CMDIChildWnd* pFrame, CString& strUrl)
{
	if (pFrame == NULL)
		OpenWindow(strUrl);
	else
	{
		CStylerView* pView = (CStylerView*)pFrame->GetActiveView();
		if (pView)
		{			
			pView->SetLoading(TRUE);
			pView->GetDocument()->SetUrl(strUrl);
			pView->Navigate(strUrl);
		}
	}

}


void CMainFrame::OnGotoUrl(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	
	CXTPControlComboBox* pCombo = (CXTPControlComboBox*)tagNMCONTROL->pControl;
	ASSERT(pCombo);
	ASSERT(pCombo->GetType() == xtpControlComboBox);

	CString strUrl = pCombo->GetEditText();
	
	strUrl.TrimLeft();
	
	if (strUrl.IsEmpty())
		return;

	int nIndex = strUrl.Find(' ');
	if (nIndex != -1)
	{
		
		CString strKeyword = strUrl.Left(nIndex);
		CString strSearch = strUrl.Mid(nIndex + 1);
		strSearch.TrimLeft();
		for (int i = 0; i < CPageSearch::m_arrEngines.GetSize(); i++)
		{
			CPageSearch::ENGINE& engine = CPageSearch::m_arrEngines[i];
			if (engine.strKeyword.CompareNoCase(strKeyword) == 0)
			{
				strUrl = engine.strSearch;
				strUrl.Replace(_T("%s"), strSearch);
				CommonNavigate(MDIGetActive(), strUrl);
				pCombo->SetEditText(strUrl);
				return;
			} 			
		}
	}

	nIndex = strUrl.Find(':');
	if(nIndex >= 0) strUrl.Replace('\\','/');
	else strUrl = _T("http://") + strUrl;

	CommonNavigate(MDIGetActive(), strUrl);
	
	if (strUrl.Right(1) == _T("/"))
		strUrl.Delete(strUrl.GetLength() - 1);

	if (pCombo->FindStringExact(0, strUrl) == CB_ERR)
		pCombo->InsertString(0, strUrl);

	*pResult = 1;
}

void CMainFrame::OnGotoSearch(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	
	CComboBoxSearch* pCombo = (CComboBoxSearch*)tagNMCONTROL->pControl;
	ASSERT(pCombo);
	ASSERT(pCombo->GetType() == xtpControlComboBox);


	int nSearch = pCombo->m_nCurrentEngine;

	CString strSearch = pCombo->GetEditText();

	if (!strSearch.IsEmpty() && nSearch >= 0 && nSearch < CPageSearch::m_arrEngines.GetSize())
	{
		CPageSearch::ENGINE& engine = CPageSearch::m_arrEngines[nSearch ];
		if (engine.strTitle == strSearch)
			return;

		CString strUrl = engine.strSearch;
		strUrl.Replace(_T("%s"), strSearch);
		OpenWindow(strUrl, TRUE, TRUE);		
	}

	*pResult = 1;

}




void CMainFrame::OnWindowCloseAll()
{
	if (m_bConfirmCloseAll)
	{
		if (AfxMessageBox(IDS_CONFIRM_CLOSEALL,  MB_YESNO | MB_ICONQUESTION ) != IDYES)
			return;
	}
	AfxGetApp()->CloseAllDocuments(FALSE); 
}

void CMainFrame::OnUpdateWindowCloseAll(CCmdUI *pCmdUI)
{
	pCmdUI->Enable((CChildFrame*)MDIGetActive() != NULL);
}

void CMainFrame::OnUpdateGotoUrl(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainFrame::OnEmptyCommand()
{
	
}


void CMainFrame::OnFavorite(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	OpenWindow(tagNMCONTROL->pControl->GetParameter(), TRUE, TRUE);
	*pResult = 1;
}

void CMainFrame::OnOpenAllItems(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;

	CString strPath = tagNMCONTROL->pControl->GetParameter();
	WIN32_FIND_DATA wfd;
	HANDLE h;
	
	h = FindFirstFile(strPath + _T("*.*"), &wfd);
	if(h != INVALID_HANDLE_VALUE)
	{
		do
		{
			CString strFile = wfd.cFileName;
			
			if((wfd.dwFileAttributes & (FILE_ATTRIBUTE_DIRECTORY|FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM))==0 &&
				strFile.Right(4).CompareNoCase(_T(".url")) == 0)
			{
				TCHAR buf[INTERNET_MAX_PATH_LENGTH];
				::GetPrivateProfileString(_T("InternetShortcut"), _T("URL"),
					_T(""), buf, INTERNET_MAX_PATH_LENGTH,
					strPath + strFile);
				
				OpenWindow(buf);
			}
		} while(FindNextFile(h, &wfd));
	} 
	FindClose(h);

	*pResult = 1;
}

void CMainFrame::OnOrganizeFavorites()
{
	CInetTools::MtlOrganizeFavorite(GetSafeHwnd());
}

void CMainFrame::OnFileWorkoffline()
{
	CInetTools::MtlSetGlobalOffline(!CInetTools::MtlIsGlobalOffline());
}

void CMainFrame::OnUpdateFileWorkoffline(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(CInetTools::MtlIsGlobalOffline());
}

void CMainFrame::OnToolsImagesfilter()
{
	CFilterDialog fd;
	fd.DoModal();
}


void CMainFrame::OnToggleDock(void)
{
	if (m_MTIClientWnd.GetPaintManager()->GetPosition() != xtpTabPositionTop)
		m_MTIClientWnd.GetPaintManager()->SetPosition(xtpTabPositionTop);
	else
		m_MTIClientWnd.GetPaintManager()->SetPosition(xtpTabPositionBottom);

	m_MTIClientWnd.SaveState();
	RecalcLayout(TRUE);

}


void CMainFrame::OnDisableMenu(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(FALSE);
}

void CMainFrame::OnViewFullscreen()
{
	if (!m_bFullScreen)
	{
		GetWindowRect(&m_rcMainFrame);

		ModifyStyle(WS_CAPTION, 0);
		// Now resize the main window
		int cxScrn   = ::GetSystemMetrics(SM_CXSCREEN);
		int cyScrn   = ::GetSystemMetrics(SM_CYSCREEN);
		int cxBorder = ::GetSystemMetrics(SM_CXBORDER);
		int cyBorder = ::GetSystemMetrics(SM_CYBORDER);
		SetWindowPos(NULL, -cxBorder, -cyBorder, cxScrn + cxBorder * 2, 
			cyScrn + cyBorder * 2, SWP_NOZORDER);
	
		RecalcLayout(TRUE);
		m_bFullScreen = TRUE;
	} else
	{
		ModifyStyle(0, WS_CAPTION);
		MoveWindow(&m_rcMainFrame);

		RecalcLayout(TRUE);
		m_bFullScreen = FALSE;
	}
}

void CMainFrame::OnUpdateViewFullscreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_bFullScreen);
}

void CMainFrame::OnFileNewBlank()
{
	OpenWindow(ABOUTBLANK);
	CXTPControlComboBox* pCombo = GetAddressCombo();
	if (pCombo) pCombo->GetEditCtrl()->SetFocus();

}

void CMainFrame::OnFileNewCurrent()
{
	CChildFrame* wndBrowserFrame = (CChildFrame*)MDIGetActive();
	if (wndBrowserFrame && wndBrowserFrame->GetActiveView())
	{
		CString str = ((CStylerView*)wndBrowserFrame->GetActiveView())->GetLocationURL();
		OpenWindow(str);

	} 
}

void CMainFrame::OnUpdateFileNewCurrent(CCmdUI *pCmdUI)
{
	pCmdUI->Enable((CChildFrame*)MDIGetActive() != NULL);
}


void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CRect rcC;	
	GetClientRect(&rcC);
	CMDIFrameWnd::OnSettingChange(uFlags, lpszSection);
	RecalcLayout(FALSE);
	RedrawWindow(FALSE);
}


void CMainFrame::OnToolsStructure()
{
	m_bShowStructure = !m_bShowStructure;
	CInetTools::SetStyleSheet(m_bShowStructure, TRUE);

	CChildFrame* wndBrowserFrame = (CChildFrame*)MDIGetActive();
	if (wndBrowserFrame && wndBrowserFrame->GetActiveView())
	{
		((CStylerView*)wndBrowserFrame->GetActiveView())->Refresh();
	}

}

void CMainFrame::OnUpdateToolsStructure(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_bShowStructure);
}





void CMainFrame::InitialNameSpace()
{
	if(CoInternetGetSession(0, &m_pSession, 0)==S_OK)
	{
		m_pFilter = (CFilterContent*)CFilterContent::CreateObject();

		m_pSession->RegisterNameSpace((LPCLASSFACTORY)m_pFilter->GetInterface(&IID_IClassFactory), 
			CLSID_FilterContent, L"http", 0, NULL, 0);

	}
}

void CMainFrame::UninitialNameSpace()
{
	if(m_pSession!=NULL)
	{
		m_pSession->UnregisterNameSpace((LPCLASSFACTORY)m_pFilter->GetInterface(&IID_IClassFactory), L"http");

		m_pSession->Release();
		m_pSession = NULL;
	
		ASSERT(m_pFilter);
		m_pFilter->InternalRelease();
		m_pFilter = NULL;
	}
}

void LoadEncoding(CMenu* pMenu)
{
	CMainFrame::m_arrEncodingPage.RemoveAll();

	TCHAR chReturn[100];
	CString strLine;
	int nIndex = 0;	
	CString strPath = GetModuleDir();

	strLine.Format(_T("line%i"), nIndex);
	BOOL bPrevSeparator = FALSE;
	int nID = ID_VIEW_ENCODING_FIRST;
	while (GetPrivateProfileString(_T("Encoding"), strLine, _T(""), chReturn, 100, strPath + _T("encoding.ini")) > 0)
	{
		CString strReturn(chReturn);
		if (!strReturn.IsEmpty())
		{
			int n = strReturn.Find(',');
			if (n != -1)
			{
				CString strPage = strReturn.Left(n);
				strPage.TrimLeft(); strPage.TrimRight();
				CString strDesc = strReturn.Right(strReturn.GetLength() - n - 1);
				strDesc.TrimLeft(); strDesc.TrimRight();

				if (!strDesc.IsEmpty() && !strPage.IsEmpty())
				{
					if (bPrevSeparator && nID != ID_VIEW_ENCODING_FIRST)
						pMenu->AppendMenu(MF_SEPARATOR);
					pMenu->AppendMenu(MF_STRING, nID++, strDesc);

					CMainFrame::m_arrEncodingPage.Add(strPage);

					bPrevSeparator = FALSE;
				} 
			} else
				bPrevSeparator = TRUE;
		}
		strLine.Format(_T("line%i"), ++nIndex);
	}

}

void CMainFrame::OnViewEncodingAuto() 
{
	DWORD           sz;
	HKEY            hKey;
	DWORD           dwSize = sizeof(DWORD);

	if(RegOpenKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\International"), &hKey) != ERROR_SUCCESS)
	{
		TRACE0("Global settings not found\n");
		return ;
	}

	if(RegQueryValueEx(hKey, _T("AutoDetect"), NULL, NULL, (LPBYTE)&sz, &dwSize) == ERROR_SUCCESS)
	{
		//set new offline value
		m_bAutoSelect = sz = !(BOOL)sz;
	} else
		m_bAutoSelect = sz = !m_bAutoSelect;
	
	RegSetValueEx(hKey, _T("AutoDetect"), NULL, REG_DWORD, (LPBYTE)(&sz), dwSize);

		
	CChildFrame* wndBrowserFrame = (CChildFrame*)MDIGetActive();
	if (wndBrowserFrame && wndBrowserFrame->GetActiveView())
	{
		((CStylerView*)(wndBrowserFrame->GetActiveView()))->Refresh2(1);
	} 

	RegCloseKey(hKey);
	
}


void CMainFrame::BuildEncodingMenu()
{
	/*CXTPControl* pControl = GetCommandBars()->FindControl(xtpControlButton, ID_VIEW_ENCODING, FALSE, TRUE);
	ASSERT(pControl);
	
	if (pControl)
	{		
		CMenu menuPopup;
		menuPopup.CreatePopupMenu();
		
		LoadEncoding(&menuPopup);

		if (menuPopup.GetMenuItemCount())
		{
			menuPopup.InsertMenu(0, MF_BYPOSITION | MF_STRING,  ID_VIEW_ENCODING_AUTOSELECT, "Auto Select");
			menuPopup.InsertMenu(1, MF_BYPOSITION | MF_SEPARATOR);
			
			CXTPControlPopup* pPopup = (CXTPControlPopup*)pControl->GetControls()->SetControlType(pControl, xtpControlPopup);
			pPopup->SetCommandBar(&menuPopup);
			pPopup->SetID(0);
			
		}						
	
	}*/
	
	
	m_bAutoSelect = FALSE;
	HKEY hKey;
	if(RegOpenKey(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Internet Explorer\\International"), &hKey) == ERROR_SUCCESS)
	{
		
		DWORD dwSize = sizeof(m_bAutoSelect);
		RegQueryValueEx(hKey, _T("AutoDetect"), NULL, NULL, (LPBYTE)&m_bAutoSelect, &dwSize);
		RegCloseKey(hKey);
	}


}


void CMainFrame::OnUpdateViewEncodingAuto(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_bAutoSelect);
}


void CMainFrame::OnToolsPopupfilter()
{
	CPopupFilter fd;
	fd.DoModal();
}

void CMainFrame::OnClose() 
{

	if (m_bConfirmExit && MDIGetActive())
	{
		if (AfxMessageBox(IDS_CONFIRM_CLOSEALL,  MB_YESNO | MB_ICONQUESTION ) != IDYES)
			return;
	}

	CComboBoxURL* pComboURL = DYNAMIC_DOWNCAST(CComboBoxURL, GetAddressCombo());
	if (pComboURL) pComboURL->SaveTypedURL();

	if (m_nStartup == STARTUP_LASTVISITED)
	{
		CString strPopups;
		int nIndex = AFX_IDM_FIRST_MDICHILD;				

		CWnd* pMDIClient = CWnd::FromHandle(m_hWndMDIClient);
		CChildFrame* pWnd = (CChildFrame*) pMDIClient->GetDlgItem(nIndex);

		while (pWnd)
		{
			CStylerView* pView = (CStylerView*)pWnd->GetActiveView();
			ASSERT(pView);			

			if (pView) strPopups += pView->GetDocument()->GetCurrentUrl() + _T(";");
			
			pWnd = (CChildFrame*) pMDIClient->GetDlgItem(++nIndex);
		}
		
		AfxGetApp()->WriteProfileString(_T("MainFrame"), _T("LastVisited"), strPopups);
		
	}

	CWindowPlacement(this, _T("Main Frame")).SaveWindowPos();
	
	SaveCommandBars(_T("CommandBarsv2"));

	CMDIFrameWnd::OnClose();
}



void SetDefault(LPCTSTR lpszKey, BOOL = TRUE)
{
	HKEY            hKey, hSubKey, hSubKey2;

	if(RegOpenKey(HKEY_CLASSES_ROOT, lpszKey, &hKey) == ERROR_SUCCESS)
	{
		DWORD dwRes;
		TCHAR lpszModule[_MAX_PATH];
		HINSTANCE hInstance = AfxGetInstanceHandle();
		
		RegSetValueEx(hKey, _T(""), NULL, REG_SZ, (LPBYTE)(_T("Styler")), 7 * sizeof(TCHAR));
		
		//open
		RegCreateKeyEx(hKey, _T("open"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,  &hSubKey, &dwRes);
		RegCreateKeyEx(hSubKey, _T("command"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,  &hSubKey2, &dwRes);
		
		if (GetModuleFileName(hInstance, lpszModule + 1, _MAX_PATH))
		{
			*lpszModule = _T('\"');
			#if (_MSC_VER > 1310) // VS2005
			_tcscat_s(lpszModule, _MAX_PATH, _T("\" \"%1\""));
			#else
			_tcscat(lpszModule, _T("\" \"%1\""));
			#endif
			RegSetValueEx(hSubKey2, _T(""), NULL, REG_SZ, (LPBYTE)(lpszModule), ((int)_tcsclen(lpszModule) + 1) * sizeof(TCHAR));
		}
		
		RegCloseKey(hSubKey);
		RegCloseKey(hSubKey2);
		
		
		//myie
		RegCreateKeyEx(hKey, _T("Styler"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,  &hSubKey, &dwRes);
		RegCloseKey(hKey);
		RegCreateKeyEx(hSubKey, _T("command"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,  &hKey, &dwRes);
		
		
		if (GetModuleFileName(hInstance, lpszModule+1, _MAX_PATH))
		{
			*lpszModule = _T('\"');
			#if (_MSC_VER > 1310) // VS2005
			_tcscat_s(lpszModule, _MAX_PATH, _T("\" \"%1\""));
			#else
			_tcscat(lpszModule, _T("\" \"%1\""));
			#endif
			RegSetValueEx(hKey, _T(""), NULL, REG_SZ, (LPBYTE)(lpszModule), ((int)_tcsclen(lpszModule) + 1) * sizeof(TCHAR));
			
		}
		
		RegCloseKey(hSubKey);
		RegCloseKey(hKey);
	}

}



void CMainFrame::OnSetDefault()
{
	SetDefault(_T("htmlfile\\shell"));
	SetDefault(_T("InternetShortcut\\shell"));
	SetDefault(_T("mhtmlfile\\shell"));
	SetDefault( _T("http\\shell"));
	SetDefault( _T("https\\shell"));
	SetDefault( _T("file\\shell"));
	SetDefault( _T("ftp\\shell"));	
}

void CMainFrame::Properties(int nPage)
{
	COptionsDialog od;
	
	CPageGeneral pageGeneral;

	int nDocking = pageGeneral.m_nDocking = m_MTIClientWnd.GetPaintManager()->GetPosition()==xtpTabPositionBottom? 1 : 0;
	pageGeneral.m_bConfirmExit = m_bConfirmExit;
	pageGeneral.m_bConfirmCloseAll = m_bConfirmCloseAll;
	pageGeneral.m_bOneInstance = m_bOneInstance;
	pageGeneral.m_nStartup = m_nStartup;
	pageGeneral.m_bRestoreWindowPos = m_bRestoreWindowPos;

	od.AddPage(&pageGeneral);

	CPageKeyboard pageKeyboard;
	od.AddPage(&pageKeyboard);

	CPageMouse pageMouse;
	od.AddPage(&pageMouse);

	CPageSearch pageSearch;
	od.AddPage(&pageSearch);
	
	od.SetActivePage(nPage);

	if (od.DoModal() == IDOK)
	{
		if (pageGeneral.m_nDocking != nDocking)
			OnToggleDock();
		
		m_bConfirmExit = pageGeneral.m_bConfirmExit;
		m_bConfirmCloseAll = pageGeneral.m_bConfirmCloseAll;
		m_bOneInstance = pageGeneral.m_bOneInstance;
		m_nStartup = pageGeneral.m_nStartup;
		m_bRestoreWindowPos = pageGeneral.m_bRestoreWindowPos;

		Save();
	}
}

void CMainFrame::OnSearchList()
{
	Properties(3);
}


void CMainFrame::OnStylerOptions()
{
	Properties(0);

}

void CMainFrame::Load()
{
	m_bConfirmExit = AfxGetApp()->GetProfileInt(_T("MainFrame"), _T("ConfirmExit"), m_bConfirmExit);
	m_bConfirmCloseAll = AfxGetApp()->GetProfileInt(_T("MainFrame"), _T("ConfirmCloseAll"), m_bConfirmCloseAll);
	m_bOneInstance = AfxGetApp()->GetProfileInt(_T("MainFrame"), _T("OneInstance"), m_bOneInstance);
	m_nStartup = AfxGetApp()->GetProfileInt(_T("MainFrame"), _T("Startup"), m_nStartup);
	m_bRestoreWindowPos = AfxGetApp()->GetProfileInt(_T("MainFrame"), _T("RestoreWindowPos"), m_bRestoreWindowPos);
	m_themeCurrent = (XTPPaintTheme)AfxGetApp()->GetProfileInt(_T("MainFrame"), _T("Theme"), m_themeCurrent);


}
void CMainFrame::Save()
{
	AfxGetApp()->WriteProfileInt(_T("MainFrame"), _T("ConfirmExit"), m_bConfirmExit);
	AfxGetApp()->WriteProfileInt(_T("MainFrame"), _T("ConfirmCloseAll"), m_bConfirmCloseAll);
	AfxGetApp()->WriteProfileInt(_T("MainFrame"), _T("OneInstance"), m_bOneInstance);
	AfxGetApp()->WriteProfileInt(_T("MainFrame"), _T("Startup"), m_nStartup);
	AfxGetApp()->WriteProfileInt(_T("MainFrame"), _T("RestoreWindowPos"), m_bRestoreWindowPos);
	AfxGetApp()->WriteProfileInt(_T("MainFrame"), _T("Theme"), m_themeCurrent);
}


LRESULT CMainFrame::OnShellOpen(WPARAM, LPARAM)
{
	try
	{
		HANDLE hMapping = CreateFileMapping( INVALID_HANDLE_VALUE, NULL,
			PAGE_READWRITE, 0, 2560, _T("STYLERSHARE"));
		
		if (hMapping == NULL)
		{
			TRACE(_T("Fail to create share memory!"));
			return FALSE;
		}

		LPTSTR lpData = (LPTSTR) MapViewOfFile(hMapping,FILE_MAP_ALL_ACCESS,0,0,0);
		if (lpData == NULL)
		{
			TRACE(_T("MapViewOfFile Fail"));
			CloseHandle(hMapping);
			return FALSE;
		}

		CString	strURL = lpData;
		UnmapViewOfFile(lpData);
		CloseHandle(hMapping);
		
		TCHAR buf[INTERNET_MAX_PATH_LENGTH];

		if(strURL.Right(4).CompareNoCase(_T(".url")) == 0)
		{
			::GetPrivateProfileString(_T("InternetShortcut"), _T("URL"),
				_T(""), buf, INTERNET_MAX_PATH_LENGTH, strURL);

			strURL =  buf;
		}

		OpenWindow(strURL);

	}
	catch(...)
	{
	}

	return TRUE;
}



void CMainFrame::OpenLastVisited()
{
	CString strBuffer = AfxGetApp()->GetProfileString(_T("MainFrame"), _T("LastVisited"));
	
	if (!strBuffer.IsEmpty())
	{
		LPTSTR pBuffer = strBuffer.GetBuffer(0);
		
		TCHAR* lpszContext = 0;

		TCHAR* token = STRTOK_S(pBuffer, _T(";"), &lpszContext);		
		while (token)
		{
			OpenWindow(token);
			token = STRTOK_S( NULL, _T(";"), &lpszContext);
		}		
	}	
}

void CMainFrame::OnUpdateIndicator(CCmdUI *pCmdUI)
{
	ASSERT_KINDOF(CXTPStatusBar, pCmdUI->m_pOther);
	((CIndicatorStatusBar*) pCmdUI->m_pOther)->SetProgress(0);

}


void CMainFrame::OnDestroy()
{
	CXTPDockingPaneLayout layout(&m_paneManager);
	m_paneManager.GetLayout(&layout);
	layout.Save(_T("Standard"));

	m_MTIClientWnd.Detach();
		

	CMDIFrameWnd::OnDestroy();
}

CXTPControlComboBox* GetAddressCombo()
{
	 return (CXTPControlComboBox*) GetMainFrame()->GetCommandBars()->FindControl(xtpControlComboBox, ID_GOTO_URL, FALSE, FALSE);
}


void CMainFrame::SetDockingPaneIcon(UINT nIDPane, UINT nIDIcon)
{
	CXTPImageManagerIcon* pIcon = XTPImageManager()->GetImage(nIDIcon);
	m_paneManager.SetIcon(nIDPane, pIcon->GetIcon());

}

void CMainFrame::RefreshIcons()
{
	
	XTPImageManager()->SetIcons(IDR_MAINFRAME, IDR_MAINFRAME);
	XTPImageManager()->SetIcons(IDR_SEARCH, IDR_SEARCH);
	XTPImageManager()->SetIcons(IDR_MENUBAR, IDR_MENUBAR);
		
	XTPPaintManager()->GetIconsInfo()->bUseDisabledIcons = TRUE;	

	SetDockingPaneIcon(IDS_TITLE_SOURCE, ID_EXPLORER_SOURCE);
	SetDockingPaneIcon(IDS_TITLE_SHELL, ID_EXPLORER_FOLDER);
	SetDockingPaneIcon(IDS_TITLE_HIS, ID_EXPLORER_HISTORY);
	SetDockingPaneIcon(IDS_TITLE_NOTEPAD, ID_EXPLORER_NOTEPAD);
	SetDockingPaneIcon(IDS_TITLE_SEARCH, ID_EXPLORER_SEARCH);
}

void CMainFrame::SetTheme(XTPPaintTheme theme)
{
	m_themeCurrent = theme;
	m_paneManager.SetTheme(
		m_themeCurrent == xtpThemeOffice2000 ? xtpPaneThemeDefault: 
		m_themeCurrent == xtpThemeOfficeXP ? xtpPaneThemeOffice: 
		m_themeCurrent == xtpThemeOffice2003 ? xtpPaneThemeOffice2003: 
		m_themeCurrent == xtpThemeOffice2007 ? xtpPaneThemeOffice2007: 
		m_themeCurrent == xtpThemeRibbon ? xtpPaneThemeOffice2007: 
		m_themeCurrent == xtpThemeWhidbey ? xtpPaneThemeVisualStudio2005: 
			xtpPaneThemeNativeWinXP);

	CXTPPaintManager::SetTheme(theme);

	EnableOffice2007Frame(theme == xtpThemeRibbon || theme == xtpThemeOffice2007 ? GetCommandBars() : 0);

	if (theme == xtpThemeOffice2000 || theme == xtpThemeNativeWinXP)
	{
		((CXTPDefaultTheme*)XTPPaintManager())->m_bSelectImageInPopupBar = TRUE;
		((CXTPDefaultTheme*)XTPPaintManager())->m_bThickCheckMark = TRUE;
		XTPPaintManager()->GetIconsInfo()->bUseFadedIcons = FALSE;
	}

	XTPPaintManager()->GetIconsInfo()->bUseDisabledIcons = TRUE;	

	RecalcLayout(FALSE);
	GetCommandBars()->RedrawCommandBars();
	RedrawWindow();
}

void CMainFrame::OnTheme(UINT nTheme)
{
	SetTheme((XTPPaintTheme)(nTheme - ID_THEME_DEFAULT));
}

void CMainFrame::OnUpdateTheme(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(int(pCmdUI->m_nID - ID_THEME_DEFAULT) == m_themeCurrent? TRUE: FALSE);
}

void CMainFrame::OnSwitchTheme()
{
	if (m_themeCurrent == xtpThemeRibbon) 
		SetTheme(xtpThemeOffice2000); 
	else
		SetTheme((XTPPaintTheme)(m_themeCurrent + 1));
}

LRESULT CMainFrame::OnTabbarMouseMsg(WPARAM wParam,LPARAM lParam)
{
	CPoint point = CPoint((DWORD)lParam);
	
	CXTPTabManagerItem* pItem =  m_MTIClientWnd.HitTest(point);
	if (pItem)
	{	
		CWnd* pFrame = CWnd::FromHandle(pItem->GetHandle());
		if (GetActiveFrame() != pFrame)
		{
			MDIActivate(pFrame);
			m_MTIClientWnd.Refresh();
		}

		int nCommand = CMouseManager::FindMouseCommand(MOUSE_AREA_TAB, (DWORD)wParam);
		if (nCommand != -1)
		{
			PostMessage(WM_COMMAND, nCommand);
			return TRUE;
		}

		if (wParam == WM_RBUTTONDOWN)
		{

			CMenu menuPopup;
			menuPopup.LoadMenu(IDR_WORKSPACE_POPUP);		

			m_MTIClientWnd.WorkspaceToScreen(&point);
			
			CXTPCommandBars::TrackPopupMenu(menuPopup.GetSubMenu(0), TPM_RIGHTBUTTON, point.x, point.y, this);
			
			m_MTIClientWnd.Refresh();
			return TRUE;
		}


		return FALSE;
	}
	
	int nCommand = CMouseManager::FindMouseCommand(MOUSE_AREA_TABBAR, (DWORD)wParam);
	if (nCommand != -1)
	{
		PostMessage(WM_COMMAND, nCommand);
		return TRUE;
	}

	if (wParam == WM_RBUTTONDOWN)
	{
		CMenu menuPopup;
		menuPopup.CreatePopupMenu();
		menuPopup.AppendMenu(MF_STRING, ID_WINDOW_CLOSE_ALL, _T("&Close All"));
		menuPopup.AppendMenu(MF_STRING, ID_TOGGLE_DOCK, _T("&Toggle Docking"));
	
		m_MTIClientWnd.WorkspaceToScreen(&point);
		CXTPCommandBars::TrackPopupMenu(&menuPopup, TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
		
		m_MTIClientWnd.Refresh();
		return TRUE;
	}

	return FALSE;
}


LRESULT CMainFrame::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
{
	if (wParam != XTP_DPN_SHOWWINDOW)
	{	
		return FALSE;
	}

	CXTPDockingPane* pPane = (CXTPDockingPane*)lParam;
	if (!pPane->IsValid())
	{
		
		//int nIndex = pPane->GetID() - IDS_TITLE_SEARCH;
		switch(pPane->GetID()) 
		{
		case IDS_TITLE_HIS:	
			if (!m_bars.wndHistory.GetWindow()->m_hWnd)
			{
				m_bars.wndHistory.Create(this);
				m_bars.wndHistory.Initialize();
			}
			pPane->Attach(m_bars.wndHistory.GetWindow());
			break;
		case IDS_TITLE_SHELL:
			if (!m_bars.wndShell.m_hWnd)
			{
				m_bars.wndShell.Create(WS_VISIBLE|WS_CHILD, CRect(0,0,0,0), this, 100);
				m_bars.wndShell.Init();
			}
			pPane->Attach(&m_bars.wndShell);
			break;
		case IDS_TITLE_NOTEPAD:
			
			if (!m_bars.wndNotepad.m_hWnd)
			{
				m_bars.wndNotepad.Create(this);
			}
			pPane->Attach(&m_bars.wndNotepad);
			break;
		case IDS_TITLE_SOURCE:
			if (!m_bars.wndSource.m_hWnd)
			{
				m_bars.wndSource.Create(this);
			}
			{			
				CChildFrame* wndBrowserFrame = (CChildFrame*)MDIGetActive();		
				if (wndBrowserFrame && wndBrowserFrame->GetActiveView())
				{
					m_bars.wndSource.Refresh((CStylerView*)wndBrowserFrame->GetActiveView(), TRUE);
				}
			}

			pPane->Attach(&m_bars.wndSource);
			break;
		case IDS_TITLE_SEARCH:
			if (!m_bars.wndSearch.m_hWnd)
			{
				m_bars.wndSearch.Create(_T("STATIC"), _T(""), WS_CHILD|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, CRect(0, 0, 0, 0), this, 0);
				m_bars.wndSearch.OnViewSearch();
			}
			pPane->Attach(&m_bars.wndSearch);
			break;
		}

	}
	return TRUE;
}


void CMainFrame::OnExploreSearch()
{
	m_paneManager.ShowPane(IDS_TITLE_SEARCH);
}

void CMainFrame::OnExploreHistory()
{
	m_paneManager.ShowPane(IDS_TITLE_HIS);	
}

void CMainFrame::OnExploreFolder()
{
	m_paneManager.ShowPane(IDS_TITLE_SHELL);	
}

void CMainFrame::OnExploreSource()
{
	m_paneManager.ShowPane(IDS_TITLE_SOURCE);	

}

void CMainFrame::OnExploreNotepad()
{
	m_paneManager.ShowPane(IDS_TITLE_NOTEPAD);		
}


void CMainFrame::OnCustomize()
{
	CXTPCustomizeSheet cs(GetCommandBars());
	
	CXTPCustomizeOptionsPage pageOptions(&cs);
	cs.AddPage(&pageOptions);
	
	CXTPCustomizeCommandsPage* pCommands = cs.GetCommandsPage();
	pCommands->AddCategories(IDR_CUSTOMIZE);

	pCommands->InsertAllCommandsCategory();
	pCommands->InsertBuiltInMenus(IDR_MAINFRAME);
	pCommands->InsertNewMenuCategory();
	
	cs.DoModal();
}

LRESULT CMainFrame::OnControlRButtonUp(WPARAM, LPARAM lParam)
{
	CXTPControl* pControl = (CXTPControl*)lParam;
	if (pControl->GetID() == ID_FAVORITE_LINK)
	{
		CControlFavoriteLink* pLink = DYNAMIC_DOWNCAST(CControlFavoriteLink, pControl);
		if (!pLink)
			return FALSE;

		CMenu menu;
		menu.LoadMenu(IDR_MENU_FAVORITE_LINK);
		
		CPoint pt;
		GetCursorPos(&pt);

		UINT nReturn = CXTPCommandBars::TrackPopupMenu(menu.GetSubMenu(0), TPM_NONOTIFY|TPM_RECURSE|TPM_RETURNCMD, pt.x, pt.y, this);

		switch (nReturn)
		{
			case ID_LINK_OPEN:
				XTPMouseManager()->SendTrackLost();
				pControl->OnExecute();
				break;

			case ID_LINK_PROPERTIES:
				XTPMouseManager()->SendTrackLost();
				ShellExecute(m_hWnd, _T("properties"), pLink->m_strFileName, NULL, NULL, SW_SHOWNORMAL);
				
				break;
		}
		return TRUE;

	}

	return FALSE;
}

int CMainFrame::OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl)
{
	class CXTPControlFriendly: public CXTPControl
	{
		friend class CMainFrame;
	};
	

	if (lpCreateControl->bToolBar)
	{
		CXTPToolBar* pToolBar = DYNAMIC_DOWNCAST(CXTPToolBar, lpCreateControl->pCommandBar);
		if (!pToolBar)
			return FALSE;

		if (lpCreateControl->nID == ID_TOOLS_SWITCHTHEME && pToolBar->GetBarID() == IDR_SWITCH)
		{
			lpCreateControl->buttonStyle = xtpButtonCaption;
			lpCreateControl->controlType = xtpControlSplitButtonPopup;
			return TRUE;
		}


		if (pToolBar->GetBarID() == IDR_MAINFRAME &&
			(
			lpCreateControl->nID == ID_EDIT_CUT ||
			lpCreateControl->nID == ID_EDIT_COPY ||
			lpCreateControl->nID == ID_EDIT_PASTE ||
			
			lpCreateControl->nID == ID_EXPLORER_SOURCE ||
			lpCreateControl->nID == ID_EXPLORER_FOLDER ||
			lpCreateControl->nID == ID_EXPLORER_HISTORY ||
			lpCreateControl->nID == ID_EXPLORER_NOTEPAD))
		{
			CXTPControlButton* pButton = (CXTPControlButton*)CXTPControlButton::CreateObject();
			pButton->SetHideFlags(xtpHideCustomize);
			lpCreateControl->pControl = pButton;
			return TRUE;
		}

		if (lpCreateControl->nID == ID_GOTO_URL && pToolBar->GetBarID() == IDR_MAINFRAME)
		{
			CComboBoxURL* pComboAddress = new CComboBoxURL(GetCommandBars());
			pComboAddress->UpdateComboBox();
			pComboAddress->SetWidth(250);
			pComboAddress->SetDropDownListStyle();
			pComboAddress->EnableShellAutoComplete();
		
			lpCreateControl->pControl = pComboAddress;
			return TRUE;
		}

		if (lpCreateControl->nID == ID_GOTO_SEARCH && pToolBar->GetBarID() == IDR_SEARCH)
		{
			CComboBoxSearch* pComboSearch = new CComboBoxSearch(GetCommandBars());
			pComboSearch->SetStyle(xtpComboLabel);
			pComboSearch->SetDropDownListStyle();
			pComboSearch->SetWidth(150);
			pComboSearch->SetFlags(xtpFlagManualUpdate);

			lpCreateControl->pControl = pComboSearch;
			return TRUE;
		}

		if (lpCreateControl->nID == ID_LINKS && pToolBar->GetBarID() == IDR_MAINFRAME)
		{
			CXTPControlPopup* pLinks = CXTPControlPopup::CreateControlPopup(xtpControlButtonPopup);
			pLinks->SetFlags(xtpFlagManualUpdate);
		
			CXTPPopupBar* pPopup = CXTPPopupBar::CreatePopupBar(GetCommandBars());

			CString strFavoriteDir;
			CInetTools::GetFavoriteFolder(strFavoriteDir);

			pPopup->GetControls()->Add(new CControlFavoriteFolder(strFavoriteDir), ID_FAVORITES_EX);

			pLinks->SetCommandBar(pPopup);

			pPopup->InternalRelease();

			lpCreateControl->pControl = pLinks;
 
			return TRUE;
		}
	} 
	else
	{
		if (lpCreateControl->nID == ID_FAVORITES_EX)
		{
			CString strFavoriteDir;
			CInetTools::GetFavoriteFolder(strFavoriteDir);

			lpCreateControl->pControl = new CControlFavoriteFolder(strFavoriteDir);
			return TRUE;
			 
		}

	}

	if (lpCreateControl->nID == ID_VIEW_ENCODING)
	{		
		
		CXTPControlPopup* pControl = CXTPControlPopup::CreateControlPopup(lpCreateControl->bToolBar? xtpControlButtonPopup: xtpControlPopup);
		
		CMenu menuPopup;
		menuPopup.CreatePopupMenu();
		
		LoadEncoding(&menuPopup);
		
		if (menuPopup.GetMenuItemCount())
		{
			menuPopup.InsertMenu(0, MF_BYPOSITION | MF_STRING,  ID_VIEW_ENCODING_AUTOSELECT, _T("Auto Select"));
			menuPopup.InsertMenu(1, MF_BYPOSITION | MF_SEPARATOR);
			
			
			pControl->SetCommandBar(&menuPopup);
			pControl->SetFlags(xtpFlagManualUpdate);
		} else
		{
			CXTPPopupBar* pPopupBar = CXTPPopupBar::CreatePopupBar(GetCommandBars());
			pControl->SetCommandBar(pPopupBar);
			pPopupBar->InternalRelease();

			pControl->SetVisible(FALSE);
		}
		
		if (lpCreateControl->bToolBar)
			pControl->SetHideFlags(xtpHideCustomize);

		lpCreateControl->pControl = pControl;
		return TRUE;
	}


	return FALSE;

}



CWindowPlacement::CWindowPlacement(CWnd* pOwner, CString strEntry)
{
	ASSERT(!strEntry.IsEmpty() && pOwner);
	m_pOwner = pOwner;
	m_strEntry = strEntry;
}

void CWindowPlacement::ShowWindow(int nCmdShow, BOOL bRestore)
{
	if (bRestore )
    {		
        WINDOWPLACEMENT* lpwndpl;
        UINT nBytes;

        if ( AfxGetApp()->GetProfileBinary( m_strEntry,
                 _T("WndPlacement"), ( LPBYTE* )&lpwndpl, &nBytes ) )
        {
            // Only restore if window intersects the screen
			if ( CRect().IntersectRect(&lpwndpl->rcNormalPosition, CXTPWindowRect(GetDesktopWindow()) ) )
            {
                if (lpwndpl->showCmd == SW_MAXIMIZE) 
					nCmdShow = SW_MAXIMIZE;

                m_pOwner->SetWindowPlacement( lpwndpl );
            }

            delete lpwndpl;
        }
    }
	m_pOwner->ShowWindow(nCmdShow);
}

void CWindowPlacement::SaveWindowPos()
{
	WINDOWPLACEMENT wndpl = { sizeof(WINDOWPLACEMENT) };

	if ( m_pOwner->GetWindowPlacement( &wndpl ) )
	{
		AfxGetApp()->WriteProfileBinary( m_strEntry,
			_T("WndPlacement"), ( LPBYTE )&wndpl, wndpl.length );
	}
}
