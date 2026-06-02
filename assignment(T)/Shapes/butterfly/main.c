#include <stdio.h>

void line(int n, char c1, char c2){
    int i, j;
    char fill;
    for(i = 1; i <= n - 2; i++){
        fill = (i % 2 != 0) ? '*' : '-';
        for(j = 1; j <= n - 2; j++) printf("%c", fill);
        printf("%c %c", c1, c2);
        for(j = 1; j <= n - 2; j++) printf("%c", fill);
        printf("\n");
    }
}

int main(){
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\n");
    
    line(n, '\\', '/');
    for(i = 1; i <= n - 1; i++) printf(" ");
    printf("@\n");
    line(n, '/', '\\');
    return 0;
}