// convDlg.cpp : implementation file
//

#include "stdafx.h"
#include "conv.h"
#include "convDlg.h"

#include "matlab.h"

#include "MyFunc.h"

#include "vcdatagrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvDlg dialog

CConvDlg::CConvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConvDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConvDlg)
	DDX_Control(pDX, IDC_MSCHART1, m_Chart);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CConvDlg, CDialog)
	//{{AFX_MSG_MAP(CConvDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnConv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvDlg message handlers

BOOL CConvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	double x1[]={1,2,3,4,5,6,7,8,9,0};
	double x2[]={4,5,6,7,4,5,8,9,0,7};
	m_Chart.SetColumnCount(3);
	m_Chart.SetRowCount(10);

	m_Chart.SetColumn(1);
	m_Chart.SetColumnLabel("X1");

	m_Chart.SetColumn(2);
	m_Chart.SetColumnLabel("X2");

	m_Chart.SetColumn(3);
	m_Chart.SetColumnLabel("CONV(X1,X)");

	int dec=0;
	int sign=0;
	
	CString value;

	
	for(int n=0;n<10;n++)
	{
		
		m_Chart.SetColumn(1);
		m_Chart.SetRow(n+1);
		value=do2CStr(x1[n]);
		m_Chart.SetData(value);
		value=do2CStr(n);
		m_Chart.SetRowLabel(value);
		
		m_Chart.SetColumn(2);
		m_Chart.SetRow(n+1);
		value=do2CStr(x2[n]);
		m_Chart.SetData(value);
		value=do2CStr(n);
		m_Chart.SetRowLabel(value);
		
		
	}

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CConvDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CConvDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CConvDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CConvDlg::OnConv() 
{
	// TODO: Add your control notification handler code here
	//x1 and x2 are the input array to do the computation
	//res will have the result, we already know that the length 
	//of the convolution of 2 vectors is (length(x1)+length(x2)-1)=19
	double x1[]={1,2,3,4,5,6,7,8,9,0};
	double x2[]={4,5,6,7,4,5,8,9,0,7};
	double res[19];
	//create the arrays that will be passed to MyFunc
	mxArray* In1;
	mxArray* In2;
	mxArray* Out;
	//we make them Real and have 10 values
	In1=mxCreateDoubleMatrix(1,10,mxREAL);
	In2=mxCreateDoubleMatrix(1,10,mxREAL);
	
	//this make In1=x1;In2=x2
	memcpy(mxGetPr(In1),x1,10*sizeof(double));
	memcpy(mxGetPr(In2),x2,10*sizeof(double));
	//Call to MyFunc.m that return the convolution of In1 and In2
	Out=mlfMyFunc(In1,In2);
	//now we have the result(Out) in a double array 'res'
	memcpy(res,mxGetPr(Out),19*sizeof(double));



	//Destroy matrices
	mxDestroyArray(Out);
	mxDestroyArray(In1);
	mxDestroyArray(In2);

	
	
	//here I configure the MSChart to display the data
	//if you don´t want to display data don´t copy this part
	m_Chart.SetColumnCount(3);
	m_Chart.SetRowCount(19);

	int dec=0;
	int sign=0;
	
	CString value;

	
	for(int n=0;n<19;n++)
	{
		if(n<11)
		{
			m_Chart.SetColumn(1);
			m_Chart.SetRow(n+1);
			value=do2CStr(x1[n]);
			m_Chart.SetData(value);

			m_Chart.SetColumn(2);
			m_Chart.SetRow(n+1);
			value=do2CStr(x2[n]);
			m_Chart.SetData(value);

		}
		m_Chart.SetColumn(3);
		m_Chart.SetRow(n+1);
		value=do2CStr(res[n]);


		m_Chart.SetData(value);
		value=do2CStr(n);
		m_Chart.SetRowLabel(value);
	}




	
}

CString CConvDlg::do2CStr(double variable)
{
	
	int  decimal, sign;
	char *buffer;
	buffer = _fcvt( variable, 5 ,&decimal, &sign );
	int len=strlen(buffer);
	CString numero(buffer);	
	CString valor;
	if(sign)//negative value
		valor="-"+numero.Left(decimal)+"."+numero.Right(len-decimal);
	else
		valor=numero.Left(decimal)+"."+numero.Right(len-decimal);
	return valor;

}
