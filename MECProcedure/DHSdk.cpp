#include "stdafx.h"
#include "DHSdk.h"

CDHSdk::CDHSdk()
{

}

CDHSdk::~CDHSdk()
{

}
//��¼
bool CDHSdk::CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd)
{
	return TRUE;
}
//�ǳ�
void CDHSdk::CameraLogout()
{

}
//��ʼ����
bool CDHSdk::SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo)
{
	return TRUE;
}
//ֹͣ����
bool CDHSdk::StopRealPlay()
{
	return TRUE;
}
//��ȡ��ǰ������Ϣ
bool CDHSdk::GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo)
{
	return TRUE;
}
//��ȡ���������
_UC CDHSdk::GetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//�������������
_UC CDHSdk::SetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//���������
_UC CDHSdk::RebootCamera()
{
	return RESULT_SUCCESS;
}