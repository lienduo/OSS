// GUI_VisualStudioDoc.cpp : implementation of the CGUI_VisualStudioDoc class
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
#include "GUI_VisualStudio.h"

#include "GUI_VisualStudioDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioDoc

IMPLEMENT_DYNCREATE(CGUI_VisualStudioDoc, CXTPSyntaxEditDoc)

BEGIN_MESSAGE_MAP(CGUI_VisualStudioDoc, CXTPSyntaxEditDoc)
	//{{AFX_MSG_MAP(CGUI_VisualStudioDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioDoc construction/destruction

CGUI_VisualStudioDoc::CGUI_VisualStudioDoc()
{
	// TODO: add one-time construction code here

}

CGUI_VisualStudioDoc::~CGUI_VisualStudioDoc()
{
}

BOOL CGUI_VisualStudioDoc::OnNewDocument()
{
	if (!CXTPSyntaxEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioDoc serialization

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioDoc diagnostics

#ifdef _DEBUG
void CGUI_VisualStudioDoc::AssertValid() const
{
	CXTPSyntaxEditDoc::AssertValid();
}

void CGUI_VisualStudioDoc::Dump(CDumpContext& dc) const
{
	CXTPSyntaxEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioDoc commands
