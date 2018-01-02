// RibbonMDISampleView.h : interface of the CRibbonMDISampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RIBBONMDISAMPLEVIEW_H__1DA10B36_73A6_4712_A870_CD24CE1D8969__INCLUDED_)
#define AFX_RIBBONMDISAMPLEVIEW_H__1DA10B36_73A6_4712_A870_CD24CE1D8969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRibbonMDISampleCntrItem;

class CRibbonMDISampleView : public CRichEditView
{
protected: // create from serialization only
	CRibbonMDISampleView();
	DECLARE_DYNCREATE(CRibbonMDISampleView)

// Attributes
public:
	CRibbonMDISampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRibbonMDISampleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRibbonMDISampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRibbonMDISampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RibbonMDISampleView.cpp
inline CRibbonMDISampleDoc* CRibbonMDISampleView::GetDocument()
   { return (CRibbonMDISampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIBBONMDISAMPLEVIEW_H__1DA10B36_73A6_4712_A870_CD24CE1D8969__INCLUDED_)
