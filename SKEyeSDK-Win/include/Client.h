#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//数据初始化
__declspec(dllexport) void SKEyeSDK_Init(char *_Api_Key, char *_Api_Secret);
//Url访问 图片路径访问
__declspec(dllexport) char *SKEyeSDK_ImagePath(char *UrlOrPath, char *service_group);
//图片+宽+高访问
__declspec(dllexport) char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_group);



typedef void (*CallBackJson)(char *JsonData);
//Url访问 图片路径访问 回调方式
__declspec(dllexport) void SKEyeSDK_ImagePath(char *Url, char *service_group, CallBackJson _CallBackJson);
//图片+宽+高访问 回调方式
__declspec(dllexport) void SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_group, CallBackJson _CallBackJson);
#endif