// CalendarResourcesDlg.cpp : implementation file
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
#include "calendardemo.h"

#include "CalendarResourcesDlg.h"
#include "DataProvidersOptions.h"
//#include "XTPCalendarCustomProperties.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
CString GetDPType(int nDPType)
{
	CString strDPType = _T("?");

	if (nDPType == xtpCalendarDataProviderMemory) {
		strDPType = _T("XML/Bin");
	} else if (nDPType == xtpCalendarDataProviderDatabase) {
		strDPType = _T("DB");
	} else if (nDPType == xtpCalendarDataProviderMAPI) {
		strDPType = _T("MAPI");			
	}
	else {
		ASSERT(FALSE);
	}
	return strDPType;
}


/////////////////////////////////////////////////////////////////////////////
// CCalendarResourcesDlg dialog


CCalendarResourcesDlg::CCalendarResourcesDlg(
								CXTPCalendarResourcesManager* pRCMan, 
								CWnd* pParent /*=NULL*/)
	: CDialog(CCalendarResourcesDlg::IDD, pParent)
{
	ASSERT(pRCMan);
	m_pRCMan = pRCMan;
	m_bChangeEditRcName_internal = TRUE;
	m_nRcNameAuto_StoredState = -1;

	//{{AFX_DATA_INIT(CCalendarResourcesDlg)
	//}}AFX_DATA_INIT
}


void CCalendarResourcesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalendarResourcesDlg)
	DDX_Control(pDX, IDC_BTN_RESOURCES_MOVE_DOWN, m_ctrlResourcesMoveDown);
	DDX_Control(pDX, IDC_BTN_RESOURCES_MOVE_UP, m_ctrlResourcesMoveUp);
	DDX_Control(pDX, IDC_LISTCTRL_DATA_PROVIDERS, m_ctrlDataProviders);
	DDX_Control(pDX, IDC_BTN_DATA_PROVIDER_DELETE, m_ctrlDataProviderDelete);
	DDX_Control(pDX, IDC_BTN_DATA_PROVIDER_EDIT, m_ctrlDataProviderEdit);
	DDX_Control(pDX, IDC_BTN_DATA_PROVIDER_ADD, m_ctrlDataProviderAdd);
	DDX_Control(pDX, IDC_LIST_RESOURCES, m_ctrlResources);
	DDX_Control(pDX, IDC_BTN_RESOURCES_DELETE, m_ctrlResourcesDelete);
	DDX_Control(pDX, IDC_BTN_RESOURCES_ADD, m_ctrlResourcesAdd);
	DDX_Control(pDX, IDC_EDIT_RC_NAME, m_ctrlRCName);
	DDX_Control(pDX, IDC_CHK_RC_NAME_AUTO, m_ctrlRCNameAuto);
	DDX_Control(pDX, IDC_CMB_RC_DATA_PROVIDER, m_ctrlRCDataProvider);
	DDX_Control(pDX, IDC_LIST_SCHEDULES, m_ctrlSchedules);	
	DDX_Control(pDX, IDC_CHK_SCHEDULES_ALL, m_ctrlSchedulesAll);
	DDX_Control(pDX, IDC_BTN_SCHEDULES_DELEDE, m_ctrlSchedulesDelete);
	DDX_Control(pDX, IDC_BTN_SCHEDULES_ADD, m_ctrlSchedulesAdd);
	DDX_Control(pDX, IDC_BTN_SCHEDULES_CHANGE, m_ctrlScheduleChangeName);
	DDX_Control(pDX, IDC_EDIT_SCHEDULE_NEW_NAME, m_ctrlScheduleNewName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalendarResourcesDlg, CDialog)
	//{{AFX_MSG_MAP(CCalendarResourcesDlg)
	ON_BN_CLICKED(IDC_BTN_DATA_PROVIDER_ADD, OnBtnDataProviderAdd)
	ON_BN_CLICKED(IDC_BTN_DATA_PROVIDER_DELETE, OnBtnDataProviderDelete)
	ON_BN_CLICKED(IDC_BTN_DATA_PROVIDER_EDIT, OnBtnDataProviderEdit)
	ON_BN_CLICKED(IDC_BTN_RESOURCES_ADD, OnBtnResourcesAdd)
	ON_BN_CLICKED(IDC_BTN_RESOURCES_DELETE, OnBtnResourcesDelete)
	ON_BN_CLICKED(IDC_BTN_SCHEDULES_ADD, OnBtnSchedulesAdd)
	ON_BN_CLICKED(IDC_BTN_SCHEDULES_DELEDE, OnBtnSchedulesDelede)
	ON_BN_CLICKED(IDC_BTN_SCHEDULES_CHANGE, OnBtnSchedulesChange)
	ON_BN_CLICKED(IDC_CHK_RC_NAME_AUTO, OnChkRcNameAuto)
	ON_BN_CLICKED(IDC_CHK_SCHEDULES_ALL, OnChkSchedulesAll)
	ON_EN_CHANGE(IDC_EDIT_RC_NAME, OnChangeEditRcName)
	ON_LBN_SELCHANGE(IDC_LIST_RESOURCES, OnSelchangeListResources)
	ON_LBN_SELCHANGE(IDC_LIST_SCHEDULES, OnSelchangeListSchedules)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTCTRL_DATA_PROVIDERS, OnItemchangedListctrlDataProviders)
	ON_CBN_SELCHANGE(IDC_CMB_RC_DATA_PROVIDER, OnSelchangeCmbRcDataProvider)
	ON_LBN_KILLFOCUS(IDC_LIST_SCHEDULES, OnKillfocusListSchedules)
	ON_BN_CLICKED(IDC_BTN_RESOURCES_MOVE_DOWN, OnBtnResourcesMoveDown)
	ON_BN_CLICKED(IDC_BTN_RESOURCES_MOVE_UP, OnBtnResourcesMoveUp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalendarResourcesDlg message handlers

BOOL CCalendarResourcesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrlDataProviders.InsertColumn(0, _T(""), 0, 25);
	m_ctrlDataProviders.InsertColumn(1, _T("Type"), 0, 90);
	m_ctrlDataProviders.InsertColumn(2, _T("Data"), 0, 280);
	ListView_SetExtendedListViewStyle(m_ctrlDataProviders.GetSafeHwnd(), LVS_EX_FULLROWSELECT);
	
	UpdateDataProvidersList();
	UpdateResourcesList();
	UpdateResourceInfoPane();

	m_ctrlSchedules.setParentDlg(this);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCalendarResourcesDlg::UpdateDataProvidersList()
{
	// Clear old list
	int nSel = m_ctrlDataProviders.GetNextItem(-1, LVNI_FOCUSED);
	m_ctrlDataProviders.DeleteAllItems();

	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

	// Iterate all data providers
	int nCount = m_pRCMan->GetDataProvidersCount();
	for (int i = 0; i < nCount; i++)
	{
		CXTPCalendarData* pDP = m_pRCMan->GetDataProvider(i);
		ASSERT(pDP);
		if (!pDP) {
			continue;
		}
		
		int nIndex = m_ctrlDataProviders.GetItemCount();
		CString strIndex; 
		strIndex.Format(_T("%d"), nIndex);
		
		CString strDPType = GetDPType(pDP->GetType());
		CString strData = pDP->GetDataSource();

		nIndex = m_ctrlDataProviders.InsertItem(nIndex, strIndex);
		m_ctrlDataProviders.SetItem(nIndex, 1, LVIF_TEXT, strDPType, -1, 0, 0, 0);
		m_ctrlDataProviders.SetItem(nIndex, 2, LVIF_TEXT, strData, -1, 0, 0, 0);
	}

	if (nSel >= 0 && m_ctrlDataProviders.GetItemCount())
	{
		UINT uFSmask = LVNI_FOCUSED|LVNI_SELECTED;

		nSel = min(m_ctrlDataProviders.GetItemCount() - 1, nSel);
		m_ctrlDataProviders.SetItemState(nSel, uFSmask, uFSmask);
	}

	UpdateDataProviders_RCCombo();
}

void CCalendarResourcesDlg::UpdateDataProviders_RCCombo()
{
	m_ctrlRCDataProvider.ResetContent();

	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

	int nCount = m_pRCMan->GetDataProvidersCount();
	for (int i = 0; i < nCount; i++)
	{
		CXTPCalendarData* pDP = m_pRCMan->GetDataProvider(i);
		ASSERT(pDP);
		if (!pDP) {
			continue;
		}
				
		CString strDP; 
		strDP.Format(_T("%d - (%s) %s"), i, GetDPType(pDP->GetType()), pDP->GetDataSource());
		
		int nIndex = m_ctrlRCDataProvider.AddString(strDP);
		m_ctrlRCDataProvider.SetItemData(nIndex, (DWORD_PTR)pDP);
	}

	UpdateSchedulesList();
}

void CCalendarResourcesDlg::UpdateResourcesList()
{
	int nSel = m_ctrlResources.GetCurSel();
	m_ctrlResources.ResetContent();

	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

	int nCount = m_pRCMan->GetResourcesCount();
	for (int i = 0; i < nCount; i++)
	{
		CXTPCalendarResourceDescription* pRCDesc = m_pRCMan->GetResource(i);
		if (!pRCDesc || !pRCDesc->m_ptrResource) {
			ASSERT(FALSE);
			continue;
		}

		int nIndex = m_ctrlResources.AddString(pRCDesc->m_ptrResource->GetName());
		m_ctrlResources.SetCheck(nIndex, pRCDesc->m_bEnabled ? 1 : 0);		
		m_ctrlResources.SetItemData(nIndex, (DWORD_PTR)pRCDesc);
	}

	if (nSel >= 0 && m_ctrlResources.GetCount())
	{
		nSel = min(m_ctrlResources.GetCount() - 1, nSel);
		m_ctrlResources.SetCurSel(nSel);
		m_ctrlResources.SetSel(nSel);
	}
}

void CCalendarResourcesDlg::UpdateResourceInfoPane()
{
	ASSERT(m_pRCMan);
    // Get current resource description	
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource)
	{
		EnableResourceInfoPane(FALSE);
		return;
	}
	EnableResourceInfoPane(TRUE);

	// Update properties
	m_bChangeEditRcName_internal = TRUE;
	m_ctrlRCName.SetWindowText(pRCDesc->m_ptrResource->GetName());
	m_bChangeEditRcName_internal = FALSE;

	m_ctrlRCNameAuto.SetCheck(pRCDesc->m_bGenerateName);
	m_ctrlRCName.EnableWindow(!pRCDesc->m_bGenerateName);

	// Set corresponding data provider in combobox
	int nDPIndex = -1;
	CXTPCalendarData* pData = pRCDesc->m_ptrResource->GetDataProvider();
	if (pData)
	{
		CString strConStr = pData->GetConnectionString();
		
		m_pRCMan->GetDataProvider(strConStr, &nDPIndex);

		if (nDPIndex < 0 || nDPIndex >= m_ctrlRCDataProvider.GetCount()) {
			nDPIndex = -1;
		}
	}
	m_ctrlRCDataProvider.SetCurSel(nDPIndex);

	// continue
	m_ctrlSchedulesAll.SetCheck(0);
	UpdateSchedulesList();	

	ProcessAutoName();
}

void CCalendarResourcesDlg::UpdateSchedulesList()
{
	ASSERT(m_pRCMan);

	int nSelSch = m_ctrlSchedules.GetCurSel();			
	m_ctrlSchedules.ResetContent();

	m_ctrlScheduleNewName.SetWindowText(_T(""));

	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource)
	{
		EnableSchedulesInfoControls(FALSE);
		return;
	}

	//------------------------------------------------------------------
	CXTPCalendarResource* pRC = pRCDesc->m_ptrResource;
	CXTPCalendarData* pData = pRC ? pRC->GetDataProvider() : NULL;
	CXTPCalendarSchedules* pSchedules = pData ? pData->GetSchedules() : NULL;
	if (!pSchedules) 
	{	
		EnableSchedulesInfoControls(FALSE);
		return;
	}
	EnableSchedulesInfoControls(TRUE);

	// Iterate schedules
	int nCount = pSchedules->GetCount();
	for (int i = 0; i < nCount; i++)
	{
		CXTPCalendarSchedule* pSch = pSchedules->GetAt(i);
		ASSERT(pSch);
		if (!pSch) {
			continue;
		}
        
		int nIndex = m_ctrlSchedules.AddString(pSch->GetName());
		m_ctrlSchedules.SetItemData(nIndex, (DWORD)pSch->GetID());
		
		BOOL bVisible = pRC->ExistsScheduleID(pSch->GetID(), FALSE);
		m_ctrlSchedules.SetCheck(nIndex, bVisible ? 1 : 0);		
	}

	if (nSelSch >= 0 && m_ctrlSchedules.GetCount())
	{
		nSelSch = min(m_ctrlSchedules.GetCount() - 1, nSelSch);
		m_ctrlSchedules.SetSel(nSelSch);

	}
		
	//-----------
	m_ctrlSchedulesAll.SetCheck(pRC->IsSchedulesSetEmpty() ? 1 : 0);
	UpdateSchedulesAll_DependsCtrls();
}

void CCalendarResourcesDlg::UpdateSchedulesAll_DependsCtrls()
{
	int nCheck = m_ctrlSchedulesAll.GetCheck();

	if (nCheck)
		m_ctrlSchedules.LockAllCheckBoxes(0);
	else
		m_ctrlSchedules.UnlockAllCheckBoxes();
}

void CCalendarResourcesDlg::EnableResourceInfoPane(BOOL bEnable)
{
	m_ctrlRCName.EnableWindow(bEnable);	
	m_ctrlRCNameAuto.EnableWindow(bEnable);	
	
	m_ctrlRCDataProvider.EnableWindow(bEnable);

	EnableSchedulesInfoControls(bEnable);
}

void CCalendarResourcesDlg::EnableSchedulesInfoControls(BOOL bEnable)
{
	m_ctrlSchedulesAll.EnableWindow(bEnable);	
	m_ctrlSchedules.EnableWindow(bEnable);	

	m_ctrlSchedulesDelete.EnableWindow(bEnable);	
	m_ctrlSchedulesAdd.EnableWindow(bEnable);	
	m_ctrlScheduleNewName.EnableWindow(bEnable);
}


//****************
void CCalendarResourcesDlg::OnBtnDataProviderAdd() 
{
	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

	CDataProvidersOptions dlgDP;
	
	dlgDP.m_bInitFromProfile = FALSE;
	dlgDP.m_bSaveToProfile = FALSE;
	
	int nDlgRes = (int)dlgDP.DoModal();
	if (nDlgRes != IDOK) {
		return;
	}

	ASSERT(!dlgDP.m_strConnectionString.IsEmpty());

	// Already present ?
	ASSERT(!m_pRCMan->GetDataProvider(dlgDP.m_strConnectionString));

	const int eDPFAll = CXTPCalendarResourcesManager::xtpCalendarDPF_CreateIfNotExists |
						CXTPCalendarResourcesManager::xtpCalendarDPF_SaveOnDestroy | 
						CXTPCalendarResourcesManager::xtpCalendarDPF_CloseOnDestroy;
	m_pRCMan->AddDataProvider(dlgDP.m_strConnectionString, eDPFAll);
	
	UpdateDataProvidersList();
}

void CCalendarResourcesDlg::OnBtnDataProviderDelete() 
{
	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

	int nSel = m_ctrlDataProviders.GetNextItem(-1, LVNI_FOCUSED);

	if (nSel >= 0 && nSel < m_ctrlDataProviders.GetItemCount())
	{
		m_pRCMan->RemoveDataProvider(nSel);

		UpdateDataProvidersList();
	}	
}

void CCalendarResourcesDlg::OnBtnDataProviderEdit() 
{
	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

    // get selected data provider
	int nSel = m_ctrlDataProviders.GetNextItem(-1, LVNI_FOCUSED);

	if (nSel < 0 || nSel >= m_ctrlDataProviders.GetItemCount())	{
		return;
	}
			
	if (!m_pRCMan->GetDataProvider(nSel)) {
		ASSERT(FALSE);
		return;
	}

	// Prepare and show DP options dialog
	CDataProvidersOptions dlgDP;
	
	dlgDP.m_bInitFromProfile = FALSE;
	dlgDP.m_bSaveToProfile = FALSE;
	dlgDP.m_strConnectionString = m_pRCMan->GetDataProvider(nSel)->GetConnectionString();
	
	int nDlgRes = (int)dlgDP.DoModal();
	if (nDlgRes != IDOK) {
		return;
	}

	ASSERT(!dlgDP.m_strConnectionString.IsEmpty());

	// Already present ?
	int n = 0;
	ASSERT(!m_pRCMan->GetDataProvider(dlgDP.m_strConnectionString, &n) || n == nSel);
	UNREFERENCED_PARAMETER(n);

	m_pRCMan->SetDataProvider(nSel, dlgDP.m_strConnectionString, TRUE);

	UpdateDataProvidersList();
}


//****************
void CCalendarResourcesDlg::OnBtnResourcesAdd() 
{
	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return;
	}

	m_pRCMan->AddResource(_T("new resource"), TRUE);
	
	UpdateResourcesList();	

	int nCount = m_ctrlResources.GetCount();
	if (nCount) 
	{
		m_ctrlResources.SetCurSel(-1);

		m_ctrlResources.SetCurSel(nCount-1);
		m_ctrlResources.SetSel(nCount-1);
	}

	UpdateResourceInfoPane();
}

void CCalendarResourcesDlg::OnBtnResourcesDelete() 
{
	if (!m_pRCMan) {
		return;
	}

	int nSel = m_ctrlResources.GetCurSel();
	if (nSel >= 0 && m_ctrlResources.GetCount())
	{		
		m_pRCMan->RemoveResource(nSel);

		UpdateResourcesList();	
	}
	UpdateResourceInfoPane();
}

void CCalendarResourcesDlg::OnBtnResourcesMoveDown() 
{
	ASSERT(m_pRCMan);
	int nIndex = -1;
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc(&nIndex);
	if (!m_pRCMan || !pRCDesc) {
		return;
	}
	if (nIndex+1 >= m_pRCMan->GetResourcesCount()) {
		return;
	}

	m_pRCMan->MoveResource(nIndex, nIndex + 1);

	m_ctrlResources.SetCurSel(nIndex + 1);
	m_ctrlResources.SetSel(nIndex + 1);

	UpdateResourcesList();	
	UpdateResourceInfoPane();
}

void CCalendarResourcesDlg::OnBtnResourcesMoveUp() 
{
		ASSERT(m_pRCMan);
	int nIndex = -1;
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc(&nIndex);
	if (!m_pRCMan || !pRCDesc) {
		return;
	}
	if (nIndex - 1 < 0) {
		return;
	}

	m_pRCMan->MoveResource(nIndex, nIndex - 1);

	m_ctrlResources.SetCurSel(nIndex - 1);
	m_ctrlResources.SetSel(nIndex - 1);

	UpdateResourcesList();	
	UpdateResourceInfoPane();
}


//****************
void CCalendarResourcesDlg::OnBtnSchedulesAdd() 
{
	CString strNewSchName;
	m_ctrlScheduleNewName.GetWindowText(strNewSchName);
    
	if (strNewSchName.IsEmpty()) {
		return;
	}

	ASSERT(m_pRCMan);

	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource) {
		return;
	}
	CXTPCalendarResource* pRC = pRCDesc->m_ptrResource;
	CXTPCalendarData* pData = pRC ? pRC->GetDataProvider() : NULL;
	CXTPCalendarSchedules* pSchedules = pData ? pData->GetSchedules() : NULL;
	if (!pSchedules) {
		return;
	}

	pSchedules->AddNewSchedule(strNewSchName);
		
	//-------------------------------------------------------
	UpdateSchedulesList_saveState();

	int nSchCount = m_ctrlSchedules.GetCount();	
	if (nSchCount > 0)
	{
		int nSchSel = nSchCount-1;
		m_ctrlSchedules.SetCurSel(nSchSel);
		m_ctrlSchedules.SetSel(nSchSel);
		
		m_ctrlSchedules.GetText(nSchSel, strNewSchName);
		m_ctrlScheduleNewName.SetWindowText(strNewSchName);
	}

	ProcessAutoName();
}

void CCalendarResourcesDlg::OnBtnSchedulesDelede() 
{
	int nSchSel = m_ctrlSchedules.GetCurSel();
	int nSchCount = m_ctrlSchedules.GetCount();

	if (nSchSel < 0 || nSchSel >= nSchCount) {
		return;
	}

	ASSERT(m_pRCMan);

	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource) {
		return;
	}
	CXTPCalendarResource* pRC = pRCDesc->m_ptrResource;
	CXTPCalendarData* pData = pRC ? pRC->GetDataProvider() : NULL;
	CXTPCalendarSchedules* pSchedules = pData ? pData->GetSchedules() : NULL;
	if (!pSchedules) {
		return;
	}

	UINT uSchID = (UINT)m_ctrlSchedules.GetItemData(nSchSel);
	pSchedules->RemoveSchedule(uSchID);

	//-------------------------------------------------------
	UpdateSchedulesList_saveState();
	ProcessAutoName();
}

void CCalendarResourcesDlg::OnBtnSchedulesChange()
{
	int nSchSel = m_ctrlSchedules.GetCurSel();
	int nSchCount = m_ctrlSchedules.GetCount();

	if (nSchSel < 0 || nSchSel >= nSchCount) {
		return;
	}

	ASSERT(m_pRCMan);

	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource) {
		return;
	}
	CXTPCalendarResource* pRC = pRCDesc->m_ptrResource;
	CXTPCalendarData* pData = pRC ? pRC->GetDataProvider() : NULL;
	CXTPCalendarSchedules* pSchedules = pData ? pData->GetSchedules() : NULL;
	if (!pSchedules) {
		return;
	}

	CString strSchName;
	m_ctrlScheduleNewName.GetWindowText(strSchName);
	UINT uSchID = (UINT)m_ctrlSchedules.GetItemData(nSchSel);

	pSchedules->SetScheduleName(uSchID, strSchName);

	//-------------------------------------------------------
	UpdateSchedulesList_saveState();
	ProcessAutoName();
}

void CCalendarResourcesDlg::UpdateSchedulesList_saveState()
{
	int nSchSel = m_ctrlSchedules.GetCurSel();
	
	BOOL bAll_Enabled = m_ctrlSchedulesAll.IsWindowEnabled();

	UpdateSchedulesList();

	m_ctrlSchedulesAll.EnableWindow(bAll_Enabled);
	UpdateSchedulesAll_DependsCtrls();

	int nSchCount = m_ctrlSchedules.GetCount();
	nSchSel = min(nSchSel, nSchCount-1);
	if (nSchSel >= 0)
	{
		m_ctrlSchedules.SetCurSel(nSchSel);
		m_ctrlSchedules.SetSel(nSchSel);

		CString strSchName;
		m_ctrlSchedules.GetText(nSchSel, strSchName);
		m_ctrlScheduleNewName.SetWindowText(strSchName);
	}
}

//****************
void CCalendarResourcesDlg::OnChkRcNameAuto() 
{	
	ApplyUpdateRcNameAuto();

	ProcessAutoName();
}

void CCalendarResourcesDlg::ApplyUpdateRcNameAuto() 
{
	ASSERT(m_pRCMan);
	int nIndex = -1;
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc(&nIndex);
	if (!m_pRCMan || !pRCDesc) {
		return;
	}

	int nCheck = m_ctrlRCNameAuto.GetCheck();
	m_ctrlRCName.EnableWindow(!nCheck);

	pRCDesc->m_bGenerateName = !!nCheck;
}

void CCalendarResourcesDlg::OnChkSchedulesAll() 
{
	UpdateSchedulesAll_DependsCtrls();

	ApplySchedules();

	ProcessAutoName();
}

void CCalendarResourcesDlg::OnChangeEditRcName() 
{
	if (m_bChangeEditRcName_internal) {
		return;
	}

	ASSERT(m_pRCMan);
	
	int nIndex = -1;
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc(&nIndex);
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource) {
		return;
	}
	m_nRcNameAuto_StoredState = -1;

	CString strName;
	m_ctrlRCName.GetWindowText(strName);
	pRCDesc->m_ptrResource->SetName(strName);
	
	m_ctrlResources.DeleteString(nIndex);

	nIndex = m_ctrlResources.InsertString(nIndex, strName);
	m_ctrlResources.SetCheck(nIndex, pRCDesc->m_bEnabled ? 1 : 0);		
	m_ctrlResources.SetItemData(nIndex, (DWORD_PTR)pRCDesc);	

	m_ctrlResources.SetCurSel(nIndex);
	m_ctrlResources.SetSel(nIndex);
	m_ctrlResources.Invalidate();
}

void CCalendarResourcesDlg::OnSelchangeListResources() 
{
	m_nRcNameAuto_StoredState = -1;
	UpdateResourceInfoPane();	
}

void CCalendarResourcesDlg::OnSelchangeListSchedules() 
{
		
}

void CCalendarResourcesDlg::OnItemchangedListctrlDataProviders(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	pNMListView;	
	*pResult = 0;
}

//****************
void CCalendarResourcesDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CCalendarResourcesDlg::OnOK() 
{
	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		CDialog::OnOK();
		return;
	}

	int nCount = m_ctrlResources.GetCount();
	for (int i = 0; i < nCount; i++)
	{
		CXTPCalendarResourceDescription* pRCDesc = 
			(CXTPCalendarResourceDescription*)m_ctrlResources.GetItemData(i);
		if (!pRCDesc) 
		{
			ASSERT(FALSE);
			continue;
		}
		
		pRCDesc->m_bEnabled = !!m_ctrlResources.GetCheck(i);		
	}
	
	CDialog::OnOK();
}

void CCalendarResourcesDlg::OnSelchangeCmbRcDataProvider() 
{
	ASSERT(m_pRCMan);
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource)
	{
		UpdateResourceInfoPane();
		return;
	}
	//------------------------------------------------------------------
	CXTPCalendarData* pData = NULL;

	int nDPSel = m_ctrlRCDataProvider.GetCurSel();
	if (nDPSel >= 0 && nDPSel < m_pRCMan->GetDataProvidersCount()) {
		pData = m_pRCMan->GetDataProvider(nDPSel);		
	}
	
	pRCDesc->m_ptrResource->SetDataProvider(pData);
	UpdateSchedulesList();
}

void CCalendarResourcesDlg::OnKillfocusListSchedules() 
{
	
}

void CCalendarResourcesDlg::ApplySchedules() 
{
	ASSERT(m_pRCMan);

	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!m_pRCMan || !pRCDesc || !pRCDesc->m_ptrResource) {
		return;
	}
	//------------------------------------------------------------------
	CXTPCalendarResource* pRC = pRCDesc->m_ptrResource;
	if (!pRC->GetSchedules()) {
		ASSERT(FALSE);
		return;
	}

	//====================================================
	pRC->GetSchedules()->RemoveAll();

	if (m_ctrlSchedulesAll.GetCheck()) {
		return;
	}

	//====================================================
	int nCount = m_ctrlSchedules.GetCount();
	for (int i = 0; i < nCount; i++)
	{
		int nCheck = m_ctrlSchedules.GetCheck(i);
		if (nCheck) 
		{
			UINT uSchID = (UINT)m_ctrlSchedules.GetItemData(i);
			pRC->GetSchedules()->Add(uSchID);
		}
	}
}

CXTPCalendarResourceDescription* CCalendarResourcesDlg::GetSelRCDesc(int* pnIndex) 
{
	ASSERT(m_pRCMan);
	if (!m_pRCMan) {
		return NULL;
	}
	int nRCSel = m_ctrlResources.GetCurSel();	
	if (nRCSel < 0 || nRCSel >= m_ctrlResources.GetCount()){
		return NULL;
	}
	CXTPCalendarResourceDescription* pRCDesc = (CXTPCalendarResourceDescription*)m_ctrlResources.GetItemData(nRCSel);
	if (pnIndex) {
		*pnIndex = nRCSel;
	}
	return pRCDesc;
}

void CCalendarResourcesDlg::ProcessAutoName()
{
	CXTPCalendarResourceDescription* pRCDesc = GetSelRCDesc();
	if (!pRCDesc || !pRCDesc->m_ptrResource || 
		!pRCDesc->m_ptrResource->GetSchedules() )
	{
		return;
	}

	if (!pRCDesc->m_ptrResource->GetDataProvider() || 
		!pRCDesc->m_ptrResource->GetDataProvider()->GetSchedules()) 
	{
		m_ctrlRCNameAuto.SetCheck(0);
		ApplyUpdateRcNameAuto();

		m_ctrlRCNameAuto.EnableWindow(FALSE);
		return;
	}

	CString strNameNew = _CalcAutoRCName();
	BOOL bAutoName_enabled = !strNameNew.IsEmpty();

	m_ctrlRCNameAuto.EnableWindow(bAutoName_enabled);

	if (bAutoName_enabled) 
	{		
		if (m_ctrlRCNameAuto.GetCheck() || m_nRcNameAuto_StoredState == 1)
		{
			m_nRcNameAuto_StoredState = -1;
			if (m_ctrlRCNameAuto.GetCheck() == 0) 
			{				
				m_ctrlRCNameAuto.SetCheck(1); 
				ApplyUpdateRcNameAuto();
			}	

			CString strNamePrev;			
			m_ctrlRCName.GetWindowText(strNamePrev);
			
			if (strNameNew != strNamePrev) {
				m_ctrlRCName.SetWindowText(strNameNew);
			}
		}		
	}
	else
	{
		if (m_nRcNameAuto_StoredState == -1) {
			m_nRcNameAuto_StoredState = m_ctrlRCNameAuto.GetCheck();
		}
		m_ctrlRCNameAuto.SetCheck(0);
		ApplyUpdateRcNameAuto();
	}

}

CString CCalendarResourcesDlg::_CalcAutoRCName() 
{
	ASSERT(m_pRCMan);

	int nCount = m_ctrlSchedules.GetCount();

	if (m_ctrlSchedulesAll.GetCheck())
	{
		return _T("");
	}

    // Automatic name calculation algorithm could be any of your choice.
	// There is implemented a simplest one with some redundancy
	int nCheckedCount = 0;
	CString strName;

	for (int i = 0; i < nCount; i++)
	{
		int nCheck = m_ctrlSchedules.GetCheck(i);
		if (nCheck) 
		{
			CString strText;
			m_ctrlSchedules.GetText(i, strText);
			nCheckedCount++;

			strName += strName.IsEmpty() ? _T("") : _T(", ");
			strName += strText;
		}
	}
	return nCheckedCount == 1 ? strName : _T("");			
}

void CCalendarResourcesDlg::_OnSelchangeSchedules()
{
	ApplySchedules();
	ProcessAutoName();

	int nSchSel = m_ctrlSchedules.GetCurSel();
	int nSchCount = m_ctrlSchedules.GetCount();

	if (nSchSel < 0 || nSchSel >= nSchCount) {
		return;
	}

	CString strSchName;
	m_ctrlSchedules.GetText(nSchSel, strSchName);

	m_ctrlScheduleNewName.SetWindowText(strSchName);
}

//////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CCheckListBox_withEvents, CCheckListBox)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CCheckListBox_withEvents::CCheckListBox_withEvents() 
{
	m_pParentDlg = NULL;
	m_nCheckLocked = -1;
}

void CCheckListBox_withEvents::setParentDlg(CCalendarResourcesDlg* pParentDlg) 
{
	m_pParentDlg = pParentDlg;
}

void CCheckListBox_withEvents::OnLButtonDown(UINT nFlags, CPoint point)
{
	CCheckListBox::OnLButtonDown(nFlags, point);

	_OnCheckChanged();
}

void CCheckListBox_withEvents::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CCheckListBox::OnLButtonDblClk(nFlags, point);

	_OnCheckChanged();
}

void CCheckListBox_withEvents::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CCheckListBox::OnKeyDown(nChar, nRepCnt, nFlags);

	_OnCheckChanged();
}

void CCheckListBox_withEvents::_OnCheckChanged()
{
	if (m_nCheckLocked >= 0) {
		AllSetCheck(m_nCheckLocked);
	}

	if (m_pParentDlg) {
		m_pParentDlg->_OnSelchangeSchedules();
	}
}

void CCheckListBox_withEvents::AllSetCheck(int nCheck)
{
	int nCount = GetCount();
	for (int i = 0; i < nCount; i++)
	{
		int nCheck_i = GetCheck(i);
		if (nCheck != nCheck_i) 
		{
			SetCheck(i, nCheck);
		}
	}
}

void CCheckListBox_withEvents::LockAllCheckBoxes(int nCheckLocked)
{
	m_nCheckLocked = nCheckLocked;

	if (m_nCheckLocked >= 0) {
		AllSetCheck(m_nCheckLocked);
	}
}

void CCheckListBox_withEvents::UnlockAllCheckBoxes(int nCheck)
{
	int nLocked = m_nCheckLocked;
	m_nCheckLocked = -1;

	if (nLocked >= 0 && nCheck >= 0) {
		AllSetCheck(nCheck);
	}
}
