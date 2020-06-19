// DlgRealPlayWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "DlgRealPlayWnd.h"
#include "afxdialogex.h"


// CDlgRealPlayWnd 对话框

IMPLEMENT_DYNAMIC(CDlgRealPlayWnd, CDialog)

CDlgRealPlayWnd::CDlgRealPlayWnd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRealPlayWnd::IDD, pParent)
{

}

CDlgRealPlayWnd::~CDlgRealPlayWnd()
{
}

void CDlgRealPlayWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRealPlayWnd, CDialog)
END_MESSAGE_MAP()


// CDlgRealPlayWnd 消息处理程序

//设置窗口标记号
void CDlgRealPlayWnd::SetWndIndex(_UI uiWndIndex)
{
	m_uiWndIndex = uiWndIndex;
}