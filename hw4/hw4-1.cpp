#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int32_t n,m;
int32_t p,q,w;
int32_t graph[1000][1000] = {0};
/*
class undirect_graph {
    public:
    undirect_graph() {};
    undirect_graph(int32_t in_num) {
        num = in_num;
        adjMatrix = new int32_t*[num];
        for(int32_t i = 0 ; i < num ; i++) {
            adjMatrix[i] = new int32_t[num];
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
    private:
    int32_t num;
    int32_t **adjMatrix;
    int32_t *visited;
};*/
bool cycle(int32_t index,int32_t next,int32_t pre,int32_t* count,int32_t target,int32_t visited[1000]) {
    // cout << index << next << pre << *(count) << target;
    if(visited[index] == 1 && index == target) {
        // cout << "stop" << endl;
        return true;
    }
    // cout << "check1" << endl;
    for(next ; next <= n ; next++) {
        // cout << index << next << pre << *(count) << target;
        // cout << "check2" << endl;
        if(graph[index][next] != 0 && next != pre) {
            visited[index] = 1;
            (*count) += graph[index][next];
            // cout << next << 1 << index << *(count) << target << endl;
            if(cycle(next,1,index,count,target,visited)) {
                // cout << (*count) << endl;
                return true;
            }
        }
    }
    (*count) = 0;
    return false;
}
void printgraph() {
        for(int32_t i = 0 ; i <= n ; i++) {
            for(int32_t j = 0 ; j <= n ; j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
int main() {
    cin >> n >> m;
    for(int32_t k = 0 ; k < m ; k++) {
        cin >> p >> q >> w;
        graph[p][q] = w;
        graph[q][p] = w;
    }
    // printgraph();
    int32_t count[1000][2] = {0};
    for(int32_t k = 1 ; k <= n ; k++) {
        for(int32_t g = 1 ; g <= n ; g++) {
            int32_t visited[1000] = {0};
            cycle(k,g,0,&count[k][0],k,visited);
            // cout << "count = " << count[k][0] << endl;
            if(g == 1) {
                count[k][1] = count[k][0];
            }
            if(count[k][1] > count[k][0] && count[k][0] != 0) {
                count[k][1] = count[k][0];
            }
            count[k][0] = 0;
        }

    }
    // cout << "count" << endl;
    int32_t ans = count[1][1];
    for(int32_t k = 1 ; k <= n ; k++) {
        if(count[k][1] < ans) {
            ans = count[k][1];
        }
        // cout << count[k][1] << " ";
    }
    // cout << endl;
    if(ans > 0) {
        cout << ans << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}