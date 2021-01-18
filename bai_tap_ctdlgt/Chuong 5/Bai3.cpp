#include <bits/stdc++.h>
#include "./class/Node.cpp"

using namespace std;

template <class T>
class Queue {
    private:
        int num;
        Node<T> *head, *trail;
    
    public:
        Queue(){
            num = 0;
            head = trail = nullptr;
        };
        
        bool empty(){ return num == 0; }
        int size()  { return num; }
        T& front()  { return head->getElem();  }
        T& back()   { return trail->getElem(); }
        
        void push(T value){
            if (num == 0) head = trail = new Node<T>(value);
            else {
                trail->getNext() = new Node<T>(value);
                trail = trail->getNext();
            }
            
            num++;
        }
        
        void pop(){
            if (num > 0){
                head = head->getNext();
                num --;
                if (!num) trail = nullptr;
            }
        }
};
