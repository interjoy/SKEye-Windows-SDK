#include <iostream>
#include "Head.h"
void _JsonData(char *JsonData)
{
	printf("%s\n", JsonData);
}
bool ReadBmp(char *filename, unsigned char *data)
{
	FILE *fp;
	fp = fopen(filename, "rb");
	if (fp == NULL) return false;
	fseek(fp, 54, SEEK_SET);
	int rlen = fread(data, 1, 640 * 480 * 3, fp);
	if (rlen != 640 * 480 * 3) return false;
	fclose(fp);
	return true;
}
void SKEyeSDK_ImagePath_Function(char *PATH, char *service_name)
{
	char  *JsonData;
	JsonData = SKEyeSDK_ImagePath(PATH, service_name);
	printf("%s\n", JsonData);
}
void SKEyeSDK_ImagePath_CallBackFunction(char *PATH, char *service_name)
{
	SKEyeSDK_ImagePath(PATH, service_name, _JsonData);
}
void SKEyeSDK_Image_Function(int With, int Height, char *service_name)
{
	unsigned char *data = new unsigned char[640 * 480 * 3];
	char *JsonData;
	if (!ReadBmp("4.bmp", data)) //∂¡»°Õº∆¨
	{
		printf("Open is error\n");
		return ;
	}
	JsonData = SKEyeSDK_Image(data, With, Height, service_name);
	printf("%s\n", JsonData);
}
void SKEyeSDK_Image_CallBackFunction(int With, int Height, char *service_name)
{
	unsigned char *data = new unsigned char[640 * 480 * 3];
	char *JsonData;
	if (!ReadBmp("4.bmp", data)) //∂¡»°Õº∆¨
	{
		printf("Open is error\n");
		return;
	}
	SKEyeSDK_Image(data, With, Height, service_name, _JsonData);
}
int main()
{
	char Api_Key[] = "942f4dea3b45def10552360de80dd17a";
	char Api_Secret[] = "282e42c53058b0b08253e60cad0746c2";
	char Image_Url[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
	char service_name[] = "objects";
	char PATH[1024] = "object3.jpg";
	SKEyeSDK_Init(Api_Key, Api_Secret);
	SKEyeSDK_ImagePath_Function(PATH, service_name);
	SKEyeSDK_ImagePath_CallBackFunction(PATH, service_name);
	SKEyeSDK_Image_Function( 640, 480, service_name);
	SKEyeSDK_Image_CallBackFunction(640, 480, service_name);
	system("pause");
	return 0;
}

