#include <iostream>
// 引入播放mp3音乐所需的头文件
#include <Windows.h>
#include <mmsystem.h>
// 引入Winmm播放库
#pragma comment(lib, "WINMM.lib")

using namespace std;

int main()
{
    // 向mci设备发送一段字符串指令
    // 打开音乐文件
    // 易错点：需要将mp3文件复制到当前项目的根目录下   "alias" 起别名    前面"L"表示支持长字节也就是Unicode编码的字符串 
    mciSendString(L"open 许嵩-有何不可.mp3 alias sound1", NULL, 0, NULL);
    // 播放音乐    repeat 代表重复播放
    mciSendString(L"play sound1 repeat", NULL, 0, NULL);

    // 注意使用该方法要求：
    // 文件名不要有空格
    // 并且wav文件不是通过其他文件类型直接改过来的
    // PlaySound(TEXT("许嵩-有何不可.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    system("pause");

    return 0;
}