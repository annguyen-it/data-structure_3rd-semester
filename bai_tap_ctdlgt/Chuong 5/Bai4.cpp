#include <bits/stdc++.h>
#include "Bai3.cpp"

using namespace std;

class App {
    private:
        Queue<int> element;
        int choice;

    public:
        App(){
            do {
                menu();
                doStuff();
                
            } while (choice != 0);
        }
        
        void menu(){
            cout << "\n\n---------------------------------------";
            cout << "\n\n\tCHUONG TRINH LUU TRU\n\n";
            cout << "1. Them mot phan tu\n";
            cout << "2. Lay phan tu ra va hien thi len man hinh\n";
            cout << "3. Hien thi so phan tu hien co\n";
            cout << "4. Cho biet Queue co rong khong?\n";
            cout << "0. Thoat chuong trinh\n";
            cout << "\nHay chon thao tac: ";
            
            cin >> choice;
        }
        
        void doStuff(){
            switch (choice){
                case 1:
                    add();
                    break;
                
                case 2:
                    remove();
                    break;
                    
                case 3:
                    show();
                    break;
                    
                case 4:
                    status();
                    break;
                    
                default:
                    break;
            }
        }
        
        void add(){
            cout << "\nHay nhap phan tu can them: ";
            int n;
            cin >> n;
            element.push(n);
            cout << "Them phan tu thanh cong!\n";
        }
        
        void remove(){
            if (element.empty()){
                cout << "\nKhong co phan tu nao de lay ra!\n";
                return;
            }
            
            cout << "\nPhan tu vua lay ra la: " << element.front() << '\n';
            element.pop();
        }

        void show(){
            cout << "\nSo phan tu hien co la: " << element.size();
        }
        
        void status(){
            cout << "\nQueue hien dang " << (element.empty() ? "rong" : "khong rong") << '\n';
        }
};

int main(){
    App();
	return 0;
}

