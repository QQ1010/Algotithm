#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
int main() {
    int32_t num;
    int32_t input[20] = {0};
    int64_t sum[3] = {0};
    int64_t s = 0;
    int32_t t = 0;
    bool T = false;
    scanf("%d",&num);
    for(int32_t i = 0 ; i < num ; i++) {
        scanf("%d",&input[i]);
        s += input[i];
    }
    if(s%3) {
        printf("NO\n");
        return 0;
    }
    s /= 3;
    for(int32_t i = pow(3,num) ; i >= 0 ; i--) {
        sum[0] = 0;
        sum[1] = 0;
        sum[2] = 0;
        t = i;
        for(int32_t j = 0 ; j < num ; j++) {
            sum[t%3] += input[j];
            t /= 3;
            if(sum[t%3] > s) {
                break;
            }
        }
        if(sum[0] == sum[1] && sum[2] == sum[1]) {
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