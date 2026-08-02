#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int start, int end){
    int temp;
    if(start >= end) return;

    temp = *(arr + start);
    *(arr + start) = *(arr + end);
    *(arr + end) = temp;

    reverse(arr, start + 1, end - 1);
    return;
}
int main(){
    int i, n;

    int *arr;
    printf("Enter the array size: ");
	scanf("%d", &n);
	arr = (int*) malloc(n * sizeof(int));
	printf("Enter your input: \n");
	for(i = 0; i < n; i++) scanf("%d", (arr + i));

    reverse(arr, 0, n - 1);
    for(i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    free(arr);
    return 0;
}