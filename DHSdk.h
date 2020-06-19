#pragma once

#include "CameraSDK.H"

class CDHSdk : CCameraSDK
{
public:
	CDHSdk();
	~CDHSdk();

public:
	//��¼
	 bool CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd=NULL);
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