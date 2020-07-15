
// MECProcedureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "MECProcedureDlg.h"
#include "afxdialogex.h"
#include "Log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//��ȡ�汾��Ϣ��
#pragma comment(lib,"version.lib")



// CMECProcedureDlg �Ի���
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




// CMECProcedureDlg ��Ϣ�������

BOOL CMECProcedureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//��ʾ����
	ShowDialogTitle();

	//������Ƶ��ʾ����
	m_pDlgRealPlay = new CDlgRealPlayPage(this);
	m_pDlgRealPlay->Create(IDD_DIALOG_REALPLAY_PAGE,this);

	InitView();
	m_pDlgRealPlay->ShowWindow(SW_SHOW);


	m_bInitOver = true;

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMECProcedureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMECProcedureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ȡ�汾����Ϣ
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

//���ô��ڱ���
void CMECProcedureDlg::ShowDialogTitle()
{
	CString sVersion;
	ReadResourceInformation(sVersion);

	sVersion.Remove(' ');

	// ������ȡ���İ汾��Ϣ
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

	// ���ñ�����
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

//�����С�仯����
void CMECProcedureDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if(m_bInitOver)
	{
		InitView();
	}
}
