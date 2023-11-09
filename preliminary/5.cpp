#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>
#include<unordered_set>
using namespace std;


std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string token;

    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}

bool canDerive(unordered_map<char, vector<char>>& m, char x, char y, unordered_set<char>& visited) {
    if(visited.find(x) != visited.end()) return false;
    visited.insert(x);
    if(x == y) return true;
    if(m.find(x) == m.end()) return false;
    for(char c : m[x]){
        if(canDerive(m, c, y, visited)) return true;
    }
    return false;
}

bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();

int main(){
    string s, v;
    getline(cin, s);
    getline(cin, v);
    unordered_map<char, vector<char>> m;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || s[i] == ',') continue;
        if(m.find(s[i]) == m.end()){
            m[s[i]] = vector<char>();
        }
        m[s[i]].push_back(v[i]);
    }
    string t;
    while(getline(cin, t)){
        auto protiens = split(t, ' ');
        string s1 = protiens[0], s2 = protiens[1];
        if(s1.size() != s2.size()){
            cout << "No" << endl;
            continue;
        }
        if(s1.size() < 3 || s1.size() >= 20) {
            cout << "No" << endl;
            continue;
        }
        if(s1 == s2){
            cout << "Yes" << endl;
            continue;
        }
        
        bool mapping = true;
        for(int i = 0; i < s1.size(); i++){
            char x = s1[i];
            char y = s2[i];
            unordered_set<char> visited;
            if(canDerive(m, x, y, visited)) continue;
            else{
                mapping = false;
                break;
            }            
        }
        if(mapping) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}