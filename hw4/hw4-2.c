#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _edge {
    int32_t w;
    int32_t u;
    int32_t v;
}edge;
int32_t n,m;
edge e[1000000] = {0};
int32_t group[10000] = {0};
long long weight_sum = 0;
int32_t bottleneck = 0;
int32_t border = 0;

int cmp(const void *a , const void *b) {
    return (* (int *)b - *(int *)a); 
}

void print() {
    printf("\n");
    for(int32_t i = 1 ; i <= m ; i++) {
        printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
    }
    // for(int32_t i = 1 ; i <= m ; i++) {
    //     printf("%d = group %d\n",i,group[i]);
    // }
    printf("\n");

}

void Union(int32_t x,int32_t y) {
    int32_t tmp = group[y];
    for(int32_t i = 1 ; i <= m ; i++) {
        if(group[i] == tmp) {
            group[i] = group[x];
        }
    }
}

void MST_KRUSKAL() {
    for(int32_t i = 1 ; i <= n ; i++) {
        group[i] = i;
    }
    qsort(&e[1],m,sizeof(edge),cmp);
    // print();
    int32_t j = 1;
    for(int32_t i = 0 ; i < n-1 && j <= m; i++) {
        while(group[e[j].u] == group[e[j].v]) {
            j += 1;
        }
        Union(e[j].u,e[j].v);
        weight_sum += e[j].w;
        bottleneck = e[j].w;
        j += 1;
        // printf("%ld %d\n",weight_sum,bottleneck);
    }
    // print();
}

bool modify() {
    for(int32_t i = 1 ; i <= m ; i++) {
        if(e[i].w == bottleneck) {
            border = i;
        }
    }
    // printf("border = %d\n",border);
    if(border <= (n-1)) {
        printf("%lld\n",weight_sum);
        return false;
    }
    else{
        return true;
        // printf("need to modify\n");
    }
}
void Min_KRUSKAL() {
    weight_sum = 0;
    for(int32_t i = 1 ; i <= n ; i++) {
        group[i] = i;
    }
    // print();
    int32_t j = border;
    for(int32_t i = 0 ; i < n-1 && j > 0; i++) {
        while(group[e[j].u] == group[e[j].v]) {
            j -= 1;
        }
        Union(e[j].u,e[j].v);
        weight_sum += e[j].w;
        j -= 1;
        // printf("%ld %d\n",weight_sum,bottleneck);
    }
    printf("%lld\n",weight_sum);
    // print();
}

// void findsmall() {
//     weight_sum = 0;
//     for(int32_t i = 1 ; i <= n ; i++) {
//         group[i] = i;
//     }
//     for(int32_t i = n ; i > 0 ; i--) {
//         if(group[e[i].u] != group[e[i].v]) {
//             Union(e[i].u,e[i].v);
//             weight_sum += e[i].w;
//             // printf("%d %d %d %ld\n",i,e[i].u,e[i].v,weight_sum);
//         }
//     }
//     printf("%lld\n",weight_sum);
// }

int main() {
    scanf("%d %d",&n,&m);
    for(int32_t i = 1 ; i <= m ; i++) {
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    }
    MST_KRUSKAL();
    if(modify()) {
        Min_KRUSKAL();
    }
    return 0;
}

/*
8 8
2 5 9
5 6 12
4 5 8
4 7 13
2 6 11
2 3 10
1 8 14
1 4 15
*/