#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int right){
    int i, mid = right / 2;
    int *arr2, *arr3;

    arr2 = (int*) malloc(mid * sizeof(int));
    arr3 = (int*) malloc((right - mid) * sizeof(int));

    if(right <= 1) return;

    for(i = 0; i < mid; i++) *(arr2 + i) = *(arr + i);
    for(i = 0; i < right - mid; i++) *(arr3 + i) = *(arr + mid + i);
    merge_sort(arr2, mid);
    merge_sort(arr3, right - mid);

    i = 0;
    int k = 0, j = 0;
    while(i < mid && j < right - mid){
        if(*(arr2 + i) <= *(arr3 + j)){
            arr[k] = *(arr2 + i);
            i++;
        }
        else if(*(arr2 + i) > *(arr3 + j)){
            arr[k] = *(arr3 + j);
            j++;
        }
        k++;
    }
    while(i < mid){
        arr[k] = *(arr2 + i);
        i++;
        k++;
    }
    while(j < right - mid){
        arr[k] = *(arr3 + j);
        j++;
        k++;
    }

    free(arr2);
    free(arr3);
}

int main(){
    int n, i;

    int *arr;
    printf("Enter the array size: ");
	scanf("%d", &n);
	arr = (int*) malloc(n * sizeof(int));
	printf("Enter your input: \n");
	for(i = 0; i < n; i++) scanf("%d", (arr + i));

    printf("The initial array:\n");
    for(int i = 0; i < n; i++) printf("%d ", *(arr + i));

    merge_sort(arr, n);
    printf("\nThe sorted array:\n");
    for(int i = 0; i < n; i++) printf("%d ", *(arr + i));
    
    free(arr);
    return 0;
}