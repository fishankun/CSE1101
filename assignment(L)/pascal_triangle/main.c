#include <stdio.h>

int main(){
	int n, row, col, C;

	printf("Enter the value of row: ");
	scanf("%d", &row);

	for(n = 0; n < row; n++){
		C = 1;		
		for(col = 0; col <= n; col++){
			printf("%d ", C);
			C = C * (n - col) / (col + 1);
		}
		printf("\n");
	}
	return 0;
}
