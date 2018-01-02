#if !defined(AFX_SCOPE1_H__20373609_0B81_493C_8F94_B4644298A84F__INCLUDED_)
#define AFX_SCOPE1_H__20373609_0B81_493C_8F94_B4644298A84F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Scope1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScope window
#include <list>
#include <iterator>
//using std::list;
//using std::iterator;
class CScope : public CStatic
{
// Construction
public:
	CScope();
// Attributes
public:
// Operations
public:
	void SetTitle(CString strTitle);
	void SetValue(double dValue);
	void SetValueString(CString strTitle,CString strUnit);
	void SetDimT(double newDimT);
	void SetDimy(double newDimY);
	void SetBase(int nNewABase,int nRange);
	void UpdateCurve();
	void AddValue(double dTime,double dValue);
	void Clear();
	
	
private:
	int ConvertTimeToAxisX(double dTime);
	int ConvertValueToAxisY(double dValue);
	void DrawValue(CDC *pDC);
	void DrawValuePanel(CDC *pDC);
	void DrawTitle(CDC *pDC);
	void DrawCurvePanel(CDC *pDC);
	void DrawGrid(CDC *pDC);
	void DrawCurve(CDC *pDC);
	void DrawAxis(CDC *pDC);
	void DrawTrack(CDC *pDC,BOOL bPressed);
	void DrawArrow(CDC *pDC,int nIndex,BOOL bLighted);
private:
	CRect	m_rectCurve;
	CRect	m_rectValue;
	CRect   m_rectCurvePanel;
	CRect   m_rectValuePanel;
	CRect   m_rectScroll;

	CRgn	m_rgnCurve;
	CRgn	m_rgnYPlus;
	CRgn	m_rgnYMinus;
	CRgn	m_rgnTPlus;
	CRgn	m_rgnTMinus;
    

	
	CBrush  m_BkBrush;
	CBrush  m_PanelBrush;
	CBrush  m_CurveBrush;

	CPen    m_PenCurve;
	CPen    m_PenGrid;
	CPen    m_PenBrightLine;
	CPen    m_PenDarkLine;

	CFont   m_FontTitle;
	CFont   m_FontValue;
	CFont   m_FontAxis;
	CFont   m_FontLabel;
	   
	double  m_dDimT;
	double  m_dDimY;
	double  m_dValue;

	int		m_nBase;
	int		m_nRange;
	int     m_nArrowIndex;
	BOOL    m_bPressed ;

	BOOL	m_bDrawing;

	CBitmap m_bitmapTitle;
	CBitmap m_bitmapTrack;


	CString m_strTitle;
	CString m_strValueName;
	CString m_strUnitName;
	std::list<double> m_TimeList;
	std::list<double> m_ValueList;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScope)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScope();

	// Generated message map functions
protected:
	
	//{{AFX_MSG(CScope)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOPE1_H__20373609_0B81_493C_8F94_B4644298A84F__INCLUDED_)
