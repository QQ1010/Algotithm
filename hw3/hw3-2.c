#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int32_t num;
    int32_t input[20] = {0};
    bool T = false;
    scanf("%d",&num);
    for(int32_t i = 0 ; i < num ; i++) {
        scanf("%d",&input[i]);
    }
    for(int32_t i = 0 ; i < pow(3,num) ; i++) {
        int32_t sum[3] = {0};
        int32_t t = i;
        for(int32_t j = 0 ; j < num ; j++) {
            sum[t%3] += input[j];
            t /= 3;
        }
        if(sum[0] == sum[1] && sum[1] == sum[2]) {
            T = true;
            break;
        }
    }
    if(T) {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}