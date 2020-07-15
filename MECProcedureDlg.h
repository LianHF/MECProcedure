
// MECProcedureDlg.h : ͷ�ļ�
//

#pragma once
#include "DlgRealPlayPage.h"


// CMECProcedureDlg �Ի���
class CMECProcedureDlg : public CDialogEx
{
// ����
public:
	CMECProcedureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MECPROCEDURE_DIALOG };
protected:
	bool m_bInitOver;			//�жϽ����Ƿ��ʼ�����

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
	//��ȡ����汾����Ϣ
	bool ReadResourceInformation(CString &sVersionNum);
	void ShowDialogTitle();
	void InitView();

private:
	CDlgRealPlayPage* m_pDlgRealPlay;
	//���ڳ���
	_SI m_siDlgWidth;
	_SI m_siDlgHeight;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
