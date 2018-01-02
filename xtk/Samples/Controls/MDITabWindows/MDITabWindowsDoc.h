// MDITabWindowsDoc.h : interface of the CMDITabWindowsDoc class
//
// This file is a part of the XTREME TOOLKIT MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO 
// BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED 
// WRITTEN CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS 
// OUTLINED IN THE XTREME TOOLKIT LICENSE AGREEMENT.  CODEJOCK SOFTWARE 
// GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE 
// THIS SOFTWARE ON A SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDITABWINDOWSDOC_H__27881607_67EB_4601_9426_7E797DC85221__INCLUDED_)
#define AFX_MDITABWINDOWSDOC_H__27881607_67EB_4601_9426_7E797DC85221__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDITabWindowsDoc : public CDocument
{
protected: // create from serialization only
	CMDITabWindowsDoc();
	DECLARE_DYNCREATE(CMDITabWindowsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDITabWindowsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDITabWindowsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDITabWindowsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDITABWINDOWSDOC_H__27881607_67EB_4601_9426_7E797DC85221__INCLUDED_)
