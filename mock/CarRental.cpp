#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    int n,k;
    for(int i = 0; i<T; i++){
        
        cin >> n; // number of requests
        cin >> k; // number of drivers
        vector<vector<int>> arr;
        for(int j = 0; j<n; j++){
            vector<int> temp;
            for(int l =0; l < n-j; l++ ){
                int a;
                cin >> a;
                temp.push_back(a);
            }
            arr.push_back(temp);
        }
        int minimumMovingCost = 0;
        for(int j = 0; j<n; j++){
            
        }




    }


    return 0;
}