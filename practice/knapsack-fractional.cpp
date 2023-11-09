#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


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

    sort(x.begin(), x.end(), [](auto &a, auto&b) {
        return a[1]/a[0] > b[1]/b[0];
    });

    long long int profit = 0;
    for(auto& a: x){
        if(W <= 0) break;
        if(W - a[0] >= 0) {
            profit += a[1];
            W -= a[0];
        }
    }
    cout << profit << endl;
    return 0;
}