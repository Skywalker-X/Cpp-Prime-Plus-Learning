头文件中一般包含：
* 函数原型
* 使用#define或const定义的符号常量
* 结构声明
* 类声明
* 模板声明
* 内联函数

## 静态变量
* 无链接性：在代码块中，使用关键字static
* 外部链接性：不在任何函数内
* 内部链接性：不在任何函数内，使用关键字static

静态变量可以被修改，静态指的是存储方式
未被初始化的静态变量默认为0

在每个使用外部变量的文件中，都必须使用关键字**extern**进行声明

作用域解析符```::```，放在变量名前面时，表示使用变量的全局版本

也可以对函数使用static关键，使该函数只在这个文件中可见
还意味着可以在其他文件中定义同名函数

## 说明符和限定符

cv限定符：
* const
* volatile

volatile表明，即使程序代码没有对内存单元进行修改，其值也有可能发生变化
例如指向某个硬件位置的指针

mutable
mutable可以用俩指出，即使结构或类的变量为const，其某个成员也可以被修改

## new
通常new会在堆(heap)中寻找内存进行分配

new还有一种变体 定位new运算符，能够指定要使用的位置
需要包含头文件```#include<new>```
```c++
#include<new>

struct chaff
{
    char dross[20];
    int slag;
};

char buffer1[50];
char buffer2[100];

int main()
{
    chaff*p1;
    int *p2;
    
    p1 = new (buffer1) chaff;
    p2 = new (buffer2) int[20];
    ......
}
```

## 名称空间