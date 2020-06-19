#pragma once

#include "CameraSDK.H"

class CDHSdk : CCameraSDK
{
public:
	CDHSdk();
	~CDHSdk();

public:
	//登录
	 bool CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd=NULL);
	//登出
	 void CameraLogout();
	//开始播放
	 bool SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo);
	//停止播放
	 bool StopRealPlay();
	//获取当前播放信息
	 bool GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo);
	//获取摄像机参数
	 _UC GetCameraParam(void* pCameraParam);
	//设置摄像机参数
	 _UC SetCameraParam(void* pCameraParam);
	//重启摄像机
	 _UC RebootCamera();
};