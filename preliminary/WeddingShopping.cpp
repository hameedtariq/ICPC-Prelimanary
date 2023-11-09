#include<iostream>
#include<vector>
using namespace std;

bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();



int solver(vector<vector<int>>& prices, int M, int C, int i, vector<vector<int>>& dp, int& count){
    if(i == C){
        count++;
        return 0;
    }
    if(M <= 0) return 0;
    if(dp[i][M] != 0) return dp[i][M];
    // int counter = 0;
    for(int j = 0; j < prices[i].size(); j++){
        if(M - prices[i][j] >= 0){
            int temp = solver(prices, M - prices[i][j], C, i + 1, dp, count);
            dp[i][M] = max(dp[i][M], prices[i][j] + temp);
        }
    }
    return dp[i][M];    
}



int main(){
    int T;
    cin >> T;
    while(T--){
        int M, C;
        cin >> M >> C;
        int count = 0;
        vector<vector<int>> prices(C);
        vector<vector<int>> dp(C + 1, vector<int>(M + 1, 0));
        for(int i = 0; i < C; i++){
            int K;
            cin >> K;
            prices[i].resize(K);
            for(int j = 0; j < K; j++){
                cin >> prices[i][j];
            }
        }
        int ans = solver(prices, M, C, 0, dp, count);
        if(count < 1){
            cout << -1 << endl;
        }else {
            cout << ans << endl;
        }
        

    }
    
    return 0;
}