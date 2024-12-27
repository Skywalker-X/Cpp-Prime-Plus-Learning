#ifndef LIST_H
#define LIST_H

typedef int Item;

class List {
public:
    List(int maxSize);
    ~List();
    void add(const Item& item);
    bool isEmpty() const;
    bool isFull() const;
    void visit(void(*pf)(Item&));

private:
    Item* items;
    int maxSize;
    int currentSize;
};

#endif
