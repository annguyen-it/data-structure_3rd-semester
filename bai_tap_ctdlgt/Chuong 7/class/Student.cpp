#include <bits/stdc++.h>

#ifndef __Student__cpp
#define __Student__cpp

using namespace std;

class Student {
    private:
        int msv;
        string hoTen, gioi;
        
    public:
        int getMsv() { return msv; }
        string getHoTen() { return hoTen; }
        
        friend istream& operator>> (istream& in, Student &s){
            cout << "\tNhap ma sv: ";
            in >> s.msv;
            in.ignore(1);
            
            cout << "\tNhap ho va ten: ";
            getline(in, s.hoTen, '\n');
            
            cout << "\tNhap gioi tinh: ";
            getline(in, s.gioi, '\n');
            
            return in;
        }
        
        friend ostream& operator<< (ostream& out, Student &s){
            out << s.msv << '\t' << s.hoTen << '\t' << s.gioi << '\n';
            return out;
        }
};

#endif
