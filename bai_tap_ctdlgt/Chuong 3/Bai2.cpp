#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(int **A, int n){
    *A = new int[n];
    for (int i=0; i<n; i++){
        (*A)[i] = i;
    }
}

ll prefixAverages1 (int *A, int n){
    ll s = 0;
    for (int i=0; i<=n-1; i++){
        s = s + A[0];
        for (int j=1; j<=i; j++) s = s + A[j];
    }
    return s;
}

ll prefixAverages2 (int *A, int n){
    ll s = A[0];
    ll t = s;
    for (int i=1; i<=n-1; i++){
        s = s + A[i];
        t = t + s;
    }
    return t;
}

int main(){
    
    cout << setw(10) << "n" << setw(20) << "prefixAverages1" << setw(20) << "prefixAverages2" << endl;
    
    for (int i=100; i<=20000; i+=100){
        int *A;
        init(&A, i);
        cout << setw(10) << i;
        
        auto begin1 = std::chrono::high_resolution_clock::now();
        prefixAverages1(A, i);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
        cout << setw(20) << setprecision(8) << elapsed1.count() * 1e-9;
        
        auto begin2 = std::chrono::high_resolution_clock::now();
        prefixAverages2(A, i);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
        cout << setw(20) << setprecision(8) << elapsed2.count() * 1e-9;
        
        cout << endl;
    }
}
