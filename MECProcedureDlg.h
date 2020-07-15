
// MECProcedureDlg.h : 头文件
//

#pragma once
#include "DlgRealPlayPage.h"


// CMECProcedureDlg 对话框
class CMECProcedureDlg : public CDialogEx
{
// 构造
public:
	CMECProcedureDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MECPROCEDURE_DIALOG };
protected:
	bool m_bInitOver;			//判断界面是否初始化完成

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
	//获取程序版本号信息
	bool ReadResourceInformation(CString &sVersionNum);
	void ShowDialogTitle();
	void InitView();

private:
	CDlgRealPlayPage* m_pDlgRealPlay;
	//窗口长宽
	_SI m_siDlgWidth;
	_SI m_siDlgHeight;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
