#include <bits/stdc++.h>
#include "Swap.cpp"

#ifndef __InsertionSort__cpp
#define __InsertionSort__cpp

using namespace std;

template <class T>
void InsertionSort(T *a, int n, bool (*comp)(T, T)){
    for (int i=1; i<n; i++){
        for (int j=i-1; j>=0 && comp(a[i], a[j]); j--){
            Swap(a[j], a[i]);
        }
    }
}

#endif
