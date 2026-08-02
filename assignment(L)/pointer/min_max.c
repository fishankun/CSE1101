#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n, min, max;
    int *arr;

	printf("Enter the array size: ");
	scanf("%d", &n);
	arr = (int*) malloc(n * sizeof(int));
	printf("Enter your input: \n");
	for(i = 0; i < n; i++) scanf("%d", (arr + i));
	
	max = *arr;
	for(i = 1; i < n; i++){
		if(*(arr + i) > max) max = *(arr + i);
	}
	printf("The maximum number is: %d\n", max);
	
	min = *arr;
	for(i = 1; i < n; i++){
		if(*(arr + i) < min) min = *(arr + i);
	}
	printf("The minimum number is: %d\n", min);
    free(arr);
	return 0;
}
