#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int main() {

    unordered_map<int, vector<int>> graph;
    graph[1] = {2, 3};
    graph[2] = {1, 3};
    graph[3] = {1, 2, 4};
    graph[4] = {3, 5};
    graph[5] = {4, 6};
    graph[6] = {5, 1};
    
    unordered_set<int> visited;
    queue<int> q;
    int connectedComponents = 0;

    for (auto node : graph) {
        if (visited.find(node.first) == visited.end()) {
            q.push(node.first);
            visited.insert(node.first);
            connectedComponents++;
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }

    return 0;
}