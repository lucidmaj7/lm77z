
// TESTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TEST.h"
#include "TESTDlg.h"
#include "afxdialogex.h"
#include "lm77z.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTESTDlg dialog



CTESTDlg::CTESTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTESTDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTESTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CTESTDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CTESTDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTESTDlg message handlers

BOOL CTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTESTDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString strAchivePath = _T("d:\\aa.7z");
	CString strPath = _T("d:\\test");


	//	swprintf_s(aPath[0], MAX_PATH, L"%s", strPath);

	if (LM77Z_eXtract(strAchivePath.GetBuffer(0), strPath.GetBuffer(0)) == 0)
	{
		AfxMessageBox(_T("Success!!!"));
	}
	else
	{
		AfxMessageBox(_T("Fail!!!"));
	}
}


void CTESTDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString strAchivePath = _T("d:\\aa11.7z");
	CString strPath = _T("C:\\Users\\lucidmaj7\\Downloads\\openssl-1.0.2m.tar\\openssl-1.0.2m");
	CString strPat2h = _T("D:\\test");
	WCHAR path[MAX_PATH] = { 0, };
	WCHAR path2[MAX_PATH] = { 0, };
	PWCHAR* aPath = new PWCHAR[2];
	aPath[0] = path;
	aPath[1] = path2;
	swprintf_s(aPath[0], MAX_PATH, L"%s", strPath);
	swprintf_s(aPath[1], MAX_PATH, L"%s", strPat2h);
	if (LM77Z_Archive(strAchivePath.GetBuffer(0), aPath, MAX_PATH, 2) == 0)
	{
		AfxMessageBox(_T("Success!!!"));
	}
	else
	{
		AfxMessageBox(_T("Fail!!!"));
	}
	if (aPath)
	{
		delete[] aPath;
	}
}
