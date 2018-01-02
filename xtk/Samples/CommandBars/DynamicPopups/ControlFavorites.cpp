// ControlFavorites.cpp: implementation of the CControlFavorites class.
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

#include "stdafx.h"
#include "resource.h"
#include "ControlFavorites.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_XTP_CONTROL(CControlFavorites, CXTPControlButton)


CControlFavorites::CControlFavorites(LPCTSTR strRootDir)
{
	m_strRootDir = strRootDir;
}

void CControlFavorites::Copy(CXTPControl* pControl, BOOL bRecursive)
{
	ASSERT(DYNAMIC_DOWNCAST(CControlFavorites, pControl));
	CXTPControlButton::Copy(pControl, bRecursive);
	m_strRootDir = ((CControlFavorites*)pControl)->m_strRootDir;
}

void CControlFavorites::DoPropExchange(CXTPPropExchange* pPX)
{
	CXTPControlButton::DoPropExchange(pPX);

	PX_String(pPX, _T("RootDir"), m_strRootDir);
}

void CControlFavorites::OnCalcDynamicSize(DWORD /*dwMode*/)
{
	if (GetParent()->GetType() !=xtpBarTypePopup)
		return;

	ASSERT(m_pControls->GetAt(m_nIndex) == this);
	while (m_nIndex + 1 < m_pControls->GetCount())
	{
		CXTPControl* pControl = m_pControls->GetAt(m_nIndex + 1);
		if (
			pControl->GetID() == ID_FAVORITE_LINK ||
			pControl->GetID() == ID_FAVORITE_FOLDER)
		{
			m_pControls->Remove(pControl);
		}
		else break;
	}

	if (m_pParent->IsCustomizeMode())
	{
		m_dwHideFlags = 0;
		return;
	}

	m_dwHideFlags |= xtpHideGeneric;

	//CString         strPath2;
	CString         str;
	WIN32_FIND_DATA wfd;
	HANDLE          h;
	int             nPos = 0;
	int             nEndPos = 0;

	#define INTERNET_MAX_PATH_LENGTH 2048

	TCHAR           buf[INTERNET_MAX_PATH_LENGTH];
	CStringArray    astrFavorites;
	CStringArray    astrFavoritesUrl;
	CStringArray    astrDirs;

	// make sure there's a trailing backslash
	if(m_strRootDir[m_strRootDir.GetLength() - 1] != _T('\\'))
		m_strRootDir += _T('\\');

	int nStartPos = m_nIndex + 1;

	// now scan the directory, first for .URL files and then for subdirectories
	// that may also contain .URL files
	h = FindFirstFile(m_strRootDir + _T("*.*"), &wfd);
	if(h != INVALID_HANDLE_VALUE)
	{
		nEndPos = nStartPos;
		do
		{
			if((wfd.dwFileAttributes & (FILE_ATTRIBUTE_DIRECTORY|FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM))==0)
			{
				str = wfd.cFileName;
				if(str.Right(4).CompareNoCase(_T(".url")) == 0)
				{
					// an .URL file is formatted just like an .INI file, so we can
					// use GetPrivateProfileString() to get the information we want
					::GetPrivateProfileString(_T("InternetShortcut"), _T("URL"),
						_T(""), buf, INTERNET_MAX_PATH_LENGTH,
						m_strRootDir + str);
					str = str.Left(str.GetLength() - 4);

					// scan through the array and perform an insertion sort
					// to make sure the menu ends up in alphabetic order
					for(nPos = nStartPos ; nPos < nEndPos ; ++nPos)
					{
						if(str.CompareNoCase(astrFavorites[nPos]) < 0)
							break;
					}
					astrFavorites.InsertAt(nPos, str);
					astrFavoritesUrl.InsertAt(nPos, buf);
					++nEndPos;
				}
			}
		} while(FindNextFile(h, &wfd));
		FindClose(h);

		// Now add these items to the menu
		for(nPos = nStartPos ; nPos < nEndPos ; ++nPos)
		{
			CXTPControlButton* pControl = (CXTPControlButton*)m_pControls->Add(xtpControlButton, ID_FAVORITE_LINK, astrFavoritesUrl[nPos], nPos, TRUE);
			pControl->SetCaption(astrFavorites[nPos]);
			pControl->SetTooltip(astrFavorites[nPos]);
			pControl->SetFlags(xtpFlagManualUpdate);
			pControl->SetStyle(xtpButtonIconAndCaption);
		}


		// now that we've got all the .URL files, check the subdirectories for more
		int nLastDir = 0;
		h = FindFirstFile(m_strRootDir + _T("*.*"), &wfd);
		ASSERT(h != INVALID_HANDLE_VALUE);
		do
		{
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				// ignore the current and parent directory entries
				if(lstrcmp(wfd.cFileName, _T(".")) == 0 || lstrcmp(wfd.cFileName, _T("..")) == 0)
					continue;

				for(nPos = 0 ; nPos < nLastDir ; ++nPos)
				{
					if(astrDirs[nPos].CompareNoCase(wfd.cFileName) > 0)
						break;
				}

				CXTPControlPopup* pControl = (CXTPControlPopup*)m_pControls->Add(xtpControlButtonPopup, ID_FAVORITE_FOLDER, _T(""), nStartPos + nPos, TRUE);
				CXTPControls* pChildControls = pControl->GetCommandBar()->GetControls();

				pChildControls->Add(new CControlFavorites(m_strRootDir + wfd.cFileName), 0);
				pControl->SetCaption(wfd.cFileName);
				pControl->SetFlags(xtpFlagManualUpdate);

				astrDirs.InsertAt(nPos, wfd.cFileName);


				++nLastDir;

			}
		} while(FindNextFile(h, &wfd));
		FindClose(h);
	}

}

BOOL CControlFavorites::IsCustomizeDragOverAvail(CXTPCommandBar* pCommandBar, CPoint /*point*/, DROPEFFECT& dropEffect)
{
	if (pCommandBar->GetType() != xtpBarTypePopup)
	{
		dropEffect = DROPEFFECT_NONE;
		return FALSE;
	}
	return TRUE;
}



//////////////////////////////////////////////////////////////////////////
// CControlShell

CControlShellFile::CControlShellFile(XT_TVITEMDATA* lptvid)
{
	m_lptvid = lptvid;
}

void CControlShellFile::OnExecute()
{
	CXTPControl::OnExecute();

	SHELLEXECUTEINFO sei;
	::ZeroMemory(&sei, sizeof(SHELLEXECUTEINFO));
	
	sei.cbSize = sizeof(SHELLEXECUTEINFO);
	sei.fMask = SEE_MASK_INVOKEIDLIST;
	sei.hwnd = AfxGetMainWnd()->m_hWnd;
	sei.nShow = SW_SHOWNORMAL;
	sei.hInstApp = AfxGetInstanceHandle();
	sei.lpIDList = GetFullyQualPidl(m_lptvid->lpsfParent, m_lptvid->lpi);
	
	::ShellExecuteEx(&sei);
}

CControlShell::CControlShell()
{
	m_lptvid = NULL;
}

CControlShell::CControlShell(XT_TVITEMDATA* lptvid)
{	
	m_lptvid = lptvid;

}


IMPLEMENT_XTP_CONTROL(CControlShell, CXTPControlButton)

BOOL CControlShell::IsCustomizeDragOverAvail(CXTPCommandBar* pCommandBar, CPoint /*point*/, DROPEFFECT& dropEffect)
{
	if (pCommandBar->GetType() != xtpBarTypePopup)
	{
		dropEffect = DROPEFFECT_NONE;
		return FALSE;
	}
	return TRUE;
}

void CControlShell::InitTreeViewItems(LPSHELLFOLDER lpsf, LPCITEMIDLIST lpifq, CArray<XT_TVITEMDATA*, XT_TVITEMDATA*>& items)
{
	// Allocate a shell memory object.
	CShellMalloc lpMalloc;
	if (!lpMalloc)
		return;
	
	// Get the IEnumIDList object for the given folder.
	LPENUMIDLIST lpe = NULL;
	if (SUCCEEDED(lpsf->EnumObjects(AfxGetMainWnd()->GetSafeHwnd(), SHCONTF_FOLDERS | SHCONTF_NONFOLDERS, &lpe)))
	{
		ULONG        ulFetched = 0;
		LPITEMIDLIST lpi = NULL;
		
		// Enumerate through the list of folder and non-folder objects.
		while (lpe->Next(1, &lpi, &ulFetched) == S_OK)
		{
			
			// Allocate memory for ITEMDATA struct
			XT_TVITEMDATA* lptvid = (XT_TVITEMDATA*)lpMalloc.Alloc(sizeof(XT_TVITEMDATA));
			if (lptvid == NULL)
			{
				if (lpe) {
					lpe->Release();
				}
				if (lpi) {
					lpMalloc.Free(lpi);
				}
			
				return;
			}				
			
			// Now, make a copy of the ITEMIDLIST and store the parent folders SF.
			lptvid->lpi = DuplicateItem(lpMalloc, lpi);
			lptvid->lpsfParent = lpsf;
			lptvid->lpifq = ConcatPidls(lpifq, lpi);
			lpsf->AddRef();			
			
			
			items.Add(lptvid);
			
			
			// Free the pidl that the shell gave us.
			if (lpi) {
				lpMalloc.Free(lpi);
				lpi = 0;
			}				
		}
		if (lpi) {
			lpMalloc.Free(lpi);
		}
		if (lpe) {
			lpe->Release();
		}
	}
}

int AFX_CDECL TreeViewCompareProc2(const void *lparam1, const void *lparam2)
{
	XT_TVITEMDATA* lptvid1 = *(XT_TVITEMDATA**)lparam1;
	XT_TVITEMDATA* lptvid2 = *(XT_TVITEMDATA**)lparam2;

	HRESULT hr = lptvid1->lpsfParent->CompareIDs(0, lptvid1->lpi, lptvid2->lpi);
	if (FAILED(hr)) {
		return 0;
	}

	return (short)SCODE_CODE(GetScode(hr));
}

void CControlShell::OnCalcDynamicSize(DWORD /*dwMode*/)
{
	if (GetParent()->GetType() != xtpBarTypePopup)
		return;

	ASSERT(m_pControls->GetAt(m_nIndex) == this);
	while (m_nIndex + 1 < m_pControls->GetCount())
	{
		CXTPControl* pControl = m_pControls->GetAt(m_nIndex + 1);
		if (pControl->GetID() == ID_CONTROL_SHELL)
		{
			m_pControls->Remove(pControl);
		}
		else break;
	}

	if (m_pParent->IsCustomizeMode())
	{
		m_dwHideFlags = 0;
		return;
	}

	m_dwHideFlags |= xtpHideGeneric;


	LPSHELLFOLDER lpsfDesktop = NULL;
		
	LPSHELLFOLDER lpsf = NULL;
	LPCITEMIDLIST lpifq = NULL;

	if (m_lptvid != NULL && m_lptvid->lpsfParent != NULL )
	{
		LPSHELLFOLDER _lpsf = NULL;
		if (SUCCEEDED(m_lptvid->lpsfParent->BindToObject(m_lptvid->lpi,
			0, IID_IShellFolder, (LPVOID *)&_lpsf))) 
		{
			lpifq = m_lptvid->lpifq;
			lpsf = _lpsf;			
		}
	}
	else
	{
		::SHGetDesktopFolder( &lpsfDesktop); 
		lpsf = lpsfDesktop;
	}

	if (lpsf == NULL)
		return;

	CArray<XT_TVITEMDATA*, XT_TVITEMDATA*> items;
	InitTreeViewItems(lpsf, lpifq, items);
	qsort(items.GetData(), items.GetSize(), sizeof(XT_TVITEMDATA*), TreeViewCompareProc2);

	for (int nIndex = 0; nIndex < items.GetSize(); nIndex++)
	{
		XT_TVITEMDATA* lptvid = items[nIndex];
	
		CXTPControl* pControl = NULL;
		
		// Create a fully qualified path to the current item
		// the SH* shell api's take a fully qualified path pidl,
		// (see GetIcon above where I call SHGetFileInfo) whereas the
		// interface methods take a relative path pidl.
		ULONG ulAttrs = SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_DISPLAYATTRMASK | SFGAO_REMOVABLE;
		
		// Determine what type of object we have.
		lpsf->GetAttributesOf(1, (const struct _ITEMIDLIST **)&lptvid->lpi, &ulAttrs);
		
		if ((ulAttrs & SFGAO_FOLDER))
		{	
			pControl = (CXTPControlPopup*)m_pControls->Add(xtpControlButtonPopup, ID_CONTROL_SHELL, _T(""), m_nIndex + nIndex + 1, TRUE);
			CXTPControls* pChildControls = pControl->GetCommandBar()->GetControls();
			
			pChildControls->Add(new CControlShell(lptvid), ID_CONTROL_SHELL, _T(""), 0, TRUE);
			
		}
		else
		{
			pControl = m_pControls->Add(new CControlShellFile(lptvid), ID_CONTROL_SHELL, _T(""), m_nIndex + nIndex + 1, TRUE);
		}
		
		CString strBuff;
		GetName(lpsf, lptvid->lpi, SHGDN_NORMAL, strBuff);

		pControl->SetCaption(strBuff);
		pControl->SetStyle(xtpButtonIconAndCaption);
		pControl->SetFlags(xtpFlagManualUpdate);
		
		pControl->SetIconId(GetItemIcon(lptvid->lpifq, 
			SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON) + ID_SHELLIMAGELIST_BASE);
	}

	if (lpsfDesktop)
	{
		lpsfDesktop->Release( );		
	}	
	
}

