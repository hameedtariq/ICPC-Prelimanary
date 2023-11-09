#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

    for(int i =1; i<= s.size(); i++){
        for(int j=1; j<=t.size(); j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string lcs = "";
    int i = s.size(), j = t.size();
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            lcs = s[i-1] + lcs;
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else {
            j--;
        }
    }

    cout << lcs << endl;

    return 0;
}