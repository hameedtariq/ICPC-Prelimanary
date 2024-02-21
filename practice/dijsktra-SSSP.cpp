#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<unordered_map>
#include<utility>
#include<unordered_set>
using namespace std;



class Graph {
    unordered_map<char, list<pair<int,char>>> graph;
public:
    void addEdge(char u, char v,char w){
        graph[u].push_back({w,v});
    }

    void dijsktraSSSP(char startNode, char endNode){
        unordered_map<char, int> dist;
        unordered_map<char, char> parent;
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
        unordered_set<char> visited;
        for(auto node: graph){
            dist[node.first] = INT_MAX;
        }

        dist[startNode] = 0;
        pq.push({0, startNode});
        parent[startNode] = startNode;


        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(visited.find(curr.second) != visited.end()){
                continue;
            }
            visited.insert(curr.second);
            if(dist[curr.second] < curr.first){
                continue;
            }
            cout << curr.second << " " << curr.first << endl;
            for(auto nbr: graph[curr.second]){
                if(dist.find(nbr.second) == dist.end()){
                    dist[nbr.second] = INT_MAX;
                }
                if(dist[nbr.second] > dist[curr.second] + nbr.first){
                    dist[nbr.second] = dist[curr.second] + nbr.first;
                    pq.push({dist[nbr.second], nbr.second});
                    parent[nbr.second] = curr.second;
                }
            }


            
        }

        // for(auto node: dist){
        //     cout<<node.first<<" "<<node.second<<endl;
        // }

        cout<<"Shortest distance from "<<startNode<<" to "<<endNode<<" is "<<dist[endNode]<<endl;
        cout<<"Path is: ";
        char temp = endNode;
        while(temp != startNode){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<startNode<<endl;
        
    }

};



int main(){
    Graph g;

    g.addEdge('A', 'B',2);
    g.addEdge('A', 'C',4);
    g.addEdge('B', 'D',3);
    g.addEdge('B', 'E',5);
    g.addEdge('C', 'E', 1);
    g.addEdge('D', 'F',6);
    g.addEdge('E', 'F', 1);
    g.addEdge('E', 'G', 5);

    char startNode = 'A';
    char endNode = 'G';

    g.dijsktraSSSP(startNode, endNode);





    return 0;
}