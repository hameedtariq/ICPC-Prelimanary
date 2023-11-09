#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_set>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
//         int crossings, roads;
//         cin>>crossings>>roads;
//         unordered_map<int, vector<int>> graph;
//         for(int i=0; i<roads; i++){
//             int a, b;
//             cin>>a>>b;
//             graph[a].push_back(b);
//             graph[b].push_back(a);
//         }
// //         Output 5 integers, the index of the top 5 crossings where the jagga collection point should be
// // established to maximize the bandits' revenue. If there are multiple valid solutions, output the
// // one with the smallest index. 
        
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> adj;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj.push_back({v, 1});
            adj.push_back({u, 1});
        }

        vector<int> top5;
        priority_queue<pair<int, int>> pq;

        vec
        

        
    }
}