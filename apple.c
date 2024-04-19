#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <mmsystem.h>
#include<time.h>
#pragma comment(lib, "WINMM.LIB")//
#pragma warning(disable : 4996)
static  void  SetPos(int  x, int  y)
{
    COORD  point = { x ,  y }; //光标要设置的位置x,y
    HANDLE  HOutput = GetStdHandle(STD_OUTPUT_HANDLE); //使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
    SetConsoleCursorPosition(HOutput, point); //设置光标位置
} 

int main()
{
    FILE* fp;//文件指针
    char buf[150], add[60], ai[5];//处理文件名的字符串
    int i = 1, delay = 33;//时间的一些常量
    clock_t stime = 0, ftime = 0;//时间变量

    while (i <= 6564)
    {
        if (i % 30 == 0)
        {
            delay = 43;
        }
        else
        {
            delay = 33;
        }

        strcpy(add, "E:/U-F/txt/a (");
        sprintf(ai, "%d", i);
        strcat(add, ai);
        strcat(add, ").txt");
        // 名字修改
        ftime = clock();
        if (ftime - stime >= delay)
        {
            fp = fopen(add, "r");//打印文本

            if (NULL == fp)
                printf("打开错误");
            else
            {
                while (fgets(buf, 150, fp))
                {
                    printf("%s", buf);
                }
                fclose(fp);
                SetPos(0, 0);
                i++;
                stime += delay;

            }
        }
    } 
}

