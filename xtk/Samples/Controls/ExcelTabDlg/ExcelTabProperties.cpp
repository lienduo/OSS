// ExcelTabProperties.cpp : implementation file
//

#include "stdafx.h"
#include "ExcelTab.h"
#include "ExcelTabProperties.h"
#include "ExcelEditCtrl.h"
#include "ExcelTabDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

template <class T>
class CAutoDestructCtrl : public T
{
protected:
	virtual void PostNcDestroy()
	{
		delete this;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CExcelTabProperties dialog

CExcelTabProperties::CExcelTabProperties(BOOL& bBottom, BOOL& bHasArrows, BOOL& bHasHomeEnd, BOOL& bHScroll, CExcelTabDlg* pParent /*=NULL*/)
	: CDialog(CExcelTabProperties::IDD, pParent)
	, m_bBottom(bBottom)
	, m_bHasArrows(bHasArrows)
	, m_bHasHomeEnd(bHasHomeEnd)
	, m_bHScroll(bHScroll)
	, m_pParentWnd(pParent)
	, m_pExcelTabCtrl(m_pParentWnd->m_pExcelTabCtrl)
{
	//{{AFX_DATA_INIT(CExcelTabProperties)
	m_iTabNum = 0;
	m_csText = _T("");
	//}}AFX_DATA_INIT

	// default values
	m_crBack = m_pExcelTabCtrl->GetTabBackColor();
	m_crText = m_pExcelTabCtrl->GetTabTextColor();
	m_crSelBack = m_pExcelTabCtrl->GetSelTabBackColor();
	m_crSelText = m_pExcelTabCtrl->GetSelTabTextColor();
}

void CExcelTabProperties::DoDataExchange(CDataExchange* pDX)
{
	const int nTabs = m_pExcelTabCtrl->GetItemCount() - 1;

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExcelTabProperties)
	DDX_Control(pDX, IDC_CLR_SELTEXT, m_cpSelText);
	DDX_Control(pDX, IDC_CLR_TEXT, m_cpText);
	DDX_Control(pDX, IDC_CLR_SELBACK, m_cpSelBack);
	DDX_Control(pDX, IDC_CLR_BACK, m_cpBack);
	DDX_Control(pDX, IDC_MODIFY_TAB, m_btnModifyTab);
	DDX_Control(pDX, IDC_DELETE_TAB, m_btnDeleteTab);
	DDX_Control(pDX, IDC_DELETE_ALL, m_btnDeleteAll);
	DDX_Control(pDX, IDC_ADD_TAB, m_btnAddTab);
	DDX_Text(pDX, IDC_TAB_NUM, m_iTabNum);
	DDV_MinMaxUInt(pDX, m_iTabNum, 0, nTabs);
	DDX_Text(pDX, IDC_TEXT, m_csText);
	DDX_Check(pDX, IDC_FTS_XT_BOTTOM, m_bBottom);
	DDX_Check(pDX, IDC_FTS_XT_HASARROWS, m_bHasArrows);
	DDX_Check(pDX, IDC_FTS_XT_HASHOMEEND, m_bHasHomeEnd);
	DDX_Check(pDX, IDC_FTS_XT_HSCROLL, m_bHScroll);
	//}}AFX_DATA_MAP
	DDX_XTColorPicker(pDX, IDC_CLR_TEXT, m_crText);
	DDX_XTColorPicker(pDX, IDC_CLR_BACK, m_crBack);
	DDX_XTColorPicker(pDX, IDC_CLR_SELTEXT, m_crSelText);
	DDX_XTColorPicker(pDX, IDC_CLR_SELBACK, m_crSelBack);
}


BEGIN_MESSAGE_MAP(CExcelTabProperties, CDialog)
	//{{AFX_MSG_MAP(CExcelTabProperties)
	ON_BN_CLICKED(IDC_FTS_XT_BOTTOM, OnFtsXtBottom)
	ON_BN_CLICKED(IDC_FTS_XT_HASARROWS, OnFtsXtHasarrows)
	ON_BN_CLICKED(IDC_FTS_XT_HASHOMEEND, OnFtsXtHashomeend)
	ON_BN_CLICKED(IDC_FTS_XT_HSCROLL, OnFtsXtHscroll)
	ON_BN_CLICKED(IDC_ADD_TAB, OnAddTab)
	ON_BN_CLICKED(IDC_DELETE_ALL, OnDeleteAll)
	ON_BN_CLICKED(IDC_DELETE_TAB, OnDeleteTab)
	ON_BN_CLICKED(IDC_MODIFY_TAB, OnModifyTab)
	ON_EN_CHANGE(IDC_TEXT, OnChangeText)
	ON_EN_CHANGE(IDC_TAB_NUM, OnChangeTabNum)
	//}}AFX_MSG_MAP
	ON_CPN_XT_SELENDOK(IDC_CLR_TEXT, OnSelEndOkTextClr)
	ON_CPN_XT_SELENDOK(IDC_CLR_BACK, OnSelEndOkBackClr)
	ON_CPN_XT_SELENDOK(IDC_CLR_SELTEXT, OnSelEndOkSelTextClr)
	ON_CPN_XT_SELENDOK(IDC_CLR_SELBACK, OnSelEndOkSelBackClr)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExcelTabProperties message handlers

void CExcelTabProperties::OnFtsXtBottom() 
{
	UpdateData();
	m_pParentWnd->UpdateExcelTab();
}

void CExcelTabProperties::OnFtsXtHasarrows() 
{
	UpdateData();
	m_pParentWnd->UpdateExcelTab();
	GetDlgItem(IDC_FTS_XT_HASHOMEEND)->EnableWindow(m_bHasArrows);
}

void CExcelTabProperties::OnFtsXtHashomeend() 
{
	UpdateData();
	m_pParentWnd->UpdateExcelTab();
}

void CExcelTabProperties::OnFtsXtHscroll() 
{
	UpdateData();
	m_pParentWnd->UpdateExcelTab();
}

void CExcelTabProperties::OnAddTab()
{
	if (UpdateData())
	{
		CAutoDestructCtrl<CExcelEditCtrl> *pSheet = new CAutoDestructCtrl<CExcelEditCtrl>();
		pSheet->Create(WS_CHILD | WS_TABSTOP | WS_CLIPCHILDREN |
			WS_HSCROLL | WS_VSCROLL | ES_MULTILINE, CXTPEmptyRect(), m_pExcelTabCtrl, 1000);
		pSheet->SetWindowText(m_csText);
		m_pExcelTabCtrl->InsertItem(m_iTabNum, m_csText, pSheet);
	}
	UpdateDlgStatus();
}

void CExcelTabProperties::OnDeleteAll()
{
	m_pExcelTabCtrl->DeleteAllItems();
	UpdateDlgStatus();
}

void CExcelTabProperties::OnDeleteTab()
{
	if (m_pExcelTabCtrl->GetItemCount() > 0  &&  UpdateData())
	{
		m_pExcelTabCtrl->DeleteItem(m_iTabNum);
	}
	UpdateDlgStatus();
}

void CExcelTabProperties::OnModifyTab()
{
	if (m_pExcelTabCtrl->GetItemCount() > 0  &&  UpdateData())
	{
		m_pExcelTabCtrl->SetItemText(m_iTabNum, m_csText);
	}
	UpdateDlgStatus();
}

void CExcelTabProperties::UpdateDlgStatus()
{
	const bool bHasTabs = (m_pExcelTabCtrl->GetItemCount() > 0);
	m_btnModifyTab.EnableWindow(bHasTabs);
	m_btnDeleteTab.EnableWindow(bHasTabs);
	m_btnModifyTab.EnableWindow(bHasTabs);
}

void CExcelTabProperties::OnChangeText() 
{
	UpdateData();
	m_btnAddTab.EnableWindow(!m_csText.IsEmpty());
}

void CExcelTabProperties::OnSelEndOkTextClr()
{
	UpdateData();
	m_pExcelTabCtrl->SetTabTextColor(m_iTabNum, m_crText);
}

void CExcelTabProperties::OnSelEndOkBackClr()
{
	UpdateData();
	m_pExcelTabCtrl->SetTabBackColor(m_iTabNum, m_crBack);
}

void CExcelTabProperties::OnSelEndOkSelTextClr()
{
	UpdateData();
	m_pExcelTabCtrl->SetSelTabTextColor(m_iTabNum, m_crSelText);
}

void CExcelTabProperties::OnSelEndOkSelBackClr()
{
	UpdateData();
	m_pExcelTabCtrl->SetSelTabBackColor(m_iTabNum, m_crSelBack);
}

void CExcelTabProperties::OnChangeTabNum() 
{
	UpdateData();

	m_crBack = m_pExcelTabCtrl->GetTabBackColor(m_iTabNum);
	m_crText = m_pExcelTabCtrl->GetTabTextColor(m_iTabNum);
	m_crSelBack = m_pExcelTabCtrl->GetSelTabBackColor(m_iTabNum);
	m_crSelText = m_pExcelTabCtrl->GetSelTabTextColor(m_iTabNum);
	m_csText = m_pExcelTabCtrl->GetItemText(m_iTabNum);

	UpdateData(FALSE);
}

BOOL CExcelTabProperties::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// set default values for color pickers.
	m_cpBack.SetDefaultColor(m_crBack);
	m_cpText.SetDefaultColor(m_crText);
	m_cpSelBack.SetDefaultColor(m_crSelBack);
	m_cpSelText.SetDefaultColor(m_crSelText);

	OnChangeTabNum();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
