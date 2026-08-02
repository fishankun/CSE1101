#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, i, s, x;
    int *arr1, *arr2, *arr3;
	printf("Enter the size of the 1st array: ");
	scanf("%d", &n);
	arr1 = (int*) malloc(n * sizeof(int));
	printf("Enter an array: \n");
	for(i = 0; i < n; i++) scanf("%d", (arr1 + i));
	
	printf("Enter the size of the 2nd array: ");
	scanf("%d", &m);
	arr2 = (int*) malloc(m * sizeof(int));
	printf("Enter an array: \n");
	for(i = 0; i < m; i++) scanf("%d", (arr2 + i));
	
	arr3 = (int*) malloc((n + m) * sizeof(int));
	for(i = 0; i < n; i++) *(arr3 + i) = *(arr1 + i);
	for(i = 0; i < m; i++) *(arr3 + n + i) = *(arr2 + i);
	
	do{
		s = 0;
		for(i = 0; i < n + m - 1; i++){
			if(*(arr3 + i) > *(arr3 + i + 1)){
				x = *(arr3 + i);
				*(arr3 + i) = *(arr3 + i + 1);
				*(arr3 + i + 1) = x;
				s = 1;
			}
		}
	}while(s);
	printf("The sorted array: ");
	for(i = 0; i < n + m; i++) printf("%d ", *(arr3 + i));
	printf("\n");
    free(arr1);
    free(arr2);
    free(arr3);

	return 0;
}
