#pragma once

#include "CameraSDK.h"

class CHKSdk : CCameraSDK
{
public:
	CHKSdk();
	~CHKSdk();


public:
	//��¼
	bool CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd);
	bool CameraLogin(_UI uIPAddress,_UI uPort);
	//�ǳ�
	void CameraLogout();
	//��ʼ����
	bool SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo);
	//ֹͣ����
	bool StopRealPlay();
	//��ȡ��ǰ������Ϣ
	bool GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo);
	//��ȡ���������
	_UC GetCameraParam(void* pCameraParam);
	//�������������
	_UC SetCameraParam(void* pCameraParam);
	//���������
	_UC RebootCamera();
};