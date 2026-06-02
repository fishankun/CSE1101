#include <stdio.h>

int main(){
	int n, r, c;
	printf("Enter the value of n: ");
	scanf("%d", &n);

	for(r = 1; r <= n; r++){
		for(c = 1; c <= n - r; c++) printf(" ");

		for(c = 1; c <= 2 * r - 1; c++){
			char a = (r == n || c == 1 || c == 2 * r - 1) ? '*' : ' ';
			printf("%c", a);
		}
		printf("\n");
	}
	return 0;
}
