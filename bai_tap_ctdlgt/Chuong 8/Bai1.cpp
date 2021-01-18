#include<bits/stdc++.h>

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
		

//        void sort(){
//            T *temp = new T[num];
//            int i = 0;
//            for (SingleList<T>::iterator it=this->begin(); it != this->end(); it++) {
//                temp[i++] = *it;
//            }
//
//            SelectionSort(temp, num, *[](T a, T b){ return a < b; });
//
//            i = 0;
//            for (SingleList<T>::iterator it=this->begin(); it != this->end(); it++) {
//                *it = temp[i++];
//            }
//        }
        
        
        ////////////////////////////////////////////////////
        iterator find(T value){
            for (iterator it=this->begin(); it != this->end(); it++) {
                if (*it == value){
                    return it;
                }
            }
            
            return nullptr;
        }
        ////////////////////////////////////////////////////
};

// ======================================================================================

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
class DoubleList {
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
		
		iterator find(T value){
            for (iterator it=this->begin(); it != this->end(); it++) {
                if (*it == value){
                    return it;
                }
            }
            
            return nullptr;
        }
};

// ======================================================================================

int main(){
//    SingleList<int> L;
//    srand(time(0));
//    
//    cout << "List ban dau:\n";
//    for (int i=0; i<10; i++){
//        L.push_back(rand()%10+1);
//    }
//    for (auto it : L){
//        cout << it << ' ';
//    }
//    
//    int k = rand()%10 + 1;
//    if (L.find(k) != nullptr){
//        cout << "\n\nTon tai phan tu " << k;
//    }
//    else {
//        cout << "\n\nKhong ton tai phan tu " << k;
//    }
    
    DoubleList<int> DBL;
    srand(time(0));
    
    cout << "List ban dau:\n";
    for (int i=0; i<10; i++){
        DBL.push_back(rand()%10+1);
    }
    for (auto it : DBL){
        cout << it << ' ';
    }
    
    int k = rand()%10 + 1;
    if (DBL.find(k) != nullptr){
        cout << "\n\nTon tai phan tu " << k;
    }
    else {
        cout << "\n\nKhong ton tai phan tu " << k;
    }
    
    return 0;
}
