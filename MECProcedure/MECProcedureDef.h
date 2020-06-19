#pragma once


typedef enum
{
	RESULT_SUCCESS=0,
	RESULT_FAIL = -1,
	RESULT_PARA_ERR = -2,
	RESULT_GET_ERR = -3,
	RESULT_SEND_MSG_FAIL = -4
}RESULT_START_ENUM;

//²¥·Å´°Ìå¾ä±ú
typedef struct
{
	_UI uiWndIndex;
	HWND hCurWnd;
}REALPLAY_WND_INFO;