#include <bits/stdc++.h>

using namespace std;

bool kiemTra(int a, int b, int c){
	return a+b > c && a+c > b && b+c > a && a>0 && b>0 && c>0;
}

int main(){
	int a, b, c;
	
	cout << "Hay nhap 3 so nguyen a, b, c: ";
	cin >> a >> b >> c;
	cout << "\n\n";
	
	cout << (kiemTra(a, b, c) ? "3 so nguyen vua nhap co the tao thanh tam giac" : "3 so nguyen vua nhap khong the tao thanh tam giac");
	
	return 0;
}

