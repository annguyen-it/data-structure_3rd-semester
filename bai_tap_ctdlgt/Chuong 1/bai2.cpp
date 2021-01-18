#include <bits/stdc++.h>

using namespace std;

void inChuoiHoa(string chuoi){
	int n = chuoi.size();
	for (int i=0; i<n; i++){
		putchar(toupper(chuoi[i]));
	}
}

void inChuoiThuong(string chuoi){
	int n = chuoi.size();
	for (int i=0; i<n; i++){
		putchar(tolower(chuoi[i]));
	}
}

int main(){
	string chuoi;
	cout << "Hay nhap chuoi can thao tac: ";
	cin >> chuoi;
	
	cout << "Chuoi hoa:\n\t";
	inChuoiHoa(chuoi);
	cout << "\n\nChuoi thuong:\n\t";
	inChuoiThuong(chuoi);
	
	return 0;
}

