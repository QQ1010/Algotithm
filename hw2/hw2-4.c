#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define mod %1000000007

long long poww(int32_t j) {
    long long ans = 1;
    long long base = 2;
    while(j) {
        if(j & 1) {
            ans = ans mod * base mod;
        }
        base = base mod * base mod;
        j >>= 1;
    }
    return ans;
}


int main() {
    int32_t num,test;
    scanf("%d %d",&num,&test);
    int32_t list[10005] = {0};
    long long ans = 0;
    for(int32_t i = 0 ; i < num ; i++) {
        scanf("%d",&list[i]);
    }
    int64_t cnt[num];
    cnt[0] = 0;
    for(int32_t i = 1 ; i < num ; i++) {
        cnt[i] = 0;
        for(int32_t j = 0 ; j < i ; j++) {
            if(abs(list[j]-list[i]) <= test) {
                cnt[i] = cnt[i]mod + poww(j)mod;
            }
            else {
                cnt[i] = cnt[i]mod + cnt[j]mod;
            }
        }
    }
    for(int32_t i = 0 ; i < num ; i++) {
        ans = ans mod + cnt[i]mod;
    }
    printf("%lld\n",ans mod);
    return 0;
}