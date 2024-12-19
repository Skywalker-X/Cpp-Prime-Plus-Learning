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

当且仅当声明函数的形参时，这两个声明是等价的：
```c++
typename arr[]
typename *arr
```

## 函数指针
获取函数的地址：使用函数名（不跟参数）即可

声明函数指针：
```c++
double pam(int);
double (*pf)(int);
pf=pam;
```
pf就是函数指针，指向函数pam
也可以使用auto
```c++
auto pf = pam
```

一个把函数指针作为参数的函数实例：
```c++
void estimate(int lines, double (*pf)(int))
```

使用指针来调用函数，```pf```和```(*pf)```都可以

## 函数指针数组
有下面三个函数(这三个函数的特征标实际上是相同的)
```c++
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);
```
使用函数指针
```c++
const double * (*p1)(const double *, int) = f1;
auto p2 = f2;
```
使用函数指针数组
```c++
const double * (*pa[3])(const double *, int) = {f1, f2, f3};
```
不能使用auto，因为auto只能用于单值初始化，不能用于初始化列表
不过可以
```c++
auto pb = pa;
```