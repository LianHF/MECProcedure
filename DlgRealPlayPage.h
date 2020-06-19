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

	//布局
	_SI m_siDlgWidth;
	_SI m_siDlgHeight;
	_SI m_siWndSpace;
	_SI m_siWndLeft;
	_SI m_siWndTop;
	_SI m_siWndWidth;
	_SI m_siWndHeight;
private:
	void CreateUI();
	void DeleteUI();
	void InitView();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnWndOne;
	CButton m_btnWndFour;
	CButton m_btnWndNine;
	CButton m_btnWndSixteen;
	CMyStatic m_staLineTop;
	CMyStatic m_staLineDown;
	CMyStatic m_staLineLeft;
	CMyStatic m_staLineRight;
};
