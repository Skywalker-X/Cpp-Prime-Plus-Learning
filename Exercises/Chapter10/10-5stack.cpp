#include<iostream>
using namespace std;

struct customer {
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    int num() {return top;}
};

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item) 
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false; 
}

int main()
{
    customer c[4] {{"x", 200},{"xx", 400},{"xxx", 600},{"xxxx", 800}};

    Stack s;
    cout<<"Total: "<<s.num()<<endl;

    for (int i=0; i<4; i++)
    {
        s.push(c[i]);
        cout<<"Total: "<<s.num()<<endl;
    }

    for (int i=0; i<4; i++)
    {
        s.pop(c[i]);
        cout<<"Total: "<<s.num()<<endl;
    }

    return 0;
}