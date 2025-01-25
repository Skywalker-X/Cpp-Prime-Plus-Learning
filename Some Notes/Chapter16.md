## string

字符串中搜索给定的子字符串或字符 使用```find()```
```c++
size_type find(const string & str, size_type pos=0) const
size_type find(const char * s, size_type pos=0) const
size_type find(const char * s, size_type pos=0, size_type n) const
size_type find(char ch, size_type pos=0) const
```
如果找到，则返回首次出现时的位置，否则，返回```string::npos```

## 智能指针模板类

三个智能指针模板： ```auto_ptr``` ```unique_ptr``` ```shared_ptr```， 需要头文件memory
```c++
#include<memory>
```
智能指针不需要delete操作，将自动调用析构函数

创建智能指针 示例
```c++
auto_ptr<double> pd(new double)
```

unique_ptr不允许拷贝和赋值
shared_ptr支持拷贝和赋值，通过引用计数支持多个资源共享

auto_ptr现在已经不再使用了

使用new分配内存时，才能使用auto_ptr和shared_ptr


## 标准模板库

所有STL容器都提供了一些基本方法，包括
* size() 返回容器内元素数目
* swap() 交换两个容器的内容
* begin() 返回一个指向容器中第一个元素的迭代器
* end() 返回一个表示超过容器尾的迭代器
* push_back() 将元素添加到矢量末尾 部分STL容器可以
* erase() 删除矢量中给定区间的元素，接受两个迭代器参数指定要删除的区间
* insert() 接受三个迭代器参数，第一个参数指定插入位置，第二三个参数定义了被插入区间

还有一些非成员函数
* for_each()将被指向的函数应用于容器区间的各个元素
  * 被指向的函数不能修改容器元素的值
  * 可以用for_each()函数来代替for循环
  * 例如 ```for_each(books.begin(), books.end(), ShowReview);```
  * 前两个迭代器参数表示范围，第三个函数指针
  * 可避免显式地使用迭代器变量
* Random_shuffle()函数接受两个指定区间的迭代器参数，并随机安排列该区间中的元素
* sort()函数按照升序对元素进行排序，也可以添加一个函数作为参数来进行排序

可以使用基于范围的for循环
例如
```c++
double prices[10];
for(double x : prices)
    cout<<x<<endl;

for(auto & x : books)
    Show(x);
```

## 泛型编程

STL定义了5种迭代器
* 输入迭代器
  * 使程序能够读取容器中的值，但不一定能修改值
  * 输入迭代器必须能够访问容器中所有的值，这是通过支持++运算符 (前缀和后缀) 实现的
  * 输入迭代器是单项迭代器，可以递增，但不能倒退
  * 并不能保证输入迭代器第二次便利容器时顺序不变
* 输出迭代器
  * 能够写，但不能读
  * 对于单通行、只读算法，可以使用输入迭代器；对于单通行、只写算法，可以使用输出迭代器
* 正向迭代器
  * 只是用++运算符 (前缀和后缀) 来遍历容器
  * 总是按相同的顺序遍历一系列的值
  * 多次通行算法
  * 既可以使得能够读取和修改数据，也可以只读数据
* 双向迭代器
  * 具有正向迭代器所有特性
  * 支持--运算符 (前缀和后缀)
* 随机访问迭代器
  * 具有双向迭代器所有特性
  * 添加了支持随机访问的操作和用于对元素进行排序的关系运算符

```copy()```可以将数据从一个容器复制到另一个容器
前两个迭代器参数表示要复制到的范围，最后一个迭代器参数表示要将另一个元素复制到什么地方

如果要输出迭代器，可以使用```copy()```
STL提供了一个表示输出流的迭代器模板 ```ostream_iterator```
需要头文件 ```#include<iterator>```
示例：
```c++
ostream_iterator<int, char> out_iter(cout, " ");
```
out_iter迭代器是一个接口，能够使用cout来显示信息，以空格进行分隔
第一个模板参数表示发送给输出流的数据类型，第二个模板参数表示输出流使用的字符类型(char, wchar_t)
构造函数第一个参数是要使用的输出流(cout, fout)，最后一个字符串参数是输出的分隔符
```c++
copy(dice.begin(), dice.end(), ostream_iterator<int, char>);
copy(dice.begin(), dice.end(), out_iter);
```
这两行代码都将dice容器复制到输出流，即显示容器的内容
类似地，也有```istream_iterator```对象

还可以使用**反向迭代器**
例如
```c++
copy(dice.rbegin(), dice.rend(), out_iter);
```
rbegin和end、rend和begin返回相同的值，但是类型不同

还有三种迭代器参数对容器插入元素
* back_insert_iterator 将元素插入容器尾部
* front_insert_iterator 将元素插入容器前端
* insert_iterator 将元素插入insert_iterator构造函数的参数指定的位置前面
三种插入迭代器通过复制转换添加新的元素，不会覆盖已有的数据，并使用自动内存分配
这些插入迭代器将容器类型作为模板参数，insert_iterator还需要一个指示插入位置的构造函数参数，例如
```c++
back_insert_iterator<vector<string>> back_iter(words);
insert_iterator<vector<int>> insert_iter(dice, dice.begin())
```