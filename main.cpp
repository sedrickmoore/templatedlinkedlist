
// Choose which run to compile
#define  L // RUN0 RUN1 RUN2 RUN3


#ifdef RUN0

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>

int main() {
    std::cout << StudentInfo::Name() << std::endl;
    std::cout << StudentInfo::ID() << std::endl;

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
    l->print();
    bool checkSub = l2.sub_list(*l);
    if(checkSub){std::cout << "Is a sublist."<<std::endl;}else{std::cout << "Is not a sublist."<<std::endl;}


    return 0;

}

#elif defined RUN1

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>
#include<string>

int main() {

    std::cout << StudentInfo::Name() << std::endl;
    std::cout << StudentInfo::ID() << std::endl;

    DLList<std::string> * l = new DLList<std::string>; //DLList of integers

    l->add_rear("Hello");
    l->add_front("World");
    l->add_front("Bob");
    l->add_front("2");

    l->print(); // 2 Bob World Hello

    l->remove_rear();  // Will trip assert if empty
    l->print(); // 2 Bob World

    std::cout << l->front() << std::endl; // 2

    return 0;

}

#elif defined RUN2

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

    // Step 1: Initial state
    // Assume that constructor implemented properly
    // If you're not sure if the constructor is
    // implemented properly, STOP, go back and make
    // sure. Luckily the default constructor is
    // done for you.  But the point remains, never,
    // ever, use a function in a test that isn't itself
    // verified to function according to spec.
    DLList<int> * l = new DLList<int>;


    // Step 2: Execute the function to test
    l->add_front(99);

    // Step 3: Verify what you expect to observe.
    // You must know what is supposed to happen in
    // order to analyze for correctness. Generally,
    // you must permute all possible combinations
    // of all member variables.
    assert(l->head != nullptr);
    assert(l->tail != nullptr);
    assert(l->count == 1);
    assert(l->head->prv() == nullptr);
    assert(l->head->nxt() == nullptr);
    assert(l->head->itm() == 99);

    return 0;
}

#elif defined RUN3

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

    // Step 1: Initial state
    // Same as above, except we must head populate the list
    // However, since we are testing add_front, we cannot
    // use it to generate the initial state of our list
    // to test.  So we have to manually set the initial state
    // in this case we are creating a list with three nodes.
    DLList<std::string>::Node* head = new DLList<std::string>::Node;
    DLList<std::string>::Node* second = new DLList<std::string>::Node;
    DLList<std::string>::Node* third = new DLList<std::string>::Node;

    // We have to manually linked everything together:
    head->itm("first");
    head->prv(nullptr);
    head->nxt(second);

    second->itm("second");
    second->prv(head);
    second->nxt(third);

    third->itm("third");
    third->prv(second);
    third->nxt(nullptr);

    // Now we create  DLList object and inject the initial control state:
    DLList<std::string> * l = new DLList<std::string>;
    l->head = head;
    l->tail = third;
    l->count = 3;

    // Step 2: Now with the list given a complete and correct starting state
    // We can test various member functions for correctness.
    // For example we can use this as one test for add_front;
    l->add_front("Zero");

    // Step 3: Verify:  Technically, we should examine all
    // member variables, and all nodes' value, nxt, prv pointers
    // to ensure that the add_front didn't mangle any of the
    // internal nodes.  But, this is mostly just to illustrate
    // how you might develop your own tests.
    assert(l->count == 4);
    assert(l->head->prv() == nullptr);
    assert(l->head == head->prv());
    assert(l->head->nxt() == head);
    assert(l->head->itm() == "Zero");
    assert(l->tail == third);

    return 0;
}

#elif defined RUN4

#define MAKE_MEMBERS_PUBLIC

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>

int main() {
    std::cout << StudentInfo::Name() << std::endl;
    std::cout << StudentInfo::ID() << std::endl;

    DLList<int>::Node* node1 = new DLList<int>::Node;
    DLList<int>::Node* node2 = new DLList<int>::Node;
    DLList<int>::Node* node3 = new DLList<int>::Node;
    DLList<int>::Node* node4 = new DLList<int>::Node;
    DLList<int>::Node* node5 = new DLList<int>::Node;
    DLList<int>::Node* node6 = new DLList<int>::Node;

    node1->itm(1);
    node1->prv(nullptr);
    node1->nxt(node2);

    node2->itm(2);
    node2->prv(node1);
    node2->nxt(node3);

    node3->itm(1);
    node3->prv(node2);
    node3->nxt(node4);

    node4->itm(2);
    node4->prv(node3);
    node4->nxt(node5);

    node5->itm(3);
    node5->prv(node4);
    node5->nxt(node6);

    node6->itm(3);
    node6->prv(node5);
    node6->nxt(nullptr);

    DLList<int> * l = new DLList<int>;
    l->head = node1;
    l->tail = node6;
    l->count = 6;

    DLList<int>::Node* sub_node1 = new DLList<int>::Node;
    DLList<int>::Node* sub_node2 = new DLList<int>::Node;
    DLList<int>::Node* sub_node3 = new DLList<int>::Node;

    //Assume Constructor Correctly Implemented
    DLList<int> * sub = new DLList<int>;

    sub_node1->itm(1);
    sub_node1->prv(nullptr);
    sub_node1->nxt(sub_node2);

    sub_node2->itm(2);
    sub_node2->prv(sub_node1);
    sub_node2->nxt(sub_node3);

    sub_node3->itm(3);
    sub_node3->prv(sub_node2);
    sub_node3->nxt(nullptr);


    //Set up the initial state of the list to test
    sub->head = sub_node1;
    sub->tail = sub_node3;
    sub->count = 3;
    l->print();
    std::cout << std::endl;
    sub->print();
    std::cout << std::endl;
    bool checkSub = l->sub_list(*sub);
    if(checkSub){std::cout << "Is a sublist."<<std::endl;}else{std::cout << "Is not a sublist."<<std::endl;}


    return 0;

}

#else
//Run unit tests
#include"listtests.h"

int main() {

//    test_empty(1); 		//0-1
//    test_add_front(1);	//0-1
//    test_add_rear(1);		//0-1
//    test_add(6);			//0-6
//    test_search(4);		//0-4
//    test_front(0);		//0-1
//    test_rear(0);			//0-1
//    test_peek(0);			//0-1
//    test_remove_front(0); //0-2
//    test_remove_rear(0);	//0-2
//    test_remove_index(0); //0-7
//    test_remove_item(1);	//0-5,
//    test_print(0);		//0-1
//    test_size(0);			//0-1
//    test_items(0);		//0-5
//    test_copyCtor(0);		//0-2
//    test_assgnOper(0);	//0-2
//    test_mem_destructor(0);//0
//    test_mem_assgnOper(0);//0-1
//    test_sub_list(1);		//0-12,

int size = 12;

for(int i = 0; i <= size; i++){
    test_sub_list(i);
}

    return 0;
}

#endif