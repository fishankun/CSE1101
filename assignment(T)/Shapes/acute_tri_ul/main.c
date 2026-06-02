#include <stdio.h>

int main(){
    int i, j, n, s;
    char c;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter a character: ");
    scanf(" %c", &c);
    
    printf("\n");
    
    s = n * 2 - 1;
    
    for(i = 1; i <= n; i++)
    {
        for(j = s; j > i * 2 - 1; j--) printf(" ");
        for(j = 1; j <= i * 2 - 1; j++) printf("%c", c);
        printf("\n");
    }
}
