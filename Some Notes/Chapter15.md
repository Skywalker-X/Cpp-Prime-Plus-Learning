## 友元类

友元类可以访问原始类的私有成员和保护成员
例如声明Remote为友元类：
```c++
friend class Remote;
```
友元声明可以位于公有、私有或保护部分，其所在的位置无关紧要

## 友元成员函数

可以选择仅让特定的类成员成为另一个类的友元
需要注意声明和定义的顺序

例如，让```Remote::set_chan()```成为Tv类的友元：
```c++
class Tv; //forward declaration
class Remote {...}; //Tv-using methods as prototypes only
class Tv {...};
```
Remote类的定义应该放在Tv类之后

## 嵌套类

可以在类中再次声明一个类

如果嵌套类的声明位置在公有部分，可以在外部通过类限定符来使用

## 异常

头文件 ```#include<cstdlib>```

```abort()``` 终止程序

也可使用```try``` ```catch``` ```throw```
```c++
try
{
   // 保护代码
}catch( ExceptionName e1 )
{
   // catch 块
}catch( ExceptionName e2 )
{
   // catch 块
}catch( ExceptionName eN )
{
   // catch 块
}
```
catch 块跟在 try 块后面，用于捕获异常
用 throw 语句在代码块中的任何地方抛出异常。throw 语句的操作数可以是任意的表达式，表达式的结果的类型决定了抛出的异常的类型，例如
```c++
double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
```

如果有一个异常类继承层次结构，应这样排列catch块：
将捕获位于层次结构最下面的异常类的catch语句放在最前面
将捕获基类一场的catch语句放在最后面

exception头文件定义了exception类
```c++
#include<exception>
```
可以通过继承和重载 ```exception``` 类来定义新的异常

## RTTI

RTTI 是运行阶段类型识别 Runtime Type Iddentification
C++有三个支持RTTI的元素：```dynamic_cast``` ```typeid``` ```type_info```

### dynamic_cast运算符

是否可以安全地将对象的地址赋给特定类型的指针
例如：
```c++
Superb * pm = dynamic_cast<Superb *>(pg);
```
指针pg的类型是否可以被安全地转换为Superb *？
如果可以，运算符将返回对象的地址，否则返回一个空指针

如果指向的对象 *pt 的类型为Type或者是由Type直接或间接派生而来的类型，那么下面的表达式
```c++
dynamic_cast<Type *>(pt)
```
将指针pt转换为Type类型的指针，否则结果为0，即空指针

### typeid运算符和type_info类

```c++
#include<typeinfo>
```

```typeid```运算符可以接受两种参数：
* 类名
* 结果为对象的表达式
返回一个对```type_info```对象的引用

```type_info```是在头文件```typeinfo```中定义的一个类，重载了 == 和 != 运算符，可以对类型进行并比较
```type_info```包含一个```name()```成员，该函数返回一个字符串，通常是类的名称

## 类型转换运算符

使用四个类型转换运算符，更严格地限制允许的类型转换，使转换过程更规范
**dynamic_cast** **const_cast** **static_cast** **reinterpret_cast**

* dynamic_cast
  * 语法: ```dynamic_cast <type-name> (expression)```
  * 该运算符的用途是，使得能够在类层次结构中进行向上转换，而不允许其他转换
  * 由于is-a关系，这样的类型转换是安全的
* const_cast
  * ```const_cast <type-name> (expression)```
  * 改变值为 const 或 volatile
* static_cast
  * ```static_cast <type-name> (expression)```
  * 当且仅当type-name可被隐式转换为expression所属的类型或expression可被隐式转换为type-name所属的类型时，才是合法的，否则出错
  * 允许向上转换和向下转换，还允许枚举类型和整型之间，以及数值类型之间的转换
* reinterpret_cast
  * ```reinterpret_cast <type-name> (expression)```
  * 用于危险的类型转换，使用reinterpret_cast可以简化对这种行为的跟踪工作
  * 适用于依赖于实现的底层编程技术，是不可移植的