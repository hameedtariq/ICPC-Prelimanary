#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int budget, M, C;
        cin >> budget >> M >> C;

        vector<vector<int>> garments(C, vector<int>());
        vector<vector<bool>> dp(C + 1, vector<bool>(budget + 1, false));

        for (int i = 0; i < C; i++) {
            int k;
            cin >> k;
            garments[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> garments[i][j];
            }
        }

        dp[0][0] = true;

        for (int i = 0; i < C; i++) {
            for (int j = 0; j < garments[i].size(); j++) {
                for (int k = budget; k >= garments[i][j]; k--) {
                    dp[i + 1][k] = dp[i][k - garments[i][j]];
                }
            }
        }

        int max_spent = -1;
        for (int k = budget; k >= 0; k--) {
            if (dp[C][k]) {
                max_spent = k;
                break;
            }
        }

        cout << max_spent << endl;
    }

    return 0;
}