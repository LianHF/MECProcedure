#pragma once

#include "MyStatic.h"
// CDlgRealPlayWnd �Ի���

class CDlgRealPlayWnd : public CDialog
{
	DECLARE_DYNAMIC(CDlgRealPlayWnd)

public:
	CDlgRealPlayWnd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgRealPlayWnd();

// �Ի�������
	enum { IDD = IDD_DIALOG_REALPLA_WND };
private:
	//���ں�
	_UI m_uiWndIndex;
public:
	void SetWndIndex(_UI uiWndIndex);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
