#include<iostream>
#include<string>
#include"15-5queuetp.h"

int main()
{
    using std::string;
    QueueTP<string> cs(5);
    string temp;

    while (!cs.isfull())
    {
        std::cout << "Please enter your name. You will be "
            "served in the order of arrival.\nname: ";
        std::getline(std::cin, temp);
        cs.enqueue(temp);
    }

    std::cout << "The queue is full. Processing begins!\n";

    while (!cs.isempty())
    {
        cs.dequeue(temp);
        std::cout << "Now processing " << temp << "...\n";
    }

    return 0;
}