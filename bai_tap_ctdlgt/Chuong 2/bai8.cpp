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

class Triangle {
    private:
        vector<Point> coordinates;
    
    public:
        Triangle(){
            coordinates = vector<Point>(3, Point());
        }
        
        Triangle(Point a, Point b, Point c){
            coordinates = vector<Point>(3, Point());
            coordinates[0] = a;
            coordinates[1] = b;
            coordinates[2] = c;
        }
        
        
        void input(){
            for (int i=0; i<3; i++){
                cout << "\nHay nhap diem thu " << i + 1 << endl;
                coordinates[i].input();
            }
        }
        
        void display(){
            for (int i=0; i<3; i++){
                coordinates[i].display();
                if (i < 2) cout << ", ";
            }
        }
        
		friend istream& operator>> (istream& in, Triangle& t){
            t.input();
		    return in;
        }
        
        friend ostream& operator<< (ostream& out, Triangle& t){
            t.display();
            return out;
        }
        
        
        float perimeter(){
            float a = coordinates[0].distance(coordinates[1]);
            float b = coordinates[1].distance(coordinates[2]);
            float c = coordinates[0].distance(coordinates[2]);
            
            return a + b + c;
        }
        
        float area(){
            float a = coordinates[0].distance(coordinates[1]);
            float b = coordinates[1].distance(coordinates[2]);
            float c = coordinates[0].distance(coordinates[2]);
            float k = (a+b+c)/2;
            
            return sqrt(k*(k-a)*(k-b)*(k-c));   
        }
};

int main(){
    Triangle t;
    cin >> t;
    cout << "\n\nToa do cac dinh cua tam giac: " << t;
    
    cout << "\nChu vi: " << t.perimeter();
    cout << "\nDien tich: " << t.area();
        
    return 0;
}

