#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sort_and_return(vector<int> arr){
    sort(arr.begin(), arr.end(), [](int a, int b) {
        int x =0, y = 0;
        while(a > 0){
            x += a % 10;
            a /= 10;
        }
        while(b > 0){
            y += b % 10;
            b /= 10;
        }
        return x < y;
    });
    reverse(arr.begin(), arr.end());
    return arr[1];
}

int main() {
    vector<int> arr = {29,12,31,32,41,42,98};
    vector<int> arr2 = {398,344,999,911,834};
    cout << sort_and_return(arr2) << endl;
    return 0;
}