#include<bits/stdc++.h>
#include "Bai1.cpp"

using namespace std;

int menu(){
    cout << "\n\n----------------------------------";
    cout << "\n\nCHUONG TRINH SU DUNG VECTOR\n\n";
    cout << "1. Chen mot phan tu\n";
    cout << "2. Xoa mot phan tu\n";
    cout << "3. Thay the mot phan tu\n";
    cout << "4. Lay gia tri mot phan tu\n";
    cout << "5. In danh sach cac phan tu hien co\n";
    cout << "0. Thoat\n";
    cout << "\n\nHay nhap thao tac: ";
    int n;
    cin >> n;
    return n;
}

void chen(Vector<double>& v){
    cout << "Hay nhap phan tu can them: ";
    double n;
    cin >> n;
    v.push_back(n);
}

void xoa(Vector<double>& v){
    cout << "Hay nhap chi so cua phan tu can xoa: ";
    double n;
    cin >> n;
    
    if (n > v.size()) return;
    
    Vector<double>::iterator it;
    for (it = v.begin(); it != v.end(); it++){}
    v.erase(it);
}

void thayThe(Vector<double>& v){
    int i;
    double n;
    cout << "Hay nhap chi so cua phan tu can thay the: ";
    cin >> i;
    
    if (i > v.size()){
        cout << "Chi so phan tu nam ngoai pham vi vector\n";
        return;
    }
    
    cout << "Hay nhap gia tri moi: ";
    cin >> n;
    v[i] = n;
}

void layGiaTri(Vector<double>& v){
    cout << "Hay nhap chi so cua phan tu can lay gia tri: ";
    int i;
    cin >> i;
    
    if (i > v.size()){
        cout << "Chi so phan tu nam ngoai pham vi vector\n";
        return;
    }
    
    cout << "Gia tri cua phan tu: " << v[i];
}

void In(Vector<double>& v){
    if (v.empty()){
        cout << "Vector rong!\n";
        return;
    }
    
    cout << "Danh sach cac phan tu hien co trong vector:\n\t";
    for (auto item : v){
        cout << item << ' ';
    }
}

int main(){
    Vector<double> v;
    int chon;
    
    while (chon = menu()){
        switch (chon){
            case 1:
                chen(v);
                break;
            
            case 2:
                xoa(v);
                break;
                
            case 3:
                thayThe(v);
                break;
            
            case 4:
                layGiaTri(v);
                break;
                
            case 5:
                In(v);
        }
    }

	return 0;
}

