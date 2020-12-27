#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
struct Node{
    T value;
    Node* prev;
    Node* next;

    template <class U>
    friend ostream& operator<<(ostream& os, const Node& node);
};

template <class U>
ostream& operator<<(ostream& os, const Node<U>& node) {
    os << node.value;
    return os;
}

#endif // NODE_H