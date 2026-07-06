#include <stdio.h>

int  my_strlen(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; i++);
    return i;
}

int main(){
    char a[100];
    printf("Enter the string: ");
    scanf("%s", a);
    printf("The length of the string is %d", my_strlen(a));    
    return 0;
}