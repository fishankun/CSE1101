#include <stdio.h>

int check(int a, int b, int c, int d){
	int s;	
	s = a + b + c + d;
	if(s == 4) return 1;
	else return 0;
}

int main(){
	int n, s;
	char p;

	for(int i = 1; i > 0; i++){
		int a = 0, b = 0, c = 0, d = 0;
		printf("Length of the password: ");
		scanf("%d", &n);
		if(n >= 8){
			printf("Enter your password: ");
			for(int i = 0; i < n; i++){
				scanf(" %c", &p);
				if(65 <= p && p <= 90) a = 1;
				else if(48 <= p && p <= 57) b = 1;
				else if(97 <= p && p <= 122) c = 1;
				else if((33 <= p && p <= 47) || (58 <= p && p <= 64) || (91 <= p && p <= 96) || (123 <= p && p <= 126) || p == 32 || p == 127) d = 1;
			}
			s = check(a, b, c, d);	
			
		}
		else s = 2;

		if(s == 1){
			printf("Password is valid.\n");
			break;
		}
		else if(s == 2){
			printf("Password length is too short.\n");
		}
		else{
	 		printf("Password is invalid.\n");		
	 		if(c != 1) printf("Lower case needed\n");
	 		if(a != 1) printf("Upper case needed\n");
	 		if(b != 1) printf("Digit needed\n");
	 		if(d != 1) printf("Special character needed\n");
		}
	}
	return 0;
}
