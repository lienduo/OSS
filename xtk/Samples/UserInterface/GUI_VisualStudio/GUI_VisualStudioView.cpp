// GUI_VisualStudioView.cpp : implementation of the CGUI_VisualStudioView class
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
#include "GUI_VisualStudioView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioView

IMPLEMENT_DYNCREATE(CGUI_VisualStudioView, CXTPSyntaxEditView)

BEGIN_MESSAGE_MAP(CGUI_VisualStudioView, CXTPSyntaxEditView)
	//{{AFX_MSG_MAP(CGUI_VisualStudioView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CXTPSyntaxEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CXTPSyntaxEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CXTPSyntaxEditView::OnFilePrintPreview)

	ON_XTP_EXECUTE(ID_EDIT_FIND_EX, OnEditFind)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIND_EX, OnUpdateEditFind)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioView construction/destruction

CGUI_VisualStudioView::CGUI_VisualStudioView()
{
#ifdef _XTP_INCLUDE_SYNTAXEDIT
	GetEditCtrl().SetConfigFile(CXTPSyntaxEditCtrl::GetModulePath() + _T("EditConfig\\SyntaxEdit.ini"));
#endif
}

CGUI_VisualStudioView::~CGUI_VisualStudioView()
{
}

BOOL CGUI_VisualStudioView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bPreCreated = CXTPSyntaxEditView::PreCreateWindow(cs);


	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioView drawing

void CGUI_VisualStudioView::OnDraw(CDC* /*pDC*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioView printing

BOOL CGUI_VisualStudioView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CXTPSyntaxEditView preparation
	return CXTPSyntaxEditView::OnPreparePrinting(pInfo);
}

void CGUI_VisualStudioView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CXTPSyntaxEditView begin printing.
	CXTPSyntaxEditView::OnBeginPrinting(pDC, pInfo);
}

void CGUI_VisualStudioView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CXTPSyntaxEditView end printing
	CXTPSyntaxEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioView diagnostics

#ifdef _DEBUG
void CGUI_VisualStudioView::AssertValid() const
{
	CXTPSyntaxEditView::AssertValid();
}

void CGUI_VisualStudioView::Dump(CDumpContext& dc) const
{
	CXTPSyntaxEditView::Dump(dc);
}

CGUI_VisualStudioDoc* CGUI_VisualStudioView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGUI_VisualStudioDoc)));
	return (CGUI_VisualStudioDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGUI_VisualStudioView message handlers


void CGUI_VisualStudioView::OnEditFind(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;

	CXTPControlComboBox* pControl = (CXTPControlComboBox*)tagNMCONTROL->pControl;
	if (pControl->GetType() == xtpControlComboBox)
	{
		CString strFind = pControl->GetEditText();

		/*if (!FindText(strFind, TRUE,FALSE))
		{
			AfxMessageBox(_T("String not Found"));
		}*/

		*pResult = 1; // Handled;
	}
}

void CGUI_VisualStudioView::OnUpdateEditFind(CCmdUI* pCmd)
{
	pCmd->Enable(TRUE);
}
