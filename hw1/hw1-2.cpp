#include <cstdio>
#include <stdint.h>
#include <iostream>

using namespace std;


int64_t list_merge(int64_t list,int64_t )

int64_t rmerge(int64_t list[],int64_t upper,int64_t lower) {
    if(upper <= lower) {
        return lower;
    }
    else {
        int64_t middle = (upper+lower)/2;
        return list_merge(list,rmerge(list,lower,middle),rmerge(list,middle+1,upper));
    }
}



int main() {
    int32_t num;
    cin >> num;
    int64_t arr[num];
    for(int i = 0 ; i < num ; i++) {
        cin >> arr[i];
    }
}