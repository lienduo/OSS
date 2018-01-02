// WorkspaceView.cpp : implementation file
//

#include "stdafx.h"
#include "ribbonsample.h"
#include "WorkspaceView.h"

#include "RibbonSampleView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceView

IMPLEMENT_DYNCREATE(CWorkspaceView, CView)

CWorkspaceView::CWorkspaceView()
{
	m_pView = 0;
}

CWorkspaceView::~CWorkspaceView()
{
}


BEGIN_MESSAGE_MAP(CWorkspaceView, CView)
	//{{AFX_MSG_MAP(CWorkspaceView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_VSCROLL()
	ON_WM_MOUSEACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceView drawing

void CWorkspaceView::OnDraw(CDC* /*pDC*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceView diagnostics

#ifdef _DEBUG
void CWorkspaceView::AssertValid() const
{
	CView::AssertValid();
}

void CWorkspaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceView message handlers

int CWorkspaceView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	
	CCreateContext contextT;
	contextT.m_pCurrentDoc     = GetDocument();
	contextT.m_pNewViewClass   = RUNTIME_CLASS(CRibbonSampleView);
	contextT.m_pNewDocTemplate = GetDocument()->GetDocTemplate();

	TRY
	{
		m_pView = (CRibbonSampleView*)contextT.m_pNewViewClass->CreateObject();
		if (m_pView == NULL)
		{
			AfxThrowMemoryException();
		}
	}
	CATCH_ALL(e)
	{
		TRACE0( "Out of memory creating a view.\n" );
		// Note: DELETE_EXCEPTION(e) not required
		return FALSE;
	}
	END_CATCH_ALL

	DWORD dwStyle = AFX_WS_DEFAULT_VIEW;
	dwStyle &= ~WS_BORDER;

	// Create with the right size (wrong position)
	CRect rect(0,0,0,0);
	if (!m_pView->Create(NULL, NULL, dwStyle,
		rect, this, AFX_IDW_PANE_FIRST, &contextT))
	{
		TRACE0( "Warning: couldn't create client tab for view.\n" );
		// pWnd will be cleaned up by PostNcDestroy
		return NULL;
	}

	m_pView->SendMessage(WM_INITIALUPDATE);
	m_pView->SetOwner(this);

	GetParentFrame()->SetActiveView(m_pView);

	m_wndScrollBar[SB_VERT].Create(WS_CHILD | WS_VISIBLE | SBS_VERT, CRect(10, 10, 50, 50), this, 100);
	m_wndScrollBar[SB_VERT].SetScrollBarStyle(xtpScrollStyleOffice2007Dark);

	//m_wndScrollBar[SB_HORZ].Create(WS_CHILD | WS_VISIBLE | SBS_HORZ, CRect(10, 10, 50, 50), this, 100);
	//m_wndScrollBar[SB_HORZ].SetScrollBarStyle(xtpScrollStyleOffice2007Dark);
	
	return 0;
}

void CWorkspaceView::Reposition(CSize sz)
{
	BOOL bBothVisible = m_wndScrollBar[SB_VERT].GetSafeHwnd() && m_wndScrollBar[SB_HORZ].GetSafeHwnd();

	if (m_wndScrollBar[SB_VERT].GetSafeHwnd())
	{
		int nWidth = GetSystemMetrics(SM_CXVSCROLL);		
		m_wndScrollBar[SB_VERT].MoveWindow(sz.cx - nWidth, 0, nWidth, sz.cy - (bBothVisible ? GetSystemMetrics(SM_CYHSCROLL) : 0));
	}
	
	if (m_wndScrollBar[SB_HORZ].GetSafeHwnd())
	{
		int nHeight = GetSystemMetrics(SM_CYHSCROLL);		
		m_wndScrollBar[SB_HORZ].MoveWindow(0, sz.cy - nHeight, sz.cx - (bBothVisible ? GetSystemMetrics(SM_CXVSCROLL) : 0), nHeight);
	}

	if (m_pView)
	{
		CRect rc(GetViewRect(CRect(0, 0, sz.cx, sz.cy)));
		m_pView->MoveWindow(rc);
	}	
}

void CWorkspaceView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	Reposition(CSize(cx, cy));
}

CRect CWorkspaceView::GetViewRect(CRect rc)
{
	if (m_wndScrollBar[SB_VERT].GetSafeHwnd())
	{
		int nWidth = GetSystemMetrics(SM_CXVSCROLL);		
		rc.right -= nWidth;
	}
	if (m_wndScrollBar[SB_HORZ].GetSafeHwnd())
	{
		int nHeight = GetSystemMetrics(SM_CYHSCROLL);		
		rc.bottom -= nHeight;
	}
	m_pView->CalcWindowRect(&rc, 0);
	
	return rc;
}


BOOL CWorkspaceView::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;
}

void CWorkspaceView::OnPaint() 
{
	CPaintDC dc(this);

	CXTPClientRect rc(this);
	if (m_wndScrollBar[SB_VERT].GetSafeHwnd())
	{
		rc.right -= CXTPWindowRect(&m_wndScrollBar[SB_VERT]).Width();
	}
	if (m_wndScrollBar[SB_HORZ].GetSafeHwnd())
	{
		rc.bottom -= CXTPWindowRect(&m_wndScrollBar[SB_HORZ]).Height();
	}

	CXTPWindowRect rcClient(GetDlgItem(AFX_IDW_PANE_FIRST));
	ScreenToClient(&rcClient);
	
	CXTPCommandBars* pCommandBars = ((CMainFrame*)GetParentFrame())->GetCommandBars();
	((CXTPOffice2007Theme*)(pCommandBars->GetPaintManager()))->FillWorkspace(&dc, rc, rcClient);
}

void CWorkspaceView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	m_pView->OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CWorkspaceView::PreCreateWindow(CREATESTRUCT& cs) 
{
	return CView::PreCreateWindow(cs);
}

void CWorkspaceView::SetLayoutRTL(BOOL bRTLLayout)
{
	ModifyStyleEx(bRTLLayout ? 0 : WS_EX_LAYOUTRTL, !bRTLLayout ? 0 : WS_EX_LAYOUTRTL);

	Reposition(CXTPClientRect(this).Size());
	Invalidate(FALSE);
}

int CWorkspaceView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) 
{
	// Don't call CView::OnMouseActivate.
	return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}
