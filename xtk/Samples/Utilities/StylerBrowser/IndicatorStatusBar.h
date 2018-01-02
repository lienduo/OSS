#pragma once




class CIndicatorStatusBar : public CXTPStatusBar
{
// Construction
public:
	CIndicatorStatusBar();

	void SetProgress(int nProgress);
	virtual ~CIndicatorStatusBar();

	void DrawPaneEntry(CDC* pDC, int nIndex, CRect rcItem);

protected:
	int m_nProgress;
};
