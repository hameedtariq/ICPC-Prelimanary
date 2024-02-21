#include<iostream>
#include<vector>

using namespace std;


int rec(vector<int>& nums, int target, int i){
    // if(target == 0) return 1;
    if(i == nums.size() && target == 0) return 1;
    if(i == nums.size()) return 0;
    int plus = rec(nums,target-nums[i], i+1);
    int minus = rec(nums,target+nums[i], i+1);
    return plus + minus;
}

int findTargetSumWays(vector<int>& nums, int target) {
    return rec(nums,target, 0);
}

int main() {
    vector<int> x = {1,1,1,1,1};
    cout << findTargetSumWays(x, 3);
}