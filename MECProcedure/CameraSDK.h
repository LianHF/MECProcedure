#ifndef __CAMERASDK_H__
#define __CAMERASDK_H__

//#pragma one


class CCameraSDK
{
public:
	CCameraSDK();
	~CCameraSDK();

public:
	//登录
	virtual bool CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd) = 0;
	//登出
	virtual void CameraLogout() = 0;
	//开始播放
	virtual bool SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo) = 0;
	//停止播放
	virtual bool StopRealPlay() = 0;
	//获取当前播放信息
	virtual bool GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo) = 0;
	//获取摄像机参数
	virtual _UC GetCameraParam(void* pCameraParam) = 0;
	//设置摄像机参数
	virtual _UC SetCameraParam(void* pCameraParam) = 0;
	//重启摄像机
	virtual _UC RebootCamera() = 0;

};


#endif