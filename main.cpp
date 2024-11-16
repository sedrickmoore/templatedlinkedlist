#include"templatelinkedlist.h"
#include<iostream>

int main() {

    DLList<int> *l = new DLList<int>;


    l->add_rear(1);
    std::cout << l->front() << std::endl;
    l->add_front(5);
    std::cout << l->front() << std::endl;
    l->add_front(7);
    std::cout << l->front() << std::endl;
    l->add_front(42);
    l->print();
    l->remove_rear();
    std::cout << l->rear() << std::endl;

    std::cout << std::endl << "New list." << std::endl << std::endl;

    DLList<int> l2(*l);
    l2.add_front(58);
    l2.add_rear(3);
    l2.add(1, 45);
    l2.add(2, 37);
    l2.remove_item(42);
    l2.add_front(42);
    l2.print();
    std::cout << std::endl;
    l->print();
    std::cout << std::endl;
    bool checkSub = l2.sub_list(*l);
    if(checkSub){std::cout << "Is a sublist."<<std::endl;}else{std::cout << "Is not a sublist."<<std::endl;}


    return 0;

}