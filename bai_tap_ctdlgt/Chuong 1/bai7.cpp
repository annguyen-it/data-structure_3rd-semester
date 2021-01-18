#include <bits/stdc++.h>

using namespace std;

template <class T>
void nhap(vector<T>& v, int n){
	v.resize(n);
	for (int i=0; i<n; i++){
		cin >> v[i];
	}
}

template <class T>
void xuat(vector<T> v){
	int n = v.size();
	for (int i=0; i<n; i++){
		cout << v[i] << ' ';
	}
}

int main(){
	int n;
	vector<double> v;
	cout << "Hay nhap so phan tu cua day: ";
	cin >> n;
	nhap(v, n);
	
	cout << "\n\nDay vua nhap la:\n\t";
	xuat(v);
	
	return 0;
}

