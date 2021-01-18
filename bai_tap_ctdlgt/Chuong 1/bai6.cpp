#include <bits/stdc++.h>

using namespace std;

template <class T>
T ucln(T a, T b){
	if (a == b) return a;
	if (a < b) return ucln(a, b - a);
	return ucln(a-b, b);
}

int main(){
	int a, b;
	
	cout << "Hay nhap 2 so nguyen a, b:\n";
	cin >> a >> b;
	cout << "Uoc chung lon nhat la: " << ucln(a, b);
	
	return 0;
}

