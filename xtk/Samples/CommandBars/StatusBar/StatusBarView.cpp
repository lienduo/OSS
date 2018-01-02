// StatusBarView.cpp : implementation of the CStatusBarView class
//

#include "stdafx.h"
#include "StatusBar.h"

#include "StatusBarDoc.h"
#include "StatusBarView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView

IMPLEMENT_DYNCREATE(CStatusBarView, CView)

BEGIN_MESSAGE_MAP(CStatusBarView, CView)
	//{{AFX_MSG_MAP(CStatusBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView construction/destruction

CStatusBarView::CStatusBarView()
{
	CXTPPaintManager::CNonClientMetrics ncm;
	ncm.lfMenuFont.lfWeight = FW_BOLD;
	m_font.CreateFontIndirect(&ncm.lfMenuFont);
}

CStatusBarView::~CStatusBarView()
{
}

BOOL CStatusBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView drawing

void CStatusBarView::OnDraw(CDC* pDC)
{
	CStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	CMainFrame* pFrame = DYNAMIC_DOWNCAST(CMainFrame, GetParentFrame());
	if (pFrame && !pFrame->m_strMessage.IsEmpty())
	{
		CXTPFontDC fontDC(pDC, &m_font);
		pDC->TextOut(10,10,pFrame->m_strMessage);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView printing

BOOL CStatusBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatusBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatusBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView diagnostics

#ifdef _DEBUG
void CStatusBarView::AssertValid() const
{
	CView::AssertValid();
}

void CStatusBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatusBarDoc* CStatusBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatusBarDoc)));
	return (CStatusBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusBarView message handlers
