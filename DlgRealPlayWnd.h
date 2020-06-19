#pragma once

#include "MyStatic.h"
// CDlgRealPlayWnd 对话框

class CDlgRealPlayWnd : public CDialog
{
	DECLARE_DYNAMIC(CDlgRealPlayWnd)

public:
	CDlgRealPlayWnd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgRealPlayWnd();

// 对话框数据
	enum { IDD = IDD_DIALOG_REALPLA_WND };
private:
	//窗口号
	_UI m_uiWndIndex;
public:
	void SetWndIndex(_UI uiWndIndex);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
