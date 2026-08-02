#include <stdio.h>

int main(){
	int n, i, j, flag, k = -1;
    int *arr, *narr;

	printf("Enter the size of the array: ");
	scanf("%d", &n);
	arr = (int*) malloc(n * sizeof(int));
    narr = (int*) malloc(n * sizeof(int));
	printf("Enter your array: \n");
	for(i = 0; i < n; i++) scanf("%d", *(arr + i));
	
	printf("After removing the duplicates: ");
	for(i = 0; i < n; i++){
		flag = 0;
		for(j = 0; j <= k; j++){
			if(*(arr + i) == *(narr + j)){
				flag = 1;
				break;
			}
		}
		if(!flag){
			k++;
			*(narr + k) = *(arr + i);
			printf("%d ", *(arr + i));
		}
	}
	printf("\n");
    free(arr);
	return 0;
}
