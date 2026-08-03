#include <stdio.h>

void reverse(int *arr, int start, int end){
    if(start >= end) return;
    int temp;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse(arr, start + 1, end - 1);
    return;
}
int main(){
    int i, n, size, arr[8] = {3, 4, 5, 6, 2, 7, 1, 0};
    size = sizeof(arr) / sizeof(int);
    reverse(arr, 0, size - 1);
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}