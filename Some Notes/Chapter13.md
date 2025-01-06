## 公有继承

派生类对象包含基类对象
基类的公有成员成为派生类的公有成员
**基类的私有部分只能用过基类的公有和保护方法访问**
派生类对象存储了基类的数据成员，可以使用基类的方法

派生类需要自己的**构造函数**，派生类构造函数必须使用基类构造函数

基类的指针/引用可以不进行显式类型转换的情况下指向/引用派生类对象，反之不行
但基类指针/引用只能调用基类方法

## 多态公有继承

两个机制：
* 在派生类中重新定义基类的方法
* 使用虚方法

```virtual```只用于类声明的函数原型中，而不用于函数定义

构造函数不能是虚函数
友元函数不能是虚函数，因为友元不是类成员，只有成员才能是虚函数

一般要都使用**虚析构函数**，调用时，先调用派生类的析构函数，然后自动调用基类的析构函数

假设要同时管理两个类对象，其中一个是基类，另一个是派生类
不能使用同一个数组来保存，因为数组所有元素类型必须相同
但是，可以创建**指向基类的指针数组**，基类指针也可以指向派生类对象，这样可以使用一个数组来表示多种类型的对象

如果重新定义继承的方法，应与原来的原型完全相同
如果基类虚函数返回类型是基类引用或指针，则可以修改为派生类引用或指针 (返回类型协变)
如果基类虚函数声明被重载了，则应在派生类中定义所有的基类版本

继承控制关键字：**override**和**final**
* override：保证在派生类中声明的重载函数，与基类的虚函数有相同的签名；添加到派生类的虚函数后面
* final：阻止类的进一步派生 和 虚函数的进一步重写，添加在类名或虚函数的后面

访问控制：**protected**
基类可以将成员声明为protected，派生类成员可以直接访问基类的保护成员
对外部来说，protected与private类似，但对派生类而言，potected与public类似
建议最好使用private而不是protected

## 输出
```c++
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

format setFormat()
{
    //set up ###.## format
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
```

## 抽象基类

抽象基类 abstract base class，ABC

类声明中，在虚函数声明后加 **=0**，使虚函数成为纯虚函数
C++允许对纯虚函数进行定义
包含纯虚函数的类称为**抽象类**
不能创建抽象类的对象，抽象类只能作为基类来使用，其纯虚函数的实现由派生类给出

## 继承和动态内存分配

如果基类使用了new，派生类不使用，派生类会自动调用基类的相关函数

如果派生类使用了new，必须为派生类定义显示析构函数、复制构造函数、赋值运算符

派生类如何访问基类友元函数？
使用强制类型转换，以便匹配原型时能选择正确的函数
例如
```c++
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const baseDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
```