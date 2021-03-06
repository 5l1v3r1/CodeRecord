
// MFC_05_TabCtrlDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_05_TabCtrl.h"
#include "MFC_05_TabCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC05TabCtrlDlg 对话框



CMFC05TabCtrlDlg::CMFC05TabCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_05_TABCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC05TabCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_DEMO, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CMFC05TabCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_DEMO, &CMFC05TabCtrlDlg::OnTcnSelchangeTabDemo)
END_MESSAGE_MAP()


// CMFC05TabCtrlDlg 消息处理程序

BOOL CMFC05TabCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	m_tabCtrl.InsertItem(0, _T("文件"));
	m_tabCtrl.InsertItem(1, _T("网络"));
	m_tabCtrl.InsertItem(2, _T("进程"));

	m_tabCtrl.SetPadding(19);
	m_tabCtrl.SetMinTabWidth(50);
	m_tabCtrl.SetItemSize(CSize(50, 25));


	m_FilePage.Create(IDD_PAGE_FILE, &m_tabCtrl);
	m_NetPage.Create(IDD_PAGE_NETWORK, &m_tabCtrl);
	m_ProcPage.Create(IDD_PAGE_PROCESS, &m_tabCtrl);


	//设定在Tab内显示的范围
	CRect rc;
	m_tabCtrl.GetClientRect(rc);
	rc.top += 25;
	// 	rc.bottom -= 8;
	// 	rc.left += 8;
	// 	rc.right -= 8;

	m_FilePage.MoveWindow(&rc);
	m_NetPage.MoveWindow(&rc);
	m_ProcPage.MoveWindow(&rc);


	//把对话框对象指针保存起来
	m_pDialog[0] = &m_FilePage;
	m_pDialog[1] = &m_NetPage;
	m_pDialog[2] = &m_ProcPage;
	//显示初始页面
	m_pDialog[0]->ShowWindow(SW_SHOW);
	m_pDialog[1]->ShowWindow(SW_HIDE);
	m_pDialog[2]->ShowWindow(SW_HIDE);

	//保存当前选择
	m_CurSelTab = 0;



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC05TabCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC05TabCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC05TabCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFC05TabCtrlDlg::OnTcnSelchangeTabDemo(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	m_pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);  // 把当前的界面隐藏
	m_CurSelTab = m_tabCtrl.GetCurSel();          // 获取选中的界面选项索引值
	if (m_pDialog[m_CurSelTab])
	{
		m_pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);  // 只显示选中的界面选项
	}
	*pResult = 0;
}

