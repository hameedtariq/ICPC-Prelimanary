
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_set>
using namespace std;

vector<vector<int>> fillDungeon() {
    const int N = 20;
    const int M = 30;

    vector<vector<int>> dungeon(N, vector<int>(M, 0));

    // Randomly select a starting point
    srand(time(NULL));
    int startX = rand() % (N - 2) + 1;
    int startY = rand() % (M - 2) + 1;
    dungeon[startX][startY] = 1;

    // Randomly select a few obstacles
    int numObstacles = 55;
    for (int i = 0; i < numObstacles; i++) {
        int obsX = rand() % (N - 2) + 1;
        int obsY = rand() % (M - 2) + 1;
        dungeon[obsX][obsY] = 2;
    }

    // Randomly select an exit
    int exitX = rand() % (N - 2) + 1;
    int exitY = rand() % (M - 2) + 1;
    dungeon[exitX][exitY] = 3;

    return dungeon;
}

int main() {
    vector<vector<int>> dungeon = fillDungeon();

    // Print the dungeon array
    for (int i = 0; i < dungeon.size(); i++) {
        for (int j = 0; j < dungeon[i].size(); j++) {
            cout << dungeon[i][j] << " ";
        }
        cout << endl;
    }
    // find starting point (1)
    int startX, startY;
    for(int i = 0; i < dungeon.size(); i++) {
        for(int j = 0; j < dungeon[i].size(); j++) {
            if(dungeon[i][j] == 1) {
                startX = i;
                startY = j;
            }
        }
    }

    return 0;
}

void bfs(vector<vector<int>> dungeon, int startX, int startY, unordered_set<int> &visited, int &steps) {
    queue<int> x;
    queue<int> y;
    x.push(startX);
    y.push(startY);
    visited.insert(startX * dungeon[0].size() + startY);
    while (!x.empty() && !y.empty()){
        if(dungeon[x.front()][y.front()] == 3) {
            return;
        }
        if(dungeon[x.front()][y.front()] != 2) {
            
            if(x.front() + 1 < dungeon.size() && visited.find((x.front() + 1) * dungeon[0].size() + y.front()) == visited.end()) {
                x.push(x.front() + 1);
                y.push(y.front());
                visited.insert((x.front() + 1) * dungeon[0].size() + y.front());
            }
            if(x.front() - 1 >= 0 && visited.find((x.front() - 1) * dungeon[0].size() + y.front()) == visited.end()) {
                x.push(x.front() - 1);
                y.push(y.front());
                visited.insert((x.front() - 1) * dungeon[0].size() + y.front());
            }
            if(y.front() + 1 < dungeon[0].size() && visited.find(x.front() * dungeon[0].size() + y.front() + 1) == visited.end()) {
                x.push(x.front());
                y.push(y.front() + 1);
                visited.insert(x.front() * dungeon[0].size() + y.front() + 1);
            }
            if(y.front() - 1 >= 0 && visited.find(x.front() * dungeon[0].size() + y.front() - 1) == visited.end()) {
                x.push(x.front());
                y.push(y.front() - 1);
                visited.insert(x.front() * dungeon[0].size() + y.front() - 1);
            }
        }

    }
    
        // dequeue a point
        // if the point is the exit
            // return
        // if the point is not a wall
            // enqueue all the neighbors
    // return
}
