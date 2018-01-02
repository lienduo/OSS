// ChildFrm.cpp : implementation of the CChildFrame class
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

#include "stdafx.h"
#include "MDITabWindows.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndBase)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndBase)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{

	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// make sure view is maximum size to eliminate 
	// flicker when switching tabs.
	cs.x = 
	cs.y = 0;
	
	cs.cx = 
	cs.cy = 32767;
	
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWndBase::PreCreateWindow(cs) )
		return FALSE;

	cs.style |= WS_CLIPCHILDREN;
	
	cs.style = WS_CHILD | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

	return TRUE;
}

void CChildFrame::ActivateFrame(int nCmdShow)
{
	// first window should be maximized
	if (GetParent()->GetWindow(GW_CHILD) == this)
	{
		nCmdShow = SW_SHOWMAXIMIZED;
	}

	CMDIChildWndBase::ActivateFrame(nCmdShow);
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndBase::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndBase::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
