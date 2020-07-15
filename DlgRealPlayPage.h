#pragma once
#include "afxwin.h"
#include "DlgRealPlayWnd.h"


// CDlgRealPlayPage �Ի���

class CDlgRealPlayPage : public CDialog
{
	DECLARE_DYNAMIC(CDlgRealPlayPage)

public:
	CDlgRealPlayPage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgRealPlayPage();

// �Ի�������
	enum { IDD = IDD_DIALOG_REALPLAY_PAGE };
private:
	//������Ƶ����
	CDlgRealPlayWnd* m_pDlgRealPlayWnd[MAX_REALPLAY_WND_NUM];

	_UI m_uiCurWndIndex;		//��¼��ǰ����
	_UI m_uiBeginWndIndex;		//��¼��ʼλ��
	_UC m_ucWndType;			//��¼�������ͣ�1��4��9��16��

	//����
	_SI m_siDlgWidth;	//�����ܿ�
	_SI m_siDlgHeight;	//�����ܸ�
	_SI m_siWndSpace;	//������
	_SI m_siWndLeft;	//�������
	_SI m_siWndTop;		//���嶥��
	_SI m_siWndWidth;	//��Ƶ��ʾ�����ܿ�
	_SI m_siWndHeight;	//��Ƶ��ʾ�����ܸ�

private:
	void CreateUI();
	void DeleteUI();
	void SetRealPlayWnd();		//���ô�����ʾ
	void MoveFrame();			//���߿�
public:
	void InitView();			//��ʼ��������ͼ
	void SetCurWndIndex(_UI uiWndIndex);		//���õ�ǰ��������
	void SetWndType(_UC ucWndType);				//���ô������ͣ�1��4��9��16��
	_UC  GetWndType();							//��ȡ��ǰ���ڲ�������
	void SetFullScreen(BOOL bIsFull);			//����ȫ���¼�
	int  GetWindowIndex();						//����Ƶ���ڵ��ô˺��������ص�ǰ���������ĸ�����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
