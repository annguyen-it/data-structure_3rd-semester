#include <bits/stdc++.h>
#include "./class/Node.cpp"

using namespace std;

template <class T>
class Stack {
    private:
        unsigned num;
        Node<T> *head;
    
    public:
        Stack(){
            num = 0;
            head = nullptr;
        };
        
        bool empty(){ return num == 0; }
        int size()  { return num; }
        T& top()    { return head->getElem(); }
        
        void push(T value){
            head = new Node<T>(value, head);
            num++;
        }
        
        void pop(){
            if (num <= 1){
                num = 0;
                head = nullptr;
                return;
            }
            
            head = head->getNext();
            num--;
        }
};
