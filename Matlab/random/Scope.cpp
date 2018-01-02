// Scope1.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "Scope.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScope

CScope::CScope()
{
	m_strTitle = _T("示波器");
	m_strValueName = _T("数值");
	m_strUnitName = _T("度");
	m_BkBrush.CreateSolidBrush(RGB(0x00,0x00,0x33));
	m_PanelBrush.CreateSolidBrush(RGB(0x22,0x22,0x44));
	m_CurveBrush.CreateSolidBrush(RGB(0x00,0x00,0x00));

	m_PenCurve.CreatePen(PS_SOLID,2,RGB(0,255,0));
	m_PenGrid.CreatePen(PS_SOLID,0,RGB(192,192,192));
	m_PenBrightLine.CreatePen(PS_SOLID,0,RGB(0xff,0xff,0xff));
	m_PenDarkLine.CreatePen(PS_SOLID,0,RGB(0x55,0x55,0x55));


	m_FontTitle.CreateFont(18,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"宋体");
	m_FontAxis.CreateFont(15,0,0,0,FW_THIN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Arial");
	m_FontValue.CreatePointFont(120,"FixedSys");
	m_FontLabel.CreatePointFont(120,"Times New Roman");
	m_bitmapTitle.LoadBitmap(IDB_TITLE);
	m_bitmapTrack.LoadBitmap(IDB_TRACK);

	m_dDimT	= 100;
	m_dDimY	= 0.5;
	m_nBase = 5;
	m_nRange = 10;
	m_dValue = 0.0;

	m_nArrowIndex =-1;
	m_bPressed = FALSE;
}

CScope::~CScope()
{
	if(!m_TimeList.empty())
		m_TimeList.clear();
	if(!m_ValueList.empty())
		m_ValueList.clear();
}
BEGIN_MESSAGE_MAP(CScope, CStatic)
	//{{AFX_MSG_MAP(CScope)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScope message handlers

BOOL CScope::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;

	GetClientRect(&rect);
	pDC->FillRect(&rect,&m_BkBrush);//Draw background
	rect.InflateRect(-3,-25,-4,-3);//curve panel
	m_rectCurvePanel = rect;
	m_rectCurve = rect;
	m_rectCurve.InflateRect(-30,-5,-23,-25);//curve area
	m_rectScroll = m_rectCurve;
	m_rectScroll.left = m_rectCurve.right+8;
	m_rectScroll.right = m_rectScroll.left+10;//rect scroll created
	m_rectValuePanel = rect;
	m_rectValuePanel.top = rect.bottom+5;
	m_rectValuePanel.bottom= m_rectValuePanel.top+51;//rectValuePanel created

	CFont *pOldFont;
	pOldFont = pDC->SelectObject(&m_FontLabel);
	CSize size = pDC->GetTextExtent(m_strValueName);
	m_rectValue.left = m_rectValuePanel.left+20+size.cx;
	m_rectValue.top = m_rectValuePanel.top+(m_rectValuePanel.Height()-size.cy)/2-2;
	m_rectValue.bottom = m_rectValue.top+size.cy+4;
	size = pDC->GetTextExtent(m_strUnitName);
	m_rectValue.right = m_rectValuePanel.right - 20 - size.cx;
	pDC->SelectObject(pOldFont);

	if(m_rgnCurve.m_hObject==NULL)
		m_rgnCurve.CreateRectRgn(m_rectCurve.left+2,m_rectCurve.top+2,m_rectCurve.right-2,m_rectCurve.bottom-2);

	POINT ptYPlus[3];
	POINT ptYMinus[3];
	POINT ptTPlus[3];
	POINT ptTMinus[3];
	ptYPlus[0].x = m_rectCurvePanel.left+15;
	ptYPlus[0].y = m_rectCurve.bottom+3;
	ptYPlus[1].x = ptYPlus[0].x-5;
	ptYPlus[1].y = ptYPlus[0].y+6;
	ptYPlus[2].x = ptYPlus[0].x+5;
	ptYPlus[2].y = ptYPlus[0].y+6;

	ptYMinus[0].x = m_rectCurvePanel.left+15;
	ptYMinus[0].y = m_rectCurve.bottom+18;
	ptYMinus[1].x = ptYMinus[0].x-5;
	ptYMinus[1].y = ptYMinus[0].y-6;
	ptYMinus[2].x = ptYMinus[0].x+5;
	ptYMinus[2].y = ptYMinus[0].y-6;

	ptTPlus[0].x = m_rectScroll.left+m_rectScroll.Width()/2;
	ptTPlus[0].y = m_rectCurve.bottom+3;
	ptTPlus[1].x = ptTPlus[0].x-5;
	ptTPlus[1].y = ptTPlus[0].y+6;
	ptTPlus[2].x = ptTPlus[0].x+5;
	ptTPlus[2].y = ptTPlus[0].y+6;

	ptTMinus[0].x = m_rectScroll.left+m_rectScroll.Width()/2;
	ptTMinus[0].y = m_rectCurve.bottom+18;
	ptTMinus[1].x = ptTMinus[0].x-5;
	ptTMinus[1].y = ptTMinus[0].y-6;
	ptTMinus[2].x = ptTMinus[0].x+5;
	ptTMinus[2].y = ptTMinus[0].y-6;
	if(m_rgnYPlus.m_hObject==NULL)
		m_rgnYPlus.CreatePolygonRgn( ptYPlus, 3, ALTERNATE );
	if(m_rgnYMinus.m_hObject==NULL)
		m_rgnYMinus.CreatePolygonRgn( ptYMinus, 3, ALTERNATE );
	if(m_rgnTPlus.m_hObject==NULL)
		m_rgnTPlus.CreatePolygonRgn( ptTPlus, 3, ALTERNATE );
	if(m_rgnTMinus.m_hObject==NULL)
		m_rgnTMinus.CreatePolygonRgn( ptTMinus, 3, ALTERNATE );
	
	return TRUE;
}

void CScope::OnPaint() 
{
	CPaintDC dc(this); 
	DrawTitle(&dc);
	DrawCurvePanel(&dc);
	DrawGrid(&dc);
	DrawCurve(&dc);
	DrawArrow(&dc,0,FALSE);
	DrawArrow(&dc,1,FALSE);
	DrawArrow(&dc,2,FALSE);
	DrawArrow(&dc,3,FALSE);
	DrawAxis(&dc);
	DrawTrack(&dc,m_bPressed);
//	DrawValuePanel(&dc);
//	DrawValue(&dc);
}
void CScope::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	CStatic::PreSubclassWindow();
}
void CScope::DrawTitle(CDC *pDC)
{
	CDC dcMem;
	BITMAP bm;
	CBitmap *pBmp;
	CFont *pFont;
	
	m_bitmapTitle.GetObject(sizeof(BITMAP),&bm);
	dcMem.CreateCompatibleDC(pDC);
	pBmp = dcMem.SelectObject(&m_bitmapTitle);

	CRect rect;
	GetClientRect(&rect);
	pFont = pDC->SelectObject(&m_FontTitle);
	CSize size= pDC->GetTextExtent(m_strTitle);
	rect.top += 3;

	rect.bottom=rect.top+size.cy;
	rect.left=3;
	rect.right=rect.right-3;

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255,255,255));
	pDC->DrawText(m_strTitle,-1,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	int nBmpWidth = (rect.Width()-size.cx-16)/2;
	int nTimes = nBmpWidth/10-1;

	pDC->BitBlt(rect.left,rect.top,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
	pDC->BitBlt(rect.right-nBmpWidth,rect.top,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
	
	int i;
	for(i=0;i<nTimes;i++)
	{
		pDC->BitBlt(rect.left+5+i*10,rect.top,10,bm.bmHeight,&dcMem,10,0,SRCCOPY);
		pDC->BitBlt(rect.right-nBmpWidth+5+i*10,rect.top,10,bm.bmHeight,&dcMem,10,0,SRCCOPY);
	}
	pDC->BitBlt(rect.left+nBmpWidth-bm.bmWidth+5,rect.top,bm.bmWidth-5,bm.bmHeight,&dcMem,5,0,SRCCOPY);
	pDC->BitBlt(rect.right-bm.bmWidth+5,rect.top,bm.bmWidth-5,bm.bmHeight,&dcMem,5,0,SRCCOPY);

	pDC->SelectObject(pFont);
	dcMem.SelectObject(pBmp);
}
void CScope::SetTitle(CString strTitle)
{	
	m_strTitle = strTitle;
	CClientDC dc(this); 
	Invalidate();
	
}
void CScope::DrawValuePanel(CDC *pDC)
{
	CFont *pOldFont;
	CPen *pOldPen;
	pDC->FillRect(&m_rectValuePanel,&m_PanelBrush);
	pDC->SetTextAlign(TA_LEFT);
	pDC->SetTextColor(RGB(255,255,0));
	pDC->SetBkMode(TRANSPARENT);
	pOldPen = pDC->SelectObject(&m_PenBrightLine);
	pDC->MoveTo(m_rectValuePanel.left,m_rectValuePanel.top);
	pDC->LineTo(m_rectValuePanel.left,m_rectValuePanel.bottom);
	pDC->MoveTo(m_rectValuePanel.left,m_rectValuePanel.top);
	pDC->LineTo(m_rectValuePanel.right,m_rectValuePanel.top);

	pDC->SelectObject(&m_PenDarkLine);
	pDC->MoveTo(m_rectValuePanel.right,m_rectValuePanel.top);
	pDC->LineTo(m_rectValuePanel.right,m_rectValuePanel.bottom);
	pDC->MoveTo(m_rectValuePanel.left,m_rectValuePanel.bottom);
	pDC->LineTo(m_rectValuePanel.right,m_rectValuePanel.bottom);
	pDC->SelectObject(pOldPen);

	pOldFont = pDC->SelectObject(&m_FontLabel);
	pDC->TextOut(m_rectValuePanel.left+10,m_rectValue.top+2,m_strValueName);
	pDC->TextOut(m_rectValue.right+10,m_rectValue.top+2,m_strUnitName);
	pDC->SelectObject(pOldFont);

}
void CScope::DrawValue(CDC *pDC)
{
	pDC->FillRect(&m_rectValue,&m_CurveBrush);
	CFont *pOldFont;
	pDC->DrawEdge(&m_rectValue,EDGE_SUNKEN,BF_RECT);

	pOldFont = pDC->SelectObject(&m_FontValue);
	CString str;
	str.Format("%.3f",m_dValue);
	CRect rect = m_rectValue;
	rect.left+=3;
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0,255,0));
	pDC->DrawText(str,&rect,DT_SINGLELINE|DT_VCENTER|DT_LEFT);
	pDC->SelectObject(&pOldFont);
}
void CScope::SetValue(double dValue)
{
	CClientDC dc(this);
	m_dValue = dValue;
//	DrawValue(&dc);
	
}
void CScope::SetDimT(double newDimT)
{
	if(m_dDimT==newDimT)
		return;
	else
	{
		m_dDimT = newDimT;
		Invalidate();
	}
}
void CScope::SetDimy(double newDimY)
{

	if(m_dDimY==newDimY)
		return;
	else
	{
		m_dDimY = newDimY;
		Invalidate();
	}
}
void CScope::SetBase(int nNewABase,int nRange)
{
	if(nNewABase == m_nBase&&m_nRange==nRange)
		return;
	else
	{
		m_nBase = nNewABase;
		m_nRange=nRange;
		Invalidate();
	}
}
void CScope::DrawCurvePanel(CDC *pDC)
{
	CPen *pOldPen;
	pDC->FillRect(&m_rectCurvePanel,&m_PanelBrush);

	pOldPen = pDC->SelectObject(&m_PenBrightLine);
	pDC->MoveTo(m_rectCurvePanel.left,m_rectCurvePanel.top);
	pDC->LineTo(m_rectCurvePanel.left,m_rectCurvePanel.bottom);
	pDC->MoveTo(m_rectCurvePanel.left,m_rectCurvePanel.top);
	pDC->LineTo(m_rectCurvePanel.right,m_rectCurvePanel.top);

	pDC->SelectObject(&m_PenDarkLine);
	pDC->MoveTo(m_rectCurvePanel.right,m_rectCurvePanel.top);
	pDC->LineTo(m_rectCurvePanel.right,m_rectCurvePanel.bottom);
	pDC->MoveTo(m_rectCurvePanel.left,m_rectCurvePanel.bottom);
	pDC->LineTo(m_rectCurvePanel.right,m_rectCurvePanel.bottom);
	pDC->SelectObject(pOldPen);
}
void CScope::DrawGrid(CDC *pDC)
{
	CPen *pOldPen;

	pDC->FillRect(&m_rectCurve,&m_CurveBrush);

	pOldPen = pDC->SelectObject(&m_PenDarkLine);
	pDC->MoveTo(m_rectCurve.left,m_rectCurve.top);
	pDC->LineTo(m_rectCurve.left,m_rectCurve.bottom);
	pDC->MoveTo(m_rectCurve.left,m_rectCurve.top);
	pDC->LineTo(m_rectCurve.right,m_rectCurve.top);

	pDC->SelectObject(&m_PenBrightLine);
	pDC->MoveTo(m_rectCurve.right,m_rectCurve.top);
	pDC->LineTo(m_rectCurve.right,m_rectCurve.bottom);
	pDC->MoveTo(m_rectCurve.left,m_rectCurve.bottom);
	pDC->LineTo(m_rectCurve.right,m_rectCurve.bottom);
	

	int i;
	CString str;
	pDC->SelectObject(&m_PenGrid);
	pDC->SelectClipRgn(&m_rgnCurve);
	int nCenterY  = m_rectCurve.top+(int)(m_nBase/(double)m_nRange*m_rectCurve.Height());
	//画基线
	pDC->MoveTo(m_rectCurve.left,nCenterY);
	pDC->LineTo(m_rectCurve.right,nCenterY);
	int nPosY;
	//画横线
	for(i=1;i<4;i++)
	{
		nPosY = nCenterY+m_rectCurve.Height()/4*i;
		if(nPosY<m_rectCurve.bottom)
		{
			pDC->MoveTo(m_rectCurve.left,nPosY);
			pDC->LineTo(m_rectCurve.right,nPosY);
		}
	}
	for(i=3;i>=0;i--)
	{
		nPosY = nCenterY-m_rectCurve.Height()/4*i;
		if(nPosY>m_rectCurve.top)
		{
			pDC->MoveTo(m_rectCurve.left,nPosY);
			pDC->LineTo(m_rectCurve.right,nPosY);
		}
	}
	//画竖线
	for(i=1;i<=3;i++)
	{
		pDC->MoveTo(m_rectCurve.left+i*m_rectCurve.Width()/4,m_rectCurve.top);
		pDC->LineTo(m_rectCurve.left+i*m_rectCurve.Width()/4,m_rectCurve.bottom);
	}
	pDC->SelectClipRgn(NULL);
	pDC->SelectObject(pOldPen);

}
void CScope::DrawTrack(CDC *pDC,BOOL bPressed)
{
	CPen *pOldPen;
	pDC->FillRect(&m_rectScroll,&m_PanelBrush);
	pOldPen = pDC->SelectObject(&m_PenDarkLine);
	pDC->MoveTo(m_rectScroll.left,m_rectScroll.top);
	pDC->LineTo(m_rectScroll.left,m_rectScroll.bottom);
	pDC->MoveTo(m_rectScroll.left,m_rectScroll.top);
	pDC->LineTo(m_rectScroll.right,m_rectScroll.top);

	pDC->SelectObject(&m_PenBrightLine);
	pDC->MoveTo(m_rectScroll.right,m_rectScroll.top);
	pDC->LineTo(m_rectScroll.right,m_rectScroll.bottom);
	pDC->MoveTo(m_rectScroll.left,m_rectScroll.bottom);
	pDC->LineTo(m_rectScroll.right,m_rectScroll.bottom);
	pDC->SelectObject(pOldPen);

	CBitmap *pBmp;
	CDC dcMem;
	BITMAP bm;
	m_bitmapTrack.GetObject(sizeof(BITMAP),&bm);
	dcMem.CreateCompatibleDC(pDC);
	pBmp = dcMem.SelectObject(&m_bitmapTrack);
	int nPosY = (int)(m_nBase/(double)m_nRange*(m_rectScroll.Height()-bm.bmHeight))+m_rectScroll.top;
	if(bPressed)
		pDC->BitBlt(m_rectScroll.left,nPosY,bm.bmWidth,bm.bmHeight,&dcMem,0,0,NOTSRCCOPY);
	else
		pDC->BitBlt(m_rectScroll.left,nPosY,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
	dcMem.SelectObject(pBmp);
}
void CScope::DrawAxis(CDC *pDC)
{
	CFont *pOldFont;
	int i,nPosY;
	CString str;
	pOldFont = pDC->SelectObject(&m_FontAxis);
	pDC->SetTextColor(RGB(255,255,0));
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextAlign(TA_RIGHT|TA_BASELINE);
	int nCenterY = m_rectCurve.top+(int)((double)m_nBase/(double)m_nRange*m_rectCurve.Height());
	nPosY = nCenterY;
	if(nPosY<=m_rectCurve.top+10)
		nPosY += 10;
	if(m_dDimY<1)
		pDC->TextOut(m_rectCurve.left-2,nPosY,CString("0.0"));
	else
		pDC->TextOut(m_rectCurve.left-2,nPosY,CString("0"));
	
	for(i=1;i<=4;i++)
	{
		nPosY = nCenterY+i*m_rectCurve.Height()/4;
		if(nPosY<=m_rectCurve.bottom)
		{
			if(m_dDimY<1)
				str.Format("%.1f",-i*m_dDimY);
			else if(m_dDimY<1000)
				str.Format("%.0f",-i*m_dDimY);
			else
				str.Format("%.0fK",-i*m_dDimY/1000);
			pDC->TextOut(m_rectCurve.left-2,nPosY,str);
		}
	}

	for(i=1;i<=4;i++)
	{
		nPosY = nCenterY-i*m_rectCurve.Height()/4;
		if(nPosY>=m_rectCurve.top)
		{
			if(nPosY<=m_rectCurve.top+10)
				nPosY += 10;
			if(m_dDimY<1)
				str.Format("%.1f",i*m_dDimY);
			else if(m_dDimY<1000)
				str.Format("%.0f",i*m_dDimY);
			else
				str.Format("%.0fK",i*m_dDimY/1000);
			pDC->TextOut(m_rectCurve.left-2,nPosY,str);
		}
	}
	//横坐标
	pDC->SetTextAlign(TA_LEFT|TA_TOP);
	pDC->TextOut(m_rectCurve.left,m_rectCurve.bottom+2,CString("0.0"));
	pDC->SetTextAlign(TA_CENTER|TA_TOP);
	for(i=1;i<=3;i++)
	{
		str.Format("%.1f",i*m_dDimT);
		pDC->TextOut(m_rectCurve.left+i*m_rectCurve.Width()/4,m_rectCurve.bottom+2,str);
	}
	pDC->SetTextAlign(TA_RIGHT|TA_TOP);
	str.Format("%.1f",4*m_dDimT);
	pDC->TextOut(m_rectCurve.right,m_rectCurve.bottom+2,str);
	pDC->SelectObject(&pOldFont);
}

void CScope::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	ReleaseCapture();
	m_bPressed = FALSE;
	DrawTrack(&dc,m_bPressed);
	CStatic::OnLButtonUp(nFlags, point);
}

void CScope::OnLButtonDown(UINT nFlags, CPoint point) 
{
	
	if(m_rgnYPlus.PtInRegion(point))
	{
		if(m_dDimY>=1&&m_dDimY<10)
			m_dDimY+=1;
		if(m_dDimY>=10&&m_dDimY<100)
			m_dDimY+=10;
		if(m_dDimY>=100&&m_dDimY<1000)
			m_dDimY+=100;
		if(m_dDimY>=1000)
			m_dDimY+=1000;
		Invalidate();
	}
	if(m_rgnYMinus.PtInRegion(point))
	{
		if(m_dDimY>1&&m_dDimY<=10)
			m_dDimY-=1;
		if(m_dDimY>10&&m_dDimY<=100)
			m_dDimY-=10;
		if(m_dDimY>100&&m_dDimY<=1000)
			m_dDimY-=100;
		if(m_dDimY>1000)
			m_dDimY-=1000;
		if(m_dDimY<=1)
			m_dDimY=max(m_dDimY-0.1,0.1);
		Invalidate();
	}

	if(m_rgnTPlus.PtInRegion(point))
	{
		m_dDimT+=0.1;
		Invalidate();
	}
	if(m_rgnTMinus.PtInRegion(point))
	{
		m_dDimT=max(m_dDimT-0.1,0.1);
		Invalidate();
	}
	if(m_rectScroll.PtInRect(point))
	{
		SetCapture();
		m_bPressed = TRUE;
		m_nBase = (int)(((point.y-m_rectScroll.top+m_rectScroll.Height()/m_nRange/2)/(double)m_rectScroll.Height())*m_nRange);
		Invalidate();
	}
	CStatic::OnLButtonDown(nFlags, point);
}

void CScope::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	if(m_rgnYPlus.PtInRegion(point)&&m_nArrowIndex !=0)
	{
		m_nArrowIndex =0;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnYMinus.PtInRegion(point)&&m_nArrowIndex !=1)
	{
		m_nArrowIndex =1;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnTPlus.PtInRegion(point)&&m_nArrowIndex !=2)
	{
		m_nArrowIndex =2;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnTMinus.PtInRegion(point)&&m_nArrowIndex !=3)
	{
		m_nArrowIndex =3;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(!m_rgnYPlus.PtInRegion(point)&&
		!m_rgnYMinus.PtInRegion(point)&&
		!m_rgnTPlus.PtInRegion(point)&&
		!m_rgnTMinus.PtInRegion(point)&&
		m_nArrowIndex!=-1)
	{
		DrawArrow(&dc,m_nArrowIndex,FALSE);
		m_nArrowIndex = -1;	
	}
	if(m_bPressed)
	{
		int newBase = (int)(((point.y-m_rectScroll.top+m_rectScroll.Height()/m_nRange/2)/(double)m_rectScroll.Height())*m_nRange);
		if(newBase<0)
			newBase =0;
		if(newBase>m_nRange)
			newBase =m_nRange;
		if(newBase !=m_nBase )
		{
			m_nBase = newBase;
			DrawCurvePanel(&dc);
			DrawCurvePanel(&dc);
			DrawGrid(&dc);
			DrawCurve(&dc);

			DrawAxis(&dc);
			DrawTrack(&dc,m_bPressed);
			DrawArrow(&dc,0,FALSE);
			DrawArrow(&dc,1,FALSE);
			DrawArrow(&dc,2,FALSE);
			DrawArrow(&dc,3,FALSE);
		}

	}

	CStatic::OnMouseMove(nFlags, point);
}
void CScope::DrawArrow(CDC *pDC,int nIndex,BOOL bLighted)
{
	CBrush brush1(RGB(192,192,192)),brush2(RGB(0,255,0));
	switch(nIndex)
	{
	case 0:
		if(bLighted)
			pDC->FillRgn(&m_rgnYPlus,&brush2);
		else
			pDC->FillRgn(&m_rgnYPlus,&brush1);
		break;
	case 1:
		if(bLighted)
			pDC->FillRgn(&m_rgnYMinus,&brush2);
		else
			pDC->FillRgn(&m_rgnYMinus,&brush1);
		break;
	case 2:
		if(bLighted)
			pDC->FillRgn(&m_rgnTPlus,&brush2);
		else
			pDC->FillRgn(&m_rgnTPlus,&brush1);
		break;
	case 3:
		if(bLighted)
			pDC->FillRgn(&m_rgnTMinus,&brush2);
		else
			pDC->FillRgn(&m_rgnTMinus,&brush1);
		break;

	}

}
void CScope::DrawCurve(CDC *pDC)
{
	m_bDrawing = TRUE;
	int nSize = m_TimeList.size();

	POINT *pPointArray =(POINT *) new POINT[nSize];
	int i;
	
	std::list<double>::iterator time_it = m_TimeList.begin();
	std::list<double>::iterator value_it = m_ValueList.begin();
	std::list<double>::iterator time_begin = time_it;
	for(i=0;i<nSize;i++)
	{
		pPointArray[i].x = ConvertTimeToAxisX(*time_it-*time_begin);
		pPointArray[i].y = ConvertValueToAxisY(*value_it);
		time_it++;
		value_it++;
	}
	m_bDrawing =FALSE;
	CPen *pOldPen = pDC->SelectObject(&m_PenCurve);
	pDC->SelectClipRgn(&m_rgnCurve);
	pDC->Polyline(pPointArray,nSize);
	pDC->SelectClipRgn(NULL);
	pDC->SelectObject(pOldPen);
	
	delete []pPointArray;


	
	 
}
void CScope::UpdateCurve()
{
	
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap bitmap,*pOldBmp;
	bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
	pOldBmp = memDC.SelectObject(&bitmap);
	DrawGrid(&memDC);
	DrawCurve(&memDC);
	dc.BitBlt(m_rectCurve.left,m_rectCurve.top,m_rectCurve.Width(),m_rectCurve.Height(),&memDC,m_rectCurve.left,m_rectCurve.top,SRCCOPY);
	memDC.SelectObject(pOldBmp);
}

LRESULT CScope::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	return HTCLIENT;
}
void CScope::AddValue(double dTime,double dValue)
{
	if(m_bDrawing)
		return;

	m_TimeList.push_back(dTime);
	m_ValueList.push_back(dValue);
	std::list<double>::iterator start_it = m_TimeList.begin();
	std::list<double>::iterator end_it = m_TimeList.end();
	end_it--;
	double dStartTime = *start_it;
	double dEndTime = *(end_it);
	while(dEndTime-dStartTime>4*m_dDimT)
	{
		m_TimeList.pop_front();
		m_ValueList.pop_front();
		
		start_it = m_TimeList.begin();
		end_it = m_TimeList.end();
		end_it--;

		dStartTime = *start_it;
		dEndTime = *(end_it);
	}
}

inline int CScope::ConvertTimeToAxisX(double dTime)
{
	int nReturn;
	nReturn = m_rectCurve.left+dTime/(4.0*m_dDimT)*m_rectCurve.Width();
	return nReturn;
}
inline int CScope::ConvertValueToAxisY(double dValue)
{
	int nReturn;
	int nCenterY  = m_rectCurve.top+(int)(m_nBase/(double)m_nRange*m_rectCurve.Height());

	nReturn = nCenterY - dValue/(4.0*m_dDimY)*m_rectCurve.Height();
	return nReturn;
}
void CScope::SetValueString(CString strTitle,CString strUnit)
{
	m_strValueName = strTitle;
	m_strUnitName = strUnit;
	Invalidate();
}
void CScope::Clear()
{
	m_TimeList.clear();
	m_ValueList.clear();
	UpdateCurve();
//	SetValue(0.0);
}
