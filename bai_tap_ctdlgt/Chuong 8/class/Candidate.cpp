#include <bits/stdc++.h>

using namespace std;

#ifndef __Candidate__cpp
#define __Candidate__cpp

class Candidate {
    private:
        string id, name;
        double mark;
        
    public:
        Candidate(){}
        Candidate(string id, string name, double mark){
            this->id = id;
            this->name = name;
            this->mark = mark;
        }
        
        string getId()   { return id; }
        string getName() { return name; }
        double getMark() { return mark; }
        
        friend istream& operator>> (istream& in, Candidate &s){
            cout << "\tNhap so bao danh: ";
            getline(in, s.id, '\n');
            
            cout << "\tNhap ho va ten: ";
            getline(in, s.name, '\n');
            
            cout << "\tNhap diem: ";
            cin >> s.mark;
            cin.ignore(1);
            
            return in;
        }
        
        friend ostream& operator<< (ostream& out, const Candidate &s){
            out << s.id << '\t' << s.name << '\t' << s.mark << '\n';
            return out;
        }
};

#endif
