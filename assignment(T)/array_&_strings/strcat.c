#include <stdio.h>

void my_strcat(char a[], char b[]){
    int i, j;
    for(i = 0; a[i] != '\0'; i++);
    for(j = 0; b[j] != '\0'; j++, i++){
        a[i] = b[j];
    }
    a[i] = '\0';
}

int main(){
    char a[100], b[100];
    printf("Enter the 'a' string: ");
    scanf("%s", a);
    printf("Enter the 'b' string: ");
    scanf("%s", b);
    my_strcat(a, b);

    printf(a);
}