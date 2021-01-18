#include <bits/stdc++.h>
#include "Swap.cpp"

#ifndef __QuickSort__cpp
#define __QuickSort__cpp

using namespace std;

template <class T>
int partition(T *a, bool (*comp)(T, T), int lo, int hi){
    int i = lo, j = hi+1;
    T v = a[lo];
    
    while (true){
        while(comp(a[++i], v)) if (i == hi) break;
        while(comp(v, a[--j])) if (j == lo) break;
        if (i >= j) break;
        Swap(a[i], a[j]);
    }
    Swap(a[lo], a[j]);
    
    return j;
}

template <class T>
void QuickSort(T *a, int n, bool (*comp)(T, T), int lo = 0, int hi = -10){
    if (hi == -10) hi = n-1;
    if (hi <= lo) return;
    int j = partition(a, comp, lo, hi);
    
    QuickSort(a, n, comp, lo, j-1);
    QuickSort(a, n, comp, j+1, hi);
}

#endif
