#include <stdio.h>

int main(){
	int n, m, i, s, x;
	printf("Enter the size of the 1st array: ");
	scanf("%d", &n);
	int arr1[n];
	printf("Enter a sorted array: \n");
	for(i = 0; i < n; i++) scanf("%d", &arr1[i]);
	
	printf("Enter the size of the 2nd array: ");
	scanf("%d", &m);
	int arr2[m];
	printf("Enter a sorted array: \n");
	for(i = 0; i < m; i++) scanf("%d", &arr2[i]);
	
	int arr3[n + m];
	for(i = 0; i < n; i++) arr3[i] = arr1[i];
	for(i = 0; i < m; i++) arr3[n + i] = arr2[i];
	
	do{
		s = 0;
		for(i = 0; i < n + m - 1; i++){
			if(arr3[i] > arr3[i + 1]){
				x = arr3[i];
				arr3[i] = arr3[i + 1];
				arr3[i + 1] = x;
				s = 1;
			}
		}
	}while(s);
	printf("The sorted array: ");
	for(i = 0; i < n + m; i++) printf("%d ", arr3[i]);
	printf("\n");
	return 0;
}
