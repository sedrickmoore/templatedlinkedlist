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

	DLList(const DLList<Item>& other);

	DLList<Item>& operator=(const DLList<Item>& other);

	~DLList();

	void	print() const;
	bool	empty() const;

	void	add_front(const Item &itm);
	void	add_rear(const Item &itm);
	void	add(int idx, const Item &itm);

	// Note that the user must head ensure the list is not empty
	// prior to calling these functions. 
	Item	front() const;
	Item	rear() const;
	Item	peek(int idx) const;

	int		size() const;
	int		items(const Item &itm) const;

	int		search(const Item &itm) const;

	bool	remove_front();
	bool	remove_rear();
	bool	remove_index(int idx);
	int		remove_item(const Item &itm);


	bool	sub_list(const DLList<Item>& sub);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our DLList.
	// Will be implemented along with list
	// member functions
	class Node;

	// We'll have both head and tail points for 
	// Fast insertion/deletion from both ends.
	Node*	head;
	Node*	tail;

	// Keep track of number of nodes in the list
	int		count;
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
	Node() :next(nullptr), prev(nullptr) {}
	Node(Item i, Node* p, Node* n) : item(i), next(n), prev(p) {}

	Node * nxt() const { return next; }
	void nxt(Node *n) { next = n; }

	Node * prv() const { return prev; }
	void prv(Node *p) { prev = p; }

	Item itm() const { return item; }
	void itm(const Item &i) { item = i; }

private:
	Item  item;
	Node * next;
	Node * prev;
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
DLList<Item>::DLList(const DLList<Item>& other) {

	/*   TODO   */


}
/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {

	/*   TODO   */
	return *this;
}


/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {

	/*   TODO   */

}

/* DLList print
*/

template<typename Item>
void DLList<Item>::print() const {

	/*   TODO   */

}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {

	/*   TODO   */
	bool retval = false;
	return retval;
}


/* DLList add_front
*/
template<typename Item>
void DLList<Item>::add_front(const Item &itm) {

	/*   TODO   */

}

/* DLList add_rear
*/
template<typename Item>
void DLList<Item>::add_rear(const Item &itm) {

	/*   TODO   */

}

/* DLList add
*/
template<typename Item>
void DLList<Item>::add(int idx, const Item &itm) {

	/*   TODO   */

}

/*  DLList front
*/
template<typename Item>
Item DLList<Item>::front() const {
	// Force check that the head is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(head != nullptr);

	/*   TODO   */
	Item retval{};
	return retval;
}

/* DLList rear
*/
template<typename Item>
Item DLList<Item>::rear() const {

	// Force check that the tail is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(tail != nullptr);

	/*   TODO   */
	Item retval{};
	return retval;

}

/* DLList peek
*/
template<typename Item>
Item DLList<Item>::peek(int idx) const {

	// Force index to be correct before getting the Item
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(idx >= 0 && idx < count);

	/*   TODO   */
	Item retval{};
	return retval;
}

/* DLList size
*/
template<typename Item>
int DLList<Item>::size() const {

	/*   TODO   */
	int retval = 8675309;
	return retval;
}
template<typename Item>
int DLList<Item>::items(const Item &itm) const {

	/*   TODO   */
	int retval = 8675309;
	return retval;

}
/* DLList search
*/
template<typename Item>
int DLList<Item>::search(const Item &itm) const {

	/*   TODO   */
	int retval = 8675309;
	return retval;
}

/* DLList remove_front
*/
template<typename Item>
bool DLList<Item>::remove_front() {

	/*   TODO   */
	bool retval = false;
	return retval;
}
/* DLList remove_rear
*/
template<typename Item>
bool DLList<Item>::remove_rear() {

	/*   TODO   */
	bool retval = false;
	return retval;
}

/* DLList remove_index
*/
template<typename Item>
bool DLList<Item>::remove_index(int idx) {

	/*   TODO   */

	bool retval = false;
	return retval;

}

/* DLList remove_item
*/
template<typename Item>
int DLList<Item>::remove_item(const Item &itm) {

	/*   TODO   */
	int retval = 9000;
	return retval;

}

/* DLList sub_list
*/
template<typename Item>
bool DLList<Item>::sub_list(const DLList<Item>& sub) {
	
	/*   TODO   */
	bool retval = true;
	return retval;
}

#endif



























































































// _X_XMMXXI