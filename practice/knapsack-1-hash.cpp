#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define a type to represent the arguments for memoization (N, W)
using MemoKey = pair<int, int>;

// Define a hash function for the MemoKey type
struct MemoKeyHash {
    size_t operator()(const MemoKey& key) const {
        return hash<int>()(key.first) ^ (hash<int>()(key.second) << 1);
    }
};

// Memoization map
unordered_map<MemoKey, int, MemoKeyHash> memo;

int knapsack(vector<int>& weights, vector<int>& values, int N, int W) {
    // Check if the result for these arguments is already memoized
    if (memo.find({N, W}) != memo.end())
        return memo[{N, W}];

    // Base case: if no items or knapsack capacity is 0
    if (N == 0 || W == 0) {
        return 0;
    }

    // If the weight of the current item exceeds the remaining capacity, skip it
    if (weights[N - 1] > W) {
        memo[{N, W}] = knapsack(weights, values, N - 1, W);
        return memo[{N, W}];
    }

    // Consider two cases: either select the current item or don't
    int includeItem = values[N - 1] + knapsack(weights, values, N - 1, W - weights[N - 1]);
    int excludeItem = knapsack(weights, values, N - 1, W);

    // Choose the maximum value between including and excluding the current item
    memo[{N, W}] = max(includeItem, excludeItem);
    return memo[{N, W}];
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
