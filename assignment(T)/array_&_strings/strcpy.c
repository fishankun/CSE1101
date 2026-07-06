#include <stdio.h>

void my_strcpy(char a[], char b[]){
    int i, j;
    for(i = 0; a[i] != '\0'; i++) a[i] = '\0';
    for(i = 0; b[i] != '\0'; i++) a[i] = b[i];
}

int main(){
    char a[100], b[100];
    printf("Enter the 'a' string: ");
    scanf("%s", a);
    printf("Enter the 'b' string: ");
    scanf("%s", b);
    my_strcpy(a, b);
    printf("%s", a);
    return 0;
}