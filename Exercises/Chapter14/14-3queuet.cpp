#include<iostream>
#include<string>
using namespace std;

//Worker Waiter Singer SingingWaiter
class Worker
{
private:
    string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const string & s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static const char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const string & s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const string & s, long n, int p=0, int v=other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & wk, int p=0, int v=other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wt, int v=other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & wt, int p=0)
        : Worker(wt), Waiter(wt, p), Singer(wt) {}
    void Set();
    void Show() const;
};

Worker::~Worker() {}

void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

const char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", 
                                "soprano", "bass", "baritone", "tenor"};
                        
void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "Category: singer\n";
    Worker::Data();
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    cin >> voice;
    while (cin.get() != '\n')
        continue;
}

void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}





//QueueTp

template <class Item>
class QueueTp
{
private:
    struct Node
    {
        Item item;
        struct Node * next;
    };
    Node * front;
    Node * rear;
    int items;
    const int qsize;
public:
    QueueTp(int qs = 10);
    QueueTp(const QueueTp & q);
    ~QueueTp();
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    int queuecount() const { return items; }
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

template <class Item>
QueueTp<Item>::QueueTp(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <class Item>
QueueTp<Item>::QueueTp(const QueueTp & q) : qsize(q.qsize)
{
    front = rear = nullptr;
    items = 0;
    Node * temp = q.front;
    while (temp != nullptr)
    {
        enqueue(temp->item);
        temp = temp->next;
    }
}

template <class Item>
QueueTp<Item>::~QueueTp()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class Item>
bool QueueTp<Item>::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <class Item>
bool QueueTp<Item>::dequeue(Item & item)
{
    if (front == nullptr)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;
}

int main()
{
    QueueTp<Worker *> q(3);
    Worker * w1 = new Waiter("John", 1234, 5);
    Worker * w2 = new Singer("Mary", 5678, 3);
    Worker * w3 = new SingingWaiter("Tom", 9012, 6, 2);
    q.enqueue(w1);
    q.enqueue(w2);
    q.enqueue(w3);

    Worker * temp;
    q.dequeue(temp);
    temp->Show();
    q.dequeue(temp);
    temp->Show();
    q.dequeue(temp);
    temp->Show();

    delete w1;
    delete w2;
    delete w3;

    return 0;
}