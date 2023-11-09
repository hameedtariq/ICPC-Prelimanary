#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;
const int INF = 1e9;

int dp[MAX_N][MAX_N];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> cost(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> cost[i][j];
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < i; x++) {
                    dp[i][j] = min(dp[i][j], dp[x][j - 1] + cost[x][i - x - 1]);
                }
            }
        }

        int min_cost = INF;
        for (int j = 0; j <= k; j++) {
            min_cost = min(min_cost, dp[n][j]);
        }

        cout << min_cost << endl;
    }

    return 0;
}
