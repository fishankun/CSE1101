#include <stdio.h>

int main(){
	int i, n, min, max;
	printf("Enter the array size: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter your input: \n");
	for(i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	max = arr[0];
	for(i = 1; i < n; i++){
		if(arr[i] > max) max = arr[i];
	}
	printf("The maximum number is: %d\n", max);
	
	min = arr[0];
	for(i = 1; i < n; i++){
		if(arr[i] < min) min = arr[i];
	}
	printf("The minimum number is: %d\n", min);
	return 0;
}
