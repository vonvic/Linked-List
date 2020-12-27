#include <iostream>
#include "list.h"
using namespace std;


int main() {
    List<int> L;
    L.pushFront(3);
    L.pushFront(5);
    cout << L << endl;
    L.popFront();
    cout << L << endl;

    L.pushFront(0);
    L.pushFront(2);
    cout << L << endl;

    cout << "Items in list: ";
    for (auto item : L) {
        cout << item << " ";
    }
    cout << endl;

}