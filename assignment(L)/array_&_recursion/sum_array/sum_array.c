#include <stdio.h>

int sum_arr(int arr[], int n){
    int sum = 0;
    if(n < 0) return 0;
    sum = sum_arr(arr, n - 1) + arr[n];
    return sum;
}

void main(){
    int n, arr[6] = {1, 2, 3, 4, 5, 6};
    n = sizeof(arr) / sizeof(int);
    printf("The sum of the array is %d", sum_arr(arr, n - 1));
}