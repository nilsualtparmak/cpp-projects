#ifndef LL_H
#define LL_H

#include <iostream>
#include <cassert>
using namespace std;

template <class T>
struct node {
    T info;
    node<T>* link;
};

template <class T>
class LL {
public:
    LL();
    ~LL();
    bool emptyList();
    void insertFirst(T& item);
    void insertLast(T& item);
    void deleteNode(T& item);
    node<T>* search(T& item);
    void destroyList();
    T front();
    T back();

    template <class U>
    friend ostream& operator<<(ostream& os, LL<U>& lst);

private:
    node<T>* head;
    node<T>* last;
    int count;
};

// Constructor
template <class T>
LL<T>::LL() {
    head = last = NULL;
    count = 0;
}

// Destructor
template <class T>
LL<T>::~LL() {
    destroyList();
}

// Destroy all nodes
template <class T>
void LL<T>::destroyList() {
    node<T>* p;
    while (head != NULL) {
        p = head;
        head = head->link;
        delete p;
    }
    last = NULL;
    count = 0;
}

// Check if list is empty
template <class T>
bool LL<T>::emptyList() {
    return head == NULL;
}

// Return first element
template <class T>
T LL<T>::front() {
    assert(head != NULL);
    return head->info;
}

// Return last element
template <class T>
T LL<T>::back() {
    assert(last != NULL);
    return last->info;
}

// Insert at the beginning
template <class T>
void LL<T>::insertFirst(T& item) {
    node<T>* p = new node<T>;
    p->info = item;
    p->link = head;
    head = p;
    if (last == NULL)
        last = p;
    count++;
}

// Insert at the end
template <class T>
void LL<T>::insertLast(T& item) {
    node<T>* p = new node<T>;
    p->info = item;
    p->link = NULL;
    if (head != NULL) {
        last->link = p;
        last = p;
    } else {
        head = last = p;
    }
    count++;
}

// Search for item
template <class T>
node<T>* LL<T>::search(T& item) {
    node<T>* p = head;
    while (p != NULL) {
        if (p->info == item)
            return p;
        p = p->link;
    }
    return NULL;
}

// Delete node by value
template <class T>
void LL<T>::deleteNode(T& item) {
    if (head == NULL) {
        cerr << "List is empty" << endl;
        return;
    }

    node<T>* p;
    if (head->info == item) {
        p = head;
        head = head->link;
        delete p;
        count--;
        if (head == NULL)
            last = NULL;
    } else {
        node<T>* q = head;
        while (q->link != NULL && q->link->info != item)
            q = q->link;

        if (q->link != NULL) {
            p = q->link;
            q->link = p->link;
            if (p == last)
                last = q;
            delete p;
            count--;
        }
    }
}

// Output stream overload
template <class T>
ostream& operator<<(ostream& os, LL<T>& lst) {
    node<T>* p = lst.head;
    while (p != NULL) {
        os << p->info << " ";
        p = p->link;
    }
    os << endl;
    return os;
}

#endif
