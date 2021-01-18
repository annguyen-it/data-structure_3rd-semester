#include <bits/stdc++.h>

using namespace std;

string format(int n){
	return n < 10 ? "0" + to_string(n) : to_string(n);
}

class Time {
	private:
		int hour, minute, second;
		
	public:
		Time(){}
		Time(int hour, int minute, int second){
			this->hour   = hour;
			this->minute = minute;
			this->second = second;
		}
		
		
	   	void input(){
			cout << "\tGio: ";
			cin >> hour;
			cout << "\tPhut: ";
			cin >> minute;
			cout << "\tGiay: ";
			cin >> second;
		}
		
		void display(){
			cout << format(hour) << ':' << format(minute) << ':' << format(second);
		}
		
		friend istream& operator>> (istream& in, Time& t){
            t.input();
		    return in;
        }
        
        friend ostream& operator<< (ostream& out, Time& t){
            t.display();
            return out;
        }
		
		
		void setHour(int hour)     { this->hour = hour; }
		void setMinute(int minute) { this->minute = minute; }
		void setSecond(int second) { this->second = second; }
		
		int getHour()   { return hour; }
		int getMinute() { return minute; }
		int getSecond() { return second; }
};

int main(){
    Time t1;
    t1.input();
    cout << "t1: " << t1 << "\n\n";
	
	Time t2;
	t2.setHour(10);
	t2.setMinute(15);
	t2.setSecond(59);
	cout << "t2:" << format(t2.getHour()) << ':' << format(t2.getMinute()) <<	':' << format(t2.getSecond()) << "\n";
	
    return 0;
}

