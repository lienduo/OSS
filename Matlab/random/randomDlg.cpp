// randomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "random.h"
#include "randomDlg.h"
#include "math.h"
#define PI 3.14159265

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
// CRandomDlg dialog

CRandomDlg::CRandomDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRandomDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRandomDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRandomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRandomDlg)
	DDX_Control(pDX, IDC_GRAPH, m_Scope);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRandomDlg, CDialog)
	//{{AFX_MSG_MAP(CRandomDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AVERAGE, OnAverage)
	ON_BN_CLICKED(IDC_ZHENGTAI, OnZhengtai)
	ON_BN_CLICKED(IDC_NORMAL_STAT, OnNormalStat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRandomDlg message handlers

BOOL CRandomDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRandomDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRandomDlg::OnPaint() 
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
HCURSOR CRandomDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



/*函数功能，产生一个在min~max范围内精度为4位小数的平均分布的随机数
*/
double AverageRandom(double min,double max)
{
	
	int minInteger = (int)(min*10000);
	int maxInteger = (int)(max*10000);
	int randInteger = rand()*rand();
	int diffInteger = maxInteger - minInteger;
	int resultInteger = randInteger % diffInteger + minInteger;
	return resultInteger/10000.0;
}
/* 函数功能 ，一维正态分布概率密度函数
x,随机变量
miu,最大概率密度处的随机变量
sigma
*/
double Normal(double x,double miu,double sigma)   
{
	return  1.0/sqrt(2*PI*sigma) * exp(-1*(x-miu)*(x-miu)/(2*sigma*sigma));
}
/*函数功能，在min 到max 范围内产生正态分布的随机数

miu,最大概率密度处的随机变量，即产生的随机数中,概率最大的那个
sigma
*/
double NormalRandom(double miu,double sigma,double min,double max)
{
	double dResult;
	double dScope;
	double dNormal;
	do
	{
		dResult = AverageRandom(min,max);
		dScope = AverageRandom(0,Normal(miu, miu, sigma));
		dNormal = Normal(dResult, miu, sigma);
	}while( dScope > dNormal);
	return dResult;
	
}
void CRandomDlg::OnAverage() 
{
	srand(GetTickCount());
	m_Scope.Clear();
	m_Scope.SetDimT(100);
	m_Scope.SetDimy(1);
	for(int i= 0;i < 400; i++)
	{
		
		double dValue = AverageRandom(-1,1);
		m_Scope.AddValue(i,dValue);
	}
	m_Scope.UpdateCurve();
}
void CRandomDlg::OnZhengtai() 
{
	
	srand(GetTickCount());
	m_Scope.Clear();
	m_Scope.SetDimy(1);
	m_Scope.SetDimT(100);
	
	for(int i= 0;i < 400; i++)
	{
		
		double dValue = NormalRandom(0,0.05,-1,1);
		m_Scope.AddValue(i,dValue);
	}
	m_Scope.UpdateCurve();
}

void CRandomDlg::OnNormalStat() 
{
	srand(GetTickCount());
	m_Scope.Clear();
	
	int Count[4000];
	m_Scope.SetDimy(10);
	m_Scope.SetDimT(1);
	memset(Count,0,4000*sizeof(int));
	int i;
	for( i= 0;i < 4000; i++)
	{
		
		double dValue = NormalRandom(2,0.2,0,4);
		int a = (int)(dValue*1000);
		Count[a]++;
	}
	for( i= 0;i < 4000; i++)
	{
		m_Scope.AddValue(i/1000.0,Count[i]);
	}
	m_Scope.UpdateCurve();
}
