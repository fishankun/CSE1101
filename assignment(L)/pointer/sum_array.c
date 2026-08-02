#include <stdio.h>
#include <stdlib.h>

int sum_arr(int *arr, int n){
    int sum = 0;
    if(n < 0) return 0;
    sum = sum_arr(arr, n - 1) + *(arr + n);
    return sum;
}

void main(){
    int n, i;
    int *arr;

    printf("Enter the array size: ");
	scanf("%d", &n);
	arr = (int*) malloc(n * sizeof(int));
	printf("Enter your input: \n");
	for(i = 0; i < n; i++) scanf("%d", (arr + i));

    printf("The sum of the array is %d", sum_arr(arr, n - 1));
    free(arr);
    return 0;
}