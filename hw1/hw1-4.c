#include <stdio.h>
#include <stdint.h>

typedef struct _count {
    int64_t sum;
    int64_t key;
}count;

void merge(count list[], count sorted[], int64_t begin, int64_t end) {
    int64_t mid = (begin + end)/2;
    if(begin == end) {
        return ;
    }
    merge(list,sorted,begin,mid);
    merge(list,sorted,mid+1,end);
    int64_t lindex = begin;
    int64_t rindex = mid+1;
    int64_t sindex = begin;
    while( lindex <= mid && rindex <= end) {
        if(list[lindex].key < list[rindex].key) {
            sorted[sindex].key = list[lindex].key;
            sorted[sindex].sum = list[lindex].sum;
            list[rindex].sum += list[lindex].key;
            sindex += 1;
            lindex += 1;

        }
        else if(list[lindex].key > list[rindex].key) {
            sorted[sindex].key = list[rindex].key;
            sorted[sindex].sum = list[rindex].sum;
            sindex += 1;
            rindex += 1;
        }
        else if(list[lindex].key == list[rindex].key) {
            sorted[sindex].key = list[lindex].key;
            sorted[sindex].sum = list[rindex].sum;
            sindex += 1;
            lindex += 1;
        }
    }
    while(lindex <= mid) {
        sorted[sindex].key = list[lindex].key;
        sorted[sindex].sum = list[lindex].sum;
        sindex += 1;
        lindex += 1;
    }
    while(rindex <= end) {
        sorted[sindex].key = list[rindex].key;
        sorted[sindex].sum = list[rindex].sum;
        sindex += 1;
        rindex += 1;
    }
    for(int64_t i = begin ; i < sindex ; i++) {
        list[i].key = sorted[i].key;
        list[i].sum = sorted[i].sum;
    }
}

int main() {
    int64_t num;
    scanf("%ld",&num);
    count arr[200005];
    count sorted[200005];
    for(int64_t i = 0 ; i < 2*num ; i++) {
        scanf("%ld",&arr[i].key);
        // printf("%ld",arr[i].key);
        arr[i].sum = 0;
        sorted[i].sum = 0;
    }
    merge(arr,sorted,0,2*num-1);
    for(int64_t i = 0 ; i < 2*num ; i++) {
        printf("%ld ",sorted[i].key);
    }
    printf("\n");
    for(int64_t i = 0 ; i < 2*num ; i++) {
        printf("%ld ",sorted[i].sum);
    }
    printf("\n");
    return 0;
}