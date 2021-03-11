#include <stdio.h>
#include <stdint.h>

oo_peh_sort()

/*
oo_pe̍h_sort(A[0..n-1])
    Sorted = false
    Counter = 0
    while Sorted == false
        Sorted = true
        for i=0; i<len(Arr)-2; i=i+1
            if A[i] > A[i+2]
                Sorted = false
                Reverse the subarray A[i..i+2]
                Counter = Counter + 1
*/