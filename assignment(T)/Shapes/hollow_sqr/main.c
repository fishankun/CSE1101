#include <stdio.h>

int main(){
    int n, i, j;
    char c;
    
    printf("Enter the length of the square: ");
    scanf("%d", &n);
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("\n");
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(i == 1 || i == n || j == 1 || j == n) printf("%c", c);
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}