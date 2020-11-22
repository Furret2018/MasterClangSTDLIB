// 获取程序运行消耗的时间
// 在程序开始的时间计时， 在结束的时候计时，两者相减
// 计时是打点计时，所以要除以CLOCKS_PER_SECONDS, 算出运行的秒数
// 用到time库中定义的变量类型clock_t ，这个本质就是long型数据，所以输出其值时，推荐用%lld
// 用到的函数是clock() ，即获得当前打点数

#include <stdio.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
    clock_t tick1, tick2;  //
    tick1 = clock();            // 开始打点

    // CODE START.................

    unsigned int MAX = pow(2, 14);
    int cnt =0;
    for(;;) if (cnt<MAX) printf("."), cnt++;
        else {
            printf(" \n * %08XH Game OVER \n", cnt);    // 消耗一些时间
            break;
        }


    // CODE END ...................

    tick2 = clock();   // 再次打点
    clock_t delta = tick2- tick1;      // 打点差
    float consumedtime = (float)delta/CLOCKS_PER_SEC;        // 换算成时间
    printf(" * The APP consumed time %f \n", consumedtime);

    getchar();
    return 0;
}
