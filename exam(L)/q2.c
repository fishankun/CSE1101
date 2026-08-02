#include <stdio.h>
int main(){
  int N, i, j, temp;
  scanf("%d", &N);
  int arr[N];
  for(i = 0; i < N; i++) scanf("%d", &arr[i]);
  
  int freq[201] = {0};
  for(i = 0; i < N; i++){
    temp = arr[i];
    freq[temp + 100]++;
  }
  
  for(i = -100; i < 101; i++){
    if(freq[i + 100] >= 1){
      printf("%d: ", i);
      for(j = 1; j <= freq[i + 100]; j++) printf("*");
      printf("\n");
    }
  }
  return 0;
}
