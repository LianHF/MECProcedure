// DlgRealPlayWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "DlgRealPlayWnd.h"
#include "afxdialogex.h"
#include "DlgRealPlayPage.h"


// CDlgRealPlayWnd 对话框




IMPLEMENT_DYNAMIC(CDlgRealPlayWnd, CDialog)

CDlgRealPlayWnd::CDlgRealPlayWnd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRealPlayWnd::IDD, pParent)
{
	m_pParent = pParent;
	m_uiWndIndex = 0;
	m_bFullScreen = FALSE;
}

CDlgRealPlayWnd::~CDlgRealPlayWnd()
{
}

void CDlgRealPlayWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
	DDX_Control(pDX, IDC_STATIC_PLAY_WND, m_staPlayWnd);
	DDX_Control(pDX, IDC_STATIC_INFO, m_staInfo);
}


BEGIN_MESSAGE_MAP(CDlgRealPlayWnd, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDlgRealPlayWnd::OnBnClickedButtonStop)
END_MESSAGE_MAP()


// CDlgRealPlayWnd 消息处理程序
BOOL CDlgRealPlayWnd::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Brush.DeleteObject();
	m_Brush.CreateSolidBrush(RGB(50, 50, 50));

	// TODO:  在此添加额外的初始化
	m_staInfo.SetForeColor(RGB(0, 50, 0));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



//设置窗口标记号
void CDlgRealPlayWnd::SetWndIndex(_UI uiWndIndex)
{
	m_uiWndIndex = uiWndIndex;
}

void CDlgRealPlayWnd::InitView()
{
	CRect rect;
	GetClientRect(&rect);
	_SI siDlgWidth = rect.Width();
	_SI siDlgHeight = rect.Height();

	_SI siBottomHeight = 20;
	_SI siSpaceHeight = 2;
	_SI siSpaceWidth = 10;
	_SI siBtnWidth = 30;
	//					20 - 4 = 16
	_SI siBtnHeight = siBottomHeight - (siSpaceHeight * 2);
	m_staPlayWnd.MoveWindow(0, 0, siDlgWidth, siDlgHeight - siBottomHeight);
	m_btnStop.MoveWindow(siDlgWidth - siBtnWidth - siSpaceWidth, siDlgHeight - siBtnHeight - siSpaceHeight, siBtnWidth, siBtnHeight);
	m_staInfo.MoveWindow(0, siDlgHeight - siBtnHeight - siSpaceHeight, siDlgWidth - siBtnWidth, siBtnHeight);


	
	//GetClientRect(&m_OldRect);
}



HBRUSH CDlgRealPlayWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(CTLCOLOR_STATIC == nCtlColor)         
	{
		if(IDC_STATIC_PLAY_WND == pWnd->GetDlgCtrlID())
		{
			return (HBRUSH)m_Brush;
		}
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CDlgRealPlayWnd::SetCurWndIndex()
{
	if(m_pParent == NULL)
	{
		return;
	}
	CDlgRealPlayPage *pParent = (CDlgRealPlayPage *)m_pParent;
	pParent->SetCurWndIndex(m_uiWndIndex);
}

void CDlgRealPlayWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCurWndIndex();
	CDialog::OnLButtonDown(nFlags, point);
}


BOOL CDlgRealPlayWnd::PreTranslateMessage(MSG* pMsg)
{
	//处理键盘事件 避免关闭
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

//双击
void CDlgRealPlayWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	//目前状态不为全屏
	if(m_bFullScreen == FALSE)
	{
		SetParent(GetDesktopWindow());   
		CRect rect;   
		GetDesktopWindow()-> GetWindowRect(&rect);   
		SetWindowPos(&wndTopMost, rect.left, rect.top, rect.Width(), rect.Height(), SWP_SHOWWINDOW);
		m_bFullScreen = TRUE;
	}
	else
	{
		CDlgRealPlayPage *pWnd = (CDlgRealPlayPage*)m_pParent;

		// SetParent(m_pParentWnd);  
		
		SetWindowPos(&wndTop, m_OldRect.left, m_OldRect.top, m_OldRect.Width(), m_OldRect.Height(), SWP_SHOWWINDOW);
		SetParent(m_pParentWnd);  
		pWnd->SetFullScreen(FALSE);
		m_bFullScreen = FALSE;
	}


	//处理全屏事件
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CDlgRealPlayWnd::SetRectRange(_UI uiLeft,_UI  uiTop,_UI uiWide,_UI uiHeight)
{
	m_OldRect.left = uiLeft;
	m_OldRect.top = uiTop;
	m_OldRect.right = uiWide + uiLeft;
	m_OldRect.bottom = uiHeight + uiTop;
}

void CDlgRealPlayWnd::OnBnClickedButtonStop()
{
	img[m_uiWndIndex] = imread(".\\Bitmap\\1.jpg");
	if(!img[m_uiWndIndex].data)
	{
		AfxMessageBox("获取图片信息失败！！");
		return;
	}
	char szTmp[10] = "";
	sprintf(szTmp,"src%d",m_uiWndIndex);
	CWnd  *pWnd1 = GetDlgItem(IDC_STATIC_PLAY_WND);//CWnd是MFC窗口类的基类,提供了微软基础类库中所有窗口类的基本功能。
	CRect rect1;
	pWnd1->GetClientRect(&rect1);//GetClientRect为获得控件相自身的坐标大555小
	namedWindow(szTmp, 1);//设置窗口名
	HWND hWndl = (HWND)cvGetWindowHandle(szTmp);//hWnd 表示窗口句柄,获取窗口句柄
	HWND hParent1 = ::GetParent(hWndl);//GetParent函数一个指定子窗口的父窗口句柄
	::SetParent(hWndl, GetDlgItem(IDC_STATIC_PLAY_WND)->m_hWnd);
	::ShowWindow(hParent1, SW_HIDE);//ShowWindow指定窗口中显示
	resize(img[m_uiWndIndex],img[m_uiWndIndex],Size(rect1.Width(),rect1.Height()));
	imshow(szTmp,img[m_uiWndIndex]);
}
