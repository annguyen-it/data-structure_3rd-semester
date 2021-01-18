#include <bits/stdc++.h>

using namespace std;

float sqr(float n){
    return n*n;
}

class Point {
    private:
        float x, y;
    
    public:
        Point(){}
        Point(float x, float y){
            this->x = x;
            this->y = y;
        }

        input(){
            cout << "\tx: ";
            cin >> x;
            cout << "\ty: ";
            cin >> y;
        }
        
        display(){
            cout << '(' << x << ", " << y << ')';
        }
        
		friend istream& operator>> (istream& in, Point& p){
            p.input();
		    return in;
        }
        
        friend ostream& operator<< (ostream& out, Point& p){
            p.display();
            return out;
        }


        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }

        float getX() { return x; }
        float getY() { return y; }

        float distance(Point d){
            return sqrt(sqr(x - d.getX()) + sqr(y - d.getY()));
        }
};

int main(){
    Point A, B(5, 5);
    cin >> A;
    cout << "\n\nDiem vua nhap la: " << A;
    
    cout << "\n\nKhoang cach giua A va B la: " << A.distance(B);
        
    return 0;
}

