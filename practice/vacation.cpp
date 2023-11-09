#include <iostream>
#include <vector>

using namespace std;


int solveRecursive(vector<vector<int>> & x, int row, int prev, vector<vector<int>>&memo){
    if(x.size() == row) {
        return 0;
    }
    switch(prev) {
        case 0:
            memo[row][1] = memo[row][1] != -1 ? memo[row][1] : x[row][1] + solveRecursive(x, row+1,1,memo);
            memo[row][2] = memo[row][2] != -1 ? memo[row][2] : x[row][2] + solveRecursive(x, row+1,2,memo);
            return max(memo[row][2],memo[row][1]);
            break;
        case 1:
            memo[row][0] = memo[row][0] != -1 ? memo[row][0] : x[row][0] + solveRecursive(x, row+1,0,memo);
            memo[row][2] = memo[row][2] != -1 ? memo[row][2] : x[row][2] + solveRecursive(x, row+1,2,memo);
            return max(memo[row][2],memo[row][0]);
            break;
        case 2:
            memo[row][1] = memo[row][1] != -1 ? memo[row][1] : x[row][1] + solveRecursive(x, row+1,1,memo);
            memo[row][0] = memo[row][0] != -1 ? memo[row][0] : x[row][0] + solveRecursive(x, row+1,0,memo);
            return max(memo[row][0],memo[row][1]);
            break;
    }
    return 0;
}

int solve(vector<vector<int>> & x, int row){
    vector<vector<int>> memo;
    for(int i =0; i< x.size();i++){
        memo.push_back(vector<int>(3,-1));
    }
    return max(max(x[row][1] + solveRecursive(x, row+1,1,memo), x[row][2] + solveRecursive(x, row+1,2,memo)), x[row][0] + solveRecursive(x, row+1,0,memo));
}

int main(){
    int N;
    vector<vector<int>> a;
    cin >> N;
    for(int i =0; i<N; i++){
        vector<int> temp(3);
        for(auto &v: temp){
            cin>>v;
        }
        a.push_back(temp);
    }
    
    cout << solve(a, 0) << endl;

    return 0;
}