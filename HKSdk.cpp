#include "stdafx.h"
#include "HKSdk.h"

CHKSdk::CHKSdk()
{

}

CHKSdk::~CHKSdk()
{

}
//��¼ʹ�� �����˻�������
bool CHKSdk::CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd)
{
	return TRUE;
}
//��¼ʹ�� Ĭ���˻�������
bool CameraLogin(_UI uIPAddress,_UI uPort)
{
	return TRUE;
}
//�ǳ�
void CHKSdk::CameraLogout()
{

}
//��ʼ����
bool CHKSdk::SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo)
{
	return TRUE;
}
//ֹͣ����
bool CHKSdk::StopRealPlay()
{
	return TRUE;
}
//��ȡ��ǰ������Ϣ
bool CHKSdk::GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo)
{
	return TRUE;
}
//��ȡ���������
_UC CHKSdk::GetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//�������������
_UC CHKSdk::SetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//���������
_UC CHKSdk::RebootCamera()
{
	return RESULT_SUCCESS;
}