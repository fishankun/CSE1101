#include <stdio.h>

int main(){
    int i, j, a, n;
    char c;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("\n");
    
    a = (n + 1) / 2;
    
    for(i = 1; i <= a; i++){
        for(j = a; j > i; j--) printf(" ");
        for(j = 1; j <= i * 2 - 1; j++) printf("%c", c);
        printf("\n");
    }
    i--;
    
    if(n % 2 == 0){
        for(j = 1; j <= i * 2 - 1; j++) printf("%c", c);
        printf("\n");
    }
    
    for(i = a - 1; i > 0; i--){
        for(j = 1; j <= a - i; j++) printf(" ");
        for(j = 1; j <= i * 2 - 1; j++) printf("%c", c);
        printf("\n");
    }
    
    return 0;
}