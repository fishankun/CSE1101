#include <stdio.h>

void my_strcpy(char *a, char *b);
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

void my_strcpy(char *a, char *b){
    int i;
    for(i = 0; *(a + i); i++) *(a + i) = '\0';
    for(i = 0; *(b + i); i++) *(a + i) = *(b + i);
}