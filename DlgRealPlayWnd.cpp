// DlgRealPlayWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "DlgRealPlayWnd.h"
#include "afxdialogex.h"


// CDlgRealPlayWnd �Ի���

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


// CDlgRealPlayWnd ��Ϣ�������

//���ô��ڱ�Ǻ�
void CDlgRealPlayWnd::SetWndIndex(_UI uiWndIndex)
{
	m_uiWndIndex = uiWndIndex;
}