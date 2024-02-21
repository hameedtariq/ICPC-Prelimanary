#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<char,char> m = {
    {']', '['},
    {')', '('},
    {'}', '{'}
};


bool isValid(string str) {
    stack<char> s;
    for(auto&a: str){
        if(a == '[' || a== '{' || a == '('){
            s.push(a);
        }else if(a == ']' || a == '}' || a ==')'){
            if(s.empty() ||s.top() != m[a]){
                return false;                
            }else {
                s.pop();
            }
        }
    }
    return s.empty();
}


int main() {
    cout << isValid("[(})]") << endl;
    return 0;
}