#include <stdio.h>
#include <math.h>

int is_prime(int n, int i){
    int p = 1;
    if(n == 2) return 1;
    if(n % i == 0) return 0;
    if(i >= sqrt(n)) return 1;
    p = is_prime(n, i + 1);
    return p; 
}
int main(){
    int m, n;
    scanf("%d", &m);
    for(n = 2; n < m; n++){
        if(is_prime(n, 2)) printf("%d ", n);
    }

    return 0;
}