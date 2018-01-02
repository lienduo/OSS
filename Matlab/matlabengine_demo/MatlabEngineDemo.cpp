// MatlabEngineDemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include "MatlabEngine.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

/////////////////////////////////////////////////////////////////////////////////////////////
// Matlab engine object, initialized in InitInstance
/////////////////////////////////////////////////////////////////////////////////////////////
CMatlabEngine* glob_pMatlab=NULL;
/////////////////////////////////////////////////////////////////////////////////////////////

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MATLABENGINEDEMO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_MATLABENGINEDEMO);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	if (glob_pMatlab)
	{
		glob_pMatlab->Quit();

		delete glob_pMatlab;
		glob_pMatlab = NULL;
	}
	CoUninitialize();

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_MATLABENGINEDEMO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_MATLABENGINEDEMO;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	CoInitialize(NULL);

	glob_pMatlab = new CMatlabEngine;

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	std::vector<double> vReal, vImg;
	UINT i,n=4, nRows, nCols;
	LPSTR szText=NULL;

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
					DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
					break;
				case IDM_EXIT:
					DestroyWindow(hWnd);
					break;
				case ID_MATLAB_EXECUTE:
					glob_pMatlab->Execute(_T("surf(peaks)"));
					glob_pMatlab->Execute(_T("title('Demo of Execute')"));
					break;
				case ID_MATLAB_PUTMATRIX:
					vReal.resize(n*2);
					for (i=0;i<n;i++)
					{
						vReal[i*2] = i/(double)n*3.14*2;
						vReal[i*2+1] = sin(vReal[i*2]); 
					}
					glob_pMatlab->PutMatrix(_T("v"), vReal, n, 2);
					glob_pMatlab->Execute(_T("figure(1); plot(v(:,1), v(:,2))"));
					glob_pMatlab->Execute(_T("title('Demo of PutMatrix')"));
					break;
				case ID_MATLAB_PUTMATRIXCOMPLEX:
					vReal.resize(n);
					vImg.resize(n);
					for (i=0;i<n;i++)
					{
						vReal[i] = i/(double)n*3.14*2;
						vImg[i] = sin(vReal[i]); 
					}
					glob_pMatlab->PutMatrix(_T("v"), vReal, vImg, n, 1);
					glob_pMatlab->Execute(_T("figure(2); plot(real(v),imag(v))"));
					glob_pMatlab->Execute(_T("title('Demo of PutMatrix with complex array')"));
					break;
				case ID_MATLAB_GETMATRIX:
					glob_pMatlab->Execute(_T("x=[0 1 2 3 4 5]; v=[1 2 3 4 5 6]';"));
					glob_pMatlab->GetLastErrorMessage();

					glob_pMatlab->GetMatrix(_T("v"), nRows, nCols, vReal);	
					glob_pMatlab->GetLastErrorMessage();

					glob_pMatlab->PutMatrix(_T("v2"), vReal, nRows, nCols);
					glob_pMatlab->GetLastErrorMessage();

					glob_pMatlab->Execute(_T("figure(3); hold on; plot(x,v); plot(x,v2,'r');"));					
					glob_pMatlab->GetLastErrorMessage();

					glob_pMatlab->Execute(_T("title('Demo of GetMatrix (you should see 1 line only)'); hold off;"));
					glob_pMatlab->GetLastErrorMessage();

				//	TestGet();
					break;
				case ID_MATLAB_PUTSTRING:
#ifdef MATLAB_VERSION_6
					glob_pMatlab->PutString(_T("text"),_T("If you read this, it worked."));
					glob_pMatlab->Execute(_T("msgbox(text,'PutString test')"));
					glob_pMatlab->GetLastErrorMessage();
#endif
					break;
				case ID_MATLAB_GETSTRING:
					TCHAR szBuffer[512];
#ifdef MATLAB_VERSION_6
					glob_pMatlab->Execute(_T("text='This a test of GetString function'"));
					glob_pMatlab->GetString(_T("text"),szText);
					glob_pMatlab->GetLastErrorMessage();
					_stprintf(szBuffer,_T("msgbox('Text sent: \"This a test of GetString function\", Text received: \"%s\"','Demo of GetString');"),szText);
					glob_pMatlab->Execute(szBuffer);
#endif
					break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }	
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
