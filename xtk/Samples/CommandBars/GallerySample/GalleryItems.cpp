// GalleryItems.cpp: implementation of the CGalleryItemStyleSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GalleryItems.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CGalleryItemStyleSet

CGalleryItemStyleSet::CGalleryItemStyleSet(int nId, LPCTSTR lpszCaption)
{
	m_strCaption = lpszCaption;	
	m_nId = nId;
}

CGalleryItemStyleSet::~CGalleryItemStyleSet()
{

}

void CGalleryItemStyleSet::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked)
{
	CXTPPaintManager* pPaintManager = pGallery->GetPaintManager();

	COLORREF clrTextColor = pPaintManager->GetRectangleTextColor(bSelected, bPressed, bEnabled, FALSE, FALSE, xtpBarTypePopup, xtpBarPopup);

	pDC->SetTextColor(clrTextColor);
	CXTPFontDC font(pDC, pPaintManager->GetRegularFont());

	int cx = pPaintManager->GetPopupBarGripperWidth(pGallery->GetParent()) - 1;
	pPaintManager->DrawPopupBarGripper(pDC, rcItem.left - 1, rcItem.top, cx + 1, rcItem.Height());

	pPaintManager->DrawRectangle(pDC, rcItem, bSelected, bPressed, bEnabled, FALSE, FALSE, xtpBarTypePopup, xtpBarPopup);

	if (bChecked && bEnabled)
	{
		CRect rcCheck(rcItem.left + 1, rcItem.top + 1, rcItem.left + cx - 2, rcItem.bottom - 1);
		pPaintManager->DrawRectangle(pDC, rcCheck, bSelected, bPressed, bEnabled, TRUE, FALSE, xtpBarTypePopup, xtpBarPopup);
		
		pPaintManager->DrawCheckMark(pDC, rcCheck);
	}

	CRect rcText(rcItem);
	rcText.left += pPaintManager->m_nPopupBarTextPadding + cx;

	pDC->DrawText(m_strCaption, rcText, DT_END_ELLIPSIS|DT_SINGLELINE|DT_VCENTER);
}

//////////////////////////////////////////////////////////////////////////
// CGalleryItemThemeColors


CGalleryItemThemeColors::CGalleryItemThemeColors(int nId, LPCTSTR lpszCaption)
{
	m_strToolTip = m_strCaption = lpszCaption;	
	m_nId = nId;
}

const struct COLORPREVIEW
{
	COLORREF clrSample[8];
} 
themeColors[] = 
{
	{//Office
		RGB(31, 73, 125), RGB(238, 236, 225), RGB(79, 129, 189), RGB(192, 80, 77), 
		RGB(155, 187, 89),RGB(128, 100, 162), RGB(75, 172, 198), RGB(247, 150, 70)
	},
	{//Grayscale
		RGB(51, 51, 51), RGB(229, 229, 229), RGB(102, 102, 102), RGB(153, 153, 153),
		RGB(178, 178, 178), RGB(81, 81, 81),RGB(127, 127, 127), RGB(192, 192, 192)
	},
	{//Apex
		RGB(105, 103, 109), RGB(201, 194, 209), RGB(206, 185, 102), RGB(156, 176, 132),
		RGB(107, 177, 201), RGB(101, 133, 207), RGB(126, 107, 201), RGB(163, 121, 187)
	},
	{//Aspect
		RGB(50, 50, 50), RGB(227, 222, 209), RGB(240, 127, 9), RGB(159, 41, 54),
		RGB(27, 88, 124), RGB(78, 133, 66), RGB(96, 72, 120), RGB(193, 152, 89)
	},
	{//Civic
		RGB(100, 107, 134), RGB(197, 209, 215), RGB(209, 99, 73), RGB(204, 180, 0),
		RGB(140, 173, 174), RGB(140, 123, 112), RGB(143, 176, 140), RGB(209, 144, 73)
	},
	{//Concourse
		RGB(70, 70, 70), RGB(222, 245, 250), RGB(045, 162, 191), RGB(218, 31, 40),
		RGB(235, 100, 27), RGB(57, 99, 157), RGB(71, 75, 120), RGB(125, 60, 74)
	},
	{//Currency
		RGB(74, 96, 110), RGB(209, 225, 227), RGB(121, 181, 176), RGB(180, 188, 76),
		RGB(183, 120, 81), RGB(119, 106, 91), RGB(182, 173, 118), RGB(149, 174, 177)
	},
	{//Deluxe
		RGB(48, 53, 110), RGB(255, 249, 229), RGB(204, 71, 87), RGB(255, 111, 97),
		RGB(255, 149, 62), RGB(248, 189, 82), RGB(70, 166, 189), RGB(84, 136, 188)
	}

};

void CGalleryItemThemeColors::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked)
{
	CXTPPaintManager* pPaintManager = pGallery->GetPaintManager();

	COLORREF clrTextColor = pPaintManager->GetRectangleTextColor(bSelected, bPressed, bEnabled, FALSE, FALSE, xtpBarTypePopup, xtpBarPopup);

	pDC->SetTextColor(clrTextColor);
	CXTPFontDC font(pDC, pPaintManager->GetRegularFont());

	pPaintManager->DrawRectangle(pDC, rcItem, bSelected, bPressed, bEnabled, FALSE, FALSE, xtpBarTypePopup, xtpBarPopup);

	CRect rcPreview(rcItem.left + 2, rcItem.top + 2, rcItem.left + 2 + 108, rcItem.bottom - 2);

	if (bChecked && bEnabled)
	{
		pPaintManager->DrawRectangle(pDC, rcPreview, bSelected, bPressed, bEnabled, TRUE, FALSE, xtpBarTypeNormal, xtpBarPopup);
	}

	CRect rcColor(rcPreview);
	rcColor.DeflateRect(2, 2);
	rcColor.right = rcColor.left + rcColor.Height();

	const COLORPREVIEW& clrPreview = themeColors[GetID()];

	for (int i = 0; i < 8; i++)
	{
		pDC->FillSolidRect(rcColor, clrPreview.clrSample[i]);
		pDC->Draw3dRect(rcColor, RGB(134, 134, 134), RGB(134, 134, 134));
		
		rcColor.OffsetRect(rcColor.Width() + 1, 0);
	}

	CRect rcText(rcItem);
	rcText.left += 120;
	pDC->DrawText(m_strCaption, rcText, DT_END_ELLIPSIS|DT_SINGLELINE|DT_VCENTER);
}

//////////////////////////////////////////////////////////////////////////
// CGalleryItemThemeFonts


const struct FONTPREVIEW
{
	LPCTSTR lpszBody;
	LPCTSTR lpszHeadings;
} 
themeFonts[] = 
{
	{//Office
		_T("Cambria"), _T("Calibri")
	},
	{//Apex
		_T("Arial"), _T("Times New Roman")
	},
	{//Aspect
		_T("Verdana"), _T("Verdana")
	},
	{//Civic
		_T("Georgia"), _T("Georgia")
	},
	{//Concourse
		_T("Eras Medium ITC"), _T("Eras Medium ITC")
	},
	{//Currency
		_T("Constantia"), _T("Constantia")
	},
	{//Deluxe
		_T("Corbel"), _T("Corbel")
	},
	{//Equity
		_T("Franklin Gothic Book"), _T("Perpetua")
	}

};

CGalleryItemThemeFonts::CGalleryItemThemeFonts(int nId, LPCTSTR lpszCaption)
{
	m_strToolTip = m_strCaption = lpszCaption;	
	m_nId = nId;
}


void CGalleryItemThemeFonts::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked)
{
	CXTPPaintManager* pPaintManager = pGallery->GetPaintManager();
	pPaintManager->DrawRectangle(pDC, rcItem, bSelected, bPressed, bEnabled, bChecked, FALSE, xtpBarTypeNormal, xtpBarPopup);

	CRect rcPreview(rcItem.left + 6, rcItem.top + 6, rcItem.left + 6 + 43, rcItem.bottom - 6);
	pDC->Draw3dRect(rcPreview, RGB(97, 108, 129), RGB(97, 108, 129));
	rcPreview.DeflateRect(1, 1);
	pDC->Draw3dRect(rcPreview, RGB(255, 255, 255), RGB(255, 255, 255));
	rcPreview.DeflateRect(1, 1);
	pDC->Draw3dRect(rcPreview, RGB(195, 200, 213), RGB(195, 200, 213));
	rcPreview.DeflateRect(1, 1);
	pDC->FillSolidRect(rcPreview, RGB(243, 243, 244));
	
	pDC->SetTextColor(0);

	const FONTPREVIEW& fontPreview = themeFonts[GetID()];

	CFont fntBody;
	fntBody.CreatePointFont(130, fontPreview.lpszBody);
	
	CFont fntHeadings;
	fntHeadings.CreatePointFont(120, fontPreview.lpszHeadings);

	CRect rcFontPreviewBody(rcPreview.left + 5, rcPreview.top, rcPreview.right, rcPreview.bottom - 5);
	CXTPFontDC fnt(pDC, &fntBody);
	pDC->DrawText(_T("A"), rcFontPreviewBody, DT_BOTTOM | DT_SINGLELINE);

	CRect rcFontPreviewBodyText(rcItem.left + 70, rcItem.top + 17, rcItem.right, rcItem.bottom);
	pDC->DrawText(fontPreview.lpszBody, rcFontPreviewBodyText, DT_TOP | DT_SINGLELINE);

	CRect rcFontPreviewHeadings(rcPreview.left + 20, rcPreview.top, rcPreview.right, rcPreview.bottom - 5);
	fnt.SetFont(&fntHeadings);
	pDC->DrawText(_T("a"), rcFontPreviewHeadings, DT_BOTTOM | DT_SINGLELINE);

	CRect rcFontPreviewHeadingsText(rcItem.left + 70, rcItem.top + 37, rcItem.right, rcItem.bottom);
	pDC->DrawText(fontPreview.lpszHeadings, rcFontPreviewHeadingsText, DT_TOP | DT_SINGLELINE);

}

//////////////////////////////////////////////////////////////////////////
// CGalleryItemTable


CGalleryItemTable::CGalleryItemTable(int nId)
{
	m_nId = nId;
}


void CGalleryItemTable::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL /*bEnabled*/, BOOL bSelected, BOOL /*bPressed*/, BOOL /*bChecked*/)
{
	int nItem = pGallery->IsItemSelected() ? pGallery->GetSelectedItem() : -1;
	CRect rcItems = pGallery->GetItemsRect();
	CSize szItems = pGallery->GetItems()->GetItemSize();
	int nItemsPerRow = rcItems.Width() / szItems.cx;

	int nColumns = nItem < 1 ? 0 : (nItem - 1) % nItemsPerRow + 1;
	int nRows = nItem < 1 ? 0 : (nItem - 1) / nItemsPerRow + 1;


	int nColumnItem = (GetIndex() - 1) % nItemsPerRow + 1;
	int nRowItem = (GetIndex() - 1) / nItemsPerRow + 1;

	bSelected = nRowItem <= nRows && nColumnItem <= nColumns;
	


	rcItem.DeflateRect(0, 0, 1, 1);

	if (bSelected)
	{
		pDC->Draw3dRect(rcItem, RGB(239, 72, 16), RGB(239, 72, 16));
		rcItem.DeflateRect(1, 1);
		pDC->Draw3dRect(rcItem, RGB(255, 226, 148), RGB(255, 226, 148));
	}
	else
	{
		rcItem.DeflateRect(1, 1);
		pDC->Draw3dRect(rcItem, 0, 0);
	}
	rcItem.DeflateRect(1, 1);
	pDC->FillSolidRect(rcItem, GetXtremeColor(COLOR_WINDOW));

}

CGalleryItemTableLabel::CGalleryItemTableLabel()
{
	m_bLabel = TRUE;
}


void CGalleryItemTableLabel::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked)
{
	int nItem = pGallery->IsItemSelected() ? pGallery->GetSelectedItem() : -1;
	CRect rcItems = pGallery->GetItemsRect();
	CSize szItems = pGallery->GetItems()->GetItemSize();
	int nItemsPerRow = rcItems.Width() / szItems.cx;

	int nColumns = nItem < 1 ? 0 : (nItem - 1) % nItemsPerRow + 1;
	int nRows = nItem < 1 ? 0 : (nItem - 1) / nItemsPerRow + 1;


	if (nItem < 1)
		m_strCaption = _T("Insert Table");
	else
		m_strCaption.Format(_T("%ix%i Table"), nRows, nColumns);

	CXTPControlGalleryItem::Draw(pDC, pGallery, rcItem, bEnabled, bSelected, bPressed, bChecked);
}

//////////////////////////////////////////////////////////////////////////
//

CGalleryItemFontColor::CGalleryItemFontColor(COLORREF clr, int nToolTip)
{
	m_nId = clr;
	m_strToolTip.LoadString(nToolTip);

	m_bTopMargin = m_bBottomMargin = TRUE;
}

CGalleryItemFontColor::CGalleryItemFontColor(COLORREF clr, LPCTSTR lpszCaption, BOOL bTopMargin /*= TRUE*/, BOOL bBotttomMargin /*= TRUE*/)
{
	m_nId = clr;
	m_strCaption = m_strToolTip = lpszCaption;

	m_bTopMargin = bTopMargin;
	m_bBottomMargin = bBotttomMargin;

	SetSize(CSize(17, 13 + (bTopMargin ? 2 : 0) + (bBotttomMargin ? 2 : 0)));
}


void CGalleryItemFontColor::Draw(CDC* pDC, CXTPControlGallery* /*pGallery*/, CRect rcItem, BOOL /*bEnabled*/, BOOL bSelected, BOOL /*bPressed*/, BOOL bChecked)
{
	rcItem.DeflateRect(2, 0);
	if (m_bTopMargin)
		rcItem.DeflateRect(0, 2, 0, 0);
	
	if (m_bBottomMargin)
		rcItem.DeflateRect(0, 0, 0, 2);

	pDC->FillSolidRect(rcItem, (COLORREF)m_nId);

	if (bSelected || bChecked)
	{
		if (bSelected)
			pDC->Draw3dRect(rcItem, RGB(242, 148, 54), RGB(242, 148, 54));
		else
			pDC->Draw3dRect(rcItem, RGB(239, 72, 16), RGB(239, 72, 16));
		
		rcItem.DeflateRect(1, 1);
		pDC->Draw3dRect(rcItem, RGB(255, 226, 148), RGB(255, 226, 148));
	}
	else
	{
		if (m_bTopMargin) pDC->FillSolidRect(rcItem.left, rcItem.top, rcItem.Width(), 1, RGB(197, 197, 197));
		pDC->FillSolidRect(rcItem.left, rcItem.top, 1, rcItem.Height(), RGB(197, 197, 197));
		pDC->FillSolidRect(rcItem.right - 1, rcItem.top, 1, rcItem.Height(), RGB(197, 197, 197));
		if (m_bBottomMargin) pDC->FillSolidRect(rcItem.left, rcItem.bottom - 1, rcItem.Width(), 1, RGB(197, 197, 197));
	}
}

void CGalleryItemFontColor::AddStandardBackColors(CXTPControlGalleryItems* pItems)
{
	pItems->AddItem(new CGalleryItemFontColor(RGB(0xFF, 0xFF, 0x00), XTP_IDS_CLR_YELLOW));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0xFF, 0x00), XTP_IDS_CLR_BRIGHT_GREEN));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0xFF, 0xFF), XTP_IDS_CLR_TURQUOISE));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0xFF, 0x00, 0xFF), XTP_IDS_CLR_PINK));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0x00, 0xFF), XTP_IDS_CLR_BLUE));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0xFF, 0x00, 0x00), XTP_IDS_CLR_RED));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0x00, 0x80), XTP_IDS_CLR_DARK_BLUE));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0x80, 0x80), XTP_IDS_CLR_TEAL));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0x80, 0x00), XTP_IDS_CLR_GREEN));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x80, 0x00, 0x80), XTP_IDS_CLR_VIOLET));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x80, 0x00, 0x00), XTP_IDS_CLR_DARK_RED));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x80, 0x80, 0x00), XTP_IDS_CLR_DARK_YELLOW));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x80, 0x80, 0x80), XTP_IDS_CLR_GRAY50));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0xC0, 0xC0, 0xC0), XTP_IDS_CLR_GRAY25));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0x00, 0x00, 0x00), XTP_IDS_CLR_BLACK));
}

void CGalleryItemFontColor::AddStandardColors(CXTPControlGalleryItems* pItems)
{
	pItems->AddItem(new CGalleryItemFontColor(RGB(192, 0, 0), _T("Dark Red")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(255, 0, 0), _T("Red")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(255, 192, 0), _T("Orange")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(255, 255, 0), _T("Yellow")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(146, 208, 80), _T("Light Green")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0, 176, 80), _T("Green")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0, 176, 240), _T("Light Blue")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0, 112, 192), _T("Blue")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(0, 32, 96), _T("Dark Blue")));
	pItems->AddItem(new CGalleryItemFontColor(RGB(112, 48, 160), _T("Purple")));
}

COLORREF TintColor(COLORREF clr, int nTint)
{
	double d = nTint * 0.01;
				
	clr = RGB(255 - (255 - GetRValue(clr)) * d, 255 - (255 - GetGValue(clr)) * d, 255 - (255 - GetBValue(clr)) * d);
	return clr;
}

COLORREF ShadeColor(COLORREF clr, int nShade)
{
	double d = nShade * 0.01;

	clr = RGB(GetRValue(clr) * d, GetGValue(clr) * d, GetBValue(clr) * d);
	return clr;
}


void CGalleryItemFontColor::AddThemeColors(CXTPControlGalleryItems* pItems, int nTheme)
{
	const COLORPREVIEW& clrPreview = themeColors[nTheme];
	COLORREF clr;

	for (int j = 0; j < 6; j++)
	{
		BOOL bTopMargin = j < 2;
		BOOL bBottomMargin = j == 0 || j == 5;
		
		clr = RGB(255, 255, 255);
		if (j > 0) clr = ShadeColor(clr, 100 - 10 * j);
		pItems->AddItem(new CGalleryItemFontColor(clr, NULL, bTopMargin, bBottomMargin));

		clr = RGB(0, 0, 0);
		if (j > 0) clr = TintColor(clr, 40 + 10 * j);
		pItems->AddItem(new CGalleryItemFontColor(clr, NULL, bTopMargin, bBottomMargin));
		
		for (int i = 0; i < 8; i++)
		{	
			clr = clrPreview.clrSample[i];

			if (j == 0)
			{
			}
			else if (j < 4)
			{
				clr = TintColor(clr, 20 * j);
			}
			else
			{
				clr = ShadeColor(clr, j == 4 ?  75 : 50);
			}
			pItems->AddItem(new CGalleryItemFontColor(clr, NULL, bTopMargin, bBottomMargin));		
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// CGalleryItemFontFace

CGalleryItemFontFace::CGalleryItemFontFace(LPCTSTR lpszCaption)
{
	m_strCaption = lpszCaption;
}

void CGalleryItemFontFace::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL bEnabled, BOOL bSelected, BOOL /*bPressed*/, BOOL bChecked)
{
	CXTPPaintManager* pPaintManager = pGallery->GetPaintManager();

	pPaintManager->DrawRectangle(pDC, rcItem, bSelected, FALSE, bEnabled, bChecked, FALSE, xtpBarTypePopup, xtpBarPopup);

	COLORREF clrTextColor = pPaintManager->GetRectangleTextColor(bSelected, FALSE, bEnabled, FALSE, FALSE, xtpBarTypePopup, xtpBarPopup);
	pDC->SetTextColor(clrTextColor);

	CFont fnt;
	fnt.CreatePointFont(150, m_strCaption);

	CXTPFontDC font(pDC, &fnt);

	CRect rcText(rcItem);
	rcText.left += 4;

	pDC->DrawText(m_strCaption, rcText, DT_END_ELLIPSIS|DT_SINGLELINE|DT_VCENTER);
}

void CGalleryItemFontFace::AddFontItems(CXTPControlGalleryItems* pItems)
{
	pItems->AddLabel(_T("Recently Used Fonts"));

	pItems->AddLabel(_T("All Fonts"));

	static CXTPControlFontComboBoxList::CFontDescHolder s_fontHolder;
	s_fontHolder.EnumFontFamilies();

		// now walk through the fonts and remove (charset) from fonts with only one
	CArray<CXTPControlFontComboBoxList::CFontDesc*, CXTPControlFontComboBoxList::CFontDesc*>& arrFontDesc = 
		s_fontHolder.m_arrayFontDesc;

	int nCount = (int)arrFontDesc.GetSize();
	int i;
	for (i = 0; i < nCount; i++)
	{
		CXTPControlFontComboBoxList::CFontDesc* pDesc = arrFontDesc[i];
		CString str = pDesc->m_strName;

		if (str == _T("Arial") || str == _T("Tahoma"))
		{
			CXTPControlGalleryItem* pItem = pItems->InsertItem(1, new CGalleryItemFontFace(str));
			pItem->SetData((DWORD_PTR)pDesc);
		}

		CXTPControlGalleryItem* pItem = pItems->AddItem(new CGalleryItemFontFace(str));
		pItem->SetData((DWORD_PTR)pDesc);
	}
}


//////////////////////////////////////////////////////////////////////////
// CControlGalleryUndo

IMPLEMENT_XTP_CONTROL(CControlGalleryUndo,  CXTPControlGallery)

CControlGalleryUndo::CControlGalleryUndo()
{
}

void CControlGalleryUndo::OnSelectedItemChanged()
{
	CXTPControlStatic* pInfo = FindInfoControl();
	if (pInfo)
	{
		CString str;
		if (!IsItemSelected())
		{
			str = _T("Cancel");
		}
		else
		{
			str.Format(_T("Undo %i Actions"), GetSelectedItem() + 1);
		}
		pInfo->SetCaption(str);
		pInfo->RedrawParent(FALSE);
	}

}

CXTPControlStatic* CControlGalleryUndo::FindInfoControl()
{
	CXTPCommandBar* pCommandBar = GetParent();

	for (int i = 0; i < pCommandBar->GetControls()->GetCount(); i++)
	{
		CXTPControlStatic* pControlStatic = DYNAMIC_DOWNCAST(CXTPControlStatic, pCommandBar->GetControl(i));
		if (pControlStatic && pControlStatic->GetID() == GetID())
		{
			return pControlStatic;
		}

	}
	return NULL;
}


CGalleryItemUndo::CGalleryItemUndo(LPCTSTR lpszCaption)
{
	m_strCaption = lpszCaption;
}

void CGalleryItemUndo::Draw(CDC* pDC, CXTPControlGallery* pGallery, CRect rcItem, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked)
{
	int nItem = pGallery->IsItemSelected() ? pGallery->GetSelectedItem() : -1;
	bSelected = GetID() <= nItem;

	CXTPControlGalleryItem::Draw(pDC, pGallery, rcItem, bEnabled, bSelected, bPressed, bChecked);
}
