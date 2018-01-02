#if !defined(AFX_SCANSCOPE_H__35A3B4E4_B84F_4151_A2D4_732EFF627DD2__INCLUDED_)
#define AFX_SCANSCOPE_H__35A3B4E4_B84F_4151_A2D4_732EFF627DD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScanScope.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScanScope window
#include <list>
class CScanScope : public CStatic
{
// Construction
protected:
	int ConvertTimeToAxisX(double dTime);
	int ConvertValueToAxisY(double dValue);
	int ConvertValueToAxisW(double dValue);
	void DrawGrid(CDC *pDC);
	virtual void DrawCurve(CDC *pDC);
	virtual void DrawFrameText(CDC *pDC);
	virtual void DrawCurveFrame(CDC *pDC);
	virtual void DrawArrow(CDC *pDC,int nIndex,BOOL bLighted);
	

	
protected:
	int     m_nArrowIndex;
	CRgn	m_rgnYPlus;
	CRgn	m_rgnYMinus;
	CRgn	m_rgnTPlus;
	CRgn	m_rgnTMinus;
	CRgn	m_rgnWPlus;
	CRgn	m_rgnWMinus;


	double m_dDimT;
	double m_dDimY;
	double m_dDimW;
	CRect  m_rectPanel;
	CRect  m_rectCurve;

	CRgn   m_rgnCurve;


	CPen   m_penGrid;
	CPen   m_penScanLine;
	CPen   m_penBlack;
	CPen   m_penValue1;
	CPen   m_penValue2;
	CPen   m_penValue3;

	CBrush m_brushCurve;
	CBrush m_brushPanel;

	CFont  m_fontLabel;
	CFont  m_fontAxis;
	

	BOOL	m_bDrawing;
	CString m_strTitle;
	std::list<double> m_timeList;
	std::list<double> m_ValueList1;
	std::list<double> m_ValueList2;
	std::list<double> m_ValueList3;

public:
	void SetTitle(CString strTitle);
	void AddValue(double t,double y1,double y2,double w);
	virtual void UpdateCurve();
	void SetDimT(double dNewT);
	void SetDimY(double dNewY);
	void SetDimW(double dNewW);
	


	
public:
	CScanScope();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScanScope)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScanScope();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScanScope)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCANSCOPE_H__35A3B4E4_B84F_4151_A2D4_732EFF627DD2__INCLUDED_)
