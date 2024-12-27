#include"10-9-1list.h"
#include<iostream>

List::List(int maxSize) : maxSize(maxSize), currentSize(0) {
    items = new Item[maxSize];
}

List::~List() {
    delete[] items;
}

void List::add(const Item& item) {
    if (isFull()) {
        std::cout << "List is full. Cannot add item." << std::endl;
        return;
    }
    items[currentSize++] = item;
}

bool List::isEmpty() const {
    return currentSize == 0;
}

bool List::isFull() const {
    return currentSize == maxSize;
}

void List::visit(void(*pf)(Item&)) {
    for (int i = 0; i < currentSize; ++i) {
        pf(items[i]);
    }
}
