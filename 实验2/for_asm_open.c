/*
 * @Author: NEFU AB-IN
 * @Date: 2022-11-10 10:20:19
 * @FilePath: \undefinedd:\Code\Course\ComputerSystemStructure\实验报告\实验2\for_asm_open.c
 * @LastEditTime: 2022-11-10 14:11:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    float a[200000]; // 定义数组变量
    int i = 0;
    int c, len = 200000;
    int ans;
    int duration;
    clock_t start, finish; // 定义时间变量

    for (i = 0; i < 200000; i++)
    {
        a[i] = 5.0;
    }
    start = clock(); // 开始计时
    int iter = 20;
    for (i = 0; i < iter; i++)
    {

        __asm__("li.s $f2, 10.0\n\t" // 采用指令 li.s 对 f2 进行赋值，并赋值为 10.0（随便赋值的），在整数类型里面
                                     // 是用 li 来赋值，浮点数类型则使用 li.s。
                "Loop: \n\t" // 设置循环
                "lwc1 $f0,0(%[a])\n\t" // 这一句话是把值赋予给 f0；这里的 a 用于外部参数输入，用%表示；0(%[a])
                // 指的是对 a 这个外部参数偏移 0 个字节
                "lwc1 $f6,4(%[a])\n\t" // 这一句话是把值赋予给 f6；这里的 a 用于外部参数输入，用%表示；4(%[a])
                // 指的是对 a 这个外部参数偏移 4 个字节
                "lwc1 $f10,8(%[a])\n" // 这一句话是把值赋予给 f10；这里的 a 用于外部参数输入，用%表示；8(%[a])
                // 指的是对 a 这个外部参数偏移 8 个字节
                "lwc1 $f14,12(%[a])\n" // 这一句话是把值赋予给f14；这里的a用于外部参数输入，用%表示；12(%[a])
                // 指的是对 a 这个外部参数偏移 12 个字节
                "add.s $f4,$f0,$f2\n"   // 这一句话是把 f0 和 f2 相加，并赋值给 f4
                "add.s $f8,$f6,$f2\n"   // 这一句话是把 f0 和 f2 相加，并赋值给 f8
                "add.s $f12,$f10,$f2\n" // 这一句话是把 f0 和 f2 相加，并赋值给 f12
                "add.s $f16,$f14,$f2\n" // 这一句话是把 f0 和 f2 相加，并赋值给 f16
                "swc1 $f4,0(%[a])\n"    // 保存结果
                "swc1 $f8,4(%[a])\n"    // 保存结果
                "swc1 $f12,8(%[a])\n"   // 保存结果
                "swc1 $f16,12(%[a])\n"  // 保存结果
                "addiu %[len],-4\n"     // 循环次数减 4，因为我们是做了 4 次循环展开
                "addiu %[a],16\n" // 指针偏移 16 位，因为我们 4 次循环展开，每个数有 4 个字节，4*4=16
                "bne %[len],$0,Loop\n" // 判断是否跳出循环
                : [ans] "=r"(ans) // 输出，这是 asm 编程需要的，这语句不能删除，但此程序不需要输出，所
                // 以这个 ans 没有实际含义
                : [a] "r"(a), [len] "r"(len) // 外部输入，把数组和数组长度传入
        );
    }
    finish = clock(); // 结束计时
    duration = (int)(finish - start) / iter;
    printf("the clock time is: %d\n", duration);
}