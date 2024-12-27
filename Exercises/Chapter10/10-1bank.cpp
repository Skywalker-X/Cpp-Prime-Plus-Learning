#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
private:
    string name_;
    string account_;
    double savings_;
public:
    BankAccount(string name="", string account="", double savings=0);
    ~BankAccount();
    void show() const;
    void save(double m);
    void draw(double m);
};

BankAccount::BankAccount(string name, string account, double savings)
{
    name_ = name;
    account_ = account;
    savings_ = savings;
}

BankAccount::~BankAccount()
{
}

void BankAccount::show() const
{
    cout<<"Name: "<<name_<<endl;
    cout<<"Account: "<<account_<<endl;
    cout<<"Savings: "<<savings_<<endl;
}

void BankAccount::save(double m)
{
    savings_ += m;
}

void BankAccount::draw(double m)
{
    savings_ -= m;
}

int main()
{
    string name = "xxx", account = "xxxx xxxx";
    double savings = 10000;

    BankAccount example(name, account, savings);
    example.show();
    example.save(500);
    example.show();
    example.draw(800);
    example.show();

    return 0;
}