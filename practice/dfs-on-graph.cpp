#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(unordered_map<char, vector<char>>& graph, unordered_map<char, bool>& visited, vector<char>& path, char node){
    visited[node] = true;
    path.push_back(node);

    for (char neighbor : graph[node]){
        if (!visited[neighbor]){
            dfs(graph, visited, path, neighbor);
        }
    }
}

int main(){
    unordered_map<char, vector<char>> graph;
    graph['A'] = {'B', 'C'};
    graph['B'] = {'D', 'E'};
    graph['C'] = {'F'};
    graph['D'] = {};
    graph['E'] = {'F'};
    graph['F'] = {'B', 'D'};

    unordered_map<char, bool> visited;
    vector<char> path;
    for(auto& node : graph){
        if(!visited[node.first]){
            dfs(graph, visited, path, node.first);
            for (char node : path){
                cout << node << " ";
            }
            cout << endl;
            path.clear();            
        }
    }
    
    return 0;   
}