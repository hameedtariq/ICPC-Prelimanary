#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int N;
    cin >> N;

    int* a = new int[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    int p1 = 0;
    int p2 = abs(a[1]-a[0]);
    for(int i =2; i<N; i++){
        int temp = p2;
        p2 = min(p2+abs(a[i]-a[i-1]), p1+abs(a[i]-a[i-2]));
        p1 = temp;
    }
    cout << p2 << endl;
    return 0;
}