#include <stdio.h>

void my_strcmp(char *a, char *b);
int main(){
    char a[100], b[100];
    printf("Enter the 'a' string: ");
    scanf("%s", a);
    printf("Enter the 'b' string: ");
    scanf("%s", b);
    
    my_strcmp(a, b);
    return 0;
}

void my_strcmp(char *a, char *b){
    int i, m = 1;
    for(i = 0; *(a + i) != '\0' || *(b + i) != '\0'; i++){
        if(*(a + i) != *(b + i)){
            printf("Not equal");
            m = 0;
            break;
        }
    }
    if(m && *(a + i) == *(b + i)) printf("Equal");
}