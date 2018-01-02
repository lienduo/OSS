// ScanScope.cpp : implementation file
//

#include "stdafx.h"
#include "ScanScope.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScanScope

CScanScope::CScanScope()
{
	m_strTitle = _T("");
	m_rectCurve.SetRect(10,10,100,100);
	m_dDimT =2.0;
	m_dDimY = 10.0;
	m_dDimW = 5.0;
	m_nArrowIndex =-1;
	m_bDrawing = FALSE;

	m_brushPanel.CreateSolidBrush(RGB(192,192,192));
	m_brushCurve.CreateSolidBrush(RGB(0x00,0x00,0x00));

	m_penGrid.CreatePen(PS_SOLID,1,RGB(192,192,192));
	m_penBlack.CreatePen(PS_SOLID,1,RGB(0,0,0));
	m_penScanLine.CreatePen(PS_SOLID,3,RGB(255,255,255));
	m_penValue1.CreatePen(PS_SOLID,2,RGB(255,255,0));
	m_penValue2.CreatePen(PS_SOLID,2,RGB(0,255,0));
	m_penValue3.CreatePen(PS_SOLID,2,RGB(255,0,0));

	m_fontLabel.CreatePointFont(120,"Times New Roman");
	m_fontAxis.CreateFont(15,0,0,0,FW_THIN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Arial");
	m_timeList.clear();
	m_ValueList1.clear();
	m_ValueList2.clear();
	m_ValueList3.clear();
}

CScanScope::~CScanScope()
{
	if(!m_timeList.empty())
		m_timeList.clear();
	if(!m_ValueList1.empty())
		m_ValueList1.clear();
	if(!m_ValueList2.empty())
		m_ValueList2.clear();
	if(!m_ValueList3.empty())
		m_ValueList3.clear();
}


BEGIN_MESSAGE_MAP(CScanScope, CStatic)
	//{{AFX_MSG_MAP(CScanScope)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScanScope message handlers

BOOL CScanScope::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect,&m_brushPanel);//Draw background
	m_rectPanel = rect;
	m_rectCurve = rect;
	m_rectCurve.InflateRect(-35,-30,-30,-22);
	if(m_rgnCurve.m_hObject==NULL)
		m_rgnCurve.CreateRectRgn(m_rectCurve.left+2,m_rectCurve.top+2,m_rectCurve.right-2,m_rectCurve.bottom-2);
	POINT ptYPlus[3];
	POINT ptYMinus[3];
	POINT ptTPlus[3];
	POINT ptTMinus[3];
	POINT ptWPlus[3];
	POINT ptWMinus[3];
	ptYPlus[0].x = m_rectPanel.left+15;
	ptYPlus[0].y = m_rectPanel.top+1;
	ptYPlus[1].x = ptYPlus[0].x-7;
	ptYPlus[1].y = ptYPlus[0].y+8;
	ptYPlus[2].x = ptYPlus[0].x+7;
	ptYPlus[2].y = ptYPlus[0].y+8;

	ptYMinus[0].x = m_rectPanel.left+15;
	ptYMinus[0].y = m_rectPanel.top+20;
	ptYMinus[1].x = ptYMinus[0].x-7;
	ptYMinus[1].y = ptYMinus[0].y-8;
	ptYMinus[2].x = ptYMinus[0].x+7;
	ptYMinus[2].y = ptYMinus[0].y-8;

	ptTPlus[0].x = m_rectCurve.right+15;
	ptTPlus[0].y = m_rectCurve.bottom+3;
	ptTPlus[1].x = ptTPlus[0].x-7;
	ptTPlus[1].y = ptTPlus[0].y+8;
	ptTPlus[2].x = ptTPlus[0].x+7;
	ptTPlus[2].y = ptTPlus[0].y+8;

	ptTMinus[0].x = m_rectCurve.right+15;
	ptTMinus[0].y = m_rectCurve.bottom+22;
	ptTMinus[1].x = ptTMinus[0].x-7;
	ptTMinus[1].y = ptTMinus[0].y-8;
	ptTMinus[2].x = ptTMinus[0].x+7;
	ptTMinus[2].y = ptTMinus[0].y-8;

	//---------------------------------------
	ptWPlus[0].x = m_rectCurve.right+15;
	ptWPlus[0].y = m_rectPanel.top+1;
	ptWPlus[1].x = ptWPlus[0].x-7;
	ptWPlus[1].y = ptWPlus[0].y+8;
	ptWPlus[2].x = ptWPlus[0].x+7;
	ptWPlus[2].y = ptWPlus[0].y+8;

	ptWMinus[0].x = m_rectCurve.right+15;
	ptWMinus[0].y = m_rectPanel.top+20;
	ptWMinus[1].x = ptWMinus[0].x-7;
	ptWMinus[1].y = ptWMinus[0].y-8;
	ptWMinus[2].x = ptWMinus[0].x+7;
	ptWMinus[2].y = ptWMinus[0].y-8;

	if(m_rgnYPlus.m_hObject==NULL)
		m_rgnYPlus.CreatePolygonRgn( ptYPlus, 3, ALTERNATE );
	if(m_rgnYMinus.m_hObject==NULL)
		m_rgnYMinus.CreatePolygonRgn( ptYMinus, 3, ALTERNATE );
	if(m_rgnTPlus.m_hObject==NULL)
		m_rgnTPlus.CreatePolygonRgn( ptTPlus, 3, ALTERNATE );
	if(m_rgnTMinus.m_hObject==NULL)
		m_rgnTMinus.CreatePolygonRgn( ptTMinus, 3, ALTERNATE );
	if(m_rgnWPlus.m_hObject==NULL)
		m_rgnWPlus.CreatePolygonRgn( ptWPlus, 3, ALTERNATE );
	if(m_rgnWMinus.m_hObject==NULL)
		m_rgnWMinus.CreatePolygonRgn( ptWMinus, 3, ALTERNATE );
	
	return TRUE;
}

void CScanScope::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	DrawCurveFrame(&dc);
	DrawFrameText(&dc);
	DrawArrow(&dc,0,FALSE);
	DrawArrow(&dc,1,FALSE);
	DrawArrow(&dc,2,FALSE);
	DrawArrow(&dc,3,FALSE);
	DrawArrow(&dc,4,FALSE);
	DrawArrow(&dc,5,FALSE);
	DrawGrid(&dc);
	DrawCurve(&dc);
}
void CScanScope::DrawGrid(CDC *pDC)
{
	CPen *pOldPen;
	pOldPen = pDC->SelectObject(&m_penGrid);
	for(int i=1;i<4;i++)
	{
		pDC->MoveTo(m_rectCurve.left,m_rectCurve.top+i*m_rectCurve.Height()/4);
		pDC->LineTo(m_rectCurve.right,m_rectCurve.top+i*m_rectCurve.Height()/4);

		pDC->MoveTo(m_rectCurve.left+i*m_rectCurve.Width()/4,m_rectCurve.top);
		pDC->LineTo(m_rectCurve.left+i*m_rectCurve.Width()/4,m_rectCurve.bottom);
	}
	pDC->SelectObject(pOldPen);
}
void CScanScope::DrawCurve(CDC *pDC)
{
	if(m_timeList.empty())
		return;
	m_bDrawing = TRUE;
	double dOldTime = m_timeList.back();
	double dValue1 = m_ValueList1.back();
	double dValue2 = m_ValueList2.back();
	double dValue3 = m_ValueList3.back();

	CPen	*pOldPen;
	CBrush	*pOldBrush;
	int		nCount		= m_timeList.size();
	BOOL	bReverse	= FALSE;
	int		nPos;
	int		i;
	int		nTimeAxis[MAX_GRAPH_DOT+1];


	POINT	ptValue1[MAX_GRAPH_DOT+1];
	POINT	ptValue2[MAX_GRAPH_DOT+1];
	POINT	ptValue3[MAX_GRAPH_DOT+1];

	std::list<double>::iterator time_it = m_timeList.begin();
	std::list<double>::iterator value_it1 = m_ValueList1.begin();
	std::list<double>::iterator value_it2 = m_ValueList2.begin();
	std::list<double>::iterator value_it3 = m_ValueList3.begin();
	//数据的获取
	for(i=0;i<nCount;i++)
	{
		nTimeAxis[i] = ConvertTimeToAxisX(*time_it);
		ptValue1[i].x = nTimeAxis[i];
		ptValue2[i].x = nTimeAxis[i];
		ptValue3[i].x = nTimeAxis[i];

		ptValue1[i].y = ConvertValueToAxisY(*value_it1);
		ptValue2[i].y = ConvertValueToAxisY(*value_it2);
		ptValue3[i].y = ConvertValueToAxisW(*value_it3);
		time_it++;
		value_it1++;
		value_it2++;
		value_it3++;
	}
	m_timeList.clear();
	m_ValueList1.clear();
	m_ValueList2.clear();
	m_ValueList3.clear();

	m_timeList.push_back(dOldTime);
	m_ValueList1.push_back(dValue1);
	m_ValueList2.push_back(dValue2);
	m_ValueList3.push_back(dValue3);

	m_bDrawing = FALSE;
	pDC->SelectClipRgn(&m_rgnCurve);
	//画标尺-----------------------------------
	pOldPen = pDC->SelectObject(&m_penScanLine);
	pDC->MoveTo(nTimeAxis[nCount-1]+2,m_rectCurve.top);
	pDC->LineTo(nTimeAxis[nCount-1]+2,m_rectCurve.bottom);
	//判断是否回头------------------------------
	for(i = 0;i<nCount-1;i++)
	{
		if( nTimeAxis[i]>nTimeAxis[i+1] )
		{
			bReverse = TRUE;	
			nPos = i+1;
			break;
		}
	}
	//-------------用刷子刷原来的曲线-----------------------------------------------
	pOldBrush = pDC->SelectObject(&m_brushCurve);
	pDC->SelectObject(&m_penBlack);
	
	if(bReverse==FALSE)				
	{
		pDC->Rectangle(nTimeAxis[0]+1,m_rectCurve.top,nTimeAxis[nCount-1]+1,m_rectCurve.bottom);
	}
	else
	{
		pDC->Rectangle(nTimeAxis[0]+1,m_rectCurve.top,m_rectCurve.right,m_rectCurve.bottom);
		pDC->Rectangle(m_rectCurve.left,m_rectCurve.top,nTimeAxis[nCount-1]+1,m_rectCurve.bottom);
	}
	//画坐标轴线，竖线在任何情况下都画------------------------
	pDC->SelectObject(&m_penGrid);
	for(i=1;i<GRIDNUMX;i++)
	{
		pDC->MoveTo(m_rectCurve.left+i* m_rectCurve.Width() /GRIDNUMX,m_rectCurve.top);
		pDC->LineTo(m_rectCurve.left+i* m_rectCurve.Width() /GRIDNUMX,m_rectCurve.bottom);
	}
	//横线只补被刷掉的地方------------------------------------
	if(bReverse==FALSE)	
	{
		for(i = 1;i<GRIDNUMY;i++)
		{
			pDC->MoveTo(nTimeAxis[0]+1,m_rectCurve.top+i*m_rectCurve.Height()/GRIDNUMY);
			pDC->LineTo(nTimeAxis[nCount-1]+1,m_rectCurve.top+i*m_rectCurve.Height()/GRIDNUMY);
		}
	}
	else
	{
		for(i = 1;i<GRIDNUMY;i++)
		{
			pDC->MoveTo(nTimeAxis[0]+1,m_rectCurve.top+i*m_rectCurve.Height()/GRIDNUMY);
			pDC->LineTo(m_rectCurve.right,m_rectCurve.top+i*m_rectCurve.Height()/GRIDNUMY);
			
			pDC->MoveTo(m_rectCurve.left,m_rectCurve.top+i*m_rectCurve.Height()/GRIDNUMY);
			pDC->LineTo(nTimeAxis[nCount-1]+1,m_rectCurve.top+i*m_rectCurve.Height()/GRIDNUMY);
		}
	}
	//画第一个位置曲线
	pDC->SelectObject(&m_penValue1);
	if(bReverse==FALSE)								
	{
		pDC->Polyline(ptValue1,nCount);
		
	}
	else
	{
		pDC->Polyline(ptValue1,nPos);
		pDC->Polyline(&ptValue1[nPos],nCount-nPos);
		
	}
	//------------画反馈位置曲线--------
	pDC->SelectObject(&m_penValue2);
	if(bReverse==FALSE)								
	{
		pDC->Polyline(ptValue2,nCount);
		
	}
	else
	{
		pDC->Polyline(ptValue2,nPos);
		pDC->Polyline(&ptValue2[nPos],nCount-nPos);
		
	}
	//------------画速度曲线--------
	pDC->SelectObject(&m_penValue3);
	if(bReverse==FALSE)								
	{
		pDC->Polyline(ptValue3,nCount);
		
	}
	else
	{
		pDC->Polyline(ptValue3,nPos);
		pDC->Polyline(&ptValue3[nPos],nCount-nPos);
	}
	pDC->SelectClipRgn(NULL);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
void CScanScope::DrawFrameText(CDC *pDC)
{
	CPen *pOldPen;
	CFont *pOldFont;
	pOldFont = pDC->SelectObject(&m_fontAxis);
	CRect rect = m_rectCurve;
	int i;
	CString str;
	pDC->SetBkMode(TRANSPARENT);
	for(i=0;i<5;i++)
	{
		
		if(fabs(2*m_dDimY-i*m_dDimY)<1)

			str.Format("%.1f",2*m_dDimY-i*m_dDimY);
		else if(fabs(2*m_dDimY-i*m_dDimY)<999)
			str.Format("%.0f",2*m_dDimY-i*m_dDimY);
		else
			str.Format("%.0fK",(2*m_dDimY-i*m_dDimY)/1000.0);

		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOut(rect.left-2,18+i*(rect.Height())/4,str);
		
		if(fabs(2*m_dDimW-i*m_dDimW)<1)
			str.Format("%.1f",2*m_dDimW-i*m_dDimW);
		else if(fabs(2*m_dDimW-i*m_dDimW)<999)
			str.Format("%.0f",2*m_dDimW-i*m_dDimW);
		else 
			str.Format("%.0fK",(2*m_dDimW-i*m_dDimW)/1000.0);

		pDC->SetTextAlign(TA_LEFT);
		pDC->TextOut(rect.right+2,18+i*(rect.Height())/4,str);
		
		str.Format("%.1f",i*m_dDimT);
		pDC->TextOut(rect.left-18+i*rect.Width()/4,rect.bottom+2,str);
	}

	str=_T("给定位置");
	pDC->TextOut(rect.left+10,rect.top-20,str);
	
	str=_T("实际位置");
	pDC->TextOut(rect.left+10+rect.Width()/3,rect.top-20,str);

	str=_T("实际速度");
	pDC->TextOut(rect.left+10+2*rect.Width()/3,rect.top-20,str);
	
	str=m_strTitle;
	pDC->TextOut(rect.left+10+2*rect.Width()/3,rect.top-20,str);
	
	pOldPen = pDC->SelectObject(&m_penValue1);
	pDC->MoveTo(rect.left+60,rect.top-10);
	pDC->LineTo(rect.left+90,rect.top-10);
	
	pDC->SelectObject(&m_penValue2);
	pDC->MoveTo(rect.left+60+rect.Width()/3,rect.top-10);
	pDC->LineTo(rect.left+90+rect.Width()/3,rect.top-10);
	
	pDC->SelectObject(&m_penValue3);
	pDC->MoveTo(rect.left+60+2*rect.Width()/3,rect.top-10);
	pDC->LineTo(rect.left+90+2*rect.Width()/3,rect.top-10);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont);
	
}
void CScanScope::DrawCurveFrame(CDC *pDC)
{
	pDC->FillRect(&m_rectCurve,&m_brushCurve);
	pDC->DrawEdge(&m_rectCurve,EDGE_SUNKEN,BF_RECT);
}

inline int CScanScope::ConvertTimeToAxisX(double time)
{
	return m_rectCurve.left+(int)( ( time / m_dDimT ) * (double)( m_rectCurve.Width() / 4 ) ) % m_rectCurve.Width();
}
inline int CScanScope::ConvertValueToAxisY(double pos)
{
	return m_rectCurve.top+m_rectCurve.Height() / 2 - (int)( ( pos / m_dDimY ) * (double)( m_rectCurve.Height() / 4 ) );
}
inline int CScanScope::ConvertValueToAxisW(double rate)
{
	return m_rectCurve.top+m_rectCurve.Height() / 2 - (int)( ( rate / m_dDimW ) * (double)(  m_rectCurve.Height() / 4 ) ) ;
}
void CScanScope::AddValue(double t,double y1,double y2,double w)
{
	if(m_bDrawing)
		return;
	if(m_timeList.size()>MAX_GRAPH_DOT)
		return;
	m_timeList.push_back(t);
	m_ValueList1.push_back(y1);
	m_ValueList2.push_back(y2);
	m_ValueList3.push_back(w);
}
void CScanScope::UpdateCurve()
{
	CClientDC dc(this);
	DrawCurve(&dc);
}
void CScanScope::SetDimT(double dNewT)
{
	m_dDimT=dNewT;
	Invalidate();
}
void CScanScope::SetDimY(double dNewY)
{
	m_dDimY=dNewY;
	Invalidate();
}
void CScanScope::SetDimW(double dNewW)
{
	m_dDimW=dNewW;
	Invalidate();
}
void CScanScope::SetTitle(CString strTitle)
{
	m_strTitle = strTitle;
	Invalidate();
}
void CScanScope::DrawArrow(CDC *pDC,int nIndex,BOOL bLighted)
{
	CBrush brush1(RGB(128,128,128)),brush2(RGB(0,255,0));
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
	case 4:
		if(bLighted)
			pDC->FillRgn(&m_rgnWPlus,&brush2);
		else
			pDC->FillRgn(&m_rgnWPlus,&brush1);
		break;
	case 5:
		if(bLighted)
			pDC->FillRgn(&m_rgnWMinus,&brush2);
		else
			pDC->FillRgn(&m_rgnWMinus,&brush1);
		break;

	}

}

void CScanScope::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if(m_rgnYPlus.PtInRegion(point))//&&m_nArrowIndex !=0)
	{
		m_nArrowIndex =0;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnYMinus.PtInRegion(point))//&&m_nArrowIndex !=1)
	{
		m_nArrowIndex =1;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnTPlus.PtInRegion(point))//&&m_nArrowIndex !=2)
	{
		m_nArrowIndex =2;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnTMinus.PtInRegion(point))//&&m_nArrowIndex !=3)
	{
		m_nArrowIndex =3;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnWPlus.PtInRegion(point))//&&m_nArrowIndex !=3)
	{
		m_nArrowIndex =4;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(m_rgnWMinus.PtInRegion(point))//&&m_nArrowIndex !=3)
	{
		m_nArrowIndex =5;
		DrawArrow(&dc,m_nArrowIndex,TRUE);
	}
	if(!m_rgnYPlus.PtInRegion(point)&&
		!m_rgnYMinus.PtInRegion(point)&&
		!m_rgnTPlus.PtInRegion(point)&&
		!m_rgnTMinus.PtInRegion(point)&&
		!m_rgnWMinus.PtInRegion(point)&&
		!m_rgnWPlus.PtInRegion(point)&&
		m_nArrowIndex!=-1)
	{
		DrawArrow(&dc,m_nArrowIndex,FALSE);
		m_nArrowIndex = -1;	
	}
	CStatic::OnMouseMove(nFlags, point);
}

void CScanScope::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_rgnYPlus.PtInRegion(point))
	{
		if(m_dDimY<0.99999)
			m_dDimY+=0.1;
		else if(m_dDimY<10)
			m_dDimY+=1;
		else if(m_dDimY<100)
			m_dDimY+=10;
		else 
			m_dDimY=min(m_dDimY+100,500);
		Invalidate();
	}
	if(m_rgnYMinus.PtInRegion(point))
	{
		if(m_dDimY<=1)
			m_dDimY=max(m_dDimY-0.1,0.1);
		else if(m_dDimY>1&&m_dDimY<=10)
			m_dDimY-=1;
		else if(m_dDimY<=100)
			m_dDimY-=10;
		else	
			m_dDimY-=100;
		Invalidate();
	}
	if(m_rgnWPlus.PtInRegion(point))
	{
		if(m_dDimW<0.99999)
			m_dDimW+=0.1;
		else if(m_dDimW<10)
			m_dDimW+=1;
		else if(m_dDimW<100)
			m_dDimW+=10;
		else 
			m_dDimW=min(m_dDimW+100,500);
		Invalidate();
	}
	if(m_rgnWMinus.PtInRegion(point))
	{
		if(m_dDimW<=1)
			m_dDimW=max(m_dDimW-0.1,0.1);
		else if(m_dDimW>1&&m_dDimW<=10)
			m_dDimW-=1;
		else if(m_dDimW<=100)
			m_dDimW-=10;
		else	
			m_dDimW-=100;
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
	CStatic::OnLButtonDown(nFlags, point);
}

void CScanScope::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CStatic::OnLButtonUp(nFlags, point);
}

UINT CScanScope::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	return HTCLIENT;
}
