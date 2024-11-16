#ifndef FA23_CS20A_LlST_H
#define FA23_CS20A_LlST_H

#include<iostream>
#include<assert.h>

// Linked DLList object that maintains both head and tail pointers
// and the count of the list.  Note that you have to keep the head,
// tail and count consistent with the intended state of the DLList 
// otherwise very bad things happen. 
template<typename Item>
class DLList {
public:

    DLList();

    DLList(const DLList<Item> &other);

    DLList<Item> &operator=(const DLList<Item> &other);

    ~DLList();

    void print() const;

    bool empty() const;

    void add_front(const Item &itm);

    void add_rear(const Item &itm);

    void add(int idx, const Item &itm);

    // Note that the user must head ensure the list is not empty
    // prior to calling these functions.
    Item front() const;

    Item rear() const;

    Item peek(int idx) const;

    int size() const;

    int items(const Item &itm) const;

    int search(const Item &itm) const;

    bool remove_front();

    bool remove_rear();

    bool remove_index(int idx);

    int remove_item(const Item &itm);


    bool sub_list(const DLList<Item> &sub);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif

    // Forward declare the nodes for our DLList.
    // Will be implemented along with list
    // member functions
    class Node;

    // We'll have both head and tail points for
    // Fast insertion/deletion from both ends.
    Node *head;
    Node *tail;

    // Keep track of number of nodes in the list
    int count;
};


/* DLList Implementation
//
//  Since DLList is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template<typename Item>
class DLList<Item>::Node {
public:
    Node() : next(nullptr), prev(nullptr) {}

    Node(Item i, Node *p, Node *n) : item(i), next(n), prev(p) {}

    Node *nxt() const { return next; }

    void nxt(Node *n) { next = n; }

    Node *prv() const { return prev; }

    void prv(Node *p) { prev = p; }

    Item itm() const { return item; }

    void itm(const Item &i) { item = i; }

private:
    Item item;
    Node *next;
    Node *prev;
};


/* DLList default constructor
//		Already implemented, nothing to do.
*/
template<typename Item>
DLList<Item>::DLList() :head(nullptr), tail(nullptr), count(0) {
}


/* Copy constructor
*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item> &other) {

    head = nullptr;
    tail = nullptr;
    count = 0;

    if (other.head == nullptr) return;

    Node *temp = other.head;

    head = new Node(temp->itm(), nullptr, nullptr);
    Node *current = head;
    temp = temp->nxt();
    count++;

    while (temp != nullptr) {
        Node *newNode = new Node(temp->itm(), current, nullptr);
        current->nxt(newNode);
        current = newNode;
        temp = temp->nxt();
        count++;
    }

    tail = current;
}

/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item> &DLList<Item>::operator=(const DLList<Item> &other) {
    if (this == &other) return *this;
    Node *curr = head;

    while (curr != nullptr) {
        Node *temp = curr->nxt();
        delete curr;
        curr = temp;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;

    if (other.head == nullptr) return *this;

    Node *temp = other.head;

    head = new Node(temp->itm(), nullptr, nullptr);
    Node *current = head;
    temp = temp->nxt();
    count++;

    while (temp != nullptr) {
        Node *newNode = new Node(temp->itm(), current, nullptr);
        current->nxt(newNode);
        current = newNode;
        temp = temp->nxt();
        count++;
    }

    tail = current;

    return *this;
}

/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {
    if (head == nullptr)return;
    Node *curr = head;

    while (curr != nullptr) {
        Node *temp = curr->nxt();
        delete curr;
        curr = temp;
    }
    head = nullptr;
    tail = nullptr;
}

/* DLList print
*/

template<typename Item>
void DLList<Item>::print() const {
    if (head == nullptr) return;

    Node *curr = head;

    while (curr != nullptr) {
        std::cout << curr->itm();

        if (curr->nxt() != nullptr) {
            std::cout << " ";
        }

        curr = curr->nxt();
    }
}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {
    return !head;
}


/* DLList add_front
*/
template<typename Item>
void DLList<Item>::add_front(const Item &itm) {
    Node *node = new Node(itm, nullptr, nullptr);
    if (head != nullptr) {
        head->prv(node);
        node->nxt(head);
    }
    head = node;
    if (tail == nullptr) { tail = node; }
    count++;

}

/* DLList add_rear
*/
template<typename Item>
void DLList<Item>::add_rear(const Item &itm) {
    Node *node = new Node(itm, nullptr, nullptr);
    if (tail != nullptr) {
        tail->nxt(node);
        node->prv(tail);
    }
    tail = node;
    if (head == nullptr) { head = node; }
    count++;
}

/* DLList add
*/
template<typename Item>
void DLList<Item>::add(int idx, const Item &itm) {
    if (idx <= 0) {
        add_front(itm);
        return;
    }
    if (idx >= count) {
        add_rear(itm);
        return;
    }
    Node *node = new Node(itm, nullptr, nullptr);
    Node *temp = head;
    int counter = 0;
    while (counter < idx) {
        temp = temp->nxt();
        counter++;
    }

    Node *prev = temp->prv();

    prev->nxt(node);
    temp->prv(node);
    node->prv(prev);
    node->nxt(temp);

    count++;

}

/*  DLList front
*/
template<typename Item>
Item DLList<Item>::front() const {
    assert(head != nullptr);
    return head->itm();
}

/* DLList rear
*/
template<typename Item>
Item DLList<Item>::rear() const {
    assert(tail != nullptr);
    return tail->itm();

}

/* DLList peek
*/
template<typename Item>
Item DLList<Item>::peek(int idx) const {
    assert(idx >= 0 && idx < count);

    Node *temp = head;
    int counter = 0;
    while (counter < idx) {
        temp = temp->nxt();
        counter++;
    }

    return temp->itm();
}

/* DLList size
*/
template<typename Item>
int DLList<Item>::size() const {
    return count;
}

template<typename Item>
int DLList<Item>::items(const Item &itm) const {

    Node *temp = head;
    int numItems = 0;
    while (temp != nullptr) {
        if (temp->itm() == itm) numItems++;
        temp = temp->nxt();
    }

    return numItems;

}

/* DLList search
*/
template<typename Item>
int DLList<Item>::search(const Item &itm) const {

    Node *temp = head;
    int counter = 0;
    while (temp != nullptr) {
        if (temp->itm() == itm) {
            return counter;
        }
        temp = temp->nxt();
        counter++;
    }

    return -42;
}

/* DLList remove_front
*/
template<typename Item>
bool DLList<Item>::remove_front() {
    if (head == nullptr) return false;
    Node *temp = nullptr;
    if (head->nxt() != nullptr) {
        temp = head->nxt();
        temp->prv(nullptr);
    }
    delete head;
    head = temp;

    if (head == nullptr) tail = nullptr;

    count--;

    return true;
}

/* DLList remove_rear
*/
template<typename Item>
bool DLList<Item>::remove_rear() {
    if (tail == nullptr) return false;
    Node *temp = nullptr;
    if (tail->prv() != nullptr) {
        temp = tail->prv();
        temp->nxt(nullptr);
    }
    delete tail;
    tail = temp;

    if (tail == nullptr) head = nullptr;

    count--;

    return true;
}

/* DLList remove_index
*/
template<typename Item>
bool DLList<Item>::remove_index(int idx) {
    if (idx < 0 || idx >= count) return false;
    if (head == nullptr) return false;
    Node *temp = head;
    int counter = 0;
    while (counter < idx && temp != nullptr) {
        temp = temp->nxt();
        counter++;
    }
    if (temp != nullptr) {
        Node *prev = temp->prv();
        Node *next = temp->nxt();


        if (prev == nullptr && next == nullptr) {
            head = nullptr;
            tail = nullptr;
        } else if (prev == nullptr) {
            head = next;
            head->prv(nullptr);
        } else if (next == nullptr) {
            tail = prev;
            tail->nxt(nullptr);
        } else {
            prev->nxt(next);
            next->prv(prev);
        }

        delete temp;
        count--;
        return true;
    }

    return false;

}

/* DLList remove_item
*/
template<typename Item>
int DLList<Item>::remove_item(const Item &itm) {
    if (head == nullptr) return -1;
    Node *temp = head;
    int counter = 0;
    while (temp != nullptr) {
        if (temp->itm() == itm) {
            break;
        }
        temp = temp->nxt();
        counter++;
    }

    if (temp != nullptr) {
        Node *prev = temp->prv();
        Node *next = temp->nxt();

        if (prev == nullptr && next == nullptr) {
            head = nullptr;
            tail = nullptr;
        } else if (prev == nullptr) {
            head = next;
            head->prv(nullptr);
        } else if (next == nullptr) {
            tail = prev;
            tail->nxt(nullptr);
        } else {
            prev->nxt(next);
            next->prv(prev);
        }

        delete temp;
        count--;
        return counter;
    }

    return -42;

}

/* DLList sub_list
*/
template<typename Item>
bool DLList<Item>::sub_list(const DLList<Item> &sub) {
    if (head == nullptr && sub.head == nullptr) return true;
    if (head == nullptr) return false;
    if (sub.head == nullptr) return true;
    if (sub.count > count) return false;

    Node *first = head;
    Node *second = sub.head;
    int counter = 0;

    while (first != nullptr) {
        if (first->itm() == second->itm()) {
            counter++;
            second = second->nxt();
            if (counter == sub.count) return true;

        } else if (counter > 0) {
            second = sub.head;
            counter = 0;
            continue;
        }
        first = first->nxt();

    }

    return false;
}

#endif



























































































// _X_XMMXXI