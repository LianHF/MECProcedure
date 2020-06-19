#if !defined(AFX_MYBUTTON_H__BCA30D3C_952E_4439_9632_3E230D954705__INCLUDED_)
#define AFX_MYBUTTON_H__BCA30D3C_952E_4439_9632_3E230D954705__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyButton window

class CMyButton : public CButton
{
	// Construction
public:
	CMyButton();

	// Attributes
public:

	// Operations
public:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyButton)
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

	// Implementation
public:
	virtual ~CMyButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:

	//��ť��״̬
	BOOL m_bOver;                //���λ�ڰ�ť֮��ʱ��ֵΪtrue����֮Ϊflase
	BOOL m_bTracking;            //����갴��û���ͷ�ʱ��ֵΪtrue
	BOOL m_bSelected;            //��ť�������Ǹ�ֵΪtrue
	BOOL m_bFocus;                //��ťΪ��ǰ��������ʱ��ֵΪtrue



	CBitmap m_bitmap_Normal;
	CBitmap m_bitmap_Focus;
	CBitmap m_bitmap_NormalOver;

	CBitmap m_Ico;

	BITMAP m_bmp_Normal;
	BITMAP m_bmp_Focus;
	BITMAP m_bmp_NormalOver;

	BITMAP m_IcoBmp;

public:
	void SetNormalBmp(UINT uIDResouce);
	void SetFocusBmp(UINT uIDResouce);
	void SetNormalOverBmp(UINT uIDResouce);
	void SetIco(UINT uIDResouce);

	void SetActive(BOOL bActive);
	BOOL GetActive();					
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTON_H__BCA30D3C_952E_4439_9632_3E230D954705__INCLUDED_)
