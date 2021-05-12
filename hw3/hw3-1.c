#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    int32_t box[2][1005] = {0};
    int32_t table[1005] = {0};
    char input[2][1005] = {0};
    scanf("%s",input[0]);
    scanf("%s",input[1]);
    int32_t len = strlen(input[0]);
    for(int32_t i = 0 ; i < len ; i++) {
        box[0][i] = input[0][i] - '0';
        box[1][i] = input[1][i] - '0';
    }
    for(int32_t i = 1 ; i < len ; i++) {
        if(box[0][i] == 0 && box[1][i] == 0) {
            if(box[0][i-1] == 0 && box[1][i-1] == 0) {
                table[i] = table[i-1] + 1;
                box[0][i] = 1;
                box[1][i-1] = 1;
                box[0][i-1] = 1;
            }
            else if(box[0][i-1] == 0 && box[1][i-1] == 1) {
                table[i] = table[i-1] + 1;
                box[0][i] = 1;
                box[1][i] = 1;
                box[0][i-1] = 1;
            }
            else if(box[0][i-1] == 1 && box[1][i-1] == 0) {
                table[i] = table[i-1] + 1;
                box[0][i] = 1;
                box[1][i] = 1;
                box[1][i-1] = 1;
            }
            else {
                table[i] = table[i-1];
            }
        }
        else if(box[0][i] == 0 && box[1][i] != 0) {
            if(box[0][i-1] == 0 && box[1][i-1] == 0) {
                table[i] = table[i-1] + 1;
                box[0][i] = 1;
                box[0][i-1] = 1;
                box[1][i-1] = 1;
            }
            else {
                table[i] = table[i-1];
            }
        }
        else if(box[0][i] != 0 && box[1][i] == 0) {
            if(box[0][i-1] == 0 && box[1][i-1] == 0) {
                table[i] = table[i-1] + 1;
                box[1][i] = 1;
                box[0][i-1] = 1;
                box[1][i-1] = 1;
            }
            else {
                table[i] = table[i-1];
            }
        }
        else {
            table[i] = table[i-1];
        }
    }
    printf("%d\n",table[len-1]);
    return 0;
}