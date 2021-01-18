#include <bits/stdc++.h>

#ifndef __Array__cpp
#define __Array__cpp

using namespace std;

template <class T>
void InputArr(T *a, int n, string str){
    for (int i=0; i<n; i++){
        cout << str << i+1 << ":\n";
        cin >> a[i];
    }
}

template <class T>
void PrintArr(T *a, int n, bool xuongdong){
    for (int i=0; i<n; i++){
        cout << a[i] << (xuongdong ? '\n' : ' ');
    }
}

#endif
