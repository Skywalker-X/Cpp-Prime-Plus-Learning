## 静态类成员函数

可以将成员函数声明为静态，声明包含关键字**static**
不能通过对象调用静态成员函数，静态成员函数不能使用this指针，只能使用静态数据成员
例如
```c++
static int HowMany() {return num_strings; }
```
调用方式为
```c++
int count = StringClass::Howmany();
```

## new

在构造函数中使用new时应注意：

析构函数需要使用delete

new和delete必须相互酱肉

多个构造函数必须以相同的放视使用new

应定义一个**复制构造函数**，通过深度赋值将一个对象初始化为另一个对象，例如：
```c++
String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new chhar [len+1];
    std::strcpy(str, st.str);
}
```

还应当定义一个**赋值运算符**，通过深度复制将一个对象复制给另一个对象，例如：
```c++
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete str [];
    len = st.len;
    str = new chhar [len+1];
    std::strcpy(str, st.str);
}
```

**复制数据而不仅仅是数据的地址**

## 成员初始化列表
成员初始化列表的语法实例：
```c++
Classy::Classy(int n, int m) : mem1(n), mem2(0), mem3(m*n+2)
{
//...
}
```

* 成员初始化列表只能用于**构造函数**
* 对于**const类成员**和**被声明为引用**的类成员，必须使用成员初始化列表
* 对于本身就是类对象的成员来说，使用成员初始化列表的效率更高