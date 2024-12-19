## function
处理数组的函数，如果需要修改数组
```c++
void function(double ar[], int n);
```
如果不修改数组
```c++
void function(const double ar[], int n);
```

处理数组的函数需要数组中的数据种类、数组起始位置和数组中元素数量
或者可以指定元素区间，给函数传递两个指针：数组的开头和尾部
例如对于```double elb[20]```来说，指针```elb```和```elb+20```定义了区间

## 函数指针
获取函数的地址：使用函数名（不跟参数）即可

声明函数指针：
```c++
double pam(int);
double (*pf)(int);
pf=pam;
```
pf就是函数指针，指向函数pam

一个把函数指针作为参数的函数实例：
```c++
void estimate(int lines, double (*pf)(int))
```

使用指针来调用函数，```pf```和```*pf```都可以
