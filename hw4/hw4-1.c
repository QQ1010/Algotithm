#include <stdio.h>
#include <stdint.h>
int32_t n,m;
int32_t graph[200][200][200] = {0};
int32_t cycle= 0;
int32_t ans = 1000;

void print() {
    for(int32_t k = 0 ; k <= n ; k++) {
        printf("%d\n",k);
        for(int32_t i = 1 ; i <= n ; i++) {
            for(int32_t j = 1 ; j <= n ; j++) {
                printf("%d ",graph[k][i][j]);
         }
            printf("\n");
        }
    }

}

int main() {
    scanf("%d %d",&n,&m);
    int32_t p,q,w;
    for(int32_t i = 1 ; i <= m ; i++) {
        scanf("%d %d %d",&p,&q,&w);
        if(graph[0][p][q] != 0) {
            if(w < graph[0][p][q]) {
                graph[0][p][q] = w;
                graph[0][q][p] = w;
            }
        }
        else {
            graph[0][p][q] = w;
            graph[0][q][p] = w;
        }
    }
    for(int32_t i = 0 ; i <= n ; i++) {
        for(int32_t j = 0 ; j <= n ; j++) {
            if(graph[0][i][j] == 0 && i != j) {
                graph[0][i][j] = 1000;
            }
        }
    }
    print();
    for(int32_t k = 1 ; k <= n ; k++) {
        for(int32_t i = 1 ; i <= n ; i++) {
            for(int32_t j = 1 ; j <= n ; j++) {
                if(graph[k-1][i][k] + graph[k-1][k][j] < graph[k-1][i][j]) {
                    graph[k][i][j] = graph[k-1][i][k] + graph[k-1][k][j];
                }
                else {
                    graph[k][i][j] = graph[k-1][i][j];
                }
            }
        }
    }
    print();
    for(int32_t k = 1 ; k <= n ; k++) {
        for(int32_t i = 1 ; i <= n ; i++) {
            for(int32_t j = 1 ; j <= n ; j++) {
                if(graph[0][i][j] != 1000 && i != k && k != j && i != j) {
                    cycle = graph[0][i][j] + graph[n][i][k] + graph[n][k][j];
                    printf("i=%d j=%d k=%d %d %d %d = %d \n",i,j,k,graph[0][i][j],graph[n][i][k],graph[n][k][j],cycle);
                    if(ans > cycle) {
                        ans = cycle;
                    }
                }
            }
        }
    }
    printf("ans = %d\n",ans);
    return 0;
}