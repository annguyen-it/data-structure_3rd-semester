#include<bits/stdc++.h>
#include "./sort/SelectionSort.cpp"

using namespace std;

template<class T>
class Node {
	private:
		T elem;
		Node<T> *next;
		
	public:
		Node<T>() { next = nullptr; }
		Node<T>(T elem, Node<T> *next = nullptr){
			this->elem = elem;
			this->next = next;
		}
		
		T &getElem()        { return elem; }
		void setElem(T elem){ this->elem = elem; }
		
		Node<T> *&getNext()        { return next; }
		void setNext(Node<T> *next){ this->next = next; }
};

template<class T>
class SingleList_iterator {
    private:
	   Node<T> *curr;
	
    public:
		SingleList_iterator(Node<T> *curr = nullptr) { this->curr = curr; }
		Node<T> *&getcurr(){ return curr; }

		T &operator*(){
			 return curr->getElem();
		}
		
		bool operator!= (SingleList_iterator<T> it){
			return curr != it.getcurr();
		}
		
		SingleList_iterator<T> operator++ (int){
            curr = curr->getNext();
			return curr;
		}
		
		SingleList_iterator<T> operator++ (){
			SingleList_iterator<T> it = curr;
			curr = curr->getNext();
			return it;
		}
};

template<class T>
class SingleList {
    private:
	   Node<T> *head, *trail;
	   int num;
	
    public:
		SingleList(){
			head = trail = nullptr;
			num = 0;
		}
		SingleList(int k, T value){
			num = 0;
			while(k--){
				push_back(value);
			}
		}
		
		Node<T> *gethead() { return head; }
		Node<T> *gettrail(){ return trail; }
		
		int size()  { return num; }
		bool empty(){ return num == 0; }
		
		T &front(){ return head->getElem(); }
		T &back() { return trail->getElem(); }
		
		void push_back(T value){
			if(num == 0){
				head = trail = new Node<T>(value);
			}
			else {
				trail->setNext(new Node<T>(value));
				trail = trail->getNext();
			}
			num++;
		}
		void push_front(T value){
			if(num == 0) head = trail = new Node<T>(value);
			else {
				head = new Node<T>(value, head);
			}
			num++;
		}
		
		void pop_front(){
			if(num == 0) return;
			if(num == 1){
				head = trail = 0;
			}
            else {
				head = head->getNext();
			}
			num--;
		}
		void pop_back(){
			if(num == 0) return;
			if(num == 1){
				head = trail = nullptr;
			}
            else {
				Node<T> *p = head;
				while(p->getNext() != trail) p = p->getNext();
				p->setNext(nullptr);
				trail = p;
			}
			num--;
		}
		
		typedef SingleList_iterator<T> iterator;
		iterator begin(){  return head;  }
		iterator end()  { return nullptr;}
		
		void insert(iterator it, T value){
			if(it.getcurr() == head) return push_front(value);
			Node<T> *p = head;
			
			while(p->getNext() != it.getcurr()) p = p->getNext();
			p->setNext(new Node<T>(value, it.getcurr()));
			
			num++;
		}
		
		void erase(iterator it){
			if(it.getcurr() == head) return pop_front();
			if(it.getcurr() == trail) return pop_back();
			
            Node<T> *p = head;
			while(p->getNext() != it.getcurr()) p = p->getNext();
			p->setNext(it.getcurr()->getNext());
			
            num--;
		}
		
		////////////////////////////////////////////////////
        void sort(){
            T *temp = new T[num];
            int i = 0;
            for (SingleList<T>::iterator it=this->begin(); it != this->end(); it++) {
                temp[i++] = *it;
            }

            SelectionSort(temp, num, *[](T a, T b){ return a < b; });

            i = 0;
            for (SingleList<T>::iterator it=this->begin(); it != this->end(); it++) {
                *it = temp[i++];
            }
        }
        ////////////////////////////////////////////////////
};

int main(){
    SingleList<int> L;
    srand(time(0));
    
    cout << "List ban dau:\n";
    for (int i=0; i<15; i++){
        L.push_back(rand()%100+1);
    }
    for (auto it : L){
        cout << it << ' ';
    }
    
    L.sort();
    cout << "\n\nList sau khi sap xep:\n";
    
    for (auto it : L){
        cout << it << ' ';
    }
    
    return 0;
}
