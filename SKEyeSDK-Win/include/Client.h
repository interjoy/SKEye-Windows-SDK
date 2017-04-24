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
__declspec(dllexport) void SKEyeSDK_Init(char *_Api_Key, char *_Api_Secret);
//Url���� ͼƬ·������
__declspec(dllexport) char *SKEyeSDK_ImagePath(char *UrlOrPath, char *service_name);
//ͼƬ+��+�߷���
__declspec(dllexport) char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_name);



typedef void (*CallBackJson)(char *JsonData);
//Url���� ͼƬ·������ �ص���ʽ
__declspec(dllexport) void SKEyeSDK_ImagePath(char *Url, char *service_name, CallBackJson _CallBackJson);
//ͼƬ+��+�߷��� �ص���ʽ
__declspec(dllexport) void SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_name, CallBackJson _CallBackJson);
#endif