#include<iostream>
#include "TopologicalSort.cpp"
using namespace std;




int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> topsort = g.topologicalSort();

    for(int i = 0; i < topsort.size(); i++){
        cout << topsort[i] << " ";
    }
    cout << endl;

    vector<int> dist(6, INT_MAX);

    dist[topsort[0]] = 0;

    vector<int> parent(6, -1);

    for(int i = 0; i < topsort.size(); i++){
        if(dist[topsort[i]] == INT_MAX){
            continue;
        }
        list<int>::iterator j;
        for(j = g.adj[topsort[i]].begin(); j != g.adj[topsort[i]].end(); j++){
            
            if(dist[*j] > dist[topsort[i]] + 1){
                parent[*j] = topsort[i];
                dist[*j] = dist[topsort[i]] + 1;
            }
        }
    }

    for(int i=0; i< topsort.size(); i++){
        cout << dist[topsort[i]] << " ";
    }

    cout << endl;

    // path to 3
    int x = 3;
    while(x != -1){
        cout << x << " ";
        x = parent[x];
    }
    return 0;
}