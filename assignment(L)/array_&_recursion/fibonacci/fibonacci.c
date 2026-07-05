#include <stdio.h>

int fibonacci(int n){
    int sum;
    if(n == 1) return 0;
    if(n == 2) return 1;
    sum = fibonacci(n - 1) + fibonacci(n - 2);
    return sum;
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("The %dth fibonacci number is %d", n, fibonacci(n));
    return 0;
}