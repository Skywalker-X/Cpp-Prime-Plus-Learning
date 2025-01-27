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

### 迭代器

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

### list模板类

```#include<list>```
list模板类表示双向链表，和vector的关键区别在于，**list在链表中任意位置进行插入和删除的时间都是固定的**
vector强调的是通过随机访问进行快速访问，list强调的是元素的快速插入和删除

list成员函数
* insert() 接受三个迭代器参数，第一个参数指定插入位置，第二三个参数定义了被插入区间
* merge(list<T, Alloc> & x)
  * 将链表x与调用链表合并，合并后的链表保存在调用链表中，x为空
  * 两个链表必须已排序
  * 复杂度为线性时间
* remove(const T & val)
  * 从链表中删除val的所有实例
  * 复杂度为线性时间
* sort() 排序 复杂度NlogN
* splice(iterator pos, list<T, Alloc> x)
  * 将链表x的内容插入到pos前面，x将为空
  * 复杂度固定时间
  * **insert将原始区间的副本插入到目标地址，splice将原始区间移到目标地址**
* unique()
  * 将连续的相同元素压缩为单个元素
  * 复杂度线性时间

### 关联容器

关联容器 associative container 将值与键关联在一起，并使用键来查找值
优点：提供了对元素的快速访问
允许插入新元素，但不能指定元素的插入位置，原因是关联容器通常由用于确定数据放置位置的算法，以便能快速检索信息
通常使用某种树来实现

STL提供了4种关联容器，前两个需要```#include<set>```，后两个需要```#include<map>```
* set
  * 值与键类型相同
  * 键是唯一的
* multiset
  * 值与键类型相同
  * 可能有多个值的键相同
* map
  * 值与键类型不同
  * 键是唯一的
* multimap
  * 值与键类型不同
  * 一个键可以与多个值相关联

集合种元素是唯一的，且集合被排序

可以使用set_union()来合并集合，有五个参数
要输出A和B的并集
```c++
set_union(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<string, char> out(cout, " "));
```
如果要将结果放到集合C中，不能用C.begin()，因为：
* 这返回一个常量迭代器，不能用作输出迭代器
* 与copy()相似，set_union()将覆盖容器里已有的数据，并要求容器有足够的空间容纳新信息，而C是空的，不能满足
可以使用插入
```c++
set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));

```
```set_intersection()``` ```set_difference()```分别查找交集和两个集合的差，接口与并集相同

## 函数对象

函数对象 也叫函数符 functor 是可以以函数方式与()结合使用的对象
包括函数名、指向函数的指针和重载了()运算符的类对象 (即定义了函数operator()()的类)

STL定义了多个基本函数符

函数```transform()```可以接受4个参数，前两个参数是指定容器区间的迭代器，第三个参数是指定将结果复制到哪里的迭代器，最后一个参数是函数符
例如
```C++
transform(A.begin(), A.end(), out, sqrt);
```
头文件```functional```定义了多个模板类函数对象，例如 
```c++
#include<functional>
...
plus<double> add;
double y = add(2.2, 3.3);
...
transform(A.begin(), A.end(), out, plus<double>);
```

STL提供的函数符包括：
* plus
* minus
* multiplies
* divides
* modulus
* negate
* equal_to
* not_equal_to
* greater
* less
* great_equal
* less_equal
* logic_and
* logic_or
* logic_not

### 自适应函数符和函数适配器

上一节的预定义函数符都是自适应的
意义在于：函数适配器对象可以使用函数对象，并认为存在这些typedef成员

例如，multiplies()函数符可以执行乘法计算，但它是二元啊还能输，因此需要一个函数适配器，将接受两个参数的函数符转换为接受一个参数的函数符
可以使用函数对象来实现
STL使用binder1st和binder2nd类来自动完成这一过程

假设有一个自适应二元函数对象f2()，可以创建一个binder1st对象
```c++
binder1st(f2, val) f1;
```
当使用单个参数调用f1(x)时，等价于调用f2(val, x)

STL提供了函数bind1st()，在头文件functional中
```c++
bind1st(multiplies<double>(), 2.5)
```
bind2nd与此类似，将常数赋给第二个参数