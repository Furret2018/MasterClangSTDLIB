// 获取当前的时间
// 先使用time()获取距离 1970年1月1日距离今天的秒数
// 使用localtime()将秒数转化为时间结构体struct tm形式，然后取得时分秒，星期几，年月日

// 参考： http://www.cplusplus.com/reference/ctime/localtime/

#include <stdio.h>
#include <time.h>
#include <math.h>


time_t nowsec;      // time_t本质是整形，目的是存储time()获得的秒数
struct tm nowtime;  // 结构体tm是一个含有9个整形的结构体，目的是接收localtime()的返回值 。 因为这个函数的返回值是一个指针，所以下面声明了一个指针pnow


int main(int argc, char *argv[])
{
    nowsec = time(NULL); //获得秒数 ，等价于 time(&nowsec);
    printf(" * time since 1970/01/01: %ld \n", nowsec);

    struct tm *pnow;
    pnow = localtime(&nowsec);      // 将秒数转化为结构体变量

    // 现在是在DEVC++中编译，可以通过
    // 如果在VS下面编译，就会遇到警告要用localtime_s()函数。
    // 使用localtime_s()的话，就会写成 localtime_s(pnow, &nowsec);
    // 这样就会遇到提示说指针在使用前没有赋值，那么可以声明结构体，再赋值：
    // struct tm nowtime = {0, 0, 0, 0, 0, 0, 0, 0, 0};  tm类型是一个含有9个int的结构体; 
    // 这样赋值很麻烦，可以使用memset函数： memset(&nowtime, 0, sizeof(nowtime));
    // localtime_s(&nowtime, &nowsec);

    int nowhour = pnow->tm_hour,
        nowmin = pnow->tm_min,
        nowsec = pnow->tm_sec;

    printf( " * 现在时间 : %02d:%02d:%02d \n", nowhour, nowmin, nowsec);
    printf( " * 今天日期 : %04d年%02d月%02d日 \n", 1900+pnow->tm_year, 1+ pnow->tm_mon, pnow->tm_mday);  // 因为tm结构体从1900年算，所以年份要加上1900；因为月份是0-11，所以月份要+1
    
    
    
    
    //  time库中函数的使用 
    printf(" 上面使用的是手动提取时间结构体内的各个成员。库中的转化函数asctime()可直接将时间结构体转化为人类可读的字符串 \n");
    
    char * now = asctime(pnow);
    printf(" * 现在的时间是 %s \n ", now);
    
    printf(" ctime()可以直接将秒数转化为人类可读的字符串 \n");
    
    
    time(&nowsec);          // 这里不能使用之前的nowsec的值。 因为未知的原因，nowsec的值似乎被改写了，所以这里需要重新获取秒数 
    now = ctime(&nowsec);
    printf(" * 现在的时间是 %s \n ", now);


    getchar();
    return 0;
}


/*
如果在VS下面编译有这样的报错：
To disable deprecation, use _CRT_SECURE_NO_WARNINGS.

方法1：
在CPP的开头加上#define _CRT_SECURE_NO_WARNINGS

方法2：
根据提示使用安全的函数 localtime_s();

*/
