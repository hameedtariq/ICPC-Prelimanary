#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long int solveRecursive(vector<vector<int>> &x, int i, int w, vector<vector<long long>>& m) {
    if(i == x.size() || w <= 0) return 0;
    if(m[x.size() -i -1][w] != -1) return m[x.size() -i -1][w];
    long long int x1 = 0, x2 = 0;
    if(w - x[i][0] >= 0){
        x1 = x[i][1] + solveRecursive(x,i+1,w - x[i][0],m); // item i taken
    }
    x2 = solveRecursive(x,i+1,w,m); // item not taken
    m[x.size() -i-1][w] = max(x1,x2);
    return m[x.size() -i -1][w];
}


int main(){
    vector<vector<int>> x;
    int N,W;
    cin >> N;
    cin >> W;
    for(int i =0; i<N; i++){
        int t;
        vector<int> temp;
        cin >> t;
        temp.push_back(t);
        cin >> t;
        temp.push_back(t);
        x.push_back(temp);
    }
    vector<vector<long long>> memo;
    for(int i =0; i<N; i++){
        memo.push_back(vector<long long>(W+1, -1));
    }
    cout << solveRecursive(x, 0, W,memo) << endl;

    return 0;
}