#include<iostream>
using namespace std;

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item *pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
};

Stack::Stack(int n) : size(n), top(0)
{
    pitems = new Item [size];
}

Stack::Stack(const Stack & st) : size(st.size), top(st.top)
{
    pitems = new Item [st.size];
    for (int i = 0; i < top; i++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item) 
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false; 
}

Stack & Stack::operator=(const Stack & st)
{
    if(this == & st)
        return *this;
    
    delete [] pitems;

    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
        pitems[i] = st.pitems[i];

    return *this;
}

int main() {
    Stack stack1(5);

    cout << "Pushing items onto stack1:" << endl;
    for (int i = 1; i <= 5; i++) {
        if (stack1.push(i))
            cout << "Pushed: " << i << endl;
        else
            cout << "Stack is full!" << endl;
    }

    Stack stack2(stack1);

    cout << "\nPopping items from stack1:" << endl;
    Item item;
    while (stack1.pop(item))
        cout << "Popped: " << item << endl;

    Stack stack3;
    stack3 = stack2;

    cout << "\nPopping items from stack3 (copied from stack2):" << endl;
    while (stack3.pop(item))
        cout << "Popped: " << item << endl;

    return 0;
}