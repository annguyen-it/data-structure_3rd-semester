#include <bits/stdc++.h>
#include "Swap.cpp"

#ifndef __SelectionSort__cpp
#define __SelectionSort__cpp

using namespace std;

template <class T>
void SelectionSort(T *a, int n, bool (*comp)(T, T)){
    for (int i=0; i<n-1; i++){
        int mini = i;
        for (int j=i+1; j<n; j++){
            if (comp(a[j], a[mini])){
                mini = j;
            }
        }
        
        Swap(a[i], a[mini]);
    }
}

#endif
