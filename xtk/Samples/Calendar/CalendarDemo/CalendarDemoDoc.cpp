// CalendarDemoDoc.cpp : implementation of the CCalendarDemoDoc class
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
#include "CalendarDemo.h"

#include "CalendarDemoDoc.h"
#include "MainFrm.h"

#include "DataProvidersOptions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
extern BOOL IsFileExist(LPCTSTR pcszFile);

// Resolve data provider code into human readable name
CString GetDPName(int nDPType)
{
	CString strDPname = _T("Data Provider");

	if (nDPType == xtpCalendarDataProviderMemory) {
		strDPname = _T("Memory Data Provider");
	} else if (nDPType == xtpCalendarDataProviderDatabase) {
		strDPname = _T("Database Data Provider");
	} else if (nDPType == xtpCalendarDataProviderMAPI) {
		strDPname = _T("MAPI Data Provider");			
	}
	else {
		ASSERT(FALSE);
	}
	return strDPname;
}

// Returns data provider type
int GetDPType(CXTPCalendarData* pData)
{   	
	if (!pData) {
		ASSERT(FALSE);
		return xtpCalendarDataProviderUnknown;
	}
	return pData->GetType();
}


/////////////////////////////////////////////////////////////////////////////
// CCalendarDemoDoc

IMPLEMENT_DYNCREATE(CCalendarDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCalendarDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CCalendarDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalendarDemoDoc construction/destruction
BOOL CCalendarDemoDoc::ms_bFileNew_ShowDialog = TRUE;
BOOL CCalendarDemoDoc::ms_bFileNew_CreateEmptyDocument = FALSE;
BOOL CCalendarDemoDoc::ms_bEmptyDocument_AddSampleData = FALSE;

CCalendarDemoDoc::CCalendarDemoDoc()
{
	m_pCalendar = NULL;
	m_bOpened = FALSE;
}

CCalendarDemoDoc::~CCalendarDemoDoc()
{
}

// Creates a new event in the specified data provider.
// This method is useful for shortening similar events creation.
CXTPCalendarEventPtr CCalendarDemoDoc::NewEvent(
	CXTPCalendarData* pData, 
	COleDateTime dtStart, COleDateTime dtEnd,
	CString strSubject, CString strLocation,
	UINT nScheduleID)
{
	CXTPCalendarEventPtr ptrEvent = pData->CreateNewEvent();

	ptrEvent->SetStartTime(dtStart);
	ptrEvent->SetEndTime(dtEnd);
	ptrEvent->SetSubject(strSubject);
	ptrEvent->SetLocation(strLocation);

	if (pData->GetSchedules() && pData->GetSchedules()->GetCount() > 0)
	{
		ptrEvent->SetScheduleID(nScheduleID);
	}

	return ptrEvent;
}

//
// This method adds a predefined set of events into a data provider.
//
void CCalendarDemoDoc::AddTestEvents(CXTPCalendarData* pCalendarData, 
	COleDateTimeSpan spTimeShift, UINT nScheduleID)
{
	if (!pCalendarData)	
	{
		ASSERT(FALSE);
		return;
	}

	// add test events
	COleDateTime dtNow(COleDateTime::GetCurrentTime() + spTimeShift);
	COleDateTimeSpan spDay(1, 0, 0, 0);
	COleDateTimeSpan sp15min(0, 0, 15, 0);
	COleDateTimeSpan spHour(0, 1, 0, 0);

	// Create 4 usual events
	CXTPCalendarEventPtr ptrEvent = NewEvent(pCalendarData, 
						dtNow, dtNow + spHour, 
						_T("Event &Now [Tentative]"), _T("New Location"),
						nScheduleID);
	ptrEvent->SetReminderMinutesBeforeStart(10);
	ptrEvent->SetBusyStatus(xtpCalendarBusyStatusTentative);	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}

	ptrEvent = NewEvent(pCalendarData, 
		dtNow + sp15min, dtNow + spHour + spHour + spHour + spHour,
		_T("Event Now + 15 min (4 hours)"), _T("[Free]"),
		nScheduleID);
	ptrEvent->SetBusyStatus(xtpCalendarBusyStatusFree);	
	ptrEvent->SetLabelID(8);
	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}

	ptrEvent = NewEvent(pCalendarData, 
		dtNow + spHour, dtNow + spHour + spHour ,
		_T("Event Now + Hour (2 hours) "), _T("[OutOfOffice]"),
		nScheduleID);
	ptrEvent->SetBusyStatus(xtpCalendarBusyStatusOutOfOffice);	
	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}

	ptrEvent = NewEvent(pCalendarData, 
		dtNow - spDay + spHour, dtNow - spDay + spHour + spHour + spHour,
		_T("Yesterday Event"), _T("Old Location"),
		nScheduleID);
	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}

	// multi day event
	COleDateTime dtE(CXTPCalendarUtils::ResetTime(dtNow + spDay));
	COleDateTime dtB(CXTPCalendarUtils::ResetTime(dtNow - spDay + spHour));
	ptrEvent = NewEvent(pCalendarData, 
		dtNow - spDay - spDay + spHour, dtE, // + spDay + spHour + spHour + spHour,
		_T("Multi day Event"), ("Multi day Location"),
		nScheduleID);
	ptrEvent->SetReminderMinutesBeforeStart(10);
	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}

	// "pure" all day event 
	COleDateTimeSpan sp10Days(10, 0, 0, 0);
	ptrEvent = NewEvent(pCalendarData, 
		dtNow, dtNow + sp10Days,
		_T("AllDay Event"), _T("Old Location"),
		nScheduleID);
	ptrEvent->SetAllDayEvent();
	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}

	// private event 	
	ptrEvent = NewEvent(pCalendarData, 
		dtNow - spHour - spHour, dtNow - spHour,
		_T("Private"), _T("Old Location"),
		nScheduleID);
	//ptrEvent->SetReminderMinutesBeforeStart(10);
	ptrEvent->SetPrivate();
	ptrEvent->SetMeeting();
	
	if (!pCalendarData->AddEvent(ptrEvent)) {
		ASSERT(FALSE);
		return;
	}


	// Create recurrent event
	CXTPCalendarEventPtr ptrMasterEvent = NewEvent(pCalendarData, 
		dtNow, dtNow + spHour, 
		_T("Recurrence event - lunch"), _T("Recurrence location"),
		nScheduleID);
	VERIFY(ptrMasterEvent->MakeEventAsRecurrence());
	ptrMasterEvent->SetLabelID(5);
	//ptrMasterEvent->SetAllDayEvent();
	ptrMasterEvent->SetReminderMinutesBeforeStart(10);
	ptrMasterEvent->SetMeeting();

	CXTPCalendarRecurrencePatternPtr ptrRecPatt = ptrMasterEvent->GetRecurrencePattern();	
	COleDateTime dtStart,dtRP_Start;
	//  duration
	dtStart.SetTime(13, 8, 0);
	dtStart += spTimeShift;
	ptrRecPatt->SetStartTime(dtStart);
	ptrRecPatt->SetDurationMinutes(90);
	//  period
	dtRP_Start = COleDateTime::GetCurrentTime();

	VERIFY(CXTPCalendarUtils::UpdateMonthDay(dtRP_Start, 1));
	ptrRecPatt->SetPatternStartDate(dtRP_Start);

	VERIFY(CXTPCalendarUtils::UpdateMonthDay(dtRP_Start, 31));
	ptrRecPatt->SetPatternEndDate(dtRP_Start);
	//ptrRecPatt->SetNoEndDate();
	// pattern
	XTP_CALENDAR_RECURRENCE_OPTIONS opt;
	opt.m_nRecurrenceType = xtpCalendarRecurrenceDaily;

	opt.m_Daily.bEveryWeekDayOnly = FALSE;
	opt.m_Daily.nIntervalDays = 3;

	ptrRecPatt->SetRecurrenceOptions(opt);
	ptrMasterEvent->UpdateRecurrence(ptrRecPatt);
	//  add
	if (!pCalendarData->AddEvent(ptrMasterEvent)) {
		ASSERT(FALSE);
		return;
	}	
}

BOOL CCalendarDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
    
	if (!m_pCalendar) {
		return FALSE;
	}

	// EXAMPLE. how to set custom locale ID.
	// CXTPPropExchange::m_lcidDateTime = GetUserDefaultLCID();

	if (ms_bFileNew_CreateEmptyDocument) 
	{
		CXTPCalendarData* pCalendarData = m_pCalendar->GetDataProvider();
		if (pCalendarData && pCalendarData->IsOpen()) {
			pCalendarData->Save();
			pCalendarData->Close();
		}

		m_pCalendar->SetDataProvider(xtpCalendarDataProviderMemory);

		ms_bFileNew_CreateEmptyDocument = FALSE;        		
		
		m_strPathName = _T("");
		SetTitle(_T(""));

		if (ms_bEmptyDocument_AddSampleData)
		{
			pCalendarData = m_pCalendar->GetDataProvider();
			AddTestEvents(pCalendarData, COleDateTimeSpan(0), 0);			
		}
		ms_bEmptyDocument_AddSampleData = FALSE;

		m_pCalendar->Populate();
	} 
	else 
	{	
		if (ms_bFileNew_ShowDialog)
		{	
			CDataProvidersOptions optDlg;	
			optDlg.m_strTitle = _T("Create new file");
			optDlg.m_bOpenMode = FALSE;
			optDlg.m_bWarnIfExist = TRUE;
	        		
			int nDlgRes = (int)optDlg.DoModal();
						
			if (nDlgRes != IDOK) {
				return TRUE;
			}
		}
		ms_bFileNew_ShowDialog = TRUE;
		
		//---------------------------------------------------------------------------
		CString strFileName;
		CString strUseDP = AfxGetApp()->GetProfileString(cstrDP_Opt_section, cstrUseDP_opt);

		CString strConnectionString;
		BOOL bNewRes = FALSE;

		if (strUseDP.CompareNoCase(cstrUseDP_Mem_optval) == 0) 
		{
			strFileName = AfxGetApp()->GetProfileString(cstrDP_Opt_section, cstrUseDP_Mem_File_opt);
			strConnectionString.Format(_T("Provider=XML;Data Source='%s';"), strFileName);
		} 
		else if (strUseDP.CompareNoCase(cstrUseDP_DB_optval) == 0) 
		{
			strFileName = AfxGetApp()->GetProfileString(cstrDP_Opt_section, cstrUseDP_DB_File_opt);
			strConnectionString.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source='%s';"), strFileName);
		} 
		else if (strUseDP.CompareNoCase(cstrUseDP_MAPI_optval) == 0) 
		{			
			strConnectionString.Format(_T("Provider=MAPI;"));
		}
		else {
			ASSERT(FALSE);		
		}

		if (!strConnectionString.IsEmpty()) {
			bNewRes = CreateNewProvider(strConnectionString);
		}

		if (!bNewRes) 
		{
			SetTitle(_T(""));
			return FALSE;
		}

		if (!strFileName.IsEmpty()) {
			SetPathName(strFileName);
		}
		else {
			SetTitle(_T(""));
		}
	}	
	
	//===========================================================================
	m_pCalendar->Populate();

	m_bOpened = TRUE;

	return TRUE;
}


BOOL CCalendarDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	CString strFileName = lpszPathName ? lpszPathName : _T("");

	CString strUseDP = AfxGetApp()->GetProfileString(cstrDP_Opt_section, cstrUseDP_opt);

	if (strFileName.IsEmpty()) 
	{
		if (strUseDP.CompareNoCase(cstrUseDP_Mem_optval) == 0) {
			strFileName = AfxGetApp()->GetProfileString(cstrDP_Opt_section, cstrUseDP_Mem_File_opt);
		} 
		else if (strUseDP.CompareNoCase(cstrUseDP_DB_optval) == 0) {			
			strFileName = AfxGetApp()->GetProfileString(cstrDP_Opt_section, cstrUseDP_DB_File_opt);
		} 
		else {
			ASSERT(FALSE);
			return FALSE;
		}
	}	
    
	if (strUseDP.CompareNoCase(cstrUseDP_MAPI_optval) == 0) 
	{
		if (!CDocument::OnNewDocument()) {
			return FALSE;
		}
	}
	else if (!CDocument::OnOpenDocument(strFileName)) {
		return FALSE;
	}

	DWORD dwFileAttrib = ::GetFileAttributes(strFileName);
	dwFileAttrib &= ~FILE_ATTRIBUTE_READONLY;
	::SetFileAttributes(strFileName, dwFileAttrib);

	CString strConnectionString;
	BOOL bOpenRes = FALSE;

	if (strUseDP.CompareNoCase(cstrUseDP_Mem_optval) == 0) {
		strConnectionString.Format(_T("Provider=XML;Data Source='%s';Encoding=iso-8859-1;"), strFileName);
//		strConnectionString.Format(_T("Data Source='%s';"), strFileName);
	}
	else if (strUseDP.CompareNoCase(cstrUseDP_DB_optval) == 0) {
		strConnectionString.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source='%s';"), strFileName);
	}
	else if (strUseDP.CompareNoCase(cstrUseDP_MAPI_optval) == 0) 
	{			
		strConnectionString.Format(_T("Provider=MAPI;"));
	}
	else {
		ASSERT(FALSE);
	}

	if (!strConnectionString.IsEmpty()) {
		bOpenRes = OpenProvider(strConnectionString);
	}
	
	if (!bOpenRes) {
		return FALSE;
	}	

	//===========================================================================
	m_pCalendar->Populate();
        	
	m_bOpened = TRUE;

	return TRUE;
}

BOOL CCalendarDemoDoc::OpenProvider(CString strConnectionString)
{	
	if (strConnectionString.IsEmpty()) {
		return FALSE;
	}

	if (!m_pCalendar) {
		ASSERT(FALSE);
		return FALSE;
	}

	CString strConn_lower = strConnectionString;
	strConn_lower.MakeLower();
	BOOL bMAPI_DP = strConn_lower.Find(_T("provider=mapi;")) >= 0;

	CXTPCalendarData* pCalendarData = m_pCalendar->GetDataProvider();
	if (pCalendarData && pCalendarData->IsOpen())
	{
		pCalendarData->Save();		
		pCalendarData->Close();
	}

	m_pCalendar->SetDataProvider(strConnectionString);
	pCalendarData = m_pCalendar->GetDataProvider();
	if (!pCalendarData) {
		return FALSE;
	}

	//===========================================================================
	BOOL bResult = pCalendarData->Open();
	if (!bResult) 
	{
		if(!bMAPI_DP)
		{
			CString strMsg;
			strMsg.Format(_T("The events data file is empty or corrupted: \n'%s'"), pCalendarData->GetDataSource());
			strMsg += _T("\n\nWould You like to recreate it and \nadd default test events set?");
			int nRes = AfxMessageBox(strMsg, MB_YESNO);
			
			if (nRes == IDYES) 
			{
				bResult = CreateNewProvider(strConnectionString);
			}
		}		
	}

	int nRemindersEnabled = AfxGetApp()->GetProfileInt(_T("Options"), _T("RemindersEnabled"), TRUE);
	m_pCalendar->EnableReminders(nRemindersEnabled > 0);

	return bResult;
}


BOOL CCalendarDemoDoc::CreateNewProvider(CString strConnectionString)
{	
	if (!m_pCalendar) {
		ASSERT(FALSE);
		return FALSE;
	}

	CString strConn_lower = strConnectionString;
	strConn_lower.MakeLower();
	BOOL bMAPI_DP = strConn_lower.Find(_T("provider=mapi;")) >= 0;

	CXTPCalendarData* pCalendarData = m_pCalendar->GetDataProvider();
	if (pCalendarData && pCalendarData->IsOpen()) {
		pCalendarData->Save();
		pCalendarData->Close();
	}

	m_pCalendar->SetDataProvider(strConnectionString);
	pCalendarData = m_pCalendar->GetDataProvider();
	
	ASSERT(pCalendarData);
	if (!pCalendarData)
		return FALSE;

	if (!bMAPI_DP) {
		::DeleteFile(pCalendarData->GetDataSource());
	}
	
	CWaitCursor _wc;	

	//===========================================================================
	if (!pCalendarData->Create())
	{
		CString strMsg;
		
		if (bMAPI_DP) 
		{
			strMsg.Format(_T("Cannot open MAPI provider."));
		}
		else
		{
			CString strDPname = GetDPName(pCalendarData->GetType());
			strMsg.Format(_T("%s cannot create file: \n%s\nProbably MDAC is not installed."), strDPname, pCalendarData->GetDataSource());
		}
		AfxMessageBox(strMsg);

		// set empty memory data provider
		m_pCalendar->SetDataProvider(_T(""));
		pCalendarData = m_pCalendar->GetDataProvider();
		if (pCalendarData && !pCalendarData->IsOpen()) {
			pCalendarData->Open();
		}
		m_pCalendar->Populate();
		
		return FALSE;
	}		
	
	if (!bMAPI_DP) 
	{
		int nRes = AfxMessageBox(_T("Would You like to add default test events set?"), MB_YESNO);
		if (nRes == IDYES) 
		{
			AddTestEvents(pCalendarData, COleDateTimeSpan(0), 0);
			
			if (!pCalendarData->Save()) 
			{
				CString strDPname = GetDPName(pCalendarData->GetType());
				CString strMsg;
				strMsg.Format(_T("%s cannot save document"), strDPname);
				AfxMessageBox(strMsg);
			}
		}
	}

	int nRemindersEnabled = AfxGetApp()->GetProfileInt(_T("Options"), _T("RemindersEnabled"), TRUE);
	m_pCalendar->EnableReminders(nRemindersEnabled > 0);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCalendarDemoDoc serialization

void CCalendarDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

void CCalendarDemoDoc::OnCloseDocument()
{
	if (!m_bOpened) {
		CDocument::OnCloseDocument();
		return;
	}

	((CMainFrame*)AfxGetMainWnd())->m_dlgOptions.Close();

	CXTPCalendarData* pCalendarData = m_pCalendar->GetDataProvider();

	if (!pCalendarData)	{
		ASSERT(FALSE);
		return;
	}
	
	if (!pCalendarData->Save()) 
	{
		CString strDPname = GetDPName(xtpCalendarDataProviderMemory);
		CString strMsg;
		strMsg.Format(_T("%s cannot save document"), strDPname);
		AfxMessageBox(strMsg);
	}

	int nRemindersEnabled = m_pCalendar->IsRemindersEnabled();
	AfxGetApp()->WriteProfileInt(_T("Options"), _T("Reminders"), nRemindersEnabled);
	
	CDocument::OnCloseDocument();
}

void CCalendarDemoDoc::SetTitle(LPCTSTR lpszTitle)
{
	UNREFERENCED_PARAMETER(lpszTitle);

	int nDPType = GetDPType(m_pCalendar->GetDataProvider());
	CString strDPName = GetDPName(nDPType);
	CString strFile = m_pCalendar->GetDataProvider()->GetDataSource(); 

	CString strTitle;
	strTitle.Format(_T("%s [%s]"), strDPName, strFile);
		
	CDocument::SetTitle(strTitle);
}
/////////////////////////////////////////////////////////////////////////////
// CCalendarDemoDoc diagnostics

#ifdef _DEBUG
void CCalendarDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCalendarDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCalendarDemoDoc commands

