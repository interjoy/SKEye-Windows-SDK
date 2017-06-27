#include <iostream>
#include "LibFile.h"
#include <atlimage.h>
#include "ximage.h"
//ͼƬ����ص�����
void CallBackImageResultFunction(char *ImageResult)
{
	//������Ӵ���
	printf("%s\n", ImageResult);
}
//��ͼ��ת��BGR�����������ж���λ���ݸ�ʽ
int GetImageData(const char *ImagePath, unsigned char *&ImageData, unsigned int &ImageWidth, unsigned int &ImageHeight)
{
	CxImage Image;
	Image.Load(ImagePath);
	ImageWidth = Image.GetWidth();
	ImageHeight = Image.GetHeight();
	int ImageBMPSize = 0;
	unsigned char *ImageDataBuff = NULL;
	if (!Image.Encode(ImageDataBuff, ImageBMPSize, CXIMAGE_SUPPORT_BMP))
		return 0;
	ImageData = new unsigned char[ImageBMPSize];
	memcpy(ImageData, ImageDataBuff, ImageBMPSize);
	Image.FreeMemory(ImageDataBuff);
	return 1;
}
//ͼ��ʶ��ص�Demo
void ImageCallBackDemoFuntion()
{
	//Image�ı��ؾ���·��
	char ImageLocalPath[] = "4.bmp";
	char ServiceName[] = "objects";
	unsigned int ImageWidth, ImageHeight;
	unsigned char *ImageData = NULL;
	//�õ�������ͼƬ����ImageData
	if (!GetImageData(ImageLocalPath, ImageData, ImageWidth, ImageHeight))
	{
		printf("Get data failed\n");
		return;
	}
	SKEyeSDK_Image(ImageData, ImageWidth, ImageHeight, ServiceName, CallBackImageResultFunction);
	//��Ҫ�ⲿ�ͷ�
	delete[] ImageData;
}

//Url�ص�Demo
void UrlCallBackDemoFuntion()
{
	//ͼ��url
	char ImageUrl[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
	//������
	char ServiceName[] = "objects";
	SKEyeSDK_ImagePath(ImageUrl, ServiceName, CallBackImageResultFunction);
}
//����·���ص�Demo
void LocalCallBackDemoFuntion()
{
	//Image�ı��ؾ���·��
	char ImageLocalPath[] = "object3.jpg";
	//������
	char ServiceName[] = "objects";
	SKEyeSDK_ImagePath(ImageLocalPath, ServiceName, CallBackImageResultFunction);
}

//����·��Demo
void LocalDemoFuntion()
{
	//Image�ı��ؾ���·��
	char ImageLocalPath[] = "object3.jpg";
	//������
	char ServiceName[] = "objects";
	//ͼ��ʶ����
	char  *ImageResult = SKEyeSDK_ImagePath(ImageLocalPath, ServiceName);
	printf("%s\n", ImageResult);
}
//Url Demo
void UrlDemoFuntion()
{
	//ͼ��url
	char ImageUrl[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
	//������
	char ServiceName[] = "objects";
	//ͼƬʶ����
	char  *ImageResult =SKEyeSDK_ImagePath(ImageUrl, ServiceName);
	printf("%s\n", ImageResult);
}
//ͼ��ʶ��Demo
void ImageDemoFuntion()
{
	//Image�ı��ؾ���·��
	char ImageLocalPath[] = "4.bmp";
	char ServiceName[] = "objects";
	//ͼƬ������
	unsigned int ImageWidth, ImageHeight;
	unsigned char *ImageData = NULL;
	char *ImageResult = NULL;
	//�õ�������ͼƬ����ImageData
	GetImageData(ImageLocalPath, ImageData, ImageWidth, ImageHeight);
	ImageResult = SKEyeSDK_Image(ImageData, ImageWidth, ImageHeight, ServiceName);
	delete [] ImageData;
	printf("%s\n", ImageResult);
}
int main()
{
	//SKEyeSDK_Init()��ʼ������ֻ��ʼ��һ��(�������ʼ�����)  ��ApiKey��ApiSecret�����ʼ��������
	char ApiKey[] = "466da4221010f834191e2da500b4a23b";
	char ApiSecret[] = "ddc8bd498e7c29f929862ab7391a7b89";
	SKEyeSDK_Init(ApiKey, ApiSecret);
	//����·��Demo
	LocalDemoFuntion();
	//Url Demo
	UrlDemoFuntion();
	//ͼ��ʶ��Demo
	ImageDemoFuntion();
	//����·���ص�Demo
	LocalCallBackDemoFuntion();
	//Url�ص�Demo
	UrlCallBackDemoFuntion();
	//ͼ��ʶ��ص�Demo
	ImageCallBackDemoFuntion();
	system("pause");
	return 0;
}

