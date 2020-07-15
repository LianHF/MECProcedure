#pragma once
#include "afxwin.h"
#include "DlgRealPlayWnd.h"


// CDlgRealPlayPage 对话框

class CDlgRealPlayPage : public CDialog
{
	DECLARE_DYNAMIC(CDlgRealPlayPage)

public:
	CDlgRealPlayPage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgRealPlayPage();

// 对话框数据
	enum { IDD = IDD_DIALOG_REALPLAY_PAGE };
private:
	//播放视频窗口
	CDlgRealPlayWnd* m_pDlgRealPlayWnd[MAX_REALPLAY_WND_NUM];

	_UI m_uiCurWndIndex;		//记录当前窗体
	_UI m_uiBeginWndIndex;		//记录开始位置
	_UC m_ucWndType;			//记录窗口类型（1、4、9、16）

	//布局
	_SI m_siDlgWidth;	//窗体总宽
	_SI m_siDlgHeight;	//窗体总高
	_SI m_siWndSpace;	//窗体间隔
	_SI m_siWndLeft;	//窗体左边
	_SI m_siWndTop;		//窗体顶部
	_SI m_siWndWidth;	//视频显示窗体总宽
	_SI m_siWndHeight;	//视频显示窗体总高

private:
	void CreateUI();
	void DeleteUI();
	void SetRealPlayWnd();		//设置窗口显示
	void MoveFrame();			//画边框
public:
	void InitView();			//初始化窗口视图
	void SetCurWndIndex(_UI uiWndIndex);		//设置当前窗口索引
	void SetWndType(_UC ucWndType);				//设置窗口类型（1、4、9、16）
	_UC  GetWndType();							//获取当前窗口布局类型
	void SetFullScreen(BOOL bIsFull);			//设置全屏事件
	int  GetWindowIndex();						//在视频窗口调用此函数，返回当前操作的是哪个窗口
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnWndOne;
	CButton m_btnWndFour;
	CButton m_btnWndNine;
	CButton m_btnWndSixteen;
	CMyStatic m_staLineTop;
	CMyStatic m_staLineBottom;
	CMyStatic m_staLineLeft;
	CMyStatic m_staLineRight;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonWndOne();
	afx_msg void OnClickedButtonWndFour();
	afx_msg void OnClickedButtonWndNine();
	afx_msg void OnClickedButtonWndSixteen();
	afx_msg void OnBnClickedButtonWndTwo();
	CButton m_btnWndTwo;
};
