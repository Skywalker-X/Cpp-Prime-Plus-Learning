## 运算符重载
运算符函数的格式为
```c++
operator op ()
```
重载的运算符至少要有一个操作数是用户定义的类型

## 友元函数
友元函数的原型在类声明中，且原型声明前加关键字**friend**
```c++
friend Time operator*(double m, const Time & t);
```
友元函数不是成员函数，但是与成员函数的访问权限相同

函数定义不再需要关键字friend

友元函数的一个常见用法是**重载<<运算符**
例如
```c++
void operator<<(ostream & os, const Time & t)
{
    os<<t.hours<<" hours, "<<t.minutes<<" minutes";
}
```
这样的<<重载可以允许```cout<<trip```，但是不能连续输出
进一步修改后，重载函数为
```c++
ostream & operator<<(ostream & os, const Time & t)
{
    os<<t.hours<<" hours, "<<t.minutes<<" minutes";
    return os;
}
```