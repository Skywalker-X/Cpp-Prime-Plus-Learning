## cctype
```#include<cctype>```
```isdigit()``` 判断是否为数字
```isalpha()``` 判断是否为字母
```isalnum()``` 判断是否为数字或字母
```islower()``` 判断是否为小写字母
```isupper()``` 判断是否为大写字母
```tolower()``` 如果参数是大写字符，则返回其小写，否则返回该参数
```toupper()``` 如果参数是小写字符，则返回其大写，否则返回该参数
```ispunct()``` 判断是否为标点符号

## ？
expression1 ? express2 : expression3
如果1为真，表达式值为2的值，否则为3的值

## I/O
```cout << fixed```用定点表示法表示浮点数(不用科学计数法)
```cout.precision(2)```控制小数点后的位数
```cout.setf(ios_base::showpoint)```结果会保留原来的精度

使用文件输出 ```#include<fstream>```
创建一个**ofstream**对象并将其与一个文件关联
```c++
ofstream outFile;
outFile.open("carinfo.txt");
```
之后就可以像使用cout一样使用这个ofstrem对象

读取文本文件 ```#include<fstream>```
创建一个**ifstream**对象并将其与一个文件关联
```c++
ifstream inFile;
inFile.open("carinfo.txt");
```
检查文件是否被成功打开 
```c++
if(!inFile.is_open())
    exit(EXIT_FAILURE)
```
函数```exit()```终止程序，```#include<cstdlib>```