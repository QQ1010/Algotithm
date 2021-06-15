#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class undirect_graph {
    public:
    undirect_graph() {};
    undirect_graph(int num) {
        adjMatrix = new int*[num];
        for(int i = 0 ; i < num ; i++) {
            adjMatrix[i] = new int[num];
        }
    }
    void addedges(int32_t i,int32_t j,int32_t w) {
        adjMatrix[i][j] = w;
        adjMatrix[j][i] = w;
    }
    void removeedges(int32_t i,int32_t j) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }
    void printgraph() {
        for(int32_t i = 0 ; i < num ; i++) {
            for(int32_t j = 0 ; j < num ; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool bfs(int32_t path[200],int32_t s,int32_t t) {
        queue<int32_t> q;
        int32_t visited[200] = {0};
        visited[s] = 1;
        path[s] = s;
        q.push(s);
        while(!q.empty()) {
            int32_t route = q.front();
            if(route == t) {
                return true;
            }
            for(int32_t i = 0 ; i <= t ; i++){
                if(adjMatrix[route][i] != 0 && visited[i] != 1) {
                    q.push(i);
                    path[i] = route;
                    visited[i] = 1;
                }
            }
            q.pop();
        }
        return false;
    }
    private:
    int num;
    int **adjMatrix;
};