#include <stdio.h>
#include <stdlib.h>

int A[40];

struct MinMax {
    int smallest;
    int greatest;
};

struct MinMax min_max(int start, int end, struct MinMax M) {
    int mid = (start+end)/2;
    if(start > end) 
        return M;
    if(start == end) {
        M.smallest = M.smallest<A[start]? M.smallest: A[start];
        M.greatest = M.greatest>A[start]? M.greatest: A[start];
        return M;
    } else if(start == (end-1)) {
        M.smallest = M.smallest<((A[start]<A[end])? A[start]: A[end])? M.smallest: ((A[start]<A[end])? A[start]: A[end]);
        M.greatest = M.greatest>((A[start]>A[end])? A[start]: A[end])? M.greatest: ((A[start]>A[end])? A[start]: A[end]);
        return M;
    } else {
        M = min_max(start, mid-1, M);
        M = min_max(mid+1, end, M);
        return M;
    }
}

int main() {

    int i, n;
    struct MinMax M;
    
    printf("\nEnter number of elements to enter: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);

    M.smallest = A[0];
    M.greatest = A[0];
    M = min_max(0, n-1, M);

    printf("\nSmallest number is %d", M.smallest);
    printf("\nGreatest number is %d\n", M.greatest);

    return 1;
}