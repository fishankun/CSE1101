#include <stdio.h>
#include <math.h>

int main(){
	int num, i, j, isprime;

	for(j = 1; j <= 5; j++){
		isprime = 1; //it is a extra variable, named "FLAG VARIABLES"
		printf("Enter a number: ");
		scanf("%d", &num);
		
		if(num == 2) printf("%d is a prime number.\n", num);
		else if(num > 2 || num % 2 == 0) printf("%d is not a prime number.\n");
		else{
			for(i = 3; i <= sqrt(num); i = i + 2){
				if(num % i == 0){
					isprime = 0;
					break;
				}			
		}
		if(isprime) printf("%d is a prime number.\n", num);
		else printf("%d is not a prime number.\n", num);
	}

	return 0;
}
