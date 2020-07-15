
// MECProcedureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "MECProcedureDlg.h"
#include "afxdialogex.h"
#include "Log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//获取版本信息库
#pragma comment(lib,"version.lib")



// CMECProcedureDlg 对话框
CMECProcedureDlg::CMECProcedureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMECProcedureDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bInitOver = false;
}

void CMECProcedureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMECProcedureDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
END_MESSAGE_MAP()




// CMECProcedureDlg 消息处理程序

BOOL CMECProcedureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//显示标题
	ShowDialogTitle();

	//创建视频显示窗口
	m_pDlgRealPlay = new CDlgRealPlayPage(this);
	m_pDlgRealPlay->Create(IDD_DIALOG_REALPLAY_PAGE,this);

	InitView();
	m_pDlgRealPlay->ShowWindow(SW_SHOW);


	m_bInitOver = true;

	// TODO: 在此添加额外的初始化代码
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMECProcedureDlg::OnPaint()
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
HCURSOR CMECProcedureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//获取版本号信息
bool CMECProcedureDlg::ReadResourceInformation(CString &sVersionNum)
{
	DWORD dwLength,dwNullHandle;
	char szFileName[1024];

	dwLength = ::GetModuleFileName(AfxGetInstanceHandle(),szFileName,sizeof(szFileName));
	dwLength = ::GetFileVersionInfoSize(szFileName,&dwNullHandle);

	char* pVersionInfo = new char[dwLength];
	::GetFileVersionInfo(szFileName,NULL,dwLength,pVersionInfo);

	unsigned int  cbTranslate = 0;
	struct LANGANDCODEPAGE {
		WORD wLanguage;
		WORD wCodePage;
	} *lpTranslate;
	::VerQueryValue(pVersionInfo,"\\VarFileInfo\\Translation",(LPVOID *)&lpTranslate,&cbTranslate);

	char  SubBlock[200];
	sprintf( SubBlock,"\\StringFileInfo\\%04x%04x\\ProductVersion",lpTranslate[0].wLanguage,lpTranslate[0].wCodePage);
	void *lpBuffer=NULL;
	unsigned int dwBytes=0;
	VerQueryValue(pVersionInfo,SubBlock,&lpBuffer,&dwBytes);

	sVersionNum.Format("%s",(char *)lpBuffer);

	delete [] pVersionInfo;

	return   TRUE;
}

//设置窗口标题
void CMECProcedureDlg::ShowDialogTitle()
{
	CString sVersion;
	ReadResourceInformation(sVersion);

	sVersion.Remove(' ');

	// 解析获取到的版本信息
	int nVersion[4];

	int nVersionIndex = 0;
	CString sVersionTemp;
	while (AfxExtractSubString(sVersionTemp,sVersion,nVersionIndex,'.'))
	{
		nVersion[nVersionIndex] = atoi(sVersionTemp.GetBuffer(0));
		nVersionIndex ++;
		if (nVersionIndex >= 4)
		{
			break;
		}
	}

	char sWindowTitle[64];
	sprintf(sWindowTitle,"MECProcedure Version %d.%d.%d.%d",nVersion[0],nVersion[1],nVersion[2],nVersion[3]);

	// 设置标题栏
	SetWindowText(sWindowTitle);
}

void CMECProcedureDlg::InitView()
{
	CRect rect;
	GetClientRect(&rect);
	m_siDlgWidth = rect.Width();
	m_siDlgHeight = rect.Height();

	m_pDlgRealPlay->MoveWindow(0, 0, m_siDlgWidth , m_siDlgHeight);
	m_pDlgRealPlay->InitView();    
}

//窗体大小变化处理
void CMECProcedureDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if(m_bInitOver)
	{
		InitView();
	}
}
