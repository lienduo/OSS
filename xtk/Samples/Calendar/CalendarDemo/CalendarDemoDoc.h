// CalendarDemoDoc.h : interface of the CCalendarDemoDoc class
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

#if !defined(AFX_CALENDARDEMODOC_H__503B51B2_6873_4C40_A4B5_4AFC3A07D591__INCLUDED_)
#define AFX_CALENDARDEMODOC_H__503B51B2_6873_4C40_A4B5_4AFC3A07D591__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

static CString cstrDP_Opt_section = _T("Use DataProvider options");

static CString cstrUseDP_opt = _T("UseDP");	// {"Mem", "DB", "MAPI"}
	static CString cstrUseDP_Mem_optval = _T("Mem");
	static CString cstrUseDP_DB_optval = _T("DB");
	static CString cstrUseDP_MAPI_optval	= _T("MAPI");

static CString cstrUseDP_Mem_File_opt = _T("DP_Mem_File");	// Full file path
static CString cstrUseDP_DB_File_opt = _T("DP_DB_File");	// Full file path

class CXTPCalendarControl;

class CCalendarDemoDoc : public CDocument
{
protected: // create from serialization only
	CCalendarDemoDoc();
	DECLARE_DYNCREATE(CCalendarDemoDoc)

// Attributes
public:

// Operations
public:
	// Creates a new event in the specified data provider.
	// This method is useful for shortening similar events creation.
	static CXTPCalendarEventPtr NewEvent(CXTPCalendarData* pData, 
		COleDateTime dtStart, COleDateTime dtEnd,
		CString strSubject, CString strLocation, 
		UINT nScheduleID);

	//
	// This method adds a predefined set of events into a data provider.
	//
	static void AddTestEvents(
		CXTPCalendarData* pCalendarData, 
		COleDateTimeSpan spTimeShift,
		UINT nScheduleID);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalendarDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCalendarDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	CXTPCalendarControl* m_pCalendar;

	static BOOL ms_bFileNew_ShowDialog;
	static BOOL ms_bFileNew_CreateEmptyDocument;
	static BOOL ms_bEmptyDocument_AddSampleData;

	BOOL CreateNewProvider(CString strConnectionString);
	BOOL OpenProvider(CString strConnectionString);
protected:    	
	virtual void OnCloseDocument();

	BOOL m_bOpened;

// Generated message map functions
protected:
	//{{AFX_MSG(CCalendarDemoDoc)	
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDARDEMODOC_H__503B51B2_6873_4C40_A4B5_4AFC3A07D591__INCLUDED_)
