#include <bits/stdc++.h>

using namespace std;

void minmax(int a, int b, int c, int& _max, int& _min){
	_max = max(a, max(b, c));
	_min = min(a, min(b, c));
}

int main(){
	int a, b, c, _max, _min;
	
	cout << "Hay nhap 3 so a, b, c:\n";
	cin >> a >> b >> c;
	
	minmax(a, b, c, _max, _min);
	
	cout << "\nGia tri lon nhat: " << _max;
	cout << "\nGia tri nho nhat: " << _min;
	
	return 0;
}

