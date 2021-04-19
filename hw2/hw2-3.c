#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _list {
    int32_t x;
    int32_t y;
}list;

// int32_t cmp(list * a, list * b) {
//    if(a->x < b->x)
//         return -1;
//     else if(a->x == b->x)
//         return 0;
//     else if(a->x > b->x)
//         return 1;
        
// }

int main() {
    int32_t num = 0;
    scanf("%d",&num);
    list point[num];
    int32_t len[num];
    int32_t tmp[num];
    for(int32_t i = 0 ; i < num ; i++) {
        scanf("%d %d",&point[i].x,&point[i].y);
    }
    for(int32_t i = 0 ; i < num ; i++) {              //bubble_sort
        for(int32_t j = i; j < num ; j++) {
            list tmp;
            if(point[i].x > point[j].x) {
            tmp = point[i];
            point[i] = point[j];
            point[j] = tmp;
            }
        }
    }
    // qsort(point,num,sizeof(list),cmp);             //qsort -> not yet done
    // for(int32_t i = 0 ; i < num ; i++) {
    //     printf("%d %d\n",point[i].x,point[i].y);
    // }
    for(int32_t i = 0 ; i < num ; i++) {    // len initial = 1
        len[i] = 1;
    }
    for(int32_t i = 0 ; i < num ; i++) {    // do LIS
        
    }
}