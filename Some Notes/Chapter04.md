面向行的输入：```cin.getline()```
例如```cin.getline(name, 20)```把这一行的输入读入到一个包含20个元素的name数组中

也可以使用```cin.get(name, ArSize).get()```
```cin.get(name, ArSize)```用法与getline一样，```cin.get()```直接读取下一个字符

使用string类 ```#include<string>```
可以将一个string对象赋值给另一个string对象，字符串合并可以直接相加
确定字符串中字符数```str.size()```
读取string使用```getline(cin, str)```

也可以使用C风格的函数（需要```#include<cstring>```）： 
```strcpy(s1, s2)```将s2复制到s1，```strcat(s1, s2)```将s2附加到s1末尾 
确定字符串中字符数```strlen(str)```

结构体

共用体 union 能够存储不同的数据类型，但是只能同时存储其中的一种类型
共用体每次只存储一个值，常用于节省内存，例如数据项使用两种或更多中格式（但不会同时使用）时候