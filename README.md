# SKEye-Windows-SDK
SKEye-Windows-SDK for Object Recognition Service 
###  更新日志
v1.0.0
- 发布常见物体识别、水果识别功能
###  目录介绍
- libs:include包含的头文件,x64、x86下的lib、dll文件。
- SKEyeSDKDemo:物体识别的demo(main.cpp)、资源文件resources(包含demo的图片)。
- 说明文档(SKEye-WINDOWS-SDK说明文档V1.0.0.pdf)
###  使用步骤
- 下载SDK文件包。
- 将x64或x86下的lib、dll文件加载到vs工程下，并包含头文件"head.h"。
- 将资源文件resources下的图片放入对应的路径下。
- 运行代码。
<<<<<<< HEAD
- 更多使用介绍请参考 [《SKEye-Windows-SDK说明文档V1.0.0》](https://github.com/interjoy/SKEye-Windows-SDK/blob/master/SKEye-WINDOWS-SDK%E8%AF%B4%E6%98%8E%E6%96%87%E6%A1%A3V1.0.0.pdf)。
=======
- 更多使用介绍请参考 [《SKEye-Windows-SDK说明文档V1.0.0》](https://github.com/interjoy/SKEye-Windows-SDK/blob/master/SKEye-Windows-SDK%E8%AF%B4%E6%98%8E%E6%96%87%E6%A1%A3V1.0.0.pdf)。
>>>>>>> a6f339469f7992176b69ad4faa9119fd003d46cb
###  调用示例
```
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
void _JsonData(char *JsonData)
{
    printf("%s\n",JsonData);
}
char Api_Key[] = "123";
char Api_Secret[] = "456";
char Image_Url[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
char service_name[] = "objects";
char PATH[1024] = "object3.jpg";
char  *JsonData;
unsigned char *data = new unsigned char[640 * 480 * 3];
if (!ReadBmp("4.bmp", data)) //读取图片
{
	printf("Open is error\n");
	return 0;
}
SKEyeSDK_Init(Api_Key, Api_Secret);
//路径
JsonData = SKEyeSDK_ImagePath(PATH, service_name);
//URL
JsonData = SKEyeSDK_ImagePath(Image_Url, service_name);
//路径(回调)
SKEyeSDK_ImagePath(PATH, service_name, _JsonData);
//URL(回调)
SKEyeSDK_ImagePath(Image_Url, service_name, _JsonData);
//rgb 
JsonData = SKEyeSDK_Image(data, With, Height, service_name);
//rgb 回调
SKEyeSDK_Image(data, With, Height, service_name, _JsonData);
```
###  SDK问题反馈
- SKEye开放平台QQ群：617518775
