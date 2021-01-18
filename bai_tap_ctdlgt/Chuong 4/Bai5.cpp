#include <bits/stdc++.h>
#include "Bai4.cpp"

using namespace std;

struct SV {
    string sbd, hoTen, gioiTinh;
    int namSinh;
    double diem;
};

int menu(){
    cout << "\n\n-----------------------------------------";
    cout << "\n\nCHUONG TRINH QUAN LY SINH VIEN\n\n";
    cout << "1. Doc danh sach tu file" << endl;
    cout << "2. Ghi danh sach thi sinh ra file" << endl;
    cout << "3. Bo sung mot thi sinh vao danh sach (bo sung vao cuoi)" << endl;
    cout << "4. Xoa thi sinh" << endl;
    cout << "5. Cap nhat thong tin" << endl;
    cout << "6. Hien thi thong tin cua thi sinh" << endl;
    cout << "7. In danh sach cac thi sinh hien co" << endl;
    cout << "0. Ket thuc" << endl;
    
    cout << endl << "Hay chon thao tac: ";
    int n;
    cin >> n;
    cin.ignore(256, '\n');
    return n;
}

void inThongTin(SV s){
    cout << s.sbd << ", " << s.hoTen << ", " << s.namSinh << ", "<< s.gioiTinh << ", " << s.diem;
}

void docTep(SingleList<SV>& sv){
    cout << "Hay nhap ten file can doc: ";
    string fileName;
    cin >> fileName;
    ifstream fi("./src/" + fileName, ios::in);
    
    if (fi.is_open()){
        int n;
        fi >> n;
        fi.ignore(256, '\n');
        
        for (int i=0; i<n; i++){
            SV s;
            
            getline(fi, s.sbd, '\n');    
            getline(fi, s.hoTen, '\n');
            
            fi >> s.namSinh;
            fi.ignore(256, '\n');
            
            getline(fi, s.gioiTinh, '\n');
            
            fi >> s.diem;
            fi.ignore(256, '\n');
            
            sv.push_back(s);
        }
        
        fi.close();
        cout << "Doc tep thanh cong!\n";
    }
    else {
        cout << "Loi doc tep!";
    }
}

bool ghiTep(SingleList<SV> sv){
    cout << "Hay nhap ten file can ghi: ";
    string fileName;
    cin >> fileName;
    ofstream fo("./src/" + fileName);
    
    if (fo.is_open()){   
        int n = sv.size();
        cout << "n = " << n << '\n';
    
        fo << n << endl;
    
        for (auto it=sv.begin(); it!=sv.end(); it++){
            fo << (*it).sbd << '\n';
            fo << (*it).hoTen << '\n';
            fo << (*it).namSinh << '\n';
            fo << (*it).gioiTinh << '\n';
            fo << (*it).diem << '\n';
        }
        
        fo.close();
        cout << "Ghi tep thanh cong!\n";
    }
    else {
        cout << "Loi ghi tep!";
    }
}

void them(SingleList<SV>& sv){
    SV s;
    cout << "Hay nhap thong tin thi sinh can them:\n";
    
    cout << "So bao danh: ";
    getline(cin, s.sbd);
    
    cout << "Ho ten: ";
    getline(cin, s.hoTen);
    
    cout << "Nam sinh: ";
    cin >> s.namSinh;
    cin.ignore(256, '\n');
    
    cout << "Gioi tinh: ";
    getline(cin, s.gioiTinh);
    
    cout << "Diem: ";
    cin >> s.diem;
    cin.ignore(256, '\n');
    
    sv.push_back(s);
}

void xoa(SingleList<SV>& sv){
    string sbd;
    cout << "Hay nhap so bao danh thi sinh can xoa: ";
    getline(cin, sbd);
    
    for (auto it=sv.begin(); it != sv.end(); it++){
        if ((*it).sbd == sbd){
            sv.erase(it);
            cout << "Xoa thi sinh thanh cong!\n";
            return;
        }
    }
    
    cout << "Khong tim thay thi sinh!\n";
}

void capNhat(SingleList<SV>& sv){
    string sbd;
    cout << "Hay nhap so bao danh thi sinh can sua: ";
    getline(cin, sbd);

    for (auto it=sv.begin(); it!=sv.end(); it++){
        if ((*it).sbd == sbd){
            cout << "Hay nhap thong tin thi sinh:\n";
    
            cout << "So bao danh: ";
            getline(cin, (*it).sbd);
            
            cout << "Ho ten: ";
            getline(cin, (*it).hoTen);
            
            cout << "Nam sinh: ";
            cin >> (*it).namSinh;
            cin.ignore(256, '\n');
            
            cout << "Gioi tinh: ";
            getline(cin, (*it).gioiTinh);
            
            cout << "Diem: ";
            cin >> (*it).diem;
            cin.ignore(256, '\n');
            
            cout << "\nCap nhat thanh cong!";
            return;
        }
    }
    
    cout << "Khong tim thay thi sinh!\n";
}

void hienThi(SingleList<SV> sv){
    string sbd;
    cout << "Hay nhap so bao danh thi sinh can tim: ";
    getline(cin, sbd);
    
    for (auto s : sv){
        if (s.sbd == sbd){
            cout << "Thong tin thi sinh can tim:\n";
            inThongTin(s);
            return;
        }
    }
    cout << "Khong tim thay thi sinh!\n";
}

void hienThiTatCa(SingleList<SV> sv){
    if (sv.empty()){
        cout << "Danh sach khong co thi sinh nao!\n";
        return;
    }
    
    cout << "Danh sach tat ca cac thi sinh:\n";
    int n = sv.size();
    int i = 1;
    
    for (auto it=sv.begin(); it!=sv.end(); it++, i++){
        cout << endl << i+1 << ". ";
        inThongTin((*it));
    }
}

int main(){
    SingleList<SV> sv;
    int chon;
    
    while (chon = menu()){
        switch(chon){
            case 1:
                docTep(sv);
                break;
                
            case 2:
                ghiTep(sv);
                break;
                
            case 3:
                them(sv);
                break;
            
            case 4:
                xoa(sv);
                break;
                
            case 5:
                capNhat(sv);
                break;
                
            case 6:
                hienThi(sv);
                break;
                
            case 7:
                hienThiTatCa(sv);
                break;
        }
    }

    return 0;
}

