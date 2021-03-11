#include <stdio.h>
#include <stdint.h>
int main()
{
    int64_t  amount = 0;
    scanf("%ld",&amount);
    for(int64_t i = 0 ; i < amount ; i++)
    {
        int64_t number[2];
        int64_t ans;
        scanf("%ld %ld",&number[0],&number[1]);
        ans = number[0]+number[1];
        printf("%ld\n",ans);
    }
    return 0;
}