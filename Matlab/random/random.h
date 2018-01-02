// random.h : main header file for the RANDOM application
//

#if !defined(AFX_RANDOM_H__E12B5649_B145_40D9_9E49_2B15B52798CE__INCLUDED_)
#define AFX_RANDOM_H__E12B5649_B145_40D9_9E49_2B15B52798CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRandomApp:
// See random.cpp for the implementation of this class
//

class CRandomApp : public CWinApp
{
public:
	CRandomApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRandomApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRandomApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANDOM_H__E12B5649_B145_40D9_9E49_2B15B52798CE__INCLUDED_)
