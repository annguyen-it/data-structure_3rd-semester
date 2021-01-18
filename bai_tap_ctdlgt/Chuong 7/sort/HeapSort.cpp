#include <bits/stdc++.h>
#include "Swap.cpp"

#ifndef __HeapSort__cpp
#define __HeapSort__cpp

using namespace std;

template<class T>
void sink(T *a, int k, int n, bool (*comp)(T, T)) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && comp(a[j], a[j + 1])) j++;
        if (!comp(a[k], a[j])) break;
        Swap(a[k], a[j]);
        k = j;
    }
}

template<class T>
void HeapSort(T *a, int n, bool (*comp)(T, T)) {
    int n1 = n;
    T *b = new T[n+1];
    for (int i = 0; i < n; ++i) {
        b[i+1] = a[i];
    }

    for (int i = n / 2; i >= 1; i--) {
        sink(b, i, n, comp);
    }
    while (n > 1) {
        Swap(b[1], b[n--]);
        sink(b, 1, n, comp);
    }

    for (int i = 0; i < n1; ++i) {
        a[i] = b[i+1];
    }
}

#endif
