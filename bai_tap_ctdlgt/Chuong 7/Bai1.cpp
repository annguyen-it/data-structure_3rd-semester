#include <bits/stdc++.h>

#include "./class/Student.cpp"
#include "./includes/Array.cpp"

#include "./includes/compare_name.cpp"
#include "./sort/BubbleSort.cpp"

using namespace std;

int main(){
    Student *a;
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    
    a = new Student[n];
    InputArr(a, n, "\nNhap sinh vien thu ");
    system("cls");
    
    cout << "Danh sach sinh vien:\n";
    PrintArr(a, n, true);
    
    BubbleSort(a, n, compare_name);
    cout << "\n\nDanh sach sinh vien sau khi sap xep:\n";
    PrintArr(a, n, true);
    
	return 0;
}

