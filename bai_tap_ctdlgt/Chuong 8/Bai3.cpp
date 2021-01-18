#include <bits/stdc++.h>

using namespace std;

template <class T>
int BinarySearch(T *a, int n, T value){
    int l = 0, r = n-1;
    
    while (l <= r){
        int mid = (l+r)/2;
        if (a[mid] == value) return mid;
        if (value < a[mid]) r = mid-1;
        else                l = mid+1;
    }
    
    return -1;
}

int main(){
    int n = 15;
    double *a = new double[n];
    
    for (int i=0; i<n; i++){
        double k = 1.0*i/10;
        a[i] = k*k*k + i*i;  
    }
    for (int i=0; i<n; i++){
        cout << a[i] << "  ";
    }
    cout << "\n\n";

    double x = 16.064;
    cout << "Vi tri cua " << x << " la: " << BinarySearch(a, n, x);
    
	return 0;
}

