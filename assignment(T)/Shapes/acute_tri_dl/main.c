#include <stdio.h>

int main(){
    int i, j, s, n;
    char c;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("\n");
    
    s = n * 2 - 1;
    
    for(i = n; i > 0; i--)
    {
        for(j = 1; j <= s - (i * 2 - 1); j++) printf(" ");
        for(j = 1; j <= i * 2 - 1; j++) printf("%c", c);
        printf("\n");
    }
}
