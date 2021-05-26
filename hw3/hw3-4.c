#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
int32_t n,d;
bool AC = false;
int32_t map[3010][3010] = {0};
int32_t a[3010];

int cmp(const void *a , const void *b) {
    return (* (int *)a - *(int *)b); 
}

void print() {
    for(int32_t i = 1 ; i <= n ; i++) {
        for(int32_t j = 1 ; j <= n ; j++) {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void bear_dfs(int32_t rad,int32_t index,int32_t next,bool visited[],int32_t ans[],int32_t *tmp) {
    if(rad < d) {
        while(map[index][next] != 0) {
            if(map[index][next] != 0 && visited[map[index][next]] == false) {
                visited[map[index][next]] = true;
                ans[(*tmp)++] = map[index][next];
                // printf("index = %d next = %d ans[%d] = %d\n",index,next,(*tmp)-1,(ans[(*tmp)-1]));
                bear_dfs(rad+1,map[index][next],1,visited,ans,tmp);
            }
            next ++;
        }
        return ;
    }
    return ;
}

int main() {
    scanf("%d %d",&n,&d);
    int32_t t1,t2;
    for(int32_t i = 0 ; i < 3010 ; i++) {
        a[i] = 1;
    }
    for(int32_t i = 0 ; i < n-1 ; i++) {
        scanf("%d %d",&t1,&t2);
        map[t1][a[t1]++] = t2;
        map[t2][a[t2]++] = t1;
    }
    for(int32_t i = 1 ; i <= n ; i++) {
        qsort(&map[i][0],a[i],sizeof(int32_t),cmp);
    }
    // print();
    int32_t ans[3010] = {0};
    for(int32_t i = 1 ; i <= n ; i++) {
        bool visited[3010] = {false};
        visited[i] = true;
        ans[0] = i;
        int32_t tmp = 1;
        bear_dfs(0,i,1,visited,ans,&tmp);
        bool go = false;
        for(int32_t j = 1 ; j <= n ; j++) {
            if(visited[j] == false) {
                go = true;
            }
        }
        if(!go) {
            AC = true;
            break;
        }
    }
    if(AC) {
        for(int32_t i = 0 ; i < n ; i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else{
        printf("-1\n");
    }
    return 0;
}