#include <stdio.h>

float cgpa(int student_number);
float mark_compare(float mark);


int main(){
    float student[5];
    float sorted[5];
    int i, j, n, is_sorted;

    for(i = 0; i < 5; i++){
        student[i] = cgpa(i);
        sorted[i] = student[i];
    }
    n = 4;
    do{
        is_sorted = 1;
        for(i = 0; i < n; i++){
            if(sorted[i] > sorted[i + 1]){
                float temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
                is_sorted = 0;
            }
        }
        n--;
    }while(!is_sorted);

    printf("\nPosition\tRoll Number\tCGPA\n");
    for(i = 4; i >= 0; i--){
        for(j = 0; j < 5; j++){
            if(sorted[i] == student[j]){
                printf("%d\t\troll %d\t\t%.2f\n", 5 - i, j + 1, sorted[i]);
                student[j] = -1; // Mark this student as printed to avoid duplicates
            }
        }
    }

    
}

float cgpa(int student_number){
    float cse_1101, cse_1102, cse_1101L, stat_1103, ge_1105, se_1106, math_1107;
    printf("Enter marks for roll no. %d:\n", student_number + 1);
    printf("Structured Programming: ");
    scanf("%f", &cse_1101);
    cse_1101 = mark_compare(cse_1101) * 3;
    printf("Discrete Mathematics: ");
    scanf("%f", &cse_1102);
    cse_1102 = mark_compare(cse_1102) * 3;
    printf("Structured Programming Lab: ");
    scanf("%f", &cse_1101L);
    cse_1101L = mark_compare(cse_1101L) * 1.5;
    printf("Statistics: ");
    scanf("%f", &stat_1103);
    stat_1103 = mark_compare(stat_1103) * 3;
    printf("Sociology: ");
    scanf("%f", &ge_1105);
    ge_1105 = mark_compare(ge_1105) * 3;
    printf("Introduction to Software Engineering: ");
    scanf("%f", &se_1106);
    se_1106 = mark_compare(se_1106) * 3;
    printf("Calculus: ");
    scanf("%f", &math_1107);
    math_1107 = mark_compare(math_1107) * 3;

    float total = cse_1101 + cse_1102 + cse_1101L + stat_1103 + ge_1105 + se_1106 + math_1107;
    float result = total / 19.5;
    return result;
}

float mark_compare(float mark){
    if(mark >= 80) return 4.00;
    else if(mark >= 75) return 3.75;
    else if(mark >= 70) return 3.50;
    else if(mark >= 65) return 3.25;
    else if(mark >= 60) return 3.00;
    else if(mark >= 55) return 2.75;
    else if(mark >= 50) return 2.50;
    else if(mark >= 45) return 2.25;
    else if(mark >= 40) return 2.00;
    else return 0.00;
}