
// MECProcedureDlg.h : ͷ�ļ�
//

#pragma once


// CMECProcedureDlg �Ի���
class CMECProcedureDlg : public CDialogEx
{
// ����
public:
	CMECProcedureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MECPROCEDURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
	//��ȡ����汾����Ϣ
	bool ReadResourceInformation(CString &sVersionNum);
	void ShowDialogTitle();


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
