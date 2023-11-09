#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){
    int N, k;
    cin >> N;
    cin >> k;
    k = min(k, N);
    int* a = new int[N];
    int* dp = new int[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i =1; i<k; i++){
        dp[i] = abs(a[i]-a[0]);
    }
    for(int i =k; i<N; i++){
        int mn = INT_MAX;
        for(int j=1; j<=k; j++){
            mn = min(dp[i-j]+abs(a[i]-a[i-j]), mn);
        }
        dp[i] = mn;
    }
    cout << dp[N-1] << endl;
    return 0;
}