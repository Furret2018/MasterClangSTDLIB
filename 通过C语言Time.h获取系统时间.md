# 通过C语言Time.h获取系统时间

time.h中有2个类型  具体参考 [c++手册] （http://www.cplusplus.com/reference/ctime/localtime/）

## 数据结构
### time_t
实际上是long

### struct tm
这是一个含有9个字段的结构体    
其中关于day的有两个      
mday表示一个月中的哪一天，1表示第一天    
wday表示一星期中的哪一天，0表示星期天， 1表示周一    


## 函数
### time(0) 
参数: 是一个time_t的指针，会把指针指向的那个long用timestamp填充。其实和返回值一样。    
返回: 当前的时间， 其实是timestamp， 即距离1970-1-1 的秒数。 LinuxShell (date +%s)可以得到timestamp       
### ctime(time_t \*p)
作用： 将传入的time_t指针 变成 人可读的时间、日期字符串
参数： 一个time_t的指针变量
返回： char型指针

注意： 如果传入的是时间戳，那么算出来的就已经是本地计算机时区对应的时间了。这个是最快得到本地时间的方法。

### localtime(time_t \*p)
作用: 将传入的time_t指针 转换成struct tm输出

注意： 这里如果传入的是时间戳，那么得到的年份需要+1900才是真实的年份


### gmtime(time_t \*p)
作用： 将传入的time_t指针 转换成GMT+0时间的人可读的字符串

注意： 如果传入的是时间戳，这里年份要+1900， 小时数hour 要+对应时区的时数才是本地正确时间，比如GMT+8是中国时间




### asctime()
将传入的struct tm指针变成人可读的日期字符串

注意这个函数比较特别:
time - localtime - asctime 就可以得到正确的时间了 ✔
也就是说，asctime会自动为localtime的tm_year加上1900，不需要我们处理了。












