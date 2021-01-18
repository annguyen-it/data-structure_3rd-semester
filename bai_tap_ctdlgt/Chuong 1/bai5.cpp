#include <bits/stdc++.h>

using namespace std;

template <class T>
T Max(T a, T b){
	return (a > b ? a : b);
}

int main(){
	int a, b;
	double c, d;
	
	cout << "Hay nhap 2 so nguyen a, b:\n";
	cin >> a >> b;
	cout << "So lon hon la: " << Max(a, b);
	
	cout << "\n\nHay nhap 2 so thuc c, d:\n";
	cin >> c >> d;
	cout << "So lon hon la: " << Max(c, d);
	
	return 0;
}

