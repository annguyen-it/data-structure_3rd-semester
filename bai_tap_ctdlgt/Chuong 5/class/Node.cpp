#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node {
    private:
        T elem;
        Node<T>* next;
    
    public:
        Node<T>(T elem, Node<T>* next = nullptr){
            this->elem = elem;
            this->next = next;
        }
        
        Node<T>*& getNext() { return next; }
        T& getElem() { return elem; }
};
