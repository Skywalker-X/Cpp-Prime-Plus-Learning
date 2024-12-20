#include<iostream>
using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show(box m)
{
    cout<<m.maker<<endl<<m.height<<endl<<m.width<<endl<<m.length<<endl<<m.volume<<endl;
}

void set_volume(box *m)
{
    m->volume = m->height * m->length * m->width;
}

int main()
{
    box m = {"xxx", 2, 3, 4, 5};
    show(m);
    set_volume(&m);
    show(m);
    return 0;
}