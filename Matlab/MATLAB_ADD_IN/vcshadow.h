#if !defined(AFX_VCSHADOW_H__14BD5F12_BFCE_440A_B6E8_801A3121B770__INCLUDED_)
#define AFX_VCSHADOW_H__14BD5F12_BFCE_440A_B6E8_801A3121B770__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CVcBrush;
class CVcCoor;

/////////////////////////////////////////////////////////////////////////////
// CVcShadow wrapper class

class CVcShadow : public COleDispatchDriver
{
public:
	CVcShadow() {}		// Calls COleDispatchDriver default constructor
	CVcShadow(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcShadow(const CVcShadow& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetStyle();
	void SetStyle(long nNewValue);
	CVcBrush GetBrush();
	CVcCoor GetOffset();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCSHADOW_H__14BD5F12_BFCE_440A_B6E8_801A3121B770__INCLUDED_)
