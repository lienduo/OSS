// SkinPropertyPageControls.h : header file
//

#ifndef __SKINPROPERTYPAGECONTROLS_H__
#define __SKINPROPERTYPAGECONTROLS_H__

/////////////////////////////////////////////////////////////////////////////
// CSkinPropertyPageControls dialog

class CSkinPropertyPageControls : public CPropertyPage
{
	DECLARE_DYNCREATE(CSkinPropertyPageControls)

public:
	CSkinPropertyPageControls();
	virtual ~CSkinPropertyPageControls();

	//{{AFX_DATA(CSkinPropertyPageControls)
	enum { IDD = IDD_PROPPAGE_CONTROLS };
	CListBox	m_wndListBox;
	CComboBox	m_comboNormal;
	CComboBox	m_comboDisabled;
	CScrollBar	m_sbarNormal;
	CScrollBar	m_sbarDisabled;
	CTreeCtrl	m_wndTreeCtrl;
	CListCtrl	m_wndListCtrl;
	CTabCtrl	m_wndTabControl;
	int		m_radioSelected;
	BOOL	m_bSelected;
	CString	m_csNormal;
	CString	m_csDisabled;
	CString	m_csSample;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSkinPropertyPageControls)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CSkinPropertyPageControls)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // __SKINPROPERTYPAGECONTROLS_H__
