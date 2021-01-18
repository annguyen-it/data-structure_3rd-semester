#include <bits/stdc++.h>

using namespace std;

#ifndef __Candidate__cpp
#define __Candidate__cpp

class Candidate {
    private:
        string id, name;
        double math, physics, chemistry;
        
    public:
        string getId()   { return id; }
        string getName() { return name; }
        double getMathMark()      { return math; }
        double getPhysicsMark()   { return physics; }
        double getChemistryMark() { return chemistry; }
        double getTotalMark()     { return math + physics + chemistry; }
        
        friend istream& operator>> (istream& in, Candidate &s){
            cout << "\tNhap so bao danh: ";
            getline(in, s.id, '\n');
            
            cout << "\tNhap ho va ten: ";
            getline(in, s.name, '\n');
            
            cout << "\tDiem toan: ";
            cin >> s.math;
            
            cout << "\tDiem ly: ";
            cin >> s.physics;
            
            cout << "\tDiem hoa: ";
            cin >> s.chemistry;
            cin.ignore(1);
            
            return in;
        }
        
        friend ostream& operator<< (ostream& out, Candidate &s){
            out << s.id << '\t' << s.name << '\t' << s.math << ' ' << s.physics << ' ' << s.chemistry << '\n';
            return out;
        }
};

#endif
