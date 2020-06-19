#ifndef __CAMERASDK_H__
#define __CAMERASDK_H__

//#pragma one


class CCameraSDK
{
public:
	CCameraSDK();
	~CCameraSDK();

public:
	//��¼
	virtual bool CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd) = 0;
	//�ǳ�
	virtual void CameraLogout() = 0;
	//��ʼ����
	virtual bool SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo) = 0;
	//ֹͣ����
	virtual bool StopRealPlay() = 0;
	//��ȡ��ǰ������Ϣ
	virtual bool GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo) = 0;
	//��ȡ���������
	virtual _UC GetCameraParam(void* pCameraParam) = 0;
	//�������������
	virtual _UC SetCameraParam(void* pCameraParam) = 0;
	//���������
	virtual _UC RebootCamera() = 0;

};


#endif