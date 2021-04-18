#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t num = 0;
    scanf("%d",&num);
    int32_t list[num+1];
    int64_t table[num+1][num+1];
    for(int32_t i = 1 ; i <= num ; i++) {
        scanf("%d",&list[i]);
    }
    for(int32_t i = 1 ; i <= num ; i ++) {
        for(int32_t j = 1 ; j <= num ; j++) {
            table[i][j] = 0;
        }
    }
    for(int32_t len = 2 ; len <= num ; len++) {
        for(int32_t j = 1 ; j <= num-len+1 ; j++) {
            int32_t i = j +len - 1;
            table[i][j] = 10000000000;
            int64_t tmp = 0;
            for(int32_t m = j ; m <= i ; m++) {
                tmp += list[m];
            }
            for(int32_t k = j ; k < i ; k++) {
                int64_t q = table[k][j] + table[i][k+1] + tmp;
                if(q < table[i][j])
                    table[i][j] = q;
            }
        }
    }
    int64_t ans = table[num][1];
    printf("%ld\n",ans);
    return 0;
}