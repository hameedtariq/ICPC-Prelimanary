#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> list1(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        list1[i] = a;
    }

    vector<int> list2(n);
    for (int i = 0; i < n; i++) {
        int b = list1[i];
        if (b < 6) {
            list2[i] = b;
        } else {
            int red = b / 2;
            int rem = list1[i] - red;
            rem = rem - 3;
            list2[i] = (rem * red) + red*2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << list2[i] <<endl;
    }

    return 0;
}
