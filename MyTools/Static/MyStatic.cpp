// MyStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyStatic.h"

// CMyStatic

IMPLEMENT_DYNAMIC(CMyStatic, CStatic)

CMyStatic::CMyStatic()
{
	m_strText = _T("");
	m_bAlarm = FALSE;
	m_bBkTransparent = TRUE;//Ĭ��͸��
	m_BkColor = RGB(255, 255, 255);//��ɫ����
	//m_TextColor = RGB(0, 0, 0);//��ɫ����
	m_TextColor = RGB(16, 16, 64);//��ɫ����
	m_siTextSize = 20;
	m_uiAlign = STATIC_ALIGN_LEFT;
	m_bFirst = FALSE;
	m_bMultiline = FALSE;
}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CMyStatic ��Ϣ�������



void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()

	// ȡ��λ��
	CRect rect;
	GetClientRect(rect);

	//����
	CFont *pDlgFont = GetFont();
	CFont *pCurFont = dc.SelectObject(pDlgFont);

	//���ñ�����ɫ
	if(m_bBkTransparent)
	{
		//�ȸ���֮ǰ�ı���
		//    dc.FillSolidRect(rect, RGB(255, 255, 255));
		if(m_bFirst)
		{
			m_bFirst = FALSE;
			CWnd* pParent = GetParent();
			CRect rectParent;
			GetWindowRect(rectParent);
			pParent->ScreenToClient(rectParent);
			rect.DeflateRect(2, 2);
			pParent->InvalidateRect(rectParent, FALSE); 
		}
		dc.SetBkMode(TRANSPARENT);
	}
	else
	{        
		dc.FillSolidRect(rect, m_BkColor);
	}

	//����������ɫ
	if(m_bAlarm)//����
	{
		dc.SetTextColor(RGB(255, 0, 0)); 
	}
	else
	{
		dc.SetTextColor(m_TextColor);
	}

	//�ж��������
	if(m_strText.GetLength() == 0)
	{
		GetWindowText(m_strText);
	}
	//�������
	switch(m_uiAlign)
	{
	case STATIC_ALIGN_LEFT:
		if(m_bMultiline)
		{
			dc.DrawText(m_strText, rect, DT_LEFT | ES_MULTILINE | DT_VCENTER);
		}
		else
		{
			dc.DrawText(m_strText, rect, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
		}
		break;

	case STATIC_ALIGN_CENTE:
		if(m_bMultiline)
		{
			dc.DrawText(m_strText, rect, DT_CENTER | ES_MULTILINE | DT_VCENTER);
		}
		else
		{
			dc.DrawText(m_strText, rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		}
		break;

	case STATIC_ALIGN_RIGHT:
		if(m_bMultiline)
		{
			dc.DrawText(m_strText, rect, DT_RIGHT | ES_MULTILINE | DT_VCENTER);
		}
		else
		{
			dc.DrawText(m_strText, rect, DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
		}
		break;

	default:
		dc.DrawText(m_strText, rect, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
		break;
	}
	// �������
	dc.SelectObject(pCurFont);
}


void CMyStatic::SetText(char *ascText)
{
	CString strText(ascText);
	m_strText = strText;
	m_bFirst = TRUE;
	Invalidate();
}

void CMyStatic::SetText(char *ascText, BOOL bAlarm)
{
	CString strText(ascText);
	m_strText = strText;
	m_bAlarm = bAlarm;
	m_bFirst = TRUE;
	Invalidate();
}

CString CMyStatic::GetCurText()
{
	return m_strText;
}

void CMyStatic::SetText(CString strText)
{
	m_strText = strText;
	m_bFirst = TRUE;
	Invalidate();
}

void CMyStatic::SetText(CString strText, BOOL bAlarm)
{
	m_strText = strText;
	m_bAlarm = bAlarm;
	m_bFirst = TRUE;
	Invalidate();
}

void CMyStatic::SetAlarm(BOOL bAlarm)
{
	m_bAlarm = bAlarm;
}

void CMyStatic::SetForeColor(COLORREF colorFore)
{
	m_TextColor = colorFore;
	Invalidate();
}

void CMyStatic::SetCurFont(HFONT hFont)
{
	::SendMessage(m_hWnd, WM_SETFONT, (WPARAM)hFont, 1);
}

void CMyStatic::SetTextSize(int siSize)
{
	m_siTextSize = siSize;
}

void CMyStatic::SetAlign(UINT uiAlign)
{
	m_uiAlign = uiAlign;
}

void CMyStatic::SetBkColor(COLORREF colorBk)
{
	m_BkColor = colorBk;
	m_bFirst = TRUE;
	Invalidate();
}

//������ʾ
void CMyStatic::SetMultiline()
{
	m_bMultiline = TRUE;
}

void CMyStatic::SetBkTransparent(BOOL bBkTransparent)
{
	m_bBkTransparent = bBkTransparent;
}
void CMyStatic::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//SendMessage()
	_SI siDlgId = ::GetDlgCtrlID(this->m_hWnd);
	_SI siValue = _ttoi(m_strText);
	GetParent()->SendMessage(WM_STATIC_MSG_DBLCLK, siDlgId, siValue);

	CStatic::OnLButtonDblClk(nFlags, point);
}

void CMyStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	_SI siDlgId = ::GetDlgCtrlID(this->m_hWnd);
	_SI siValue = _ttoi(m_strText);
	GetParent()->SendMessage(WM_STATIC_MSG_LCLK, siDlgId, siValue);

	CStatic::OnLButtonDown(nFlags, point);
}

void CMyStatic::SetCurStyle(_UC ucStyle)
{
	HFONT hFont;

	switch(ucStyle)
	{
	case STATIC_STYLE_INFO_NORMAL:
		hFont = CreateFont(20, 0, 0, 0, FW_NORMAL,FALSE, FALSE, FALSE,ANSI_CHARSET,OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,_T("����"));
		SetCurFont(hFont);
		SetAlign(STATIC_ALIGN_CENTE);
		SetForeColor(RGB(0, 0, 64));
		break;
	case STATIC_STYLE_INFO_LEFT:
		hFont = CreateFont(20, 0, 0, 0, FW_NORMAL,FALSE, FALSE, FALSE,ANSI_CHARSET,OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,_T("����"));
		SetCurFont(hFont);
		SetAlign(STATIC_ALIGN_RIGHT);
		SetForeColor(RGB(0, 0, 64));
		break;
	case STATIC_STYLE_INFO_RIGHT:
		hFont = CreateFont(20, 0, 0, 0, FW_NORMAL,FALSE, FALSE, FALSE,ANSI_CHARSET,OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,_T("����"));
		SetCurFont(hFont);
		SetAlign(STATIC_ALIGN_LEFT);
		SetForeColor(RGB(0, 64, 0));
		break;
	case STATIC_STYLE_MSG:
		hFont = CreateFont(24, 0, 0, 0, FW_EXTRABOLD,FALSE, FALSE, FALSE,ANSI_CHARSET,OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,_T("����"));
		SetCurFont(hFont);
		SetAlign(STATIC_ALIGN_CENTE);
		SetForeColor(RGB(34, 177, 76));
		break;
	case STATIC_STYLE_TITLE:
		hFont = CreateFont(38, 0, 0, 0, FW_EXTRABOLD,FALSE, FALSE, FALSE,ANSI_CHARSET,OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,_T("����"));
		SetCurFont(hFont);
		SetAlign(STATIC_ALIGN_CENTE);
		SetForeColor(RGB(0, 162, 232));
		break;
	case STATIC_STYLE_IMPERATIVE:
		hFont = CreateFont(22, 0, 0, 0, FW_NORMAL,FALSE, FALSE, FALSE,ANSI_CHARSET,OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,_T("����"));
		SetCurFont(hFont);
		SetAlign(STATIC_ALIGN_LEFT);
		SetForeColor(RGB(0, 64, 32));
		break;
	default:
		break;
	}
}