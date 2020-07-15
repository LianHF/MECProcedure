#pragma once

#include "MyStatic.h"
#include "afxwin.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
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
	CBrush m_Brush;
	BOOL m_bFullScreen;			//ȫ����־
	CRect m_OldRect;			//��¼�ʹ��ڴ�С
	Mat img[16];

protected:
	CWnd * m_pParent;
protected:
	void SetCurWndIndex();
public:
	void SetWndIndex(_UI uiWndIndex);
	void SetRectRange(_UI uiLeft,_UI  uiTop,_UI uiWide,_UI uiHeight);
	void InitView();


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnStop;
	CStatic m_staPlayWnd;
	CMyStatic m_staInfo;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnStnDblclickStaticPlayWnd();
	afx_msg void OnBnClickedButtonStop();
};
