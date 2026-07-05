#include <stdio.h>

void merge_sort(int arr[], int right){
    int i, mid = right / 2;
    int arr2[mid], arr3[right - mid];
    if(right <= 1) return;
    for(i = 0; i < mid; i++) arr2[i] = arr[i];
    for(i = 0; i < right - mid; i++) arr3[i] = arr[mid + i];
    merge_sort(arr2, mid);
    merge_sort(arr3, right - mid);

    i = 0;
    int k = 0, j = 0;
    while(i < mid && j < right - mid){
        if(arr2[i] <= arr3[j]){
            arr[k] = arr2[i];
            i++;
        }
        else if(arr2[i] > arr3[j]){
            arr[k] = arr3[j];
            j++;
        }
        k++;
    }
    while(i < mid){
        arr[k] = arr2[i];
        i++;
        k++;
    }
    while(j < right - mid){
        arr[k] = arr3[j];
        j++;
        k++;
    }
}

int main(){
    int arr[] = {4, 8, 3, 9, 0, 1, 5};
    int n = sizeof(arr) / sizeof(int);
    printf("The initial array:\n");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    merge_sort(arr, n);
    printf("\nThe sorted array:\n");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}