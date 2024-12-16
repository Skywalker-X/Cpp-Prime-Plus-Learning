## cin
面向行的输入：```cin.getline()```
例如```cin.getline(name, 20)```把这一行的输入读入到一个包含20个元素的name数组中

也可以使用```cin.get(name, ArSize).get()```
```cin.get(name, ArSize)```用法与getline一样，```cin.get()```直接读取下一个字符

## string
使用string类 ```#include<string>```
可以将一个string对象赋值给另一个string对象，字符串合并可以直接相加
确定字符串中字符数```str.size()```
读取string使用```getline(cin, str)```

也可以使用C风格的函数（需要```#include<cstring>```）： 
```strcpy(s1, s2)```将s2复制到s1，```strcat(s1, s2)```将s2附加到s1末尾 
确定字符串中字符数```strlen(str)```

## struct
结构体

共用体 union 能够存储不同的数据类型，但是只能同时存储其中的一种类型
共用体每次只存储一个值，常用于节省内存，例如数据项使用两种或更多中格式（但不会同时使用）时候

## enum
枚举 ```enum spectrum {red, orange, yellow, green}``` 将red等作为符号常量，对应整数值0~3，叫做枚举量 enumerator
枚举没有算术运算

可以使用赋值来设置枚举量的值 ```enum bits {one=1, two=2, four=4, eight}```
指定的值必须是整数，默认第一个为0，未被初始化的枚举量的值比前一个大1，例如此处eight=5

## pointer
使用new分配内存 ```int *p = new int;```
使用delete来释放使用new分配的内存 ```delete p```

使用new来创建动态数组 ```int *p = new int [10]``` 
释放内存```delete [] p```

C++通常将数组名视为数组的第一个元素的地址
可以将指针与整数相加，加1结果是原来的地址值加上指向的对象占用的总字节数

## new struct
可以使用new来创建动态结构，例如船舰一个inflatable类型的结构
```inflatable *ps = new inflatable```

访问成员的时候，动态结构不能将成员运算符句点用于结构名，因为这种结构没用名称，只有地址
使用**箭头运算符(->)**，该运算符可用于指向结构的指针，例如 ```ps->price``` 是被指向结构的price成员

如果结构标识符是结构名，则使用句点运算符；如果标识符是指向结构的指针，则使用箭头运算符。

## vector & array
```#include<vector>```，名称空间std， 动态数组
```vector<typename> vt(num)``` num可以是int常量也可以是int变量
也可以创建一个空的vector，例如 ```std::vector<int> myVector```
vector 动态调整大小 可以在插入或添加值的时候自动调整长度

```#include<array>```，名称空间std, 长度固定的数组
```array<typename, num> arr```