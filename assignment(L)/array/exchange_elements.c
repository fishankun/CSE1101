#include <stdio.h>

int main(){
	int n, i, x, y;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter your array: \n");
	for(i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	printf("Change X with Y\nEnter the element(x): ");
	scanf("%d", &x);
	printf("Enter the number you want to place: ");
	scanf("%d", &y);
	printf("Your desired array: ");
	for(i = 0; i < n; i++){
		if(arr[i] == x) arr[i] = y;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
