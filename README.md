# SKEye-Windows-SDK
SKEye-Windows-SDK for Object Recognition Service 
###  更新日志
v1.0.0
- 发布常见物体识别、水果识别功能
###  目录介绍
- libs:include包含的头文件,x64、x86下的lib、dll文件。
- SKEyeSDKDemo:物体识别的demo(main.cpp)、资源文件resources(包含demo的图片)。
- 说明文档(SKEye-WINDOWS-SDK说明文档V1.0.0.pdf)
###  调用示例
```
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
SKEyeSDK_Init(Api_Key, Api_Secret);
//URL/路径
JsonData = SKEyeSDK_ImagePath(PATH, service_name);
//URL/路径(回调)
SKEyeSDK_ImagePath(PATH, service_name, _JsonData);
//rgb 
JsonData = SKEyeSDK_Image(data, With, Height, service_name);
//rgb 回调
SKEyeSDK_Image(data, With, Height, service_name, _JsonData);
```
###  SDK问题反馈
- SKEye开放平台用户群：617518775
