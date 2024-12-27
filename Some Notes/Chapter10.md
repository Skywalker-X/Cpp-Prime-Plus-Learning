函数的默认参数应只定义一次
一般默认参数只能在函数声明中提供一次，而不能同时在声明和定义中都提供

对于类的const成员函数，声明和定义应该像这样：
```c++
void show() const;
void stock::show() const;
```

## this指针
类方法中，this指针指向调用它的对象的地址
例如```stock1.topval(stock2)```中的this指针就指向stock1

## 类 常量

创建一个所有对象共享的常量，直接const行不通
有两种方法：
1. 在类中声明一个枚举
2. 在类中定义常量时使用关键字```static```

## 作用域内枚举

两个枚举定义中的枚举量可能发生冲突，可使用关键字class或struct
```c++
enum class egg {Small, Medium, Large, Jumbo};
enum class t_shirt {Small, Medium, Large, Xlarge};
```
需要使用枚举名来限定枚举量
```c++
egg choice = egg::Large;
t_shirt Floyd = t_shirt::Large;
```