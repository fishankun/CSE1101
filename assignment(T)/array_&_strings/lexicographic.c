#include <stdio.h>

int main(){
    char a[100], b[100];
    printf("Enter the 'a' string: ");
    scanf("%s", a);
    printf("Enter the 'b' string: ");
    scanf("%s", b);

    int i, m = 0;
    for(i = 0; a[i] != '\0' || b[i] != '\0'; i++){
        if(a[i] > b[i]){
            m = (int)a[i] - (int)b[i];
            break;
        }
        else if(a[i] < b[i]){
            m = (int)a[i] - (int)b[i];
            break;
        }
    }
    if(m == 0){
        if(a[i] == '\0' && b[i] != '\0') m = (int)a[i] - (int)b[i];
        else if(a[i] != '\0' && b[i] == '\0') m = (int)a[i] - (int)b[i];
    }

    printf("%d", m);
}