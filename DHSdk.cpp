#include "stdafx.h"
#include "DHSdk.h"

CDHSdk::CDHSdk()
{

}

CDHSdk::~CDHSdk()
{

}
//登录
bool CDHSdk::CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd)
{
	return TRUE;
}
//登出
void CDHSdk::CameraLogout()
{

}
//开始播放
bool CDHSdk::SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo)
{
	return TRUE;
}
//停止播放
bool CDHSdk::StopRealPlay()
{
	return TRUE;
}
//获取当前播放信息
bool CDHSdk::GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo)
{
	return TRUE;
}
//获取摄像机参数
_UC CDHSdk::GetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//设置摄像机参数
_UC CDHSdk::SetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//重启摄像机
_UC CDHSdk::RebootCamera()
{
	return RESULT_SUCCESS;
}