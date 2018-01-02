// RibbonSampleView.cpp : implementation of the CRibbonSampleView class
//

#include "stdafx.h"
#include "RibbonSample.h"

#include "RibbonSampleDoc.h"
#include "CntrItem.h"
#include "RibbonSampleView.h"
#include "MainFrm.h"
#include "GalleryItems.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonSampleView

IMPLEMENT_DYNCREATE(CRibbonSampleView, CRichEditView)

BEGIN_MESSAGE_MAP(CRibbonSampleView, CScrollRichEditView)
	//{{AFX_MSG_MAP(CRibbonSampleView)
	ON_WM_DESTROY()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)

	ON_COMMAND_RANGE(ID_ILLUSTRATION_PICTURE, ID_TABLE_INSERTTABLE, OnInsertSomeObject)

	ON_COMMAND(ID_EDIT_GOTO, OnEditGoto)
	ON_COMMAND_RANGE(ID_PAGES_NEW, ID_NEWPAGE_BLANKPAGE, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_THEMES_BUILTIN, ID_THEMES_BUILTIN, OnEmptyCommand)
	
	ON_UPDATE_COMMAND_UI(ID_PARAGRAPH_INDENTLEFT, OnUpdateIndentLeft)
	ON_XTP_EXECUTE(ID_PARAGRAPH_INDENTLEFT, OnIndentLeft)
	ON_NOTIFY(XTP_FN_SPINUP, ID_PARAGRAPH_INDENTLEFT, OnIndentLeftSpin)
	ON_NOTIFY(XTP_FN_SPINDOWN, ID_PARAGRAPH_INDENTLEFT, OnIndentLeftSpin)

	ON_UPDATE_COMMAND_UI(ID_PARAGRAPH_INDENTRIGHT, OnUpdateIndentRight)
	ON_XTP_EXECUTE(ID_PARAGRAPH_INDENTRIGHT, OnIndentRight)
	ON_NOTIFY(XTP_FN_SPINUP, ID_PARAGRAPH_INDENTRIGHT, OnIndentRightSpin)
	ON_NOTIFY(XTP_FN_SPINDOWN, ID_PARAGRAPH_INDENTRIGHT, OnIndentRightSpin)

	ON_UPDATE_COMMAND_UI(ID_PARAGRAPH_SPACINGBEFORE, OnUpdateSpaceBefore)
	ON_XTP_EXECUTE(ID_PARAGRAPH_SPACINGBEFORE, OnSpaceBefore)
	ON_NOTIFY(XTP_FN_SPINUP, ID_PARAGRAPH_SPACINGBEFORE, OnSpaceBeforeSpin)
	ON_NOTIFY(XTP_FN_SPINDOWN, ID_PARAGRAPH_SPACINGBEFORE, OnSpaceBeforeSpin)

	ON_UPDATE_COMMAND_UI(ID_PARAGRAPH_SPACINGAFTER, OnUpdateSpaceAfter)
	ON_XTP_EXECUTE(ID_PARAGRAPH_SPACINGAFTER, OnSpaceAfter)
	ON_NOTIFY(XTP_FN_SPINUP, ID_PARAGRAPH_SPACINGAFTER, OnSpaceAfterSpin)
	ON_NOTIFY(XTP_FN_SPINDOWN, ID_PARAGRAPH_SPACINGAFTER, OnSpaceAfterSpin)

	ON_COMMAND_RANGE(ID_CONTENTS_TABLE, ID_CONTENTS_UPDATE, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_FOOTNOTES_INSERT, ID_FOOTNOTES_NEXT, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_CAPTIONS_INSERT, ID_CAPTIONS_UPDATE, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_INDEX_MARK, ID_INDEX_INSERT, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_VIEW_PRINTLAYOUT, ID_VIEW_DRAFT, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_ZOOM_ZOOM, ID_ZOOM_PAGEWIDTH, OnEmptyCommand)

	ON_UPDATE_COMMAND_UI(ID_NEWPAGE_SELECTION, CRichEditView::OnUpdateNeedSel)

	ON_COMMAND_RANGE(ID_INSERT_HYPERLINK, ID_TEXT_DATETIME, OnEmptyCommand)
	ON_COMMAND_RANGE(ID_TEXT_CHANGECASE, ID_BORDERS_NOBORDER, OnEmptyCommand)
	

	ON_COMMAND(ID_CHAR_BOLD, CRichEditView::OnCharBold)
	ON_COMMAND(ID_CHAR_UNDERLINE, CRichEditView::OnCharUnderline)
	ON_COMMAND(ID_CHAR_ITALIC, CRichEditView::OnCharItalic)
	ON_UPDATE_COMMAND_UI(ID_CHAR_BOLD, CRichEditView::OnUpdateCharBold)
	ON_UPDATE_COMMAND_UI(ID_CHAR_UNDERLINE, CRichEditView::OnUpdateCharUnderline)
	ON_UPDATE_COMMAND_UI(ID_CHAR_ITALIC, CRichEditView::OnUpdateCharItalic)

	ON_COMMAND(ID_PARA_CENTER, OnParaCenter)
	ON_UPDATE_COMMAND_UI(ID_PARA_CENTER, OnUpdateParaCenter)
	ON_COMMAND(ID_PARA_LEFT, OnParaLeft)
	ON_UPDATE_COMMAND_UI(ID_PARA_LEFT, OnUpdateParaLeft)
	ON_COMMAND(ID_PARA_RIGHT, OnParaRight)
	ON_UPDATE_COMMAND_UI(ID_PARA_RIGHT, OnUpdateParaRight)
	ON_COMMAND(ID_PARA_JUSTIFY, OnParaJustify)
	ON_UPDATE_COMMAND_UI(ID_PARA_JUSTIFY, OnUpdateParaJustify)

	ON_COMMAND(ID_INSERT_BULLET, CRichEditView::OnBullet)
	ON_UPDATE_COMMAND_UI(ID_INSERT_BULLET, CRichEditView::OnUpdateBullet)

	ON_COMMAND(ID_GROUP_FONT_OPTION, OnGroupFont)
	ON_COMMAND(ID_GROUP_CLIPBOARD_OPTION, OnGroupClipboad)
	ON_COMMAND(ID_GROUP_PARAGRAPH_OPTION, OnGroupParagraph)

	ON_UPDATE_COMMAND_UI(XTP_ID_RIBBONCONTROLTAB, OnUpdateRibbonTab)

	ON_UPDATE_COMMAND_UI(ID_TEXT_COLOR_SELECTOR, OnUpdateSelectorText)
	ON_XTP_EXECUTE(ID_TEXT_COLOR_SELECTOR, OnSelectorText)

	ON_UPDATE_COMMAND_UI(ID_TEXT_COLOR, OnUpdateText)
	ON_COMMAND(ID_TEXT_COLOR, OnButtonText)

	ON_UPDATE_COMMAND_UI(XTP_IDS_AUTOMATIC, OnUpdateTextAuto)
	ON_COMMAND(XTP_IDS_AUTOMATIC, OnTextAuto)

	ON_XTP_EXECUTE(ID_GALLERY_FONTBACKCOLOR, OnGalleryFontBackColor)
	ON_UPDATE_COMMAND_UI(ID_GALLERY_FONTBACKCOLOR, OnUpdateGalleryFontBackColor)	
	ON_UPDATE_COMMAND_UI(ID_TEXT_HIGHLIGHTCOLOR, OnUpdateBack)
	ON_COMMAND(ID_TEXT_HIGHLIGHTCOLOR, OnButtonBack)


	ON_UPDATE_COMMAND_UI(ID_GALLERY_FONTFACE, OnUpdateGalleryFontFace)	
	ON_UPDATE_COMMAND_UI(ID_GALLERY_FONTSIZE, OnUpdateGalleryFontSize)	

	ON_UPDATE_COMMAND_UI(ID_FONT_FACE, OnUpdateComboFont)
	ON_XTP_EXECUTE(ID_FONT_FACE, OnEditFont)

	ON_UPDATE_COMMAND_UI(ID_FONT_SIZE, OnUpdateComboSize)
	ON_XTP_EXECUTE(ID_FONT_SIZE, OnEditSize)

	ON_CONTROL_REFLECT(EN_VSCROLL, OnEditScrollChanged)
	ON_NOTIFY_REFLECT(EN_REQUESTRESIZE,	OnRequestResize)

	ON_COMMAND(ID_TEXT_INSERTOBJECT, CRichEditView::OnInsertObject)
	
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_XTP_EXECUTE(ID_EDIT_UNDO, OnEditUndo)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRibbonSampleView construction/destruction

CRibbonSampleView::CRibbonSampleView()
{
	m_clr = RGB(255, 0, 0);
	m_clrBack = COLORREF_NULL;
}

CRibbonSampleView::~CRibbonSampleView()
{
}

BOOL CRibbonSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;


	return CScrollRichEditView::PreCreateWindow(cs);
}

void CRibbonSampleView::OnInitialUpdate()
{
	CScrollRichEditView::OnInitialUpdate();

	USES_CONVERSION;



	// Set the printing margins (720 twips = 1/2 inch).
	SetMargins(CRect(720, 720, 720, 720));

	CHARFORMAT cf;
	ZeroMemory(&cf, sizeof(CHARFORMAT));
	
	CString strDefFont = _T("Tahoma");
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_BOLD |CFM_ITALIC | CFM_UNDERLINE | CFM_STRIKEOUT | CFM_SIZE |
		CFM_COLOR | CFM_OFFSET | CFM_PROTECTED | CFM_FACE;
	cf.dwEffects = CFE_AUTOCOLOR;
	cf.yHeight = 200; //10pt
	cf.bPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;

#if (_RICHEDIT_VER >= 0x0200)
	lstrcpyn(cf.szFaceName, strDefFont, LF_FACESIZE);
#else
	lstrcpynA(cf.szFaceName, T2A((LPTSTR) (LPCTSTR) strDefFont), LF_FACESIZE);
#endif

	GetRichEditCtrl().SetDefaultCharFormat(cf);

	ModifyStyleEx(WS_EX_CLIENTEDGE, 0);
	ModifyStyle(0, WS_BORDER);
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonSampleView printing

BOOL CRibbonSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CRibbonSampleView::OnDestroy()
{
	CRichEditView::OnDestroy();
}


/////////////////////////////////////////////////////////////////////////////
// CRibbonSampleView diagnostics

#ifdef _DEBUG
void CRibbonSampleView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CRibbonSampleView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CRibbonSampleDoc* CRibbonSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRibbonSampleDoc)));
	return (CRibbonSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRibbonSampleView message handlers

void CRibbonSampleView::OnEditGoto()
{

}

void CRibbonSampleView::OnEmptyCommand(UINT)
{

}

void CRibbonSampleView::OnParaJustify()
{
	OnParaAlign(0x4);
}

void CRibbonSampleView::OnUpdateParaJustify(CCmdUI* pCmdUI)
{
	OnUpdateParaAlign(pCmdUI, 0x4);
}

void CRibbonSampleView::OnRButtonDown(UINT /*nFlags*/, CPoint point) 
{
	ClientToScreen(&point);
	CMenu mnu;
	mnu.LoadMenu(IDR_MENU_CONTEXT);
	((CMainFrame*)AfxGetMainWnd())->GetCommandBars()->TrackPopupMenuEx(mnu.GetSubMenu(0), TPM_RIGHTBUTTON , point.x, point.y);

}


void CRibbonSampleView::OnGroupClipboad()
{
	AfxMessageBox(_T("Clipboard dialog"));
}
void CRibbonSampleView::OnGroupParagraph()
{
	AfxMessageBox(_T("Paragraph dialog"));

}
void CRibbonSampleView::OnGroupFont()
{
	OnFormatFont();
}

void CRibbonSampleView::OnUpdateRibbonTab(CCmdUI* pCmdUI)
{
	CXTPRibbonControlTab* pControl = DYNAMIC_DOWNCAST(CXTPRibbonControlTab, CXTPControl::FromUI(pCmdUI));
	if (!pControl)
		return;

	pCmdUI->Enable(TRUE);

	BOOL bVisible;
	CXTPRibbonTab* pTab;

	CRibbonSampleCntrItem* pItem = (CRibbonSampleCntrItem*)GetSelectedItem();
	bVisible = pItem != NULL && pItem->m_nImage == IDB_BITMAP_TABLE;

	pTab = pControl->FindTab(ID_TAB_TABLEDESIGN);
	if (!pTab)
		return;

	pControl->GetParent()->LockRedraw();

	pTab->SetVisible(bVisible);
	
	pTab = pControl->FindTab(ID_TAB_TABLELAYOUT);
	pTab->SetVisible(bVisible);


	bVisible = pItem != NULL && pItem->m_nImage == IDB_BITMAP_CHART;

	pTab = pControl->FindTab(ID_TAB_CHARTDESIGN);
	pTab->SetVisible(bVisible);
	
	pTab = pControl->FindTab(ID_TAB_CHARTLAYOUT);
	pTab->SetVisible(bVisible);

	pTab = pControl->FindTab(ID_TAB_CHARTFORMAT);
	pTab->SetVisible(bVisible);

	pControl->GetParent()->UnlockRedraw();

}

void CRibbonSampleView::OnInsertSomeObject(UINT nID)
{
	if (!OpenClipboard())
		return;

	if (!::EmptyClipboard())
	{
		::CloseClipboard ();
		return;
	}

	int nImage = nID - ID_ILLUSTRATION_PICTURE + IDB_BITMAP_PICTURE;

	CBitmap bmp;
	bmp.LoadBitmap(nImage);

	SetClipboardData(CF_BITMAP, (HANDLE)bmp.GetSafeHandle());

	::CloseClipboard ();


	COleDataObject dataobj;
	dataobj.AttachClipboard();	
	
	
	CWaitCursor wait;

	CRibbonSampleCntrItem* pItem = NULL;
	TRY
	{
		pItem = (CRibbonSampleCntrItem*)GetDocument()->CreateClientItem(NULL);
		pItem->m_bLock = TRUE;

		// paste embedded
		if (!pItem->CreateFromData(&dataobj) &&
			!pItem->CreateStaticFromData(&dataobj))
		{
			AfxThrowMemoryException();      // any exception will do
		}

		HRESULT hr = InsertItem(pItem);
		pItem->UpdateItemType();

		pItem->m_bLock = FALSE;

		if (hr != NOERROR)
			AfxThrowOleException(hr);

	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			pItem->m_bLock = FALSE;
			ASSERT_VALID(pItem);
			pItem->Delete();
			pItem = NULL;
		}
	}
	END_CATCH

	if (pItem)
	{
		pItem->m_nImage = nImage;
	}

}


void CRibbonSampleView::OnUpdateSelectorText(CCmdUI* pCmd)
{
	CXTPControlColorSelector* pSelector = DYNAMIC_DOWNCAST(CXTPControlColorSelector, CXTPControl::FromUI(pCmd));
	if (pSelector)
	{
		CHARFORMAT& cfm = GetCharFormatSelection( );
		pSelector->SetColor(cfm.dwEffects & CFE_AUTOCOLOR? -1: cfm.crTextColor);
	}
	pCmd->Enable(TRUE);
}

void CRibbonSampleView::OnButtonText()
{
	CHARFORMAT& cfm = GetCharFormatSelection( );
	cfm.dwMask |= CFM_COLOR;
	cfm.dwEffects &= ~CFE_AUTOCOLOR ;
	cfm.crTextColor = m_clr;
	GetRichEditCtrl().SetSelectionCharFormat(cfm);

}
void CRibbonSampleView::OnSelectorText(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;

	CXTPControlColorSelector* pControl = (CXTPControlColorSelector*)tagNMCONTROL->pControl;
	m_clr = pControl->GetColor();

	OnButtonText();

	*pResult = 1;
}


void CRibbonSampleView::OnUpdateText(CCmdUI* pCmd)
{

	CXTPControlPopupColor* pPopup = DYNAMIC_DOWNCAST(CXTPControlPopupColor, CXTPControl::FromUI(pCmd));
	if (pPopup)
	{
		pPopup->SetColor(m_clr);
	}

	pCmd->Enable(TRUE);
}

void CRibbonSampleView::OnTextAuto()
{
	CHARFORMAT& cfm = GetCharFormatSelection( );
	cfm.dwMask |= CFM_COLOR;
	cfm.dwEffects |= CFE_AUTOCOLOR ;
	GetRichEditCtrl().SetSelectionCharFormat(cfm);
}

void CRibbonSampleView::OnUpdateTextAuto(CCmdUI* pCmd)
{
	CHARFORMAT& cfm = GetCharFormatSelection( );
	pCmd->SetCheck(cfm.dwEffects & CFE_AUTOCOLOR? TRUE: FALSE);
}


//////////////////////////////////////////////////////////////////////////
//

void CRibbonSampleView::OnUpdateGalleryFontFace(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CRibbonSampleView::OnUpdateGalleryFontSize(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CRibbonSampleView::OnUpdateComboFont(CCmdUI* pCmd)
{
	CXTPControlComboBox* pFontCombo = (CXTPControlComboBox*)CXTPControl::FromUI(pCmd);

	pCmd->Enable(TRUE);

	if (pFontCombo && pFontCombo->GetType() == xtpControlComboBox)
	{
		CHARFORMAT& cf = GetCharFormatSelection();

		if (pFontCombo->HasFocus())
			return;
		
		// the selection must be same font and charset to display correctly
		if ((cf.dwMask & (CFM_FACE | CFM_CHARSET)) == (CFM_FACE | CFM_CHARSET))
			pFontCombo->SetEditText(CString(cf.szFaceName));
		else
			pFontCombo->SetEditText(_T(""));
	}
}


void CRibbonSampleView::OnEditFont(NMHDR* pNMHDR, LRESULT* pResult)
{
	USES_CONVERSION;

	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;

	CXTPControlComboBox* pControl = (CXTPControlComboBox*)tagNMCONTROL->pControl;
	if (pControl->GetType() == xtpControlComboBox)
	{
		CString strFont = pControl->GetEditText();
	
	#if (_MSC_VER < 1300)
		CHARFORMAT cf;
	#else
		CHARFORMAT2 cf;
	#endif
		cf.dwMask = CFM_FACE;
				
	#if (_RICHEDIT_VER >= 0x0200)
		lstrcpyn(cf.szFaceName, strFont, LF_FACESIZE);
	#else
		lstrcpynA(cf.szFaceName, T2A((LPTSTR)(LPCTSTR)strFont), LF_FACESIZE);
	#endif
		SetCharFormat(cf);

		*pResult = 1; // Handled;
	}
}


void CRibbonSampleView::OnUpdateComboSize(CCmdUI* pCmd)
{
	CXTPControlComboBox* pFontCombo = (CXTPControlComboBox*)CXTPControl::FromUI(pCmd);

	pCmd->Enable(TRUE);

	if (pFontCombo && pFontCombo->GetType() == xtpControlComboBox)
	{
		CHARFORMAT& cf = GetCharFormatSelection();

		if (pFontCombo->HasFocus())
			return;

		int nTwip = (cf.dwMask & CFM_SIZE) ? cf.yHeight : -1;
		
		pFontCombo->SetEditText(CXTPControlSizeComboBox::TwipsToPointString(nTwip));
	}
}

void CRibbonSampleView::OnEditSize(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;

	CXTPControlComboBox* pControl = (CXTPControlComboBox*)tagNMCONTROL->pControl;
	if (pControl->GetType() == xtpControlComboBox)
	{

	#if (_MSC_VER < 1300)
		CHARFORMAT cf;
	#else
		CHARFORMAT2 cf;
	#endif

		int nSize = CXTPControlSizeComboBox::GetTwipSize(pControl->GetEditText());
		if (nSize > 0)
		{
			cf.dwMask = CFM_SIZE;
			cf.yHeight = nSize;				

			SetCharFormat(cf);
		}

		*pResult = 1; // Handled;
	}
}

void CRibbonSampleView::OnGalleryFontBackColor(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;

	CXTPControlGallery* pControl = DYNAMIC_DOWNCAST(CXTPControlGallery, tagNMCONTROL->pControl);
	
	if (pControl)
	{
		CXTPControlGalleryItem* pItem = pControl->GetItem(pControl->GetSelectedItem());
		if (pItem)
		{
			m_clrBack = (COLORREF)pItem->GetID();
			OnButtonBack();
		}

		*pResult = TRUE; // Handled
	}
}

void CRibbonSampleView::OnUpdateGalleryFontBackColor(CCmdUI* pCmdUI)
{
	CXTPControlGallery* pControl = 	DYNAMIC_DOWNCAST(CXTPControlGallery, CXTPControl::FromUI(pCmdUI));

	if (pControl)
	{
		pControl->SetCheckedItem(m_clrBack);
	}

	pCmdUI->Enable(TRUE);
}

void CRibbonSampleView::OnButtonBack()
{
	CHARFORMAT2 cfm;
	cfm.cbSize =  sizeof(CHARFORMAT2);
	::SendMessage(GetRichEditCtrl().GetSafeHwnd(), EM_GETCHARFORMAT, 1, (LPARAM)&cfm);

	cfm.dwMask |= CFM_BACKCOLOR;
	cfm.dwEffects &= ~CFE_AUTOBACKCOLOR ;
	cfm.crBackColor = m_clrBack;
	::SendMessage(GetRichEditCtrl().GetSafeHwnd(), EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&cfm);
}

void CRibbonSampleView::OnUpdateBack(CCmdUI* pCmdUI)
{

	CXTPControlPopupColor* pPopup = DYNAMIC_DOWNCAST(CXTPControlPopupColor, CXTPControl::FromUI(pCmdUI));
	if (pPopup)
	{
		pPopup->SetColor(m_clrBack == COLORREF_NULL ? 0xFFFFFF : m_clrBack);
	}

	pCmdUI->Enable(TRUE);
}

CString FormatIndent(int nIndent)
{
	CString strIndent;

	if (nIndent % 1000 == 0)
		strIndent.Format(_T("%0.0f\""), (double)nIndent / 1000);
	else if (nIndent % 100 == 0)
		strIndent.Format(_T("%0.1f\""), (double)nIndent / 1000);
	else
		strIndent.Format(_T("%0.2f\""), (double)nIndent / 1000);

	return strIndent;
}

void CRibbonSampleView::SetIndentLeft(long nIndentLeft)
{
	if (nIndentLeft < -11000)
		nIndentLeft = -11000;
	if (nIndentLeft > 22000)
		nIndentLeft = 22000;

	PARAFORMAT pf;
	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask =  PFM_STARTINDENT;
	pf.dxStartIndent = nIndentLeft;
	
	::SendMessage(m_hWnd, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
}
long CRibbonSampleView::GetIndentLeft()
{
	PARAFORMAT pf;
	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask =  PFM_STARTINDENT;

	::SendMessage(m_hWnd, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
	return pf.dxStartIndent;
}

void CRibbonSampleView::OnUpdateIndentLeft(CCmdUI* pCmdUI)
{
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, CXTPControl::FromUI(pCmdUI));
	if (pControl && !pControl->HasFocus())
	{
		pControl->SetEditText(FormatIndent(GetIndentLeft()));
	}
	pCmdUI->Enable(TRUE);
}

double _ttof(LPCTSTR lpszStr)
{
	USES_CONVERSION;
	return atof(T2A((LPTSTR)lpszStr));
}

void CRibbonSampleView::OnIndentLeft(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetIndentLeft(int(_ttof(pControl->GetEditText()) * 1000));
		*pResult = TRUE;
	}
}

void CRibbonSampleView::OnIndentLeftSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPUPDOWN* tagNMCONTROL = (NMXTPUPDOWN*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetIndentLeft(int(_ttof(pControl->GetEditText()) * 1000) + tagNMCONTROL->iDelta * 100);

		pControl->SetEditText(FormatIndent(GetIndentLeft()));
	}
	*pResult = 1;
}


void CRibbonSampleView::SetIndentRight(long nIndentRight)
{
	if (nIndentRight < -11000)
		nIndentRight = -11000;
	if (nIndentRight > 22000)
		nIndentRight = 22000;

	PARAFORMAT pf;
	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask =  PFM_RIGHTINDENT;
	pf.dxRightIndent = nIndentRight;
	
	::SendMessage(m_hWnd, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
}

long CRibbonSampleView::GetIndentRight()
{
	PARAFORMAT pf;
	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask =  PFM_RIGHTINDENT;

	::SendMessage(m_hWnd, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
	return pf.dxRightIndent;
}


void CRibbonSampleView::OnUpdateIndentRight(CCmdUI* pCmdUI)
{
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, CXTPControl::FromUI(pCmdUI));
	if (pControl && !pControl->HasFocus())
	{
		pControl->SetEditText(FormatIndent(GetIndentRight()));
	}
	pCmdUI->Enable(TRUE);
}

void CRibbonSampleView::OnIndentRight(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetIndentRight(int(_ttof(pControl->GetEditText()) * 1000));
		*pResult = TRUE;
	}
}

void CRibbonSampleView::OnIndentRightSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPUPDOWN* tagNMCONTROL = (NMXTPUPDOWN*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetIndentRight(int(_ttof(pControl->GetEditText()) * 1000) + tagNMCONTROL->iDelta * 100);

		pControl->SetEditText(FormatIndent(GetIndentRight()));
	}
	*pResult = 1;
}

#define SPACE_SIZE 20
//////////////////////////////////////////////////////////////////////////
CString FormatSpacing(int nIndent)
{
	CString strSpacing;
	strSpacing.Format(_T("%i pt"), (int)(nIndent / SPACE_SIZE));
	return strSpacing;
}

void CRibbonSampleView::SetSpaceBefore(long nSpaceBefore)
{
	if (nSpaceBefore < 0)
		nSpaceBefore = 0;

	PARAFORMAT2 pf;
	pf.cbSize = sizeof(PARAFORMAT2);
	pf.dwMask =  PFM_SPACEBEFORE;
	pf.dySpaceBefore = nSpaceBefore;
	
	::SendMessage(m_hWnd, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
}

long CRibbonSampleView::GetSpaceBefore()
{
	PARAFORMAT2 pf;
	pf.cbSize = sizeof(PARAFORMAT2);
	pf.dwMask =  PFM_SPACEBEFORE;

	::SendMessage(m_hWnd, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
	return pf.dySpaceBefore;
}


void CRibbonSampleView::OnUpdateSpaceBefore(CCmdUI* pCmdUI)
{
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, CXTPControl::FromUI(pCmdUI));
	if (pControl && !pControl->HasFocus())
	{
		pControl->SetEditText(FormatSpacing(GetSpaceBefore()));
	}
	pCmdUI->Enable(TRUE);
}

void CRibbonSampleView::OnSpaceBefore(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetSpaceBefore(_ttoi(pControl->GetEditText()) * SPACE_SIZE);
		*pResult = TRUE;
	}
}

void CRibbonSampleView::OnSpaceBeforeSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPUPDOWN* tagNMCONTROL = (NMXTPUPDOWN*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetSpaceBefore(int(_ttoi(pControl->GetEditText()) * SPACE_SIZE) + tagNMCONTROL->iDelta * 6 * SPACE_SIZE);

		pControl->SetEditText(FormatSpacing(GetSpaceBefore()));
	}
	*pResult = 1;
}

//////////////////////////////////////////////////////////////////////////


void CRibbonSampleView::SetSpaceAfter(long nSpaceAfter)
{
	if (nSpaceAfter < 0)
		nSpaceAfter = 0;

	PARAFORMAT2 pf;
	pf.cbSize = sizeof(PARAFORMAT2);
	pf.dwMask =  PFM_SPACEAFTER;
	pf.dySpaceAfter = nSpaceAfter;
	
	::SendMessage(m_hWnd, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
}

long CRibbonSampleView::GetSpaceAfter()
{
	PARAFORMAT2 pf;
	pf.cbSize = sizeof(PARAFORMAT2);
	pf.dwMask =  PFM_SPACEAFTER;

	::SendMessage(m_hWnd, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
	return pf.dySpaceAfter;

}


void CRibbonSampleView::OnUpdateSpaceAfter(CCmdUI* pCmdUI)
{
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, CXTPControl::FromUI(pCmdUI));
	if (pControl && !pControl->HasFocus())
	{
		pControl->SetEditText(FormatSpacing(GetSpaceAfter()));
	}
	pCmdUI->Enable(TRUE);
}

void CRibbonSampleView::OnSpaceAfter(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPCONTROL* tagNMCONTROL = (NMXTPCONTROL*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetSpaceAfter(int(_ttoi(pControl->GetEditText()) * SPACE_SIZE));
		*pResult = TRUE;
	}
}

void CRibbonSampleView::OnSpaceAfterSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMXTPUPDOWN* tagNMCONTROL = (NMXTPUPDOWN*)pNMHDR;
	CXTPControlEdit* pControl = DYNAMIC_DOWNCAST(CXTPControlEdit, tagNMCONTROL->pControl);

	if (pControl)
	{
		SetSpaceAfter(int(_ttoi(pControl->GetEditText()) * SPACE_SIZE) + tagNMCONTROL->iDelta * 6 * SPACE_SIZE);

		pControl->SetEditText(FormatSpacing(GetSpaceAfter()));
	}
	*pResult = 1;
}


void CRibbonSampleView::OnUpdateEditUndo(CCmdUI* pCmd)
{
	CXTPControlGallery* pControlUndo = DYNAMIC_DOWNCAST(CXTPControlGallery, CXTPControl::FromUI(pCmd));

	if (pControlUndo)
	{
		pCmd->Enable(GetRichEditCtrl().CanUndo());

		CXTPControlGalleryItems* pItems = pControlUndo->GetItems();
		pItems->RemoveAll();

		int nCount = RAND_S() % 20 + 3;

		for (int i = 0; i < nCount; i++)
		{
			CString str;
			str.Format(_T("Undo String %i"), i + 1);
			pItems->AddItem(new CGalleryItemUndo(str), i);
		}

		pControlUndo->OnSelectedItemChanged();
		pControlUndo->SetHeight(pItems->GetItemSize().cy * nCount + 2);

	}
	else
	{
		CRichEditView::OnUpdateEditUndo(pCmd);
	}

}

void CRibbonSampleView::OnEditUndo(NMHDR* pNMHDR, LRESULT* pResult)
{
	CXTPControlGallery* pControlUndo = DYNAMIC_DOWNCAST(CXTPControlGallery, ((NMXTPCONTROL*)pNMHDR)->pControl);
	if (pControlUndo)
	{
		CString str;
		str.Format(_T("Undo last %i actions"), pControlUndo->GetSelectedItem() + 1);

		AfxMessageBox(str);
	}
	else
	{
		CRichEditView::OnEditUndo();
	}

	*pResult = 1; // Handled;
}
