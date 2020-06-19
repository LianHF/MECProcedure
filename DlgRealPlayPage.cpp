// DlgRealPlayPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "DlgRealPlayPage.h"
#include "afxdialogex.h"


// CDlgRealPlayPage 对话框

IMPLEMENT_DYNAMIC(CDlgRealPlayPage, CDialog)

CDlgRealPlayPage::CDlgRealPlayPage(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRealPlayPage::IDD, pParent)
{

}

CDlgRealPlayPage::~CDlgRealPlayPage()
{
}

void CDlgRealPlayPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_WND_ONE, m_btnWndOne);
	DDX_Control(pDX, IDC_BUTTON_WND_FOUR, m_btnWndFour);
	DDX_Control(pDX, IDC_BUTTON_WND_NINE, m_btnWndNine);
	DDX_Control(pDX, IDC_BUTTON_WND_SIXTEEN, m_btnWndSixteen);
	DDX_Control(pDX, IDC_STATIC_LINE_TOP, m_staLineTop);
	DDX_Control(pDX, IDC_STATIC_LINE_DOWN, m_staLineDown);
	DDX_Control(pDX, IDC_STATIC_LINE_LEFT, m_staLineLeft);
	DDX_Control(pDX, IDC_STATIC_LINE_RIGHT, m_staLineRight);
}


BEGIN_MESSAGE_MAP(CDlgRealPlayPage, CDialog)
END_MESSAGE_MAP()


// CDlgRealPlayPage 消息处理程序


//创建UI句柄
void CDlgRealPlayPage::CreateUI()
{
	for(_UI uiIndex=0; uiIndex < MAX_REALPLAY_WND_NUM; uiIndex++)
	{
		m_pDlgRealPlayWnd[uiIndex] = new CDlgRealPlayWnd(this);
		m_pDlgRealPlayWnd[uiIndex]->Create(IDD_DIALOG_REALPLA_WND,this);
		m_pDlgRealPlayWnd[uiIndex]->SetWndIndex(uiIndex);
	}

}
//删除句柄
void CDlgRealPlayPage::DeleteUI()
{
	for(_UI uiIndex = 0; uiIndex < MAX_REALPLAY_WND_NUM; uiIndex++)
	{
		delete m_pDlgRealPlayWnd[uiIndex];
	}
}

//初始化界面
void CDlgRealPlayPage::InitView()
{

}