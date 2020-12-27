#ifndef ITER_H
#define ITER_H

#include <iostream>
#include "node.h"
using namespace std;

template <class T>
class Iterator {
    public:
        Iterator() {
            data = new Node<T>();
        }
        Iterator(Node<T> *item) {
            data = item;
        }

        Iterator next() {
            return Iterator<T>(data->next);
        }

        Iterator operator++() {
            Node<T> *temp = data;
            data = data->next;
            return Iterator<T>(temp);
        }
        Iterator operator++(int) {
            data = data->next;
            return data;
        }
        bool operator!=(const Iterator<T> iter) const {
            return (data != iter.data);
        }
        bool operator==(const Iterator<T> iter) const {
            return (data == iter.data);
        }
        T& operator*() {
            return this->data->value;
        }
    private:
        Node<T> *data;

};


#endif // ITER_H