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
__declspec(dllexport) void SKEyeSDK_Init(char *ApiKey, char *ApiSecret);
//Url访问 图片路径访问
__declspec(dllexport) char *SKEyeSDK_ImagePath(char *UrlOrLocalPath, char *ServiceName);
//图片+宽+高访问
__declspec(dllexport) char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName);


typedef void(*CallBackImageResult)(char *ImageResult);
//Url访问 图片路径访问 回调方式
__declspec(dllexport) void SKEyeSDK_ImagePath(char *UrlOrLocalPath, char *ServiceName, CallBackImageResult ImageResult);
//图片+宽+高访问 回调方式
__declspec(dllexport) void SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName, CallBackImageResult ImageResult);
#endif