#include <stdio.h>

int month_checker(int month, int year);
int year_checker(int year);
int main(){
  int month, year;
  
  while(1){
    scanf("%d", &month);
    if(month > 0 && month <= 12) break;
    else{
      printf("Invalid month.\n");
      return 0;
    }
  }
  
  scanf("%d", &year);
  
  printf("%d", month_checker(month, year));
  return 0;
}


int month_checker(int month, int year){
  if(month == 1 || month == 3 || month == 5 ||
     month == 7 || month == 8 || month == 10 ||
     month == 12) return 31;
  else if(month == 4 || month == 6 || month == 9 ||
          month == 11) return 30;
  else if(month == 2) return year_checker(year);
  else return 0;
}

int year_checker(int year){
  if(year % 400 == 0) return 29;
  else if(year % 4 == 0 && year % 100 != 0) return 29;
  else return 28;
}
