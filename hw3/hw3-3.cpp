#include <iostream>
#include <queue>

using namespace std;

typedef struct _position {
    int32_t x;
    int32_t y;
}position;


int main() {
    int32_t n,m;
    cin >> n >> m;
    queue<position> q;
    queue<position> p;
    int32_t k = n*m;
    int32_t B_position[2] = {0};
    int32_t P_position[2] = {0};
    int32_t T_position[2] = {0};
    bool bvisited[35][35] = {false};
    char map[35][35] = {'0'};
    for(int32_t i = 1 ; i < n+1 ; i++) {
        for(int32_t j = 1 ; j < m+1 ; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'B') {
                B_position[0] = i;
                B_position[1] = j;
            }
            else if(map[i][j] == 'P') {
                P_position[0] = i;
                P_position[1] = j;
            }
            else if(map[i][j] == 'T') {
                T_position[0] = i;
                T_position[1] = j;
            }
        }
    }
    int32_t ans = 0;
    bool BT = false;
    q.push(position{B_position[0],B_position[1]});
    p.push(position{P_position[0],P_position[1]});
    for(int32_t i = 0 ; i < k ; i++) {
        position tmp = q.front();
        cout << map[tmp.x][tmp.y] << endl;
        if(q.empty()) {
            break;
        }
        ans ++;
        if(map[tmp.x][tmp.y] == 'T') {
            BT = true;
            break;
        }
        if(map[tmp.x-1][tmp.y] == '.' && bvisited[tmp.x-1][tmp.y] == false) {
            bool PB = false;
            bool pvisited[35][35] = {false};
            for(int32_t j = 0 ; j < k ; j++) {
                if(p.empty()){
                    break;
                }
                position ptmp = p.front();
                if(ptmp.x == tmp.x+1 && ptmp.y == tmp.y){
                    PB = true;
                    p = queue<position>();
                    p.push(position{P_position[0],P_position[1]});
                    break;
                }
                if(map[ptmp.x-1][ptmp.y] == '.' && pvisited[ptmp.x-1][ptmp.y] == false)
                    p.push(position{ptmp.x-1,ptmp.y});
                if(map[ptmp.x+1][ptmp.y] == '.' && pvisited[ptmp.x+1][ptmp.y] == false)
                    p.push(position{ptmp.x+1,ptmp.y});
                if(map[ptmp.x][ptmp.y-1] == '.' && pvisited[ptmp.x][ptmp.y-1] == false)
                    p.push(position{ptmp.x,ptmp.y-1});
                if(map[ptmp.x][ptmp.y+1] == '.' && pvisited[ptmp.x][ptmp.y+1] == false)
                    p.push(position{ptmp.x,ptmp.y+1});
                pvisited[ptmp.x][ptmp.y] = true;
                p.pop();
            }
            if(PB) {
                q.push(position{tmp.x-1 , tmp.y});
                P_position[0] = tmp.x;
                P_position[1] = tmp.y;
            }
        }
        if(map[tmp.x+1][tmp.y] == '.' && bvisited[tmp.x+1][tmp.y] == false) {
            bool PB = false;
            bool pvisited[35][35] = {false};
            for(int32_t j = 0 ; j < k ; j++) {
                if(p.empty()){
                    break;
                }
                position ptmp = p.front();
                if(ptmp.x == tmp.x-1 && ptmp.y == tmp.y){
                    PB = true;
                    p.push(position{P_position[0],P_position[1]});
                    p = queue<position>();
                    break;
                }
                if(map[ptmp.x-1][ptmp.y] == '.' && pvisited[ptmp.x-1][ptmp.y] == false)
                    p.push(position{ptmp.x-1,ptmp.y});
                if(map[ptmp.x+1][ptmp.y] == '.' && pvisited[ptmp.x+1][ptmp.y] == false)
                    p.push(position{ptmp.x+1,ptmp.y});
                if(map[ptmp.x][ptmp.y-1] == '.' && pvisited[ptmp.x][ptmp.y-1] == false)
                    p.push(position{ptmp.x,ptmp.y-1});
                if(map[ptmp.x][ptmp.y+1] == '.' && pvisited[ptmp.x][ptmp.y+1] == false)
                    p.push(position{ptmp.x,ptmp.y+1});
                pvisited[ptmp.x][ptmp.y] = true;
                p.pop();
            }
            if(PB) {
                q.push(position{tmp.x+1 , tmp.y});
                P_position[0] = tmp.x;
                P_position[1] = tmp.y;
            }
        }
        if(map[tmp.x][tmp.y-1] == '.' && bvisited[tmp.x][tmp.y-1] == false) {
            bool PB = false;
            bool pvisited[35][35] = {false};
            for(int32_t j = 0 ; j < k ; j++) {
                if(p.empty()) {
                    break;
                }
                position ptmp = p.front();
                if(ptmp.x == tmp.x && ptmp.y == tmp.y+1){
                    PB = true;
                    p = queue<position>();
                    p.push(position{P_position[0],P_position[1]});
                    break;
                }
                if(map[ptmp.x-1][ptmp.y] == '.' && pvisited[ptmp.x-1][ptmp.y] == false)
                    p.push(position{ptmp.x-1,ptmp.y});
                if(map[ptmp.x+1][ptmp.y] == '.' && pvisited[ptmp.x+1][ptmp.y] == false)
                    p.push(position{ptmp.x+1,ptmp.y});
                if(map[ptmp.x][ptmp.y-1] == '.' && pvisited[ptmp.x][ptmp.y-1] == false)
                    p.push(position{ptmp.x,ptmp.y-1});
                if(map[ptmp.x][ptmp.y+1] == '.' && pvisited[ptmp.x][ptmp.y+1] == false)
                    p.push(position{ptmp.x,ptmp.y+1});
                pvisited[ptmp.x][ptmp.y] = true;
                p.pop();
            }
            if(PB) {
                q.push(position{tmp.x , tmp.y-1});
                P_position[0] = tmp.x;
                P_position[1] = tmp.y;
            }
        }
        if(map[tmp.x][tmp.y+1] == '.' && bvisited[tmp.x][tmp.y+1] == false) {
            bool PB = false;
            bool pvisited[35][35] = {false};
            for(int32_t j = 0 ; j < k ; j++) {
                if(p.empty()){
                    break;
                }
                position ptmp = p.front();
                if(ptmp.x == tmp.x && ptmp.y == tmp.y-1){
                    PB = true;
                    p.push(position{P_position[0],P_position[1]});
                    break;
                }
                if(map[ptmp.x-1][ptmp.y] == '.' && pvisited[ptmp.x-1][ptmp.y] == false)
                    p.push(position{ptmp.x-1,ptmp.y});
                if(map[ptmp.x+1][ptmp.y] == '.' && pvisited[ptmp.x+1][ptmp.y] == false)
                    p.push(position{ptmp.x+1,ptmp.y});
                if(map[ptmp.x][ptmp.y-1] == '.' && pvisited[ptmp.x][ptmp.y-1] == false)
                    p.push(position{ptmp.x,ptmp.y-1});
                if(map[ptmp.x][ptmp.y+1] == '.' && pvisited[ptmp.x][ptmp.y+1] == false)
                    p.push(position{ptmp.x,ptmp.y+1});
                pvisited[ptmp.x][ptmp.y] = true;
                p.pop();
            }
            if(PB) {
                q.push(position{tmp.x , tmp.y+1});
                P_position[0] = tmp.x;
                P_position[1] = tmp.y;
            }
        }
        bvisited[tmp.x][tmp.y] = true;
        q.pop();
    }
    cout << ans << endl;
}

