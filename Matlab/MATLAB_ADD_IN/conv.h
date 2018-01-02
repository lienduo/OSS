// conv.h : main header file for the CONV application
//

#if !defined(AFX_CONV_H__BC3A19B8_3B69_4888_9F4B_B2CD76BCE477__INCLUDED_)
#define AFX_CONV_H__BC3A19B8_3B69_4888_9F4B_B2CD76BCE477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConvApp:
// See conv.cpp for the implementation of this class
//

class CConvApp : public CWinApp
{
public:
	CConvApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConvApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONV_H__BC3A19B8_3B69_4888_9F4B_B2CD76BCE477__INCLUDED_)
