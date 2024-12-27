#include"10-9-1list.h"
#include<iostream>

void printItem(Item& item) {
    std::cout << item << " ";
}

int main() {
    List list(5);

    list.add(1);
    list.add(2);
    list.add(3);
    
    std::cout << "List items: ";
    list.visit(printItem);
    std::cout << std::endl;

    std::cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is the list full? " << (list.isFull() ? "Yes" : "No") << std::endl;

    return 0;
}
