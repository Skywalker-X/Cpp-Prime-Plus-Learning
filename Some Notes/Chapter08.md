## 内联函数
函数声明和定义前加上关键字```inline```
编译器使用相应的函数代码替换函数调用
提高程序运行速度
```c++
inline double square(double x) {return x*x;}
```

## 引用
创建引用变量 **&**
```c++
int rats;
int & rodents = rats;
```
rats和rodents可以呼唤，指向相同的值和内存单元
必须再声明引用变量时进行初始化

## 默认参数
可以为函数的参数设置默认值
对于带参数列表的函数，必须**从右向左**添加默认值
实参按照从左到右的顺序依次被赋给相应的形参，而不能跳过任何参数

只需要在函数原型(声明)地方添加默认值，函数定义部分不需要

## 函数重载
函数的参数列表也被成为函数特征标 function signature
可以定义名称相同的函数，特征标不同

类型引用和类型本身被视为是同一个特征标

匹配函数时，不区分const和非const变量

## 函数模板
```c++
template<typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
```
也可以对函数模板进行重载

## 显式具体化
对于给定的函数名，可以有非模板函数、模板函数和显式具体化模板函数以及他们的重载版本
显示具体化的原型和定义以```template<>```打头，并通过名称来指定类型

例如，有一个job结构，下面是用于交换job结构的非模板函数、模板函数和具体化的原型：
```c++
void Swap(job &, job &);

template <typename T>
void Swap(T &, T &);

template <> void Swap<job> (job &, job &);
```

## decltype
```c++
int x;
decltype (x) y; \\ make y the same type as x
```
也可用于模板函数
```C++
template <class T1, class T2>
void ft(T1 x, T2 y)
{
    ...
    decltype(x+y) xpy = x + y;
    ...
}
```