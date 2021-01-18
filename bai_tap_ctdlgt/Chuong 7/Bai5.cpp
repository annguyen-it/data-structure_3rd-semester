#include <bits/stdc++.h>
#include "./sort/HeapSort.cpp"

#ifndef __Bai5__cpp
#define __Bai5__cpp

using namespace std;

template <class T>
class Vector_reverse_it {
    private:
        T *curr;

    public:
        Vector_reverse_it(T *curr=0){
            this->curr = curr;
        }

        T *getCurr() { return curr; }

        T& operator* () { return *curr; }

        Vector_reverse_it operator++ (){
            Vector_reverse_it temp = curr;
            curr--;
            return temp;
        }

        Vector_reverse_it operator++ (int){
            curr = curr-1;
            return curr;
        }

        bool operator!= (Vector_reverse_it<T> it){
            return it.getCurr() != curr;
        }
};

template<class T>
class Vector {
    private:
        int cap, num;
        T *buff;
        

    public:
        Vector(){
            buff = new T[1];
            cap = 1;
            num = 0;
        }

        Vector(int k,T x){
            cap = num = k;
            buff = new T[k];

            for(int i=0; i<k; i++){
                buff[i] = x;
            }
        }

        ~Vector(){
            delete[] buff;
            buff = nullptr;
        }

        int size()     { return num; }
        int capacity() { return cap; }
        bool empty()   { return num == 0; }

        T &operator[](int k) { return buff[k]; }
        T &back()            { return buff[num-1]; }

        void pop_back()     {if (num > 0) num--; }
        void push_back(T x){
            if (num == cap) reserve(cap*2+1);
            buff[num++] = x;
        }


        typedef T *iterator;
        iterator begin() { return buff; }
        iterator end()   { return buff + num; }

        void insert(iterator it, T x){
            int p = it - buff;
            if(num == cap) reserve(cap*2+1);
            for(int i=num-1; i>=p; i--) buff[i+1] = buff[i];
            buff[p] = x;
            num++;
        }

        void reserve(int newcap){
            T *temp = new 
            T[newcap];
            for(int i=0; i<num; i++) temp[i] = buff[i];
            cap = newcap;
            delete[] buff;
            buff = temp;
        }

        void erase(iterator it){
            for(; it+1 != buff+num; it++) *it = *(it+1);
            num--;
        }


        typedef Vector_reverse_it<T> reverse_iterator;
        reverse_iterator rbegin() { return buff + num - 1; }
        reverse_iterator rend()   { return buff - 1; }
        
        ////////////////////////////////////////////////////
        void sort(){
            HeapSort(buff, num, *[](T a, T b) { return a < b; });
        }
        ////////////////////////////////////////////////////
};

#endif

void print(Vector<int> &v){
    for (auto i : v){
        cout << i << ' ';
    }
}

//int main(){
//    Vector<int> v(15, 0);
//    srand(time(0));
//    
//    cout << "Vector ban dau:\n";
//    for (int i=0; i<15; i++){
//        v[i] = rand() % 100 + 1;
//    } 
//    
//    print(v);
//    cout << "\n\nVector sau khi sap xep:\n";
//    
//    v.sort();
//    print(v);
//}
