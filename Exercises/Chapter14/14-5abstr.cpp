#include<iostream>
#include<string>

using namespace std;

class abstr_emp
{
private:
    string fname;
    string lname;
    string job;
public:
    abstr_emp() : fname("none"), lname("none"), job("none") {}
    abstr_emp(const string & fn, const string & ln, const string & j) 
        : fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    friend ostream & operator<<(ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};

void abstr_emp::ShowAll() const
{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
    while(cin.get() != '\n')
        continue;
    cout << "Enter first name: ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
    cout << "Enter job: ";
    getline(cin, job);
}

ostream & operator<<(ostream & os, const abstr_emp & e)
{
    os << e.fname << " " << e.lname;
    return os;
}

abstr_emp::~abstr_emp() {}

class employee : public abstr_emp
{
public:
    employee() : abstr_emp() {}
    employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

class manager : virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const string & fn, const string & ln, const string & j, int ico = 0) : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}
    manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter in charge of: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
        continue;
}

class fink : virtual public abstr_emp
{
private:
    string reportsto;
protected:
    const string ReportsTo() const { return reportsto; }
    string & ReportsTo() { return reportsto; }
public:
    fink() : abstr_emp(), reportsto("none") {}
    fink(const string & fn, const string & ln, const string & j, const string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo) {}
    fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter who reports to: ";
    getline(cin, reportsto);
}

class highfink : public manager, public fink
{
public:
    highfink() : abstr_emp(), manager(), fink() {}
    highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
    highfink(const abstr_emp & e, const string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
    highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}
    highfink(const manager & m, const string & rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}
    highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "In charge of: " << manager::InChargeOf() << endl;
    cout << "Reports to: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter in charge of: ";
    cin >> manager::InChargeOf();
    while (cin.get() != '\n')
        continue;
    cout << "Enter who reports to: ";
    getline(cin, fink::ReportsTo());
}

int main()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    cout << endl;

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    cout << endl;

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    cout << endl;

    highfink hf(ma, "Curly Kew");
    hf.ShowAll();
    cout << endl;

    cout << "Press a key for next phase:\n";
    cin.get();

    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
    {
        tri[i]->ShowAll();
        cout << endl;
    }

    return 0;
}

//为什么不定义赋值运算符？ 默认的赋值运算符通常已经足够，因为 abstr_emp 类只包含简单的数据成员（string 类型）。如果类中包含了需要深拷贝的资源（如动态分配的内存），则需要自定义赋值运算符。

// 为什么要将 ShowAll 和 SetAll 定义为虚函数？ 将 ShowAll 和 SetAll 定义为虚函数是为了确保在派生类中重载这些函数时，能够通过基类指针或引用调用派生类的实现。这是多态性的基础，允许程序在运行时决定调用哪个版本的函数。

// 为什么要将 abstr_emp 定义为虚基类？ 将 abstr_emp 定义为虚基类是为了避免多重继承时的菱形继承问题。虚基类确保在多重继承的情况下，基类的成员只会存在一份实例，避免数据冗余和潜在的冲突。

// 为什么 highfink 类没有数据部分？ highfink 类没有数据部分，因为它继承了所有需要的数据成员自其基类 manager 和 fink。highfink 类的主要作用是组合 manager 和 fink 的功能，而不需要额外的数据成员。

// 为什么只需要一个 operator<< 版本？ 只需要一个 operator<< 版本是因为 operator<< 是一个友元函数，它可以访问 abstr_emp 类的私有成员。通过多态性，operator<< 可以调用虚函数 ShowAll，从而正确地输出派生类对象的内容。

// 如果使用下面的代码来替换程序的结尾部分，会怎么样：
// abstr_emp tri[4] = {em, fi, hf, hf2};
// for (int i = 0; i < 4; i++) tri[i].ShowAll();
// 这样做会导致对象切片问题。对象切片发生在将派生类对象赋值给基类对象时，派生类对象的特有部分会被切掉，只保留基类部分。因此，tri 数组中的每个元素都将是 abstr_emp 类型，而不是它们的派生类型。调用 ShowAll 时，只会调用 abstr_emp 类的 ShowAll 方法，而不会调用派生类的 ShowAll 方法，从而丢失了多态性。