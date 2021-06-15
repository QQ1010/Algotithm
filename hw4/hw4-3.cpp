/*
fordfulkerson algrothim 參考https://www.itread01.com/content/1545247022.html
*/

#include <iostream>
#include <queue>
#include <stdint.h>
using namespace std;

int32_t graph[200][200] = {0}; 
int32_t t[200] = {0};
int32_t m,n;
void print_graph() {
    for(int32_t i = 0 ; i <= n+m+1 ; i++){
        for(int32_t j = 0 ; j <= n+m+1 ; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void print(int32_t arr[200]) {
    for(int32_t i = m+n+1 ; i != 0 ; i = arr[i]) {
        cout << "path" << i << "=" << arr[i] << " ";
    }
    cout << endl;
}

bool bfs(int32_t graph[200][200], int32_t path[200],int32_t t) {
    queue<int32_t> q;
    int32_t visited[200] = {0};
    visited[0] = 1;
    path[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int32_t route = q.front();
        if(route == t) {
            return true;
        }
        for(int32_t i = 0 ; i <= t ; i++){
            if(graph[route][i] != 0 && visited[i] != 1) {
                q.push(i);
                path[i] = route;
                visited[i] = 1;
                // print(path);
            }
        }
        q.pop();
    }
    return false;
}

int32_t my_ford_fulkerson(int32_t s,int32_t t) {  // s = 0 , t = n+m+1
    int32_t f = 0;
    int32_t path[200];
    while(bfs(graph,path,t)) {
        // print(path);
        for(int32_t i = t ; i != 0 ; i = path[i]){
            int32_t j = path[i];
            // printf("%d %d\n",i,j);
            graph[i][j] += 1;
            graph[j][i] -= 1;
            // print_graph();
        }
        f += 1;
    }
    return f;
}

int main() {
    cin >> n >> m;
    int32_t tmp;
    for(int32_t i = 1 ; i <= n ; i++){
        cin >>t[i];
        for(int32_t j = 1 ; j <= t[i] ; j++){
            cin >> tmp;
            tmp += n;
            graph[i][tmp] += 1;
        }
    }
    for(int32_t i = 1;i <= n ;i++) {
        graph[0][i] = 1;
    }
    for(int32_t i = n+1 ; i <=n+m ; i++) {
        graph[i][n+m+1] = 2;
    }
    // print_graph();
    int32_t ans = my_ford_fulkerson(0,m+n+1);
    // print_graph();
    printf("%d\n",ans);
    return 0;
}