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