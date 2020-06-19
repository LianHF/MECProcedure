#include "stdafx.h"
#include "HKSdk.h"

CHKSdk::CHKSdk()
{

}

CHKSdk::~CHKSdk()
{

}
//登录使用 传输账户和密码
bool CHKSdk::CameraLogin(_UI uIPAddress,_UI uPort,char* psUser,char* psPwd)
{
	return TRUE;
}
//登录使用 默认账户和密码
bool CameraLogin(_UI uIPAddress,_UI uPort)
{
	return TRUE;
}
//登出
void CHKSdk::CameraLogout()
{

}
//开始播放
bool CHKSdk::SrartRealPlay(void* pCameraInfo,REALPLAY_WND_INFO*  pWndInfo)
{
	return TRUE;
}
//停止播放
bool CHKSdk::StopRealPlay()
{
	return TRUE;
}
//获取当前播放信息
bool CHKSdk::GetCurRealPlayInfo(void* pCameraInfo,REALPLAY_WND_INFO* pWndInfo)
{
	return TRUE;
}
//获取摄像机参数
_UC CHKSdk::GetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//设置摄像机参数
_UC CHKSdk::SetCameraParam(void* pCameraParam)
{
	return RESULT_SUCCESS;
}
//重启摄像机
_UC CHKSdk::RebootCamera()
{
	return RESULT_SUCCESS;
}