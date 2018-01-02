// ReportMultilinePaintManager.h: interface for the CReportMultilinePaintManager class.
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

#if !defined(AFX_REPORTMULTILINEPAINTMANAGER_H__A7C8FD37_4FE9_4D51_80F1_683E015E8E5B__INCLUDED_)
#define AFX_REPORTMULTILINEPAINTMANAGER_H__A7C8FD37_4FE9_4D51_80F1_683E015E8E5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////////
// This class is a customization of standard Report Paint Manager, 
// which allows drawing record items text with word wrapping.
// You can test this customization sample with "Multiline Sample" menu option.
// It is implemented using DT_WORDBREAK mode, and uses 2 methods overriding.
class CReportMultilinePaintManager : public CXTPReportPaintManager
{
public:
	CReportMultilinePaintManager();
	virtual ~CReportMultilinePaintManager();

	// Draws Item Caption with word wrapping.
	void DrawItemCaption(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pMetrics);

	// Customized calculation of the row height in word wrapping mode, 
	// which is required in other report drawing methods.
	int GetRowHeight(CDC* pDC, CXTPReportRow* pRow, int nWidth);

};

#endif // !defined(AFX_REPORTMULTILINEPAINTMANAGER_H__A7C8FD37_4FE9_4D51_80F1_683E015E8E5B__INCLUDED_)
