#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


int64_t merge(int64_t list[], int64_t sorted[] ,int64_t begin , int64_t end) {
    int64_t counter = 0;
    int64_t mid = (begin + end)/2;
    if(begin == end) {
        return 0;
    }
    counter += merge(list,sorted,begin,mid);
    counter += merge(list,sorted,mid+1,end);
    int64_t rindex = begin;
    int64_t lindex = mid+1;
    int64_t sindex = begin;
    while( rindex <= mid && lindex <= end) {
        if(list[rindex] < list[lindex]) {
            sorted[sindex++] = list[rindex++];
        }
        else if(list[rindex] > list[lindex]) {
            sorted[sindex++] = list[lindex++];
            counter += (mid - rindex + 1);
        }
    }
    while(rindex <= mid) {
        sorted[sindex++] = list[rindex++];
    }
    while(lindex <= end) {
        sorted[sindex++] = list[lindex++];
    }
    for(int64_t i = begin ; i < sindex ; i++)
    {
        list[i] = sorted[i];
    }
    return counter;
}

int main() {
    int64_t num;
    scanf("%ld",&num);
    int64_t arr[200005] = {0};
    int64_t even_num = 0;
    int64_t odd_num = num/2;
    if(num % 2 == 0) {
        even_num = num/2;
    }
    else {
        even_num = num/2 + 1;
    }
    int64_t odd[100005] = {0};
    int64_t even[100005] = {0};
    int64_t even_index = 0;
    int64_t odd_index = 0;
    for(int i = 0 ; i < num ; i++) {
        scanf("%ld",&arr[i]);
        if(i % 2 == 0) 
            even[even_index++] = arr[i];
        else
            odd[odd_index++] = arr[i];
    }
    int64_t counter = 0;
    int64_t odd_sorted[100005] = {0};
    int64_t even_sorted[100005] = {0};
    counter += merge(odd,odd_sorted,0,odd_num-1);
    counter += merge(even,even_sorted,0,even_num-1);
    if(odd_index == 1) 
        odd_sorted[0] = odd[0];
    bool execute = true;
    for(int64_t i = 0 ; i < odd_num ; i++)
    {
        if(num % 2 == 1) {
            if(even_sorted[i] > odd_sorted[i] || even_sorted[i+1] < odd_sorted[i])
            {
                execute = false;
            }
        }
        else if(num % 2 == 0) {
            if(i != odd_num - 1) {
                if(even_sorted[i] > odd_sorted[i] || even_sorted[i+1] < odd_sorted[i]) {
                    execute = false;
                }
            }
            if( i == odd_num - 1) {
                if(even_sorted[i] > odd_sorted[i])
                    execute = false;
            } 
        }
    }
    if(execute == true) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }    
    printf("%ld\n",counter);
    return 0;
}

/*
void swap(int64_t *a,int64_t *b) {
    int64_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

}

void list_all(int64_t random[] ,int64_t start , int64_t num) {
    if(start == num)
    {
        int64_t sorted[7] = {0};
        merge(random,sorted,0,6);
        for(int32_t i = 0 ; i < 7 ; i++) {
            printf("%ld ",sorted[i]);
        }
        printf("\n");
    }
    else
    {
      for(int32_t j = start; j <= num; j++)
      {
        swap(&random[start], &random[j]);
        list_all(random, start + 1, num);
        swap(&random[start], &random[j]);
      }
    }
}


int main() {
    int64_t test_list[7] = {1,3,4,10,89,66,54};
    list_all(test_list,0,6);
}
*/