#include <bits/stdc++.h>

using namespace std;

int priority(char x){
    if ((x == '*') ||
       (x == '/'))
       return 2;
       
    if ((x == '+') ||
       (x == '-'))
       return 1;
    
    return -1;
}

bool higherPriority(char a, char b){
    return priority(a) >= priority(b);
}

bool isNumber(char c){
    return '0' <= c && c <= '9';
}

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string postfix(string s){
    stack<char> st;
    string pf = "";
    int n = s.size();
    
    for (int i=0; i<n; i++){
        if (isOperator(s[i])){
            while (!st.empty() &&
                   st.top() != '(' &&
                   higherPriority(st.top(), s[i])){
                       pf += st.top();
                       st.pop();
                   }
            
            st.push(s[i]);
        }
        else if (isNumber(s[i])){
            pf += s[i];
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (!st.empty() &&
                   st.top() != '('){
                       pf += st.top();
                       st.pop();
                   }
            st.pop();
        }
    }
    
    while (!st.empty()){
        pf += st.top();
        st.pop();
    }
    
    return pf;
}

double calc(double a, char x, double b){
    if (x == '+') return a+b;
    if (x == '-') return a-b;
    if (x == '*') return a*b;
    return a/b;
}

double calc(string s){
    stack<double> num;
    int n = s.size();
    
    for (int i=0; i<n; i++){
        if (isNumber(s[i])){
            num.push((double)(s[i] - '0'));
        }
        else {
            double b = num.top();
            num.pop();
            double a = num.top();
            num.pop();
            num.push(calc(a, s[i], b));
        }
    }
    
    return num.top();
}

int main(){
    string str;
    cin >> str;
    cout << calc(postfix(str));
    
	return 0;
}

