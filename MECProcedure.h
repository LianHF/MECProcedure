
// MECProcedure.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMECProcedureApp:
// �йش����ʵ�֣������ MECProcedure.cpp
//

class CMECProcedureApp : public CWinApp
{
public:
	CMECProcedureApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMECProcedureApp theApp;