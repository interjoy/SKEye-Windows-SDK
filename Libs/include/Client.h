#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//���ݳ�ʼ��
__declspec(dllexport) void SKEyeSDK_Init(char *ApiKey, char *ApiSecret);
//Url���� ͼƬ·������
__declspec(dllexport) char *SKEyeSDK_ImagePath(char *UrlOrLocalPath, char *ServiceName);
//ͼƬ+��+�߷���
__declspec(dllexport) char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName);


typedef void(*CallBackImageResult)(char *ImageResult);
//Url���� ͼƬ·������ �ص���ʽ
__declspec(dllexport) void SKEyeSDK_ImagePath(char *UrlOrLocalPath, char *ServiceName, CallBackImageResult ImageResult);
//ͼƬ+��+�߷��� �ص���ʽ
__declspec(dllexport) void SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName, CallBackImageResult ImageResult);
#endif