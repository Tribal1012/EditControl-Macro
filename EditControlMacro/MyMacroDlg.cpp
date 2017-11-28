
// MyMacroDlg.cpp : ���� ����
//

#include "stdafx.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include "EditControlMacro.h"
#include "MyMacroDlg.h"
#include "afxdialogex.h"
#include "randomstr.h"
#include <iomanip>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyMacroDlg ��ȭ ����



CMyMacroDlg::CMyMacroDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EDITCONTROLMACRO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMacroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mHEdit);
	DDX_Control(pDX, IDC_EDIT2, mHBtn);
	DDX_Control(pDX, IDC_EDIT1, mHEdit);
	DDX_Control(pDX, IDC_EDIT2, mHBtn);
}

BEGIN_MESSAGE_MAP(CMyMacroDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMyMacroDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMyMacroDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CMyMacroDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMyMacroDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CMyMacroDlg �޽��� ó����

BOOL CMyMacroDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMyMacroDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMyMacroDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMyMacroDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyMacroDlg::OnBnClickedOk()
{
	CString str;
	HWND Hwnd = 0;
	HWND Hcon = 0;
	char buf[65536] = { 0, };

	// Get Windows Handle from Window_Edit EditControl
	mHEdit.GetWindowTextW(str);
	Hwnd = (HWND)wcstol(str, NULL, 16);
	// Get Context Handle from Context_Edit EditControl
	mHBtn.GetWindowTextW(str);
	Hcon = (HWND)wcstol(str, NULL, 16);
	
	if (Hwnd == 0 || Hcon == 0) return;

	// use boost::log for Logging
	boost::log::add_file_log
	(
		boost::log::keywords::file_name = "OppaGo_TV_%N.log",
		boost::log::keywords::rotation_size = 10 * 1024 * 1024,
		boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
		boost::log::keywords::format = "[%TimeStamp%]: %Message%"
		//(			
		//	boost::log::expressions::stream
		//	<< std::hex << std::setw(8) << std::setfill('0')
		//	<< boost::log::expressions::attr< unsigned int >("LineID")
		//	<< "\t"
		//	<< boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp","%Y-%m-%d %H:%M:%S.%f")
		//	<< "\t:\t[" << boost::log::expressions::smessage
		//	<< "]"
		//)
	);
	boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);

	GenRandomString((uint8*)buf, 65535);
	SendMessageA(Hwnd, WM_SETTEXT, 65535, (WPARAM)buf);
	SendMessageA(Hcon, BM_CLICK, 0, 0);
	//SendMessageA(Hcon, WM_LBUTTONDOWN, 0, 1);
	//SendMessageA(Hcon, WM_LBUTTONUP, 0, 1);
	//SendMessageA((HWND)0x804ba, WM_COMMAND, NULL, MAKELONG(Hcon, BN_CLICKED));

	// Logging
	BOOST_LOG_TRIVIAL(info) << buf;
}


void CMyMacroDlg::OnBnClickedCancel()
{
	MessageBox(TEXT("Bye~"));
	CDialogEx::OnCancel();
}


void CMyMacroDlg::OnEnChangeEdit1()
{
}


void CMyMacroDlg::OnEnChangeEdit2()
{
}
