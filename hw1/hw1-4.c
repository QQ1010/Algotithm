#include <stdio.h>
#include <stdint.h>

typedef struct _count {
    int64_t sum;
    int64_t key;
}count;

void cnt(count list[], int64_t begin, int64_t end) {
    int64_t mid = (begin + end)/2;
    if(begin == end) {
        return ;
    }
    cnt(list,begin,mid);
    cnt(list,mid+1,end);
    for(int64_t i = mid+1; i <= end ; i++) {
        for(int64_t j = begin ; j < mid+1 ; j++) {
            if(list[j].key < list[i].key) {
                list[i].sum += list[j].key;
            }
        }
    }
}

void merge(count list[],count sorted[],int64_t begin,int64_t end) {
    int64_t mid = (begin + end)/2;
    if(begin == end) {
        return;
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
            sindex ++;
            lindex ++;
        }
        else if(list[lindex].key > list[rindex].key) {
            sorted[sindex].key = list[rindex].key;
            sorted[sindex].sum = list[rindex].sum;
            sindex ++;
            rindex ++;
        }
        else if(list[lindex].key == list[rindex].key) {
            sorted[sindex].key = list[lindex].key;
            sorted[sindex].sum = list[lindex].sum;
            sindex ++;
            lindex ++;
            sorted[sindex].key = list[rindex].key;
            sorted[sindex].sum = list[rindex].sum;
            sindex ++;
            rindex ++;
        }
    }
    while(lindex <= mid) {
        sorted[sindex].key = list[lindex].key;
        sorted[sindex].sum = list[lindex].sum;
        sindex ++;
        lindex ++;
    }
    while(rindex <= end) {
        sorted[sindex] .key= list[rindex].key;
        sorted[sindex].sum = list[rindex].sum;
        sindex ++;
        rindex ++;
    }
    for(int64_t i = begin ; i < sindex ; i++)
    {
        list[i].key = sorted[i].key;
        list[i].sum = sorted[i].sum;
    }
    // for(int64_t i = begin ; i < sindex ; i++) {
    //     printf("%ld ",sorted[i].key);
    // }
    // printf("\n");
    // for(int64_t i = begin ; i < sindex ; i++) {
    //     printf("%ld ",sorted[i].sum);
    // }
    // printf("\n");
}

int main() {
    int64_t num;
    scanf("%ld",&num);
    count arr[200005];
    count sorted[200005];
    for(int64_t i = 0 ; i < 2*num ; i++) {
        scanf("%ld",&arr[i].key);
        arr[i].sum = 0;
        sorted[i].sum = 0;
    }
    cnt(arr,0,2*num-1);
    merge(arr,sorted,0,2*num-1); 
    // for(int64_t i = 0 ; i < 2*num ; i++) {
    //     printf("%ld ",sorted[i].key);
    // }
    // printf("\n");
    // for(int64_t i = 0 ; i < 2*num ; i++) {
    //     printf("%ld ",sorted[i].sum);
    // }
    // printf("\n");
    int64_t ans = 0;
    for(int64_t i = 0 ; i < 2*num ; i += 2) {
        if((sorted[i+1].sum-sorted[i].sum) < 0) {
            ans += (sorted[i].sum-sorted[i+1].sum);
        }
        else{
            ans += (sorted[i+1].sum-sorted[i].sum);
        }
    }
    printf("%ld\n",ans);
    return 0;
}