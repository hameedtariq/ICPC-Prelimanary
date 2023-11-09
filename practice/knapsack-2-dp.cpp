#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int N, int W) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;
    cin >> N;
    cin >> W;

    vector<int> weights(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
        cin >> values[i];
    }
    int maxProfit = knapsack(weights, values, N, W);
    cout << maxProfit << endl;

    return 0;
}

