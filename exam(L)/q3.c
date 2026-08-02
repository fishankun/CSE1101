#include <stdio.h>
int req_sum(int n);

int main(){
  int n;
  scanf("%d", &n);
  printf("%d", req_sum(req_sum(req_sum(n));
  return 0;
}

int req_sum(int n){
  if(n < 10) return n; 
  return  req_sum(n / 10) + n % 10;
}
