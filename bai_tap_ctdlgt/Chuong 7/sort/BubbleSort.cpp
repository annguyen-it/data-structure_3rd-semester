#include <bits/stdc++.h>
#include "Swap.cpp"

#ifndef __BubbleSort__cpp
#define __BubbleSort__cpp

using namespace std;

template <class T>
void BubbleSort(T *a, int n, bool (*comp)(T, T)){
    for (int i=0; i<n-1; i++){
        for (int j=n-1; j>i; j--){
            if (comp(a[j], a[j-1])){
                Swap(a[j], a[j-1]);
            }
        }
    }
}

#endif
