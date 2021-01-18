#include <bits/stdc++.h>

using namespace std;

template <class T>
class Vector {
    private:
        vector<T> coordinates;
        
    public:
        Vector(){
            coordinates = vector<T>(1, 0);
        }
        
        Vector(int n){
            coordinates = vector<T>(n, 0);
        }
        
        Vector(vector<T> coordinates){
            this->coordinates = coordinates;
        }
        
        ~Vector(){
            coordinates.clear();
        }
        
        vector<T> getCoordinates() { return coordinates; }
        void setCoordinates(vector<T> v){
            coordinates = v;
        }
        void setCoordinates(int i, T value){
            if (0 <= i && i < coordinates.size()){
                coordinates[i] = value;
            }
        }
        
        void operator= (Vector<T> v){
            coordinates = v.getCoordinates();
        }
        
        Vector<T> operator- (){
            vector<T> va = getCoordinates();
            int n = va.size();
            vector<T> vres(n, 0);
            
            for (int i=0; i<n; i++){
                vres[i] = -va[i];
            }
            
            return Vector(vres);
        }
        
        Vector<T> operator+ (Vector<T> b){
            vector<T> vres = getCoordinates();
            vector<T> vb = b.getCoordinates();
            int n = vres.size();
            
            for (int i=0; i<n; i++){
                vres[i] += vb[i];
            }
            
            return Vector(vres);
        }

        friend Vector<T> operator- (Vector<T> a, Vector<T> b){
            return Vector(a + (-b));
        }
        
        T operator* (Vector<T> b){
            vector<T> va = getCoordinates();
            vector<T> vb = b.getCoordinates();
            int n = va.size();
            T res = 0;
            
            for (int i=0; i<n; i++){
                res += va[i]*vb[i];
            }
            
            return res;
        }
        
        friend istream& operator>> (istream& in, Vector<T>& v){
            int n = v.getCoordinates().size();
            for (int i=0; i<n; i++){
                T t;
                in >> t;
                v.setCoordinates(i, t);
            }
            
            return in;
        }
        
        friend ostream& operator<< (ostream& out, Vector<T> v){
            vector<T> o = v.getCoordinates();
            int n = o.size();
            
            if (n > 0){
                out << '(';
                for (int i=0; i<n; i++){
                    out << o[i];
                    if (i != n-1) out << ", ";
                }
                out << ')';
            }
            
            return out;
        }
};

int main(){
    Vector<double> v1(3);
    Vector<double> v2({1, 2, 3});
    
    cout << "Hay nhap vector v1: ";
    cin >> v1;
    
    cout << endl << "Vector v1: " << v1 << endl << "Vector v2: "<< v2 << endl; 
    
    Vector<double> v3 = v1 + v2;
    
    cout << endl << "v1 + v2 = " << v3;
    cout << endl << "v1 * v2 = " << v1 * v2;
    cout << endl << "v1 - v2 = " << v1 - v2;
    cout << endl << "-v2 = " << -v2;
    
    return 0;
}

