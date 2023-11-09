#include <iostream>
#include <vector>
using namespace std;

int main(){
    time_t start, end; 
    int N;
    cin >> N;
    vector<int> list1(N);
    for (int i = 0; i < N; i++) {
        list1[i] = rand() % 1000 +  4000;
    }
    time(&start);

    for(int i =0; i<N; i++) {
        // for each test case
        int p = list1[i]; // people seated on circular table
        vector<int> pos(p);
        for(int j=0; j<p; j++){
            pos[j] = j+1;
        }
        int curr = 0;
        int inc = 1;
        while(pos.size() > 1){
            pos.erase(pos.begin() + curr);
            curr = (curr + inc) % pos.size();
            inc++;
        }
        cout << pos[0] << endl;
        
    }
    time(&end);
        double time_taken = double(end - start);
        cout << "Time taken by program is : " << fixed 
            << time_taken;
    

    return 0;
}