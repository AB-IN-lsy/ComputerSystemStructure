/*
 * @Author: NEFU AB-IN
 * @Date: 2022-11-10 10:19:35
 * @FilePath: \undefinedc:\Users\liusy\Desktop\for_asm_s.c
 * @LastEditTime: 2022-11-10 10:20:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    float a[200000];
    int i = 0;
    int x = 4, c, len = 200000;
    int ans;
    int duration;
    clock_t start, finish;

    for (i = 0; i < 200000; i++)
    {
        a[i] = 5;
    }
    start = clock();
    __asm__("li.s $f2, 10.0\n"
            "Loop: \n"
            "lwc1 $f0, 0(%[a])\n"
            "add.s $f0, $f0, $f2\n"
            "swc1 $f0, 0(%[a])\n"
            "addiu %[a], 4 \n"
            "addiu %[ans], 0 \n"
            "addiu %[len], -1\n"
            "bne %[len], $0, Loop\n"
            : [ans] "=r"(ans)
            : [a] "r"(a), [len] "r"(len));
    finish = clock();
    duration = (int)(finish - start) * 1000;
    printf("the clock time is: %d\n", duration);
}