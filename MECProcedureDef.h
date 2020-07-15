#pragma once

//��󴰿���
#define MAX_REALPLAY_WND_NUM 16

//���ؽ��
typedef enum
{
	RESULT_SUCCESS=0,
	RESULT_FAIL = -1,
	RESULT_PARA_ERR = -2,
	RESULT_GET_ERR = -3,
	RESULT_SEND_MSG_FAIL = -4
}RESULT_START_ENUM;

//���Ŵ�����
typedef struct
{
	_UI uiWndIndex;
	HWND hCurWnd;
}REALPLAY_WND_INFO;

//�������
typedef enum
{
	REALPLAY_WND_TYPE_ONE = 1,//������
	REALPLAY_WND_TYPE_TWO = 2,//2����
	REALPLAY_WND_TYPE_FOUR = 4,//4����
	REALPLAY_WND_TYPE_NINE = 9,//9����
	REALPLAY_WND_TYPE_SIXTEEN = 16,//16����
}REALPLAY_WND_TYPE_ENUM;