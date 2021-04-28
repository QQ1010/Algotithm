#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t num = 0;
    int32_t maxbag = 0;
    int32_t weight[101] = {0};
    int32_t value[101] = {0};
    scanf("%d %d",&num,&maxbag);
    int32_t n_tmp = num+1;
    int32_t b_tmp = maxbag+1;
    int64_t table[n_tmp][b_tmp];
    for(int32_t i = 1 ; i <= num ; i++) {
        scanf("%d %d",&weight[i],&value[i]);
    }
    for(int32_t i = 0 ; i <= num ; i++) {
        for(int32_t j = 0 ; j <= maxbag ; j++) {
            if(i == 0) 
                table[i][j] = 0;
            else if( j == 0)
                table[i][j] = 0;
        }
    }
    for(int32_t i = 1 ; i <= num ; i++) {
        for(int32_t  j = 1 ; j <= maxbag ; j++) {
            if(j - weight[i] < 0) {
                table[i][j] = table[i-1][j];
            }
            else if(j - weight[i] >= 0) {
                if(table[i-1][j] < (table[i-1][j-weight[i]] + value[i])) {
                    table[i][j] = table[i-1][j-weight[i]] + value[i];
                }
                else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
    }
    printf("%ld\n",table[num][maxbag]);
}