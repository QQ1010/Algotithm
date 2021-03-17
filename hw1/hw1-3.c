#include <stdio.h>
#include <stdint.h>

int main() {
    int64_t arr[100001] = {0};
    int64_t num = 0;
    scanf("%ld",&num);
    for(int64_t i = 0 ; i < num ; i++) {
        int64_t input;
        scanf("%ld",&input);
        arr[input] += 1;
    }
    int64_t cnt = 0;
    for(int64_t i = 0 ; i < 100001 ; i++) {
        cnt += arr[i];
        if(cnt >= num/2+1) {
            printf("%ld\n",i);
            return 0;
        }
    }
}