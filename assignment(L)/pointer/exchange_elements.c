#include <stdio.h>
#include <stdlib.h>

void exchange(int *arr, int n){
    int x, y, i;
    printf("Change X with Y\nEnter the element(x): ");
	scanf("%d", &x);
	printf("Enter the number you want to place: ");
	scanf("%d", &y);
	printf("Your desired array: ");
	for(i = 0; i < n; i++){
		if(*(arr + i) == x) *(arr + i) = y;
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int main(){
	int n, i;
    int *arr;

	printf("Enter the size of the array: ");
	scanf("%d", &n);

	arr = (int*) malloc(n * sizeof(int));
	printf("Enter your array: \n");
	for(i = 0; i < n; i++) scanf("%d", (arr + i));

    exchange(arr, n);
    free(arr);
    return 0;
}
