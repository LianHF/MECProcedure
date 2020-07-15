// DlgRealPlayPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MECProcedure.h"
#include "DlgRealPlayPage.h"
#include "afxdialogex.h"


// CDlgRealPlayPage �Ի���

IMPLEMENT_DYNAMIC(CDlgRealPlayPage, CDialog)

CDlgRealPlayPage::CDlgRealPlayPage(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRealPlayPage::IDD, pParent)
{
	m_ucWndType = REALPLAY_WND_TYPE_SIXTEEN;
	//m_ucOldWndType = REALPLAY_WND_TYPE_NINE;
	m_uiCurWndIndex = 0;
	m_siDlgWidth = 0;
	m_siWndSpace = 0;
	m_siDlgHeight = 0;
	m_siWndLeft = 0;
	m_siWndTop = 0;
	m_siWndWidth = 0;
	m_siWndHeight = 0;
	m_uiBeginWndIndex = 0;
	/*memset(&m_RealPlay_Wnd_Type_Four,0,sizeof(int));
	for(int i=0;i<9;i++)
	{
		memset(&m_CurOpenDevice[i],0,sizeof(DB_DEVICE_INFO_STRU));
	}
	memset(&m_CurOpenDevice[0],1,sizeof(DB_DEVICE_INFO_STRU)*9);*/
}

CDlgRealPlayPage::~CDlgRealPlayPage()
{
	DeleteUI();
}

void CDlgRealPlayPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_WND_ONE, m_btnWndOne);
	DDX_Control(pDX, IDC_BUTTON_WND_FOUR, m_btnWndFour);
	DDX_Control(pDX, IDC_BUTTON_WND_NINE, m_btnWndNine);
	DDX_Control(pDX, IDC_BUTTON_WND_SIXTEEN, m_btnWndSixteen);
	DDX_Control(pDX, IDC_STATIC_LINE_TOP, m_staLineTop);
	DDX_Control(pDX, IDC_STATIC_LINE_DOWN, m_staLineBottom);
	DDX_Control(pDX, IDC_STATIC_LINE_LEFT, m_staLineLeft);
	DDX_Control(pDX, IDC_STATIC_LINE_RIGHT, m_staLineRight);
	DDX_Control(pDX, IDC_BUTTON_WND_TWO, m_btnWndTwo);
}


BEGIN_MESSAGE_MAP(CDlgRealPlayPage, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_WND_ONE, &CDlgRealPlayPage::OnBnClickedButtonWndOne)
	ON_BN_CLICKED(IDC_BUTTON_WND_FOUR, &CDlgRealPlayPage::OnClickedButtonWndFour)
	ON_BN_CLICKED(IDC_BUTTON_WND_NINE, &CDlgRealPlayPage::OnClickedButtonWndNine)
	ON_BN_CLICKED(IDC_BUTTON_WND_SIXTEEN, &CDlgRealPlayPage::OnClickedButtonWndSixteen)
	ON_BN_CLICKED(IDC_BUTTON_WND_TWO, &CDlgRealPlayPage::OnBnClickedButtonWndTwo)
END_MESSAGE_MAP()


// CDlgRealPlayPage ��Ϣ�������


//����UI���
void CDlgRealPlayPage::CreateUI()
{
	for(_UI uiIndex=0; uiIndex < MAX_REALPLAY_WND_NUM; uiIndex++)
	{
		m_pDlgRealPlayWnd[uiIndex] = new CDlgRealPlayWnd(this);
		m_pDlgRealPlayWnd[uiIndex]->Create(IDD_DIALOG_REALPLA_WND,this);
		m_pDlgRealPlayWnd[uiIndex]->SetWndIndex(uiIndex);
	}

}
//ɾ�����
void CDlgRealPlayPage::DeleteUI()
{
	for(_UI uiIndex = 0; uiIndex < MAX_REALPLAY_WND_NUM; uiIndex++)
	{
		delete m_pDlgRealPlayWnd[uiIndex];
	}
}

void CDlgRealPlayPage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()

	//CRect rect;
	//GetClientRect(&rect);
	////dc.FillSolidRect(rect, RGB(100, 100, 50));


	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP_PARAM);
	//BITMAP bmp;
	//bitmap.GetBitmap(&bmp);
	//CDC dcCompatible;
	//dcCompatible.CreateCompatibleDC(&dc);
	//dcCompatible.SelectObject(&bitmap);
	//dc.SetStretchBltMode(HALFTONE);

	//dc.StretchBlt(0, 50, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bmp.bmWidth, bmp.bmHeight-50, SRCCOPY);
	MoveFrame();
}


BOOL CDlgRealPlayPage::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_staLineLeft.SetText("");
	m_staLineRight.SetText("");
	m_staLineTop.SetText("");
	m_staLineBottom.SetText("");

	CreateUI();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

//��ʼ������
void CDlgRealPlayPage::InitView()
{
	CRect rect;
	GetClientRect(&rect);
	m_siDlgWidth = rect.Width();	//������
	m_siDlgHeight = rect.Height();	//����߶�

	_SI siBottomHeight = 60;		//�ײ��߶�
	m_siWndSpace = 4;				//������


	_SI siBtnWidth = 100;			//��ť��
	_SI siBtnHeight = 35;			//��ť�߶�

	m_siWndLeft = m_siWndSpace;
	m_siWndTop = m_siWndSpace;
	m_siWndWidth = m_siDlgWidth - (m_siWndSpace * 2);
	m_siWndHeight = m_siDlgHeight - (m_siWndSpace * 2) - siBottomHeight;

	//btn�ֲ�
	_SI siBtnSpace = m_siDlgWidth / 6;
	_SI siBtnLeft = siBtnSpace + (siBtnSpace - siBtnWidth) / 2;
	_SI siBtnTop = m_siDlgHeight - siBottomHeight + (siBottomHeight - siBtnHeight) / 2;
	m_btnWndOne.MoveWindow(siBtnLeft, siBtnTop, siBtnWidth, siBtnHeight);
	m_btnWndTwo.MoveWindow(siBtnLeft + siBtnSpace, siBtnTop, siBtnWidth, siBtnHeight);
	m_btnWndFour.MoveWindow(siBtnLeft + (siBtnSpace * 2), siBtnTop, siBtnWidth, siBtnHeight);
	m_btnWndNine.MoveWindow(siBtnLeft + (siBtnSpace * 3), siBtnTop, siBtnWidth, siBtnHeight);
	m_btnWndSixteen.MoveWindow(siBtnLeft + (siBtnSpace * 4), siBtnTop, siBtnWidth, siBtnHeight);


	m_staLineLeft.SetBkTransparent(FALSE);
	m_staLineRight.SetBkTransparent(FALSE);
	m_staLineBottom.SetBkTransparent(FALSE);
	m_staLineTop.SetBkTransparent(FALSE);

	m_staLineLeft.SetBkColor(RGB(128, 0, 0));
	m_staLineRight.SetBkColor(RGB(128, 0, 0));
	m_staLineTop.SetBkColor(RGB(128, 0, 0));
	m_staLineBottom.SetBkColor(RGB(128, 0, 0));

	SetRealPlayWnd();
}

//������Ƶ���ڲ���
void CDlgRealPlayPage::SetRealPlayWnd()
{
	_SI siWndWidth = 0;
	_SI siWndHeight = 0;
	_UI uiColIndex = 0;
	_UI uiRowIndex = 0;

	//�ж��Ƿ�Խ��
	if(m_uiCurWndIndex > MAX_REALPLAY_WND_NUM)
	{
		return;
	}

	//����������
	for(_UI uiWndIndex = 0; uiWndIndex < MAX_REALPLAY_WND_NUM; uiWndIndex++)
	{
		m_pDlgRealPlayWnd[uiWndIndex]->ShowWindow(SW_HIDE);
	}

	//����λ�ã���ʾ
	if(m_ucWndType == REALPLAY_WND_TYPE_ONE)//������
	{
		m_uiBeginWndIndex = m_uiCurWndIndex;
		siWndWidth = m_siWndWidth;
		siWndHeight = m_siWndHeight ;
		m_pDlgRealPlayWnd[m_uiCurWndIndex]->MoveWindow(m_siWndLeft, m_siWndTop, siWndWidth, siWndHeight);
		m_pDlgRealPlayWnd[m_uiCurWndIndex]->InitView();
		m_pDlgRealPlayWnd[m_uiCurWndIndex]->SetRectRange(m_siWndLeft, m_siWndTop, siWndWidth, siWndHeight);
		m_pDlgRealPlayWnd[m_uiCurWndIndex]->ShowWindow(SW_SHOW);
	}
	else if(m_ucWndType == REALPLAY_WND_TYPE_TWO)
	{
		m_uiBeginWndIndex = 0;
		if(m_uiCurWndIndex > (MAX_REALPLAY_WND_NUM  -  REALPLAY_WND_TYPE_TWO))
		{
			m_uiBeginWndIndex = MAX_REALPLAY_WND_NUM  -  REALPLAY_WND_TYPE_TWO;
		}
		else
		{
			m_uiBeginWndIndex = m_uiCurWndIndex;
		}

		siWndWidth = (m_siWndWidth - m_siWndSpace) / 2;
		siWndHeight = (m_siWndHeight - m_siWndSpace);
		for(_UI uiWndIndex = 0; uiWndIndex < REALPLAY_WND_TYPE_TWO; uiWndIndex++)
		{
			uiColIndex = uiWndIndex % 2;
			uiRowIndex = uiWndIndex / 2;
			m_pDlgRealPlayWnd[m_uiBeginWndIndex+uiWndIndex]->MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[m_uiBeginWndIndex+ uiWndIndex]->InitView();
			m_pDlgRealPlayWnd[m_uiBeginWndIndex+ uiWndIndex]->SetRectRange(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[m_uiBeginWndIndex+ uiWndIndex]->ShowWindow(SW_SHOW);
		}
	}
	else if(m_ucWndType == REALPLAY_WND_TYPE_FOUR)
	{
		m_uiBeginWndIndex = 0;
		if(m_uiCurWndIndex > (MAX_REALPLAY_WND_NUM  -  REALPLAY_WND_TYPE_FOUR))
		{
			m_uiBeginWndIndex = MAX_REALPLAY_WND_NUM  -  REALPLAY_WND_TYPE_FOUR;
		}
		else
		{
			m_uiBeginWndIndex = m_uiCurWndIndex;
		}

		siWndWidth = (m_siWndWidth - m_siWndSpace) / 2;
		siWndHeight = (m_siWndHeight - m_siWndSpace) / 2;
		for(_UI uiWndIndex = 0; uiWndIndex < REALPLAY_WND_TYPE_FOUR; uiWndIndex++)
		{
			uiColIndex = uiWndIndex % 2;
			uiRowIndex = uiWndIndex / 2;
			m_pDlgRealPlayWnd[m_uiBeginWndIndex + uiWndIndex]->MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[m_uiBeginWndIndex + uiWndIndex]->InitView();
			m_pDlgRealPlayWnd[m_uiBeginWndIndex + uiWndIndex]->SetRectRange(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[m_uiBeginWndIndex + uiWndIndex]->ShowWindow(SW_SHOW);
			//m_RealPlay_Wnd_Type_Four[uiWndIndex] = m_uiBeginWndIndex + uiWndIndex;
		}
	}
	else if(m_ucWndType == REALPLAY_WND_TYPE_NINE)
	{
		m_uiBeginWndIndex = 0;

		siWndWidth = (m_siWndWidth - (m_siWndSpace * 2)) / 3;
		siWndHeight = (m_siWndHeight - (m_siWndSpace * 2)) / 3;
		for(_UI uiWndIndex = 0; uiWndIndex < REALPLAY_WND_TYPE_NINE; uiWndIndex++)
		{
			uiColIndex = uiWndIndex % 3;
			uiRowIndex = uiWndIndex / 3;
			m_pDlgRealPlayWnd[uiWndIndex]->MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[uiWndIndex]->InitView();
			m_pDlgRealPlayWnd[uiWndIndex]->SetRectRange(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[uiWndIndex]->ShowWindow(SW_SHOW);
		}
	}

	else if(m_ucWndType == REALPLAY_WND_TYPE_SIXTEEN)
	{
		m_uiBeginWndIndex = 0;
		siWndWidth = (m_siWndWidth - (m_siWndSpace * 2)) / 4;
		siWndHeight = (m_siWndHeight - (m_siWndSpace * 2)) / 4;
		for(_UI uiWndIndex = 0; uiWndIndex < REALPLAY_WND_TYPE_SIXTEEN; uiWndIndex++)
		{
			uiColIndex = uiWndIndex % 4;
			uiRowIndex = uiWndIndex / 4;
			m_pDlgRealPlayWnd[uiWndIndex]->MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[uiWndIndex]->InitView();
			m_pDlgRealPlayWnd[uiWndIndex]->SetRectRange(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)), m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)), siWndWidth, siWndHeight);
			m_pDlgRealPlayWnd[uiWndIndex]->ShowWindow(SW_SHOW);
		}
	}
}

//����Ƶ���ڱ߿�
void CDlgRealPlayPage::MoveFrame()
{
	//���	��С
	_SI siPenWidth = 3;

	//���ж��ǵڼ��еڼ���
	_UI uiWndIndex = 0;		//��������
	_UI uiColIndex = 0;		//����
	_UI uiRowIndex = 0;		//����
	_SI siWndWidth = 0;		//�����
	_SI siWndHeight = 0;	//����߶�

	//������
	if(m_ucWndType == REALPLAY_WND_TYPE_ONE)
	{
		siWndWidth = m_siWndWidth;
		siWndHeight = m_siWndHeight;

		m_staLineLeft.MoveWindow(m_siWndLeft - siPenWidth, 
			m_siWndTop,  
			siPenWidth, 
			m_siWndHeight + (siPenWidth*2));

		m_staLineTop.MoveWindow(m_siWndLeft - siPenWidth,
			m_siWndTop - siPenWidth,
			siWndWidth + siPenWidth,
			siPenWidth);

		m_staLineRight.MoveWindow(m_siWndLeft + m_siWndWidth ,
			m_siWndTop - siPenWidth,
			siPenWidth,
			m_siWndHeight + (siPenWidth * 2));

		m_staLineBottom.MoveWindow(m_siWndLeft - siPenWidth,
			m_siWndHeight + (siPenWidth*2),
			siWndWidth + siPenWidth,
			siPenWidth);

	}
	//������
	else if(m_ucWndType == REALPLAY_WND_TYPE_TWO)
	{
		if(m_uiBeginWndIndex > m_uiCurWndIndex)
		{
			return;
		}
		//�������� = ��ǰ���� - ��ʼ����
		uiWndIndex = m_uiCurWndIndex - m_uiBeginWndIndex;
		//�������� = �������� % 2   �磺3 % 2 = 1
		uiColIndex = uiWndIndex % 2;
		//�������� = �������� / 2  �� �� 3/2 = 1
		uiRowIndex = uiWndIndex / 2;

		//����� =  �������ܿ� - �����С�� / 2
		siWndWidth = (m_siWndWidth - m_siWndSpace) / 2;
		//����� =  �������ܸ� - �����С�� / 2
		siWndHeight = (m_siWndHeight - m_siWndSpace);

		m_staLineLeft.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,		
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,  
			siPenWidth, 
			siWndHeight + (siPenWidth*2));

		m_staLineTop.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth ,		
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth ,
			siWndWidth + siPenWidth,
			siPenWidth);

		m_staLineRight.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) + siWndWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,
			siPenWidth,
			siWndHeight + (siPenWidth*2));

		//��uiWndIndex=3ʱ			�������  +  ����������(1)*(���ڿ�+���))				- ��ܴ�С��  
		m_staLineBottom.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) + siWndHeight,
			siWndWidth + siPenWidth,
			siPenWidth);
	}
	//�Ĵ���
	else if(m_ucWndType == REALPLAY_WND_TYPE_FOUR)
	{
		if(m_uiBeginWndIndex > m_uiCurWndIndex)
		{
			return;
		}
		//�������� = ��ǰ���� - ��ʼ����
		uiWndIndex = m_uiCurWndIndex - m_uiBeginWndIndex;
		//�������� = �������� % 2   �磺3 % 2 = 1
		uiColIndex = uiWndIndex % 2;
		//�������� = �������� / 2  �� �� 3/2 = 1
		uiRowIndex = uiWndIndex / 2;

		//����� =  �������ܿ� - �����С�� / 2
		siWndWidth = (m_siWndWidth - m_siWndSpace) / 2;
		//����� =  �������ܸ� - �����С�� / 2
		siWndHeight = (m_siWndHeight - m_siWndSpace) / 2;

		m_staLineLeft.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,		
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,  
			siPenWidth, 
			siWndHeight + (siPenWidth*2));

		m_staLineTop.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth ,		
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth ,
			siWndWidth + siPenWidth,
			siPenWidth);

		m_staLineRight.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) + siWndWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,
			siPenWidth,
			siWndHeight + (siPenWidth*2));

		//��uiWndIndex=3ʱ			�������  +  ����������(1)*(���ڿ�+���))				- ��ܴ�С��  
		m_staLineBottom.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) + siWndHeight,
			siWndWidth + siPenWidth,
			siPenWidth);
	}
	//�Ŵ���
	else if(m_ucWndType == REALPLAY_WND_TYPE_NINE)
	{
		uiColIndex = m_uiCurWndIndex % 3;
		uiRowIndex = m_uiCurWndIndex / 3;
		siWndWidth = (m_siWndWidth - (m_siWndSpace * 2)) / 3;
		siWndHeight = (m_siWndHeight - (m_siWndSpace * 2)) / 3;

		m_staLineLeft.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth, 
			siPenWidth,  
			siWndHeight + (siPenWidth*2));
		
		m_staLineTop.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,
			siWndWidth+siPenWidth,
			siPenWidth);
		
		m_staLineRight.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) + siWndWidth, 
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,
			siPenWidth,
			siWndHeight + (siPenWidth*2));
		
		m_staLineBottom.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace))-siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) + siWndHeight,
			siWndWidth+siPenWidth,
			siPenWidth);
	}
	//ʮ������
	else if(m_ucWndType == REALPLAY_WND_TYPE_SIXTEEN)
	{
		uiColIndex = m_uiCurWndIndex % 4;
		uiRowIndex = m_uiCurWndIndex / 4;
		siWndWidth = (m_siWndWidth - (m_siWndSpace * 2)) / 4;
		siWndHeight = (m_siWndHeight - (m_siWndSpace * 2)) / 4;

		m_staLineLeft.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth, 
			siPenWidth,  
			siWndHeight + (siPenWidth*2));

		m_staLineTop.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,
			siWndWidth+siPenWidth,
			siPenWidth);

		m_staLineRight.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) + siWndWidth, 
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) - siPenWidth,
			siPenWidth,
			siWndHeight + (siPenWidth*2));

		m_staLineBottom.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace))-siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) + siWndHeight,
			siWndWidth+siPenWidth,
			siPenWidth);
	}
}

//���õ�ǰ������Ƶ����
void CDlgRealPlayPage::SetCurWndIndex(_UI uiWndIndex)
{
	m_uiCurWndIndex = uiWndIndex;

	MoveFrame();
}

//���ý�����ʾ��������
void CDlgRealPlayPage::SetWndType(_UC ucWndType)
{
	if(ucWndType != REALPLAY_WND_TYPE_ONE)
	{
		//m_ucOldWndType = ucWndType;
	}
	m_ucWndType = ucWndType;
	SetRealPlayWnd();
}


_UC CDlgRealPlayPage::GetWndType()
{
	return m_ucWndType;
}

//�����ڰ�ť�¼�
void CDlgRealPlayPage::OnBnClickedButtonWndOne()
{
	SetWndType(REALPLAY_WND_TYPE_ONE);
}
//�����ڰ�ť�¼�
void CDlgRealPlayPage::OnBnClickedButtonWndTwo()
{
	SetWndType(REALPLAY_WND_TYPE_TWO);
}

//�Ĵ��ڰ�ť�¼�
void CDlgRealPlayPage::OnClickedButtonWndFour()
{
	SetWndType(REALPLAY_WND_TYPE_FOUR);
}

//�Ŵ��ڰ�ť�¼�
void CDlgRealPlayPage::OnClickedButtonWndNine()
{
	SetWndType(REALPLAY_WND_TYPE_NINE);
}

//ʮ�����ڰ�ť�¼�
void CDlgRealPlayPage::OnClickedButtonWndSixteen()
{
	SetWndType(REALPLAY_WND_TYPE_SIXTEEN);
}


//���ô���ȫƷ�¼�
void CDlgRealPlayPage::SetFullScreen(BOOL bIsFull)
{

	//Ŀǰ״̬��Ϊȫ��
	/*if(bIsFull)
	{
	SetParent(GetDesktopWindow());   
	CRect rect;   
	GetDesktopWindow()-> GetWindowRect(&rect);   
	SetWindowPos(&wndTopMost, rect.left, rect.top, rect.Width(), rect.Height(), SWP_SHOWWINDOW);

	}
	else
	{
	SetParent(this);  
	SetWindowPos(&wndTop, OldRect.left, OldRect.top, OldRect.Width(), OldRect.Height(), SWP_SHOWWINDOW);
	}*/
	for(int i=0;i<MAX_REALPLAY_WND_NUM;i++)
		m_pDlgRealPlayWnd[i]->InitView();
}


