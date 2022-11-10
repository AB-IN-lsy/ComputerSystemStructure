/*
 * @Author: NEFU AB-IN
 * @Date: 2022-11-10 10:18:39
 * @FilePath: \undefinedc:\Users\liusy\Desktop\for.c
 * @LastEditTime: 2022-11-10 10:19:16
 */
/* for.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    float a[200000];
    int i = 0;
    int duration;
    clock_t start, finish;
    start = clock();
    for (i = 0; i < 200000; i++)
    {
        a[i] = 5.0;
    }
    for (i = 0; i < 200000; i++)
    {
        a[i] = a[i] + 10.0;
    }
    finish = clock();
    duration = (int)(finish - start) * 1000;
    printf("the clock time is: %d\n", duration);
    return 0;
}