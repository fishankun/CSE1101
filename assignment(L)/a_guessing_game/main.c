#include <stdio.h>

int main(){
	int a, b, x, total, w, i;
	a = 69;
	b = 67;
	w = 0; // w = 1 means won, w = 0 means defeated
	// let's assume until he is winning, w = 0
	total = a + b;

	for(i = 0; i < 5; i++){  //he will be asked 5 times
		printf("Guess the total...\n");
		scanf("%d", &x);
		
		if(total > x)
			printf("Total is greater than this.\n\n");
		else if(total < x)
			printf("Total is smaller than this.\n\n");
		else if(total == x){
			w = 1; //he guessed the correct number, so w = 1
			printf("Shabbash, beta!!!\nTor darai hobe.\n");
			break;//as he guessed the correct number, let's just end this shyt here.
		}
	}

	if(w == 0) //after failing 5 times, it's time to declare that he lost.
	//so first we check the value of w, and when we see that it's 0, we know that he lost.
	printf("\n\nBetter luck next time, NGA...\nLol XD\n");
    return 0;
    
}
