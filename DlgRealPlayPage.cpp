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

void CDlgRealPlayPage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

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
	// 异常: OCX 属性页应返回 FALSE
}

//初始化界面
void CDlgRealPlayPage::InitView()
{
	CRect rect;
	GetClientRect(&rect);
	m_siDlgWidth = rect.Width();	//窗体宽度
	m_siDlgHeight = rect.Height();	//窗体高度

	_SI siBottomHeight = 60;		//底部高度
	m_siWndSpace = 4;				//窗体间隔


	_SI siBtnWidth = 100;			//按钮宽
	_SI siBtnHeight = 35;			//按钮高度

	m_siWndLeft = m_siWndSpace;
	m_siWndTop = m_siWndSpace;
	m_siWndWidth = m_siDlgWidth - (m_siWndSpace * 2);
	m_siWndHeight = m_siDlgHeight - (m_siWndSpace * 2) - siBottomHeight;

	//btn分布
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

//设置视频窗口布局
void CDlgRealPlayPage::SetRealPlayWnd()
{
	_SI siWndWidth = 0;
	_SI siWndHeight = 0;
	_UI uiColIndex = 0;
	_UI uiRowIndex = 0;

	//判断是否越界
	if(m_uiCurWndIndex > MAX_REALPLAY_WND_NUM)
	{
		return;
	}

	//先隐藏所有
	for(_UI uiWndIndex = 0; uiWndIndex < MAX_REALPLAY_WND_NUM; uiWndIndex++)
	{
		m_pDlgRealPlayWnd[uiWndIndex]->ShowWindow(SW_HIDE);
	}

	//设置位置，显示
	if(m_ucWndType == REALPLAY_WND_TYPE_ONE)//单画面
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

//画视频窗口边框
void CDlgRealPlayPage::MoveFrame()
{
	//横杠	大小
	_SI siPenWidth = 3;

	//先判断是第几行第几列
	_UI uiWndIndex = 0;		//窗口索引
	_UI uiColIndex = 0;		//纵向
	_UI uiRowIndex = 0;		//横向
	_SI siWndWidth = 0;		//窗体宽
	_SI siWndHeight = 0;	//窗体高度

	//单窗口
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
	//二窗口
	else if(m_ucWndType == REALPLAY_WND_TYPE_TWO)
	{
		if(m_uiBeginWndIndex > m_uiCurWndIndex)
		{
			return;
		}
		//窗体索引 = 当前窗口 - 开始窗口
		uiWndIndex = m_uiCurWndIndex - m_uiBeginWndIndex;
		//纵向索引 = 窗体索引 % 2   如：3 % 2 = 1
		uiColIndex = uiWndIndex % 2;
		//横向索引 = 窗体索引 / 2  如 ： 3/2 = 1
		uiRowIndex = uiWndIndex / 2;

		//窗体宽 =  （窗体总宽 - 间隔大小） / 2
		siWndWidth = (m_siWndWidth - m_siWndSpace) / 2;
		//窗体高 =  （窗体总高 - 间隔大小） / 2
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

		//当uiWndIndex=3时			窗体左边  +  （纵向索引(1)*(窗口宽+间隔))				- 横杠大小，  
		m_staLineBottom.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) + siWndHeight,
			siWndWidth + siPenWidth,
			siPenWidth);
	}
	//四窗口
	else if(m_ucWndType == REALPLAY_WND_TYPE_FOUR)
	{
		if(m_uiBeginWndIndex > m_uiCurWndIndex)
		{
			return;
		}
		//窗体索引 = 当前窗口 - 开始窗口
		uiWndIndex = m_uiCurWndIndex - m_uiBeginWndIndex;
		//纵向索引 = 窗体索引 % 2   如：3 % 2 = 1
		uiColIndex = uiWndIndex % 2;
		//横向索引 = 窗体索引 / 2  如 ： 3/2 = 1
		uiRowIndex = uiWndIndex / 2;

		//窗体宽 =  （窗体总宽 - 间隔大小） / 2
		siWndWidth = (m_siWndWidth - m_siWndSpace) / 2;
		//窗体高 =  （窗体总高 - 间隔大小） / 2
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

		//当uiWndIndex=3时			窗体左边  +  （纵向索引(1)*(窗口宽+间隔))				- 横杠大小，  
		m_staLineBottom.MoveWindow(m_siWndLeft + (uiColIndex * (siWndWidth + m_siWndSpace)) - siPenWidth,
			m_siWndTop + (uiRowIndex * (siWndHeight + m_siWndSpace)) + siWndHeight,
			siWndWidth + siPenWidth,
			siPenWidth);
	}
	//九窗口
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
	//十六窗口
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

//设置当前激活视频窗口
void CDlgRealPlayPage::SetCurWndIndex(_UI uiWndIndex)
{
	m_uiCurWndIndex = uiWndIndex;

	MoveFrame();
}

//设置界面显示布局类型
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

//单窗口按钮事件
void CDlgRealPlayPage::OnBnClickedButtonWndOne()
{
	SetWndType(REALPLAY_WND_TYPE_ONE);
}
//二窗口按钮事件
void CDlgRealPlayPage::OnBnClickedButtonWndTwo()
{
	SetWndType(REALPLAY_WND_TYPE_TWO);
}

//四窗口按钮事件
void CDlgRealPlayPage::OnClickedButtonWndFour()
{
	SetWndType(REALPLAY_WND_TYPE_FOUR);
}

//九窗口按钮事件
void CDlgRealPlayPage::OnClickedButtonWndNine()
{
	SetWndType(REALPLAY_WND_TYPE_NINE);
}

//十六窗口按钮事件
void CDlgRealPlayPage::OnClickedButtonWndSixteen()
{
	SetWndType(REALPLAY_WND_TYPE_SIXTEEN);
}


//设置窗口全品事件
void CDlgRealPlayPage::SetFullScreen(BOOL bIsFull)
{

	//目前状态不为全屏
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


