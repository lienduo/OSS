// CalendarDemo.h : main header file for the CALENDARDEMO application
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

#if !defined(AFX_CALENDARDEMO_H__AFCC35AE_1F74_407C_9142_1222C34A7B29__INCLUDED_)
#define AFX_CALENDARDEMO_H__AFCC35AE_1F74_407C_9142_1222C34A7B29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CCalendarDemoView;
class CXTPCalendarResourcesManager;

/////////////////////////////////////////////////////////////////////////////
// CCalendarDemoApp:
// See CalendarDemo.cpp for the implementation of this class
//
class CCalendarDemoApp : public CWinApp
{
public:
	CCalendarDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalendarDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCalendarDemoApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileOpen();
	afx_msg void OnMultiSchedulesCfg();
	afx_msg void OnMultiSchedulesSample();
	afx_msg void OnMultiSchedulesSampleExt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	BOOL m_bOnOpenFile_CreateNewIfNotExist;

	BOOL m_bOnOpenFile_AppStarting;

	CXTPCalendarResourcesManager* m_pCalRCman;

	CString GetModulePath();
	
	CCalendarDemoView* GetCalendarDemoView();
};

/////////////////////////////////////////////////////////////////////////////
// This dialog allows to modify some advances Data Providers related options
// in order to change its performance 
class CCalendarInternalOptions : public CDialog
{
	DECLARE_DYNAMIC(CCalendarInternalOptions)

public:
	CCalendarInternalOptions(CXTPCalendarData* pCData, CWnd* pParent = NULL);   // standard constructor
	virtual ~CCalendarInternalOptions();

	// Dialog Data
	enum { IDD = IDD_INTERNAL_OPTIONS };

	virtual BOOL OnInitDialog ();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	CXTPCalendarData* m_ptrCData;

	CComboBox m_ctrlDBDPCacheModeCb;

public:
	CStatic m_ctrlDBDPCacheModeComment;
	afx_msg void OnBnClickedOk();
};

#if _MSC_VER < 1200
inline void DDX_DateTimeCtrl(CDataExchange* pDX, int nIDC, COleDateTime& value)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	CWnd* pWnd = CWnd::FromHandle(hWndCtrl);

	if (pDX->m_bSaveAndValidate)
	{
		SYSTEMTIME sysTime;
		BOOL bRetVal = TRUE;
		
		LRESULT result = pWnd->SendMessage(DTM_GETSYSTEMTIME, 0, (LPARAM) &sysTime);
		if (result == GDT_VALID)
		{
			value = COleDateTime(sysTime);
			ASSERT(value.GetStatus() == COleDateTime::valid);
		}
		else if (result == GDT_NONE)
		{
			value.SetStatus(COleDateTime::null);
		}
		else
		{
			value.SetStatus(COleDateTime::invalid);
		}
	}
	else
	{
		// make sure the time isn't invalid
		ASSERT(value.GetStatus() != COleDateTime::invalid);
		
		SYSTEMTIME sysTime;
		WPARAM wParam = GDT_NONE;
		if (value.GetStatus() == COleDateTime::valid &&
			GETASSYSTEMTIME_DT(value, sysTime))
		{
			wParam = GDT_VALID;
		}
		
		pWnd->SendMessage(DTM_SETSYSTEMTIME, wParam, (LPARAM) &sysTime);

	}
}

#endif


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDARDEMO_H__AFCC35AE_1F74_407C_9142_1222C34A7B29__INCLUDED_)
