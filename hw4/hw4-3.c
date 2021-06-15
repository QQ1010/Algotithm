#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int32_t map[110][110] = {0};
int32_t visited[110] = {0};
int32_t a[110] = {0};
int32_t n,m;

void print_map() {
    for(int32_t i = 0 ; i <= n+m ; i++){
        for(int32_t j = 1 ; j <= n ; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void print_visited() {
    for(int32_t i = 1 ; i <= m+n+1 ; i++) {
        printf("%d ",visited[i]);
    }
    printf("\n");
}

int32_t my_method(int32_t s,int32_t t,int32_t l) {
    for(int32_t i = 1 ; i <= n ; i++){
        if(visited[a[i]] != 1){
            int32_t route = map[0][a[i]];
            int32_t index = 1;
            while(map[route][index] != 0) {
                // printf("%d %d %d   ",route,index,map[route][index]);
                if(visited[map[route][index]] < l) {
                    visited[a[i]] = 1;
                    visited[map[route][index]] += 1;
                    return 1;
                }
                index ++;
                // print_visited();
            }
        }
    }
    return 0;
}

int32_t my_ford_fulkerson(int32_t s,int32_t t) {  // s = 0 , t = m+n+1
    int32_t f = 0;
    while(my_method(s,t,2)) {
        f += 1;
        // print_visited();
    }
    // printf("%d\n",f);
    // if(f < n) {   
    //     while(my_method(s,t,2)) {
    //         f += 1;
    //     }
    // //     // print_visited();
    // }
    return f;
}

int main() {
    scanf("%d %d",&n,&m);
    int32_t t[110] = {0};
    for(int32_t i = 1 ; i <= n ; i++){
        scanf("%d",&t[i]);
        for(int32_t j = 1 ; j <= t[i] ; j++){
            scanf("%d",&map[i][j]);
            map[i][j] += n;
        }
    }
    if(n == m == 1 && map[1][1] == 0) {
        printf("0\n");
        return 0;
    }
    int32_t tmp = 1;
    for(int32_t i = 1 ; i <= m ; i++) {
        for(int32_t j = 1 ; j <= n ;j ++) {
            if(t[j] == i) {
                a[tmp++] = j;
            }

        }
    }
    // for(int32_t i = 1 ; i < tmp ; i++) {
    //     printf("a[%d] = %d ",i,a[i]);
    // }
    // printf("\n");
    for(int32_t i = 1 ; i <= n ; i++){      //initial s
        map[0][i] = i;
    }
    for(int32_t i = n+1 ; i <= m+n ; i++){  //initial t
        map[i][1] = m+n+1;
    }
    // print_map();
    int32_t ans = my_ford_fulkerson(0,m+n+1);
    printf("%d\n",ans);
    return 0;
}