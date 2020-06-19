// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "btn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
	m_bOver = m_bSelected = m_bTracking = m_bFocus = FALSE;
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	
	CRect rect    =    lpDrawItemStruct->rcItem;
	CDC *pDC    =    CDC::FromHandle(lpDrawItemStruct->hDC);
	int nSaveDC    =    pDC->SaveDC();
	UINT state    =    lpDrawItemStruct->itemState;


	TCHAR strText[MAX_PATH + 1];
	::GetWindowText(m_hWnd, strText, MAX_PATH);

	
	//根据按钮的状态填充按钮的背景图片
	if(m_bFocus)
	{
		CDC dcCompatible;
		dcCompatible.CreateCompatibleDC(pDC);
		dcCompatible.SelectObject(&m_bitmap_Focus);
		pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, m_bmp_Focus.bmWidth, m_bmp_Focus.bmHeight,SRCCOPY);
	}
	else
	{
		if(m_bOver)
		{
			CDC dcCompatible;
			dcCompatible.CreateCompatibleDC(pDC);
			dcCompatible.SelectObject(&m_bitmap_NormalOver);
			pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, m_bmp_NormalOver.bmWidth, m_bmp_NormalOver.bmHeight,SRCCOPY);
		}
		else
		{
			CDC dcCompatible;
			dcCompatible.CreateCompatibleDC(pDC);
			dcCompatible.SelectObject(&m_bitmap_Normal);
			pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, m_bmp_Normal.bmWidth, m_bmp_Normal.bmHeight,SRCCOPY);
		}
	}
	
	//画小图标
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&m_Ico);
	pDC->StretchBlt(15, 9, m_IcoBmp.bmWidth, m_IcoBmp.bmHeight, &dcCompatible, 0, 0, m_IcoBmp.bmWidth, m_IcoBmp.bmHeight,SRCCOPY);


	//显示按钮的文本
	if (strText!=NULL)
	{
		CFont        vertFont;
		CFont        *pOldFont;        
		COLORREF    oldColor = pDC->GetTextColor();
		if(m_bFocus)
		{
			vertFont.CreateFont(17, 0, 0, 0, FW_BOLD,
				0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH, _T("Arial"));
			pOldFont = pDC->SelectObject(&vertFont);
			pDC->SetTextColor(RGB(0, 0, 0));  //文本颜色
		}
		else
		{
			vertFont.CreateFont(15, 0, 0, 0, FW_NORMAL,
				0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH, _T("Arial"));
			pOldFont = pDC->SelectObject(&vertFont);
			pDC->SetTextColor(RGB(255, 255, 255));  //文本颜色
		}

		pDC->SetBkMode(TRANSPARENT);
		pDC->TextOut(50, 15, strText);

		pDC->SetTextColor(oldColor);    
		pDC->SelectObject(pOldFont);
		vertFont.DeleteObject();
	}

	pDC->RestoreDC(nSaveDC);
}

void CMyButton::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	CButton::PreSubclassWindow();
	ModifyStyle(0, BS_OWNERDRAW);
}

void CMyButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bTracking = _TrackMouseEvent(&tme);
	}    

	CButton::OnMouseMove(nFlags, point);
}

LRESULT CMyButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	m_bOver            = FALSE;
	m_bTracking        = FALSE;
	InvalidateRect(NULL, FALSE);
	return 0;
}

LRESULT CMyButton::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	m_bOver            = TRUE;
	InvalidateRect(NULL);
	return 0;
}

void CMyButton::SetNormalBmp(UINT uIDResouce)
{
	m_bitmap_Normal.LoadBitmap(uIDResouce);
	m_bitmap_Normal.GetBitmap(&m_bmp_Normal);
}

void CMyButton::SetFocusBmp(UINT uIDResouce)
{
	m_bitmap_Focus.LoadBitmap(uIDResouce);
	m_bitmap_Focus.GetBitmap(&m_bmp_Focus);
}

void CMyButton::SetNormalOverBmp(UINT uIDResouce)
{
	m_bitmap_NormalOver.LoadBitmap(uIDResouce);
	m_bitmap_NormalOver.GetBitmap(&m_bmp_NormalOver);
}

void CMyButton::SetIco(UINT uIDResouce)
{
	m_Ico.LoadBitmap(uIDResouce);
	m_Ico.GetBitmap(&m_IcoBmp);
}

void CMyButton::SetActive(BOOL bActive)
{
	if(m_bFocus != bActive)
	{
		m_bFocus = bActive;
		Invalidate();
	}
}

BOOL CMyButton::GetActive()
{
	return m_bFocus;
}
