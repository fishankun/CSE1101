#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, j, space, star;
    char c;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter a character: ");
    scanf(" %c", &c);

    printf("\n");

    for(i = 0; i < n; i++) {

        space = abs(n / 2 - i);
        star = n - 2 * space;

        for(j = 0; j < space; j++)
            printf(" ");

        for(j = 0; j < star; j++)
            printf("%c", c);

        printf("\n");
    }

    return 0;
}