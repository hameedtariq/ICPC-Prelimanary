#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int rec(vector<int>& prices, int buy,int i){
    if(i >= prices.size()) {
        return 0;
    }
    if(buy == -1){
        return rec(prices,i,i+1);
    }else {
        return max((rec(prices,-1,i+2) + (prices[i] - prices[buy])),rec(prices,buy,i+1));
    }
}

int maxProfit(vector<int>& prices) {
    return rec(prices,-1,0);
}


int main(){
    vector<int> prices = {1,2,3,0,2};
    cout << maxProfit(prices);
    return 0;
}
