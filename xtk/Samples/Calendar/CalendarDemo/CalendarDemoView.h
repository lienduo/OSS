// CalendarDemoView.h : interface of the CCalendarDemoView class
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

#if !defined(AFX_CALENDARDEMOVIEW_H__59A561F0_994C_4D99_B1D2_E665584B4348__INCLUDED_)
#define AFX_CALENDARDEMOVIEW_H__59A561F0_994C_4D99_B1D2_E665584B4348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
class CCalendarDemoDoc;


enum EnumCalendarToolTipMode
{
	ctmStandard = 0,
	ctmCustom	= 1,
	ctmDisabled	= 2,
};

/////////////////////////////////////////////////////////////////////////////
// This customized Calendar class shows how to redefine a behavior of some 
// standard methods, in this case it shows how to customize events' tooltips.
//
class CXTPCalendarControl_Custom : public CXTPCalendarControl
{
public:
	int m_nToolTipMode;

	CXTPCalendarControl_Custom();

	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
};

//////////////////////////////////////////////////////////////////////////
// Default View class for our Demo application.
class CCalendarDemoView : public CXTPCalendarControlView 
{
protected: // create from serialization only
	CCalendarDemoView();
	DECLARE_DYNCREATE(CCalendarDemoView)

// Attributes
public:
	CCalendarDemoDoc* GetDocument();


	CXTPCalendarControl_Custom m_wndCalendarEx;

	CXTPCalendarController m_CalendarController;

	CXTPScrollBar m_wndScrollBar;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalendarDemoView)
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCalendarDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCalendarDemoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCalendarViewDay();
	afx_msg void OnCalendarViewWorkWeek();
	afx_msg void OnCalendarViewWeek();
	afx_msg void OnCalendarViewMonth();
	afx_msg void OnUpdateCalendarViewDay(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarViewWorkWeek(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarViewWeek(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarViewMonth(CCmdUI* pCmdUI);
	afx_msg void OnCalendarTimescale60();
	afx_msg void OnCalendarTimescale30();
	afx_msg void OnCalendarTimescale15();
	afx_msg void OnCalendarTimescale10();
	afx_msg void OnCalendarTimescale6();
	afx_msg void OnCalendarTimescale5();
	afx_msg void OnUpdateCalendarTimescale60(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarTimescale30(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarTimescale15(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarTimescale10(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarTimescale6(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarTimescale5(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCalendarTimescale(CCmdUI* pCmdUI, int nScale);
	afx_msg void OnCalendarTimezone();
	afx_msg void OnAdvancedOptions();
	afx_msg void OnAddNewEvent();

//	afx_msg void OnCalendarLangRussian();
//	afx_msg void OnCalendarLangDefault();

	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	afx_msg void OnViewReminders();
	afx_msg void OnUpdateViewReminders(CCmdUI* pCmdUI);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
	DECLARE_XTP_SINK(CCalendarDemoView, m_Sink);
	
	void OnEvent_Calendar(XTP_NOTIFY_CODE Event, WPARAM wParam, LPARAM lParam);
	
	void OnEvent_IsEditActionDisabled(XTP_NOTIFY_CODE Event, WPARAM wParam, LPARAM lParam);
	void OnEvent_BeforeEditAction(XTP_NOTIFY_CODE Event, WPARAM wParam, LPARAM lParam);
	void OnEvent_PrePopulate(XTP_NOTIFY_CODE Event, WPARAM wParam, LPARAM lParam);
	//void OnEvent_SelChanged(XTP_NOTIFY_CODE Event, WPARAM wParam, LPARAM lParam);
		
	void OnEvent_CalendarData(XTP_NOTIFY_CODE Event, WPARAM wParam, LPARAM lParam);
	void OnReminders(XTP_NOTIFY_CODE Event, WPARAM wParam , LPARAM lParam);
	void OnBeforeDrawThemeObject(XTP_NOTIFY_CODE Event, WPARAM wParam , LPARAM lParam);

	void CreateRemindersWindow();

	COleDateTime m_dtDayViewStart;
	COleDateTimeSpan m_dsDayViewDays;

public:
	void AddNewEvent(CPoint* pPtHitContext = NULL);

	afx_msg void OnBnClickedScrollDayPrev();
	afx_msg void OnBnClickedIdcScrollDayNext();
	
	void OnUpdateTimeScale();
	void SetView(XTPCalendarViewType viewtype);
	void SetCalendarTimeScale(int nScale);
	void SetCalendarToolTipMode(int nToolTipMode);

	virtual void OnOfficeThemeChanged(int nTheme);

	int m_nScale;
};

#ifndef _DEBUG  // debug version in CalendarDemoView.cpp
inline CCalendarDemoDoc* CCalendarDemoView::GetDocument()
   { return (CCalendarDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDARDEMOVIEW_H__59A561F0_994C_4D99_B1D2_E665584B4348__INCLUDED_)
