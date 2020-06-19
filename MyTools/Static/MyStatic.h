#pragma once

typedef char           _SC;
typedef short          _SS;
typedef signed int     _SI;
typedef long           _SL;
typedef unsigned char  _UC;
typedef unsigned short _US;
typedef unsigned long  _UL;
typedef unsigned long long _ULL;

#define STATIC_ALIGN_LEFT  0
#define STATIC_ALIGN_CENTE 1
#define STATIC_ALIGN_RIGHT 2


typedef enum
{
    STATIC_STYLE_INFO_NORMAL,//����
    STATIC_STYLE_INFO_LEFT,//��Ϣ�ұ�
    STATIC_STYLE_INFO_RIGHT,//��Ϣ���
    STATIC_STYLE_MSG,//��ʾ��Ϣ
    STATIC_STYLE_TITLE,//ҳ�����
    STATIC_STYLE_IMPERATIVE,//��Ҫ��
}STATIC_STYLE_ENUM;
// CMyStatic
#define WM_STATIC_MSG_DBLCLK (WM_USER + 15000) //���˫��
#define WM_STATIC_MSG_LCLK (WM_USER + 15001) //�������

class CMyStatic : public CStatic
{
    DECLARE_DYNAMIC(CMyStatic)

public:
    CMyStatic();
    virtual ~CMyStatic();

protected:
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnPaint();

public:
    void SetText(char *ascText);
    void SetText(char *ascText, BOOL bAlarm);
    void SetText(CString strText);
    void SetText(CString strText, BOOL bAlarm);
    CString GetCurText();
    void SetAlarm(BOOL bState);
    void SetBkColor(COLORREF colorBk);
    void SetTextSize(int siSize);
    void SetAlign(UINT uiAlign);
    void SetBkTransparent(BOOL bBkTransparent);
    void SetForeColor(COLORREF colorFore);
    void SetCurFont(HFONT hFont);
    void SetMultiline(); 
    void SetCurStyle(_UC ucStyle);
protected:
    CString m_strText;
    BOOL m_bAlarm;//�������ϣ������ú�ɫ������ɫ ���������趨������ɫ
    BOOL m_bBkTransparent;//����͸��
    COLORREF m_BkColor;
    COLORREF m_TextColor;
    int m_siTextSize;
    UINT m_uiAlign;//���뷽ʽ
    BOOL m_bFirst;
    BOOL m_bMultiline;
public:
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


