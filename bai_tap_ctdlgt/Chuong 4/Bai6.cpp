#include <bits/stdc++.h>

#ifndef __Bai6__cpp
#define __Bai6__cpp

using namespace std;

template <class T>
class DblNode{
	T elem;
	DblNode<T> *prev, *next;
	
	public:
		DblNode(T elem, DblNode<T> *L = nullptr,DblNode<T> *R = nullptr){
			this->elem = elem;
            prev = L;
            next = R;
		}
		
		T &getelem(){
			return elem;
		}
		
		DblNode<T> *&getprev(){ return prev; }
		DblNode<T> *&getnext(){ return next; }
		
		void setelem(T elem){ this->elem = elem; }
		void setprev(DblNode<T> *p = nullptr){ prev = p; }
		void setnext(DblNode<T> *p = nullptr){ next = p; }
};


template<class T>
class DoubleList_iterator
{
	DblNode<T> *curr;
	public:
		DoubleList_iterator(DblNode<T> *curr = 0){ this->curr = curr; }
		DblNode<T> *getcurr(){ return curr; }
		
		DoubleList_iterator &operator= (DoubleList_iterator<T> it){
			this->curr = it.getcurr();
            return *this;
		}
		
		bool operator!= (DoubleList_iterator<T> it){ return curr != it.getcurr(); }
		T &operator*(){ return curr->getelem(); }
		
		DoubleList_iterator operator++ (int){
			DoubleList_iterator it = curr;
            curr = curr->getnext();
            return it;
		}
		DoubleList_iterator operator++(){
			curr = curr->getnext();
            return curr;
		}
};

template<class T>
class DoubleList_reverse_iterator
{
	DblNode<T> *curr;
	public:
		DoubleList_reverse_iterator(DblNode<T> *c=0){ curr = c; }
		DblNode<T> *getcurr(){ return curr; }
		
		DoubleList_reverse_iterator &operator= (DoubleList_reverse_iterator<T> it){
			this->curr = it.getcurr();
            return *this;
		}
		
		bool operator!= (DoubleList_reverse_iterator<T> it){ return curr != it.getcurr(); }
		T &operator*(){ return curr->getelem(); }
		DoubleList_reverse_iterator operator++ (int){
			DoubleList_reverse_iterator it = curr;
            curr = curr->getprev();
            return it;
		}
		
		DoubleList_reverse_iterator operator++ (){
			curr = curr->getprev();
            return curr;
		}
};


template <class T>
class DoubleList{
	DblNode<T> *head, *trail;
	unsigned int num;
	public:
		typedef DoubleList_iterator<T> iterator;
		typedef DoubleList_reverse_iterator<T> reverse_iterator;
		
        DoubleList(){
            num=0;
            head = trail = nullptr;
        }
		DoubleList(int k,T value){
            num = 0;
            head = trail = nullptr;
            while(k--) push_back(value);
        }
		
        bool empty(){ return num == 0; }
		unsigned size(){ return num; }
		
		reverse_iterator rbegin(){
			return trail;
		}
		reverse_iterator rend(){
			return nullptr;
		}
		iterator begin(){
			return head;
		}
		iterator end(){
			return nullptr;
		}
		
		void push_back(T value){
			if(num == 0) head = trail = new DblNode<T>(value);
			else {
				trail->setnext(new DblNode<T>(value, trail, nullptr));
				trail = trail->getnext();
			}
			num++;
		}
		
		void push_front(T value){
			if(num == 0) head = trail = new DblNode<T>(value);
			else {
				head->setprev(new DblNode<T>(value, nullptr, head));
				head = head->getprev();
			}
			num++;
		}
		
		
		T &front(){ return head->getelem(); }
		T &back() { return trail->getelem(); }
		
        void pop_back(){
			if(num == 0) return;
			if(num == 1) head = trail = nullptr;
			else {
				trail = trail->getprev();
				trail->setnext(NULL);
			}
			num--;
		}
		void pop_front(){
			if(num == 0) return;
			if(num == 1) head = trail = nullptr;
			else {
				head = head->getnext();
				head->setprev(nullptr);
			}
			num--;
		}
		
		void insert(iterator it,T value){
			DblNode<T> *p = it.getcurr();
			if(p == head) return push_front(value);
			
			DblNode<T> *q = p->getprev();
			DblNode<T> *r = new DblNode<T>(value, q, p);
			
			p->setprev(r);
			q->setnext(r);
			
			num++;
		}
		
		void erase(iterator it) {
			if(it.getcurr() == head) return pop_front();
			if(it.getcurr() == trail) return pop_back();
			
			DblNode<T> *L = it.getcurr()->getprev(), *R = it.getcurr()->getnext();
			L->setnext(R);
            R->setprev(L);
			
            num--;
		}
};

#endif
