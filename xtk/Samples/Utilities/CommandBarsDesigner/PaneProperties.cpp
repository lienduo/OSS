// PaneProperties.cpp : implementation file
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
#include "CommandBarsDesigner.h"
#include "PaneProperties.h"

#include "ResourceManager.h"
#include "DialogListEditor.h"
#include "PropertyItemFlags.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

LPCTSTR lpStyles[] = {_T("xtpButtonAutomatic"), _T("xtpButtonCaption"), _T("xtpButtonIcon"), _T("xtpButtonIconAndCaption"), _T("xtpButtonIconAndCaptionBelow"), _T("xtpButtonCaptionAndDescription") };
LPCTSTR lpDropDownStyles[] = {_T("DropDown"), _T("DropDownList")};
LPCTSTR lpVisibility[] = {_T("Always visible in menus"), _T("Visible if recently used")};

AFX_INLINE BOOL GetBoolValue(CXTPPropertyGridItem* pItem) {
	return ((CXTPPropertyGridItemBool*)pItem)->GetBool();
}
AFX_INLINE int GetFlagsValue(CXTPPropertyGridItem* pItem) {
	return ((CXTPPropertyGridItemFlags*)pItem)->GetFlags();
}
AFX_INLINE int GetNumberValue(CXTPPropertyGridItem* pItem) {
	return ((CXTPPropertyGridItemNumber*)pItem)->GetNumber();
}
AFX_INLINE int GetEnumValue(CXTPPropertyGridItem* pItem) {
	return ((CXTPPropertyGridItemEnum*)pItem)->GetEnum();
}




/////////////////////////////////////////////////////////////////////////////
// CPaneProperties

CPaneProperties::CPaneProperties()
{
	m_pCommandBar = NULL;
	m_pActiveCommandBars = NULL;

	m_bApplyForGroup = FALSE;
}

CPaneProperties::~CPaneProperties()
{
}


BEGIN_MESSAGE_MAP(CPaneProperties, CWnd)
	//{{AFX_MSG_MAP(CPaneProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_PANEPROPERTIES_CATEGORIZED, OnPanePropertiesCategorized)
	ON_UPDATE_COMMAND_UI(ID_PANEPROPERTIES_CATEGORIZED, OnUpdatePanePropertiesCategorized)
	ON_COMMAND(ID_PANEPROPERTIES_ALPHABETIC, OnPanePropertiesAlphabetic)
	ON_UPDATE_COMMAND_UI(ID_PANEPROPERTIES_ALPHABETIC, OnUpdatePanePropertiesAlphabetic)
	ON_COMMAND(ID_PANEPROPERTIES_PAGES, OnPanePropertiesPages)
	ON_UPDATE_COMMAND_UI(ID_PANEPROPERTIES_PAGES, OnUpdatePanePropertiesPages)
	//}}AFX_MSG_MAP
	ON_MESSAGE(XTPWM_PROPERTYGRID_NOTIFY, OnGridNotify)
END_MESSAGE_MAP()


void CPaneProperties::Refresh(CXTPCommandBar* pCommandBar)
{
	m_pActiveCommandBars = GetMainFrame()? GetMainFrame()->GetActiveCommandBars(): NULL;

	m_pCommandBar = pCommandBar;
	m_pControl = NULL;

	m_wndPropertyGrid.BeginUpdate(m_stateExpanding);

	if (pCommandBar)
	{
		RefreshCommandBarProperties();
	} else
	{
		RefreshControlProperties();
	}

	m_wndPropertyGrid.EndUpdate(m_stateExpanding);
}



void CPaneProperties::FillConstraintsToolbarsID(CXTPPropertyGridItem* pItem)
{
	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
	CXTPCommandBars* pCommandBars = GetMainFrame()->GetActiveCommandBars();

	ASSERT(pCommandBars);

	for (int i = 0; i < pCommandBars->GetCount(); i++)
	{
		CXTPCommandBar* pCommandBar = pCommandBars->GetAt(i);

		if (pCommandBar->GetType() == xtpBarTypeNormal)
		{
			pItem->GetConstraints()->AddConstraint(pFrame->ResourceManager()->GetStringID(pCommandBar->GetBarID()));
		}
	}
}

void CPaneProperties::FillConstraintsID(CXTPPropertyGridItem* pItem)
{
	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
	CMapResources* pResources = pFrame->ResourceManager()->GetResources();

	POSITION pos = pResources->GetStartPosition();
	while (pos)
	{
		CResourceInfo* pInfo;
		CString strCaption;
		pResources->GetNextAssoc(pos, strCaption, (CObject*&)pInfo);

		pItem->GetConstraints()->AddConstraint(strCaption);
	}
	pItem->GetConstraints()->Sort();
}

void CPaneProperties::FillConstraintsActionsID(CXTPPropertyGridItem* pItem)
{
	CXTPCommandBars* pCommandBars = GetMainFrame()->GetActiveCommandBars();
	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
	CResourceManager* pResourceManager = pFrame->ResourceManager();

	for (int i = 0; i < pCommandBars->GetActions()->GetCount(); i++)
	{
		int nID = pCommandBars->GetActions()->GetAt(i)->GetID();
		CString strCaption = pResourceManager->GetStringID(nID);
		

		pItem->GetConstraints()->AddConstraint(strCaption);
	}
	pItem->GetConstraints()->Sort();

}

void CPaneProperties::FillActionProperties(CXTPPropertyGridItem* pCategory, CXTPControlAction* pAction)
{
	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();

	pCategory->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_ACTION_CAPTION, pAction->GetCaption()));

	CString strIconID;
	if (pAction->GetIconId() != pAction->GetID())
		strIconID = pFrame->ResourceManager()->GetStringID(pAction->GetIconId());

	CXTPPropertyGridItem* pItemControlIconId = pCategory->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_ACTION_ICONID, strIconID));
	pItemControlIconId->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
	FillConstraintsID(pItemControlIconId);

	pCategory->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_ACTION_DESCRIPTION, pAction->GetDescription()));
	pCategory->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_ACTION_TOOLTIP, pAction->GetTooltip()));

	CXTPPropertyGridItem* pItemControlCategory = pCategory->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_ACTION_CATEGORY, pAction->GetCategory()));
	pItemControlCategory->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
	
	CXTPControls* pControls = pFrame->m_pControls;
	CXTPPropertyGridItemConstraints* pConstrants = pItemControlCategory->GetConstraints();
	
	for (int i = 0; i < pControls->GetCount(); i++)
	{
		CXTPControl* pControl = pControls->GetAt(i);
		
		if (pConstrants->FindConstraint(pControl->GetCategory()) == -1)
		{
			pConstrants->AddConstraint(pControl->GetCategory());
		}
	}
	
	CXTPCommandBarsOptions* pOptions = pAction->GetCommandBars()->GetCommandBarsOptions();
	
	BOOL bExists;
	BOOL bVisible = pOptions->m_mapHiddenCommands.Lookup(pAction->GetID(), bExists);
	
	CXTPPropertyGridItem* pItemControlVisibility = pCategory->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_VISIBILITY, lpVisibility[bVisible]));
	pConstrants = pItemControlVisibility->GetConstraints();
	pConstrants->AddConstraint(lpVisibility[0]);
	pConstrants->AddConstraint(lpVisibility[1]);
	pItemControlVisibility->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);

}

void CPaneProperties::RefreshControlProperties()
{
	CXTPCommandBars* pCommandBars = GetMainFrame()->GetActiveCommandBars();
	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();

	if (!pCommandBars)
		return;

	CXTPControl* pControl = pCommandBars->GetDragControl();

	if (!pControl)
		return;

	if (!pControl->GetControls())
		return;

	BOOL bActionsEnable  = pCommandBars->IsActionsEnabled();

	BOOL bListControl = pControl->GetParent() == NULL;

	CXTPPropertyGridItem* pCategoryAppearance = m_wndPropertyGrid.AddCategory(ID_GRID_CATEGORY_APPEARANCE);
	CXTPPropertyGridItem* pCategoryBehavior = m_wndPropertyGrid.AddCategory(ID_GRID_CATEGORY_BEHAVIOR);

	BOOL bControlHasAction = bActionsEnable && pControl->GetAction() != NULL;

	if (bActionsEnable)
	{
		CString strID;
		if (bControlHasAction) strID =pFrame->ResourceManager()->GetStringID(pControl->GetID());
		CXTPPropertyGridItem* pItemControlAction = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_ACTION, strID));
		pItemControlAction->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
		FillConstraintsActionsID(pItemControlAction);

		if (bControlHasAction)
		{
			FillActionProperties(pItemControlAction, pControl->GetAction());
		}
	}

	if (!bControlHasAction)
	{
		pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_CAPTION, pControl->GetCaption()));

		CString strID = pFrame->ResourceManager()->GetStringID(pControl->GetID());
		CXTPPropertyGridItem* pItemControlId = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_ID, strID));
		pItemControlId->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
		FillConstraintsID(pItemControlId);

		CString strIconID;
		if (pControl->GetIconId() != pControl->GetID())
			strIconID = pFrame->ResourceManager()->GetStringID(pControl->GetIconId());

		CXTPPropertyGridItem* pItemControlIconId = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_ICONID, strIconID));
		pItemControlIconId->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
		FillConstraintsID(pItemControlIconId);
	}


	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_CONTROL_CLOSESUBMENUONCLICK, pControl->GetCloseSubMenuOnClick()));
	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemNumber(ID_GRID_ITEM_CONTROL_EXECUTEONPRESSINTERVAL, pControl->GetExecuteOnPressInterval()));

	if (!bControlHasAction)
	{
		pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_DESCRIPTION, pControl->GetDescription()));
		pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_TOOLTIP, pControl->GetTooltip()));
	}

	CXTPPropertyGridItem* pItemControlType = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemEnum(ID_GRID_ITEM_CONTROL_TYPE, pControl->GetType()));

	CXTPPropertyGridItemConstraints* pConstraints = pItemControlType->GetConstraints();
	for (int i = 0; i < _countof(lpTypes); i++) if (lpTypes[i])
	{
		pConstraints->AddConstraint(lpTypes[i], i);
	}

	if (pControl->GetType() != xtpControlCheckBox)
	{
		CXTPPropertyGridItem* pItemControlStyle = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemEnum(ID_GRID_ITEM_CONTROL_STYLE, pControl->GetStyle()));

		CXTPPropertyGridItemConstraints* pConstraints = pItemControlStyle->GetConstraints();
		for (int i = 0; i < _countof(lpStyles); i++)
			pConstraints->AddConstraint(lpStyles[i], i);
	}

	pCategoryBehavior->AddChildItem(new CPropertyGridItemControlFlags(ID_GRID_ITEM_CONTROL_FLAGS, pControl->GetFlags()));

	if (!bListControl)
	{
		CXTPPropertyGridItem* pItemControlBeginGroup = pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_CONTROL_BEGINGROUP, pControl->GetBeginGroup()));
		pItemControlBeginGroup->SetReadOnly(pControl->GetIndex() == 0);
	}

	if (bListControl && !bControlHasAction)
	{
		CXTPPropertyGridItem* pItemControlCategory = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_CATEGORY, pControl->GetCategory()));
		pItemControlCategory->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);

		CXTPControls* pControls = pControl->GetControls();
		CXTPPropertyGridItemConstraints* pConstrants = pItemControlCategory->GetConstraints();

		for (int i = 0; i < pControls->GetCount(); i++)
		{
			CXTPControl* pControl = pControls->GetAt(i);

			if (pConstrants->FindConstraint(pControl->GetCategory()) == -1)
			{
				pConstrants->AddConstraint(pControl->GetCategory());
			}
		}
	}
	pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_CONTROL_ITEMDEFAULT,
		pControl->IsItemDefault()));
	
	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemNumber(ID_GRID_ITEM_CONTROL_WIDTH,
		pControl->GetWidth()));

	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemNumber(ID_GRID_ITEM_CONTROL_HEIGHT,
		pControl->GetHeight()));

	if (pControl->GetType() == xtpControlComboBox)
	{
		CXTPPropertyGridItem* pCategoryData = m_wndPropertyGrid.AddCategory(ID_GRID_CATEGORY_BEHAVIOR);

		CXTPPropertyGridItem* pItemControlList = pCategoryData->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_LIST, _T("(Collection)")));
		pItemControlList->SetFlags(xtpGridItemHasExpandButton);



		pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemNumber(ID_GRID_ITEM_CONTROL_DROPDOWNWIDTH,
			((CXTPControlComboBox*)pControl)->GetDropDownWidth()));

		CString strSelected = ((CXTPControlComboBox*)pControl)->GetDropDownListStyle()? lpDropDownStyles[0]: lpDropDownStyles[1];

		CXTPPropertyGridItem* pItemControlDropDownStyle = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_DROPDOWNSTYLE, strSelected));
		CXTPPropertyGridItemConstraints* pConstrants = pItemControlDropDownStyle->GetConstraints();
		pConstrants->AddConstraint(lpDropDownStyles[0]);
		pConstrants->AddConstraint(lpDropDownStyles[1]);
		pItemControlDropDownStyle->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);

	}
	if (pControl->GetType() == xtpControlEdit)
	{
		pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_CONTROL_READONLY, ((CXTPControlEdit*)pControl)->GetReadOnly()));
		pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_CONTROL_SHOWSPINBUTTONS, ((CXTPControlEdit*)pControl)->IsSpinButtonsVisible()));
	}

	if (!bListControl && pControl->GetParent()->GetType() == xtpBarTypePopup && pControl->GetID() > 0 && !bControlHasAction)
	{
		CXTPCommandBarsOptions* pOptions = pCommandBars->GetCommandBarsOptions();

		BOOL bExists;
		BOOL bVisible = pOptions->m_mapHiddenCommands.Lookup(pControl->GetID(), bExists);

		CXTPPropertyGridItem* pItemControlVisibility = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_CONTROL_VISIBILITY, lpVisibility[bVisible]));
		CXTPPropertyGridItemConstraints* pConstrants = pItemControlVisibility->GetConstraints();
		pConstrants->AddConstraint(lpVisibility[0]);
		pConstrants->AddConstraint(lpVisibility[1]);
		pItemControlVisibility->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
	}


	m_pControl = pControl;

	if (!pCommandBars->IsActionsEnabled())
	{
		m_wndPropertyGrid.GetVerbs()->Add(_T("Enable Actions"), 0);
	}


	if (m_stateExpanding.IsEmpty())
	{
		pCategoryAppearance->Expand();
		pCategoryBehavior->Expand();

	}
}

void CPaneProperties::CreateActionList(CXTPCommandBars* pCommandBars, CXTPControls* pControls)
{
	for (int i = 0; i < pControls->GetCount(); i++)
	{
		CXTPControl* pControl = pControls->GetAt(i);

		if (pControl->IsTemporary())
			continue;

		if (pControl->GetID() > 0 && pControl->GetID() < 0xFFFFFF && pControl->GetAction() == NULL)
		{
			CXTPControlAction* pAction = pCommandBars->CreateAction(pControl->GetID());

			if (!pControl->GetCaption().IsEmpty())
				pAction->SetCaption(pControl->GetCaption());
			
			if (!pControl->GetTooltip().IsEmpty())
				pAction->SetTooltip(pControl->GetTooltip());

			if (!pControl->GetDescription().IsEmpty())
				pAction->SetDescription(pControl->GetDescription());

			if (!pControl->GetCategory().IsEmpty())
				pAction->SetCategory(pControl->GetCategory());

			pControl->SetAction(pAction);		
		}

		if (pControl->GetCommandBar())
		{
			CreateActionList(pCommandBars, pControl->GetCommandBar()->GetControls());
		}
	}
}

void CPaneProperties::EnableActions()
{
	CXTPCommandBars* pCommandBars = GetMainFrame()->GetActiveCommandBars();
	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();

	if (!pCommandBars)
		return;

	pCommandBars->EnableActions();

	CXTPToolBar* pMenuBar = pCommandBars->GetMenuBar();

	int i;
	for (i = 0; i < pCommandBars->GetCount(); i++)
	{
		CXTPCommandBar* pCommandBar = pCommandBars->GetAt(i);
		if (pCommandBar != pMenuBar)
			CreateActionList(pCommandBars, pCommandBar->GetControls());
	}

	for (i = 0; i < pCommandBars->GetContextMenus()->GetCount(); i++)
	{
		CXTPCommandBar* pCommandBar = pCommandBars->GetContextMenus()->GetAt(i);
		CreateActionList(pCommandBars, pCommandBar->GetControls());
	}

	CreateActionList(pCommandBars, pFrame->m_pControls);

	if (pMenuBar)
		CreateActionList(pCommandBars, pCommandBars->GetMenuBar()->GetControls());

	Refresh();
}


void CPaneProperties::RefreshCommandBarProperties()
{
	CXTPToolBar* pToolBar = DYNAMIC_DOWNCAST(CXTPToolBar, m_pCommandBar);
	CXTPPopupBar* pPopupBar = DYNAMIC_DOWNCAST(CXTPPopupBar, m_pCommandBar);

	CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();

	if (!pFrame)
		return;


	CXTPPropertyGridItem* pCategoryAppearance = m_wndPropertyGrid.AddCategory(ID_GRID_CATEGORY_APPEARANCE);
	CXTPPropertyGridItem* pCategoryBehavior = m_wndPropertyGrid.AddCategory(ID_GRID_CATEGORY_BEHAVIOR);


	pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_COMMANDBAR_TITLE, m_pCommandBar->GetTitle()));

	CString strID = pFrame->ResourceManager()->GetStringID(m_pCommandBar->GetBarID());
	CXTPPropertyGridItem* pItemCommandBarId = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_COMMANDBAR_ID, strID));
	pItemCommandBarId->SetReadOnly(TRUE);

	CXTPPropertyGridItem* pItemCommandBarVisible = pCategoryBehavior->AddChildItem(
		new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_VISIBLE, pToolBar? pToolBar->IsVisible(): TRUE));
	if (!m_pCommandBar->IsKindOf(RUNTIME_CLASS(CXTPToolBar))) pItemCommandBarVisible->SetReadOnly(TRUE);

	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_CUSTOMIZABLE, m_pCommandBar->IsCustomizable()));

	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_ANIMATION, m_pCommandBar->IsAnimationEnabled()));

	pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_SHOWGRIPPER, m_pCommandBar->GetShowGripper()));
		
	{
		CXTPPropertyGridItem* pItemCommandBarStyle = pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemEnum(ID_GRID_ITEM_COMMANDBAR_DEFAULTBUTTONSTYLE, m_pCommandBar->GetDefaultButtonStyle()));
		CXTPPropertyGridItemConstraints* pConstraints = pItemCommandBarStyle->GetConstraints();
		for (int i = 0; i < _countof(lpStyles); i++)
			pConstraints->AddConstraint(lpStyles[i], i);
	}

	if (pToolBar)
	{
		pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_CLOSEABLE, pToolBar->IsCloseable()));
		pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_CONTEXTMENUPRESENT, pToolBar->IsContextMenuPresent()));
		pCategoryBehavior->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_CUSTOMIZEDIALOGPRESENT, pToolBar->IsCustomizeDialogPresent()));	

	}


	if (m_pCommandBar->IsKindOf(RUNTIME_CLASS(CXTPPopupBar)))
	{
		CString strCaption;
		UINT nID;
		int nWidth;
		BOOL bTearOff = pPopupBar->IsTearOffPopup(strCaption, nID, nWidth);

		CXTPPropertyGridItem* pItemCommandBarTearOff = pCategoryBehavior->AddChildItem(
			new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_TEAROFF, bTearOff));

		if (bTearOff)
		{
			CString strID = pFrame->ResourceManager()->GetStringID(nID);


			pItemCommandBarTearOff->AddChildItem(new CXTPPropertyGridItem(ID_GRID_ITEM_COMMANDBAR_TEAROFF_CAPTION, strCaption));
			CXTPPropertyGridItem* pItemCommandBarTearOffId = pItemCommandBarTearOff->AddChildItem(
				new CXTPPropertyGridItem(ID_GRID_ITEM_COMMANDBAR_TEAROFF_ID, strID));
			pItemCommandBarTearOffId->SetFlags(xtpGridItemHasComboButton | xtpGridItemHasEdit);
			FillConstraintsToolbarsID(pItemCommandBarTearOffId);


			pItemCommandBarTearOff->AddChildItem(new CXTPPropertyGridItemNumber(ID_GRID_ITEM_COMMANDBAR_TEAROFF_WIDTH, nWidth));
			pItemCommandBarTearOff->Expand();
		}

		CXTPPropertyGridItem* pItemPopupToolBar = pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_POPUPTOOLBAR, m_pCommandBar->GetType() !=xtpBarTypePopup));

		if (m_pCommandBar->GetType() != xtpBarTypePopup)
		{
			pItemPopupToolBar->AddChildItem(new CXTPPropertyGridItemNumber(ID_GRID_ITEM_COMMANDBAR_WIDTH, m_pCommandBar->GetWidth()));
		}

		if (m_pCommandBar->GetType() == xtpBarTypePopup)
		{
			pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_DOUBLEGRIPPER, ((CXTPPopupBar*)m_pCommandBar)->IsDoubleGripper()));
		}
	}

///if (m_pCommandBar->GetType() != xtpBarTypePopup)
	{
		CSize sz = m_pCommandBar->GetIconSize();
		pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemSize(ID_GRID_ITEM_COMMANDBAR_ICON_SIZE, sz));
	}

	if (m_pCommandBar->GetType() != xtpBarTypePopup)
	{
		CSize sz = m_pCommandBar->GetButtonSize();
		pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemSize(ID_GRID_ITEM_COMMANDBAR_BUTTON_SIZE, sz));
	}

	if (m_pCommandBar->GetType() != xtpBarTypePopup)
	{
		pCategoryAppearance->AddChildItem(new CXTPPropertyGridItemBool(ID_GRID_ITEM_COMMANDBAR_TEXTBELOWICONS, m_pCommandBar->IsTextBelowIcons()));
	}



	if (m_pCommandBar->IsKindOf(RUNTIME_CLASS(CXTPToolBar)))
	{
		pCategoryBehavior->AddChildItem(new CPropertyGridItemDockingFlags(ID_GRID_ITEM_COMMANDBAR_FLAGS, m_pCommandBar->GetFlags()));
		pCategoryBehavior->AddChildItem(new CPropertyGridItemStretchFlags(ID_GRID_ITEM_COMMANDBAR_STRETCH, m_pCommandBar->GetFlags()));
	}

	if (m_stateExpanding.IsEmpty())
	{
		pCategoryAppearance->Expand();
		pCategoryBehavior->Expand();
	}
}



/////////////////////////////////////////////////////////////////////////////
// CPaneProperties message handlers

int CPaneProperties::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	VERIFY(m_wndToolBar.CreateToolBar(WS_TABSTOP|WS_VISIBLE|WS_CHILD|CBRS_TOOLTIPS, this));
	VERIFY(m_wndToolBar.LoadToolBar(IDR_PANE_PROPERTIES));


	VERIFY(m_wndPropertyGrid.Create( CRect(0, 0, 0, 0), this, 0 ));
	m_wndPropertyGrid.SetTheme(xtpGridThemeWhidbey);

	return 0;
}

void CPaneProperties::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	CSize sz(0);
	if (m_wndToolBar.GetSafeHwnd())
	{
		sz = m_wndToolBar.CalcDockingLayout(cx, /*LM_HIDEWRAP|*/ LM_HORZDOCK|LM_HORZ | LM_COMMIT);

		m_wndToolBar.MoveWindow(0, 0, cx, sz.cy);
		m_wndToolBar.Invalidate(FALSE);
	}
	if (m_wndPropertyGrid.GetSafeHwnd())
	{
		m_wndPropertyGrid.MoveWindow(0, sz.cy, cx, cy - sz.cy);
	}
}

void CPaneProperties::OnPanePropertiesCategorized()
{
	m_wndPropertyGrid.SetPropertySort(xtpGridSortCategorized);

}

void CPaneProperties::OnUpdatePanePropertiesCategorized(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropertyGrid.GetPropertySort() == xtpGridSortCategorized);

}

void CPaneProperties::OnPanePropertiesAlphabetic()
{
	m_wndPropertyGrid.SetPropertySort(xtpGridSortAlphabetical);

}

void CPaneProperties::OnUpdatePanePropertiesAlphabetic(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropertyGrid.GetPropertySort() == xtpGridSortAlphabetical);

}

void CPaneProperties::RefreshToolbarsPane()
{
	GetMainFrame()->m_paneToolbars.Refresh();
}
void CPaneProperties::RefreshControlsPane()
{
	GetMainFrame()->m_paneControls.Refresh(TRUE);
}


void CPaneProperties::OnPropertyChanged(CXTPControl* pControl)
{
	CXTPCommandBar* pCommandBar = pControl->GetParent();
	if (pCommandBar)
	{
		pCommandBar->SetSelected(-1);
		pCommandBar->SetPopuped(-1);
		if (pCommandBar->GetSafeHwnd())
		{
			pCommandBar->OnIdleUpdateCmdUI(NULL, NULL);
		}
	}
}

void CPaneProperties::OnControlValueChanged(CXTPPropertyGridItem* pItem )
{
	ASSERT(pItem);
	ASSERT(m_pControl);

	FINDCONTROLPARAM param;
	param.bIncludeSelf = FALSE;
	param.pItem = pItem;
	param.bRefresh = TRUE;

	OnControlValueChangedInstance(m_pControl, &param);
}

void CPaneProperties::OnControlValueChangedInstance(CXTPControl* pControl, FINDCONTROLPARAM* pParam )
{
	CXTPPropertyGridItem* pItem = pParam->pItem;
	BOOL bRefresh = pParam->bRefresh;

	switch (pItem->GetID())
	{

	case ID_GRID_ITEM_CONTROL_CAPTION:
		ASSERT(pControl);
		pControl->SetCaption(pItem->GetValue());
		OnPropertyChanged(pControl);
		if (pControl->GetParent() == NULL) RefreshControlsPane();
		return;
	case ID_GRID_ITEM_ACTION_CAPTION:
		ASSERT(pControl && pControl->GetAction());
		pControl->GetAction()->SetCaption(pItem->GetValue());
		OnPropertyChanged(pControl);
		if (pControl->GetParent() == NULL) RefreshControlsPane();
		return;
	case ID_GRID_ITEM_CONTROL_CLOSESUBMENUONCLICK:
		ASSERT(pControl);
		pControl->SetCloseSubMenuOnClick(GetBoolValue(pItem));
		OnPropertyChanged(pControl);
		return;
	case ID_GRID_ITEM_CONTROL_EXECUTEONPRESSINTERVAL:
		ASSERT(pControl);
		pControl->SetExecuteOnPressInterval(GetNumberValue(pItem));
		OnPropertyChanged(pControl);
		return;
	case ID_GRID_ITEM_CONTROL_DESCRIPTION:
		ASSERT(pControl);
		pControl->SetDescription(pItem->GetValue());
		OnPropertyChanged(pControl);
		return;
	case ID_GRID_ITEM_ACTION_DESCRIPTION:
		ASSERT(pControl && pControl->GetAction());
		pControl->GetAction()->SetDescription(pItem->GetValue());
		OnPropertyChanged(pControl);
		return;
	case ID_GRID_ITEM_CONTROL_TOOLTIP:
		ASSERT(pControl);
		pControl->SetTooltip(pItem->GetValue());
		OnPropertyChanged(pControl);
		return;
	case ID_GRID_ITEM_ACTION_TOOLTIP:
		ASSERT(pControl && pControl->GetAction());
		pControl->GetAction()->SetTooltip(pItem->GetValue());
		OnPropertyChanged(pControl);
		return;

	case ID_GRID_ITEM_CONTROL_FLAGS:
		ASSERT(pControl);
		pControl->SetFlags(GetFlagsValue(pItem));
		OnPropertyChanged(pControl);
		pControl->DelayLayoutParent();
		return;

	case ID_GRID_ITEM_CONTROL_TYPE:
		{
			CXTPControls* pControls = pControl->GetControls();
			CXTPCommandBars* pCommandBars = pControls->GetCommandBars();

			XTPControlType type = (XTPControlType)GetEnumValue(pItem);


			int nIndex = pControl->GetIndex();
			if (bRefresh) pCommandBars->SetDragControl(NULL);

			pControl = pControls->SetControlType(nIndex, type);
			pControl->DelayLayoutParent();

			OnPropertyChanged(pControl);
			if (bRefresh) pCommandBars->SetDragControl(pControl);

			if (pControl->GetParent() == NULL) RefreshControlsPane();
		}
		return;

	case ID_GRID_ITEM_CONTROL_STYLE:
		pControl->SetStyle((XTPButtonStyle)GetEnumValue(pItem));
		OnPropertyChanged(pControl);
		return;

	case ID_GRID_ITEM_CONTROL_BEGINGROUP:
		ASSERT(pControl);
		pControl->SetBeginGroup(GetBoolValue(pItem));
		OnPropertyChanged(pControl);
		return;

	case ID_GRID_ITEM_CONTROL_CATEGORY:
		ASSERT(pControl);
		pControl->SetCategory(pItem->GetValue());
		RefreshControlsPane();
		return;
	case ID_GRID_ITEM_ACTION_CATEGORY:
		ASSERT(pControl && pControl->GetAction());
		pControl->GetAction()->SetCategory(pItem->GetValue());
		RefreshControlsPane();
		return;

	case ID_GRID_ITEM_CONTROL_ACTION:
		{
			ASSERT(pControl);

			CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
			ASSERT(pFrame);

			UINT nID = pFrame->ResourceManager()->GetStringID(pItem->GetValue());

			if (nID > 0)
				pControl->SetAction(pFrame->GetCommandBars()->CreateAction(nID));
			else
				pControl->SetAction(NULL);

			pControl->DelayLayoutParent();
			OnPropertyChanged(pControl);
			if (pControl->GetParent() == NULL) RefreshControlsPane();
			if (bRefresh) Refresh();
		}
		return;

	case ID_GRID_ITEM_CONTROL_ID:
		{

			ASSERT(pControl);

			CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
			ASSERT(pFrame);

			UINT nID = pFrame->ResourceManager()->GetStringID(pItem->GetValue());

			pControl->SetID(nID);
			pControl->DelayLayoutParent();
			OnPropertyChanged(pControl);
			if (pControl->GetParent() == NULL) RefreshControlsPane();
			if (bRefresh) Refresh();
		}
		return;

	case ID_GRID_ITEM_CONTROL_ICONID:
	case ID_GRID_ITEM_ACTION_ICONID:
		{
			ASSERT(pControl);

			CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
			ASSERT(pFrame);

			int nID = pFrame->ResourceManager()->GetStringID(pItem->GetValue());
			if (nID == 0) nID = -1;

			if (pItem->GetID() == ID_GRID_ITEM_CONTROL_ICONID)
				pControl->SetIconId(nID);
			else
				pControl->GetAction()->SetIconId(nID);
			pControl->DelayLayoutParent();
			OnPropertyChanged(pControl);
			if (pControl->GetParent() == NULL) RefreshControlsPane();
			if (bRefresh) Refresh();
		}
		return;

	case ID_GRID_ITEM_CONTROL_WIDTH:
		pControl->SetWidth(GetNumberValue(pItem));
		pControl->DelayLayoutParent();
		return;
	case ID_GRID_ITEM_CONTROL_HEIGHT:
		pControl->SetHeight(GetNumberValue(pItem));
		pControl->DelayLayoutParent();
		return;
	case ID_GRID_ITEM_CONTROL_ITEMDEFAULT:
		pControl->SetItemDefault(GetBoolValue(pItem));
		pControl->DelayLayoutParent();
		return;
	case ID_GRID_ITEM_CONTROL_DROPDOWNWIDTH:
		if (pControl->GetType() == xtpControlComboBox)
			((CXTPControlComboBox*)pControl)->SetDropDownWidth(GetNumberValue(pItem));
		pControl->DelayLayoutParent();
		return;
	case ID_GRID_ITEM_CONTROL_DROPDOWNSTYLE:
		if (pControl->GetType() == xtpControlComboBox)
			((CXTPControlComboBox*)pControl)->SetDropDownListStyle(pItem->GetValue() == lpDropDownStyles[0]);
		return;
	case ID_GRID_ITEM_CONTROL_READONLY:
		if (pControl->GetType() == xtpControlEdit)
			((CXTPControlEdit*)pControl)->SetReadOnly(GetBoolValue(pItem));
		return;
	case ID_GRID_ITEM_CONTROL_SHOWSPINBUTTONS:
		if (pControl->GetType() == xtpControlEdit)
			((CXTPControlEdit*)pControl)->ShowSpinButtons(GetBoolValue(pItem));
		pControl->DelayLayoutParent();
		return;
	case ID_GRID_ITEM_CONTROL_VISIBILITY:
		{
			CXTPCommandBarsOptions* pOptions = pControl->GetControls()->GetCommandBars()->GetCommandBarsOptions();
			if (pItem->GetValue() == lpVisibility[0])
			{
				pOptions->m_mapHiddenCommands.RemoveKey(pControl->GetID());

			} else
			{
				pOptions->m_mapHiddenCommands.SetAt(pControl->GetID(), TRUE);

			}
			if (bRefresh) Refresh();
		}
		return;
	}
}

LRESULT CPaneProperties::OnGridNotify(WPARAM wParam, LPARAM lParam)
{
	if (wParam == XTP_PGN_INPLACEBUTTONDOWN)
	{
		CXTPPropertyGridInplaceButton* pButton = (CXTPPropertyGridInplaceButton*)lParam;
		CXTPPropertyGridItem* pItem = pButton->GetItem();

		switch (pItem->GetID())
		{
			case ID_GRID_ITEM_CONTROL_LIST:
				if (m_pControl->GetType() == xtpControlComboBox)
				{
					CXTPControlComboBox* pCombo = (CXTPControlComboBox*)m_pControl;
					CDialogListEditor ld(pCombo);
					ld.DoModal();

					return TRUE;
				}
		}

	}
	if (wParam == XTP_PGN_VERB_CLICK)
	{
		CXTPPropertyGridVerb* pVerb = (CXTPPropertyGridVerb*)lParam;
		if (pVerb->GetID() == 0)
		{
			if (AfxMessageBox(_T("Are you sure you want to enable Actions? It will modify all controls was created"), MB_YESNO) != IDYES)
				return TRUE;

			EnableActions();
		}
		

		return TRUE;
	}

	if (wParam == XTP_PGN_ITEMVALUE_CHANGED)
	{
		CXTPPropertyGridItem* pItem = (CXTPPropertyGridItem*)lParam;

		if (m_pCommandBar)
		{

			switch (pItem->GetID())
			{
			case ID_GRID_ITEM_COMMANDBAR_TITLE:
				m_pCommandBar->SetTitle(pItem->GetValue());
				RefreshToolbarsPane();
				return TRUE;
			case  ID_GRID_ITEM_COMMANDBAR_ICON_SIZE:
				{
					CSize sz = ((CXTPPropertyGridItemSize*)pItem)->GetSize();
					m_pCommandBar->SetIconSize(sz);
					m_pCommandBar->DelayLayout();
					GetMainFrame()->RefreshPanes(TRUE);

				}
				return TRUE;
			case  ID_GRID_ITEM_COMMANDBAR_BUTTON_SIZE:
				{
					CSize sz = ((CXTPPropertyGridItemSize*)pItem)->GetSize();
					m_pCommandBar->SetButtonSize(sz);
					m_pCommandBar->DelayLayout();
					GetMainFrame()->RefreshPanes(TRUE);

				}
				return TRUE;

			case ID_GRID_ITEM_COMMANDBAR_TEXTBELOWICONS:
				m_pCommandBar->ShowTextBelowIcons(GetBoolValue(pItem));
				return TRUE;

			case ID_GRID_ITEM_COMMANDBAR_VISIBLE:
				m_pCommandBar->SetVisible(GetBoolValue(pItem));
				RefreshToolbarsPane();
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_CUSTOMIZABLE:
				m_pCommandBar->EnableCustomization(GetBoolValue(pItem));
				RefreshToolbarsPane();
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_ANIMATION:
				m_pCommandBar->EnableAnimation(GetBoolValue(pItem));
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_SHOWGRIPPER:
				m_pCommandBar->SetShowGripper(GetBoolValue(pItem));
				m_pCommandBar->OnRecalcLayout();
				return TRUE;

			case ID_GRID_ITEM_COMMANDBAR_DEFAULTBUTTONSTYLE:
				m_pCommandBar->SetDefaultButtonStyle((XTPButtonStyle)GetEnumValue(pItem));
				m_pCommandBar->OnRecalcLayout();
				return TRUE;

			case ID_GRID_ITEM_COMMANDBAR_CLOSEABLE:
				((CXTPToolBar*)m_pCommandBar)->SetCloseable(GetBoolValue(pItem));
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_CONTEXTMENUPRESENT:
				((CXTPToolBar*)m_pCommandBar)->SetContextMenuPresent(GetBoolValue(pItem));
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_CUSTOMIZEDIALOGPRESENT:
				((CXTPToolBar*)m_pCommandBar)->SetCustomizeDialogPresent(GetBoolValue(pItem));
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_STRETCH:
			case ID_GRID_ITEM_COMMANDBAR_FLAGS:
				{
					DWORD dwMask = pItem->GetID() == ID_GRID_ITEM_COMMANDBAR_STRETCH? xtpFlagHideWrap|xtpFlagStretched: xtpFlagAlignAny|xtpFlagFloating;
					DWORD dwFalgs = (m_pCommandBar->GetFlags() & ~dwMask) | GetFlagsValue(pItem);

					((CXTPToolBar*)m_pCommandBar)->EnableDocking(dwFalgs);
					m_pCommandBar->DelayLayout();
					RefreshToolbarsPane();
				}
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_POPUPTOOLBAR:
				((CXTPPopupBar*)m_pCommandBar)->SetPopupToolBar(GetBoolValue(pItem));
				m_pCommandBar->DelayLayout();
				RefreshToolbarsPane();
				Refresh(m_pCommandBar);
				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_WIDTH:
				m_pCommandBar->SetWidth(GetNumberValue(pItem));
				m_pCommandBar->DelayLayout();
				RefreshToolbarsPane();
				return TRUE;
			case  ID_GRID_ITEM_COMMANDBAR_DOUBLEGRIPPER:
				{
					CXTPPopupBar* pPopupBar = DYNAMIC_DOWNCAST(CXTPPopupBar, m_pCommandBar);
					ASSERT(pPopupBar);
					pPopupBar->SetDoubleGripper(GetBoolValue(pItem));
					break;
				}

			case ID_GRID_ITEM_COMMANDBAR_TEAROFF:
				{
					CXTPPopupBar* pPopupBar = DYNAMIC_DOWNCAST(CXTPPopupBar, m_pCommandBar);
					ASSERT(pPopupBar);

					if (GetBoolValue(pItem))
					{
						CString strCaption;
						UINT nID;
						int nWidth;
						pPopupBar->IsTearOffPopup(strCaption, nID, nWidth);
						if (nID == 0)
						{
							CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
							ASSERT(pFrame);

							nID = pFrame->ResourceManager()->GetStringID(_T("IDR_UNTITLED"));

							pPopupBar->SetTearOffPopup(_T("Untitled"), nID);
						}
						else  pPopupBar->SetTearOffPopup(strCaption, nID, nWidth);
					}
					else
					{
						pPopupBar->SetTearOffPopup(_T(""), 0);
					}
					Refresh(m_pCommandBar);
				}
				return TRUE;

			case ID_GRID_ITEM_COMMANDBAR_TEAROFF_ID:
				{
					CEmbeddedFrame* pFrame = GetMainFrame()->GetActiveEmbeddedFrame();
					ASSERT(pFrame);

					CXTPPopupBar* pPopupBar = DYNAMIC_DOWNCAST(CXTPPopupBar, m_pCommandBar);
					ASSERT(pPopupBar);

					CString strCaption;
					UINT nID;
					int nWidth;
					pPopupBar->IsTearOffPopup(strCaption, nID, nWidth);
					pPopupBar->SetTearOffPopup(strCaption, pFrame->ResourceManager()->GetStringID(pItem->GetValue()), nWidth);
				}

				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_TEAROFF_CAPTION:
				{
					CXTPPopupBar* pPopupBar = DYNAMIC_DOWNCAST(CXTPPopupBar, m_pCommandBar);
					ASSERT(pPopupBar);

					CString strCaption;
					UINT nID;
					int nWidth;
					pPopupBar->IsTearOffPopup(strCaption, nID, nWidth);
					pPopupBar->SetTearOffPopup(pItem->GetValue(), nID, nWidth);
				}

				return TRUE;
			case ID_GRID_ITEM_COMMANDBAR_TEAROFF_WIDTH:
				{
					CXTPPopupBar* pPopupBar = DYNAMIC_DOWNCAST(CXTPPopupBar, m_pCommandBar);
					ASSERT(pPopupBar);

					CString strCaption;
					UINT nID;
					int nWidth;
					pPopupBar->IsTearOffPopup(strCaption, nID, nWidth);
					pPopupBar->SetTearOffPopup(strCaption, nID, GetNumberValue(pItem));
				}

				return TRUE;
			}
		}
		if (m_pControl)
		{
			OnControlValueChanged(pItem);
			return TRUE;
		}


	}
	return 0;
}
void CPaneProperties::OnPanePropertiesPages()
{
	if (m_pActiveCommandBars)
	{
		GetMainFrame()->GetActiveEmbeddedFrame()->ShowPropertyPage();
	}

}

void CPaneProperties::OnUpdatePanePropertiesPages(CCmdUI* pCmdUI)
{

	pCmdUI->Enable(m_pActiveCommandBars != NULL);

}
