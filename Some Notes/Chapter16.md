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

686