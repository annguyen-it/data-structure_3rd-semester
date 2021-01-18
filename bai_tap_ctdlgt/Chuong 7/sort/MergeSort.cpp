#include <bits/stdc++.h>
#include "Swap.cpp"

#ifndef __MergeSort__cpp
#define __MergeSort__cpp

using namespace std;

template <class T>
void merge(T *a, int lo, int mid, int hi, T *subArr, bool (*comp)(T, T)){
    int i = lo, j = mid+1;
    
    for (int k=lo; k<=hi; k++){
        subArr[k] = a[k];
    }
    
    for (int k=lo; k<=hi; k++){
        if      (i > mid)                    a[k] = subArr[j++];
        else if (j > hi )                    a[k] = subArr[i++];
        else if (comp(subArr[j], subArr[i])) a[k] = subArr[j++];
        else                                 a[k] = subArr[i++];
    }
}

template <class T>
void MergeSort(T *a, int n, bool (*comp)(T, T), int lo, int hi, T *subArr){
    if (hi <= lo) return;
    
    int mid = lo + (hi - lo)/2;
    MergeSort(a, n, comp, lo, mid, subArr);
    MergeSort(a, n, comp, mid+1, hi, subArr);
    merge(a, lo, mid, hi, subArr, comp);
}

template <class T>
void MergeSort(T *a, int n, bool (*comp)(T, T)){
    T *subArr = new T[n];
    MergeSort(a, n, comp, 0, n-1, subArr);
}

#endif
