#include <bits/stdc++.h>
#include "Bai1.cpp"

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
    cin.ignore();
    return n;
}

void inThongTin(SV s){
    cout << s.sbd << ", " << s.hoTen << ", " << s.namSinh << ", "<< s.gioiTinh << ", " << s.diem;
}

void docTep(Vector<SV>& sv){
    cout << "Hay nhap ten file can doc: ";
    string fileName;
    cin >> fileName;
    ifstream fi("./src/" + fileName, ios::in);
    
    if (fi.is_open()){
        int n;
        fi >> n;
        fi.ignore();
        
        for (int i=0; i<n; i++){
            SV s;
            
            getline(fi, s.sbd, '\n');    
            getline(fi, s.hoTen, '\n');
            
            fi >> s.namSinh;
            fi.ignore();
            
            getline(fi, s.gioiTinh, '\n');
            
            fi >> s.diem;
            fi.ignore();
            
            sv.push_back(s);
        }
        
        fi.close();
        cout << "Doc tep thanh cong!\n";
    }
    else {
        cout << "Loi doc tep!";
    }
}

bool ghiTep(Vector<SV> sv){
    cout << "Hay nhap ten file can ghi: ";
    string fileName;
    cin >> fileName;
    ofstream fo("./src/" + fileName);
    
    if (fo.is_open()){   
        int n = sv.size();
        cout << "n = " << n << '\n';
    
        fo << n << '\n';
    
        for (int i=0; i<n; i++){
            fo << sv[i].sbd << '\n';
            fo << sv[i].hoTen << '\n';
            fo << sv[i].namSinh << '\n';
            fo << sv[i].gioiTinh << '\n';
            fo << sv[i].diem << '\n';
        }
        
        fo.close();
        cout << "Ghi tep thanh cong!\n";
    }
    else {
        cout << "Loi ghi tep!";
    }
}

void them(Vector<SV>& sv){
    SV s;
    cout << "Hay nhap thong tin thi sinh can them:\n";
    
    cout << "So bao danh: ";
    getline(cin, s.sbd);
    
    cout << "Ho ten: ";
    getline(cin, s.hoTen);
    
    cout << "Nam sinh: ";
    cin >> s.namSinh;
    cin.ignore();
    
    cout << "Gioi tinh: ";
    getline(cin, s.gioiTinh);
    
    cout << "Diem: ";
    cin >> s.diem;
    cin.ignore();
    
    sv.push_back(s);
}

void xoa(Vector<SV>& sv){
    string sbd;
    cout << "Hay nhap so bao danh thi sinh can xoa: ";
    getline(cin, sbd);
    
    for (auto it=sv.begin(); it != sv.end(); it++){
        if (it->sbd == sbd){
            sv.erase(it);
            cout << "Xoa thi sinh thanh cong!\n";
            return;
        }
    }
    
    cout << "Khong tim thay thi sinh!\n";
}

void capNhat(Vector<SV>& sv){
    string sbd;
    cout << "Hay nhap so bao danh thi sinh can sua: ";
    getline(cin, sbd);

    for (auto& s : sv){
        if (s.sbd == sbd){
            cout << "Hay nhap thong tin thi sinh:\n";
    
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
            
            cout << "\nCap nhat thanh cong!";
            return;
        }
    }
    
    cout << "Khong tim thay thi sinh!\n";
}

void hienThi(Vector<SV> sv){
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

void hienThiTatCa(Vector<SV> sv){
    if (sv.empty()){
        cout << "Danh sach khong co thi sinh nao!\n";
        return;
    }
    
    cout << "Danh sach tat ca cac thi sinh:\n";
    int n = sv.size();
    for (int i=0; i<n; i++){
        cout << endl << i+1<< ". ";
        inThongTin(sv[i]);
    }
}

int main(){
    Vector<SV> sv;
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

