// ResourceEditorDoc.h : interface of the CResourceEditorDoc class
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

#if !defined(AFX_RESOURCEEDITORDOC_H__015DC1DC_08FD_48C2_8697_E049FB8F1CD7__INCLUDED_)
#define AFX_RESOURCEEDITORDOC_H__015DC1DC_08FD_48C2_8697_E049FB8F1CD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CResourceEditorDoc : public CDocument
{
protected: // create from serialization only
	CResourceEditorDoc();
	DECLARE_DYNCREATE(CResourceEditorDoc)

// Attributes
public:
	CXTPPropExchangeXMLNode* m_pResources;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResourceEditorDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL
	BOOL OnOpenDocument(LPCTSTR lpszPathName);
	BOOL OnSaveDocument(LPCTSTR lpszPathName);

	BOOL AssignResource(CXTPPropExchangeXMLNode* pResources);

// Implementation
public:
	virtual ~CResourceEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	XTP_RESOURCEMANAGER_LANGINFO* m_pLanguageInfo;

// Generated message map functions
protected:
	//{{AFX_MSG(CResourceEditorDoc)
	afx_msg void OnFileExportDll();
	afx_msg void OnFileExportRc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESOURCEEDITORDOC_H__015DC1DC_08FD_48C2_8697_E049FB8F1CD7__INCLUDED_)
