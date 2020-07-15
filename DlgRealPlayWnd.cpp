// DlgRealPlayWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "DlgRealPlayWnd.h"
#include "afxdialogex.h"
#include "DlgRealPlayPage.h"


// CDlgRealPlayWnd �Ի���




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


// CDlgRealPlayWnd ��Ϣ�������
BOOL CDlgRealPlayWnd::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Brush.DeleteObject();
	m_Brush.CreateSolidBrush(RGB(50, 50, 50));

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_staInfo.SetForeColor(RGB(0, 50, 0));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



//���ô��ڱ�Ǻ�
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

	// TODO:  �ڴ˸��� DC ���κ�����
	if(CTLCOLOR_STATIC == nCtlColor)         
	{
		if(IDC_STATIC_PLAY_WND == pWnd->GetDlgCtrlID())
		{
			return (HBRUSH)m_Brush;
		}
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCurWndIndex();
	CDialog::OnLButtonDown(nFlags, point);
}


BOOL CDlgRealPlayWnd::PreTranslateMessage(MSG* pMsg)
{
	//��������¼� ����ر�
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

//˫��
void CDlgRealPlayWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	//Ŀǰ״̬��Ϊȫ��
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


	//����ȫ���¼�
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
		AfxMessageBox("��ȡͼƬ��Ϣʧ�ܣ���");
		return;
	}
	char szTmp[10] = "";
	sprintf(szTmp,"src%d",m_uiWndIndex);
	CWnd  *pWnd1 = GetDlgItem(IDC_STATIC_PLAY_WND);//CWnd��MFC������Ļ���,�ṩ��΢�������������д�����Ļ������ܡ�
	CRect rect1;
	pWnd1->GetClientRect(&rect1);//GetClientRectΪ��ÿؼ�������������555С
	namedWindow(szTmp, 1);//���ô�����
	HWND hWndl = (HWND)cvGetWindowHandle(szTmp);//hWnd ��ʾ���ھ��,��ȡ���ھ��
	HWND hParent1 = ::GetParent(hWndl);//GetParent����һ��ָ���Ӵ��ڵĸ����ھ��
	::SetParent(hWndl, GetDlgItem(IDC_STATIC_PLAY_WND)->m_hWnd);
	::ShowWindow(hParent1, SW_HIDE);//ShowWindowָ����������ʾ
	resize(img[m_uiWndIndex],img[m_uiWndIndex],Size(rect1.Width(),rect1.Height()));
	imshow(szTmp,img[m_uiWndIndex]);
}
