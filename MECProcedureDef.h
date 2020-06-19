#pragma once

//最大窗口数
#define MAX_REALPLAY_WND_NUM 16

//返回结果
typedef enum
{
	RESULT_SUCCESS=0,
	RESULT_FAIL = -1,
	RESULT_PARA_ERR = -2,
	RESULT_GET_ERR = -3,
	RESULT_SEND_MSG_FAIL = -4
}RESULT_START_ENUM;

//播放窗体句柄
typedef struct
{
	_UI uiWndIndex;
	HWND hCurWnd;
}REALPLAY_WND_INFO;

//界面参数
typedef enum
{
	REALPLAY_WND_TYPE_ONE = 1,//单画面
	REALPLAY_WND_TYPE_FOUR = 4,//4画面
	REALPLAY_WND_TYPE_NINE = 9,//9画面
	REALPLAY_WND_TYPE_SIXTEEN = 16,//16画面
}REALPLAY_WND_TYPE_ENUM;