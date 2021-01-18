#include <bits/stdc++.h>

using namespace std;

int MaxMin(int a, int b, int c, bool ismax = true){
	return ismax ? max(a, max(b, c)) : min(a, min(b, c));
}

int sum(int a, int b, int c){
	return a+b+c;
}

int main(){
	int a, b, c, _max, _min;
	
	cout << "Hay nhap 3 so a, b, c:\n";
	cin >> a >> b >> c;
	
	cout << "\nSo khong phai max, khong phai min la: " << sum(a, b, c) - MaxMin(a, b, c) - MaxMin(a, b, c, false);
	
	return 0;
}

