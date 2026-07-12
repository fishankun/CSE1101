#include <stdio.h>
#include <string.h>

void grade_calc(int total_marks, char grade[3]);

int main(){
    int student, course, roll, num_students, total_marks, choice;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    int marks[num_students][7][2];
    char grade[3];
    char course_name[7][50] = {
                            "CSE 1101",
                            "CSE 1101L",
                            "CSE 1102",
                            "STAT 1103",
                            "GE 1105",
                            "SE 1106",
                            "MATH 1107"
                         };

    for(student = 0; student < num_students; student++){
        printf("\nEnter Roll %d's marks for each subject:", student + 1);
        for(course = 0; course < 7; course++){
            printf("\nContinuous Evaluation marks of \"%s\": ", course_name[course]);
            scanf("%d", &marks[student][course][0]);
            printf("Term Final marks of \"%s\": ", course_name[course]);
            scanf("%d", &marks[student][course][1]);
            printf("\n");
        }
        printf("\n");
    }

    do{
        printf("Enter the Roll, whose result you want to see: ");
        scanf("%d", &roll);
        if (roll < 1 || roll > num_students) {
            printf("Invalid roll number!\n");
            continue;
        }
        printf("%-15s %-15s %-10s\n", "Course Name", "Total Marks", "Grade");

        for (course = 0; course < 7; course++) {
            total_marks = marks[roll - 1][course][0] + marks[roll - 1][course][1];
            grade_calc(total_marks, grade);

            printf("%-15s %-15d %-10s\n", course_name[course], total_marks, grade);
}
        printf("\nDo you want to see another result? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }while(choice);
}

void grade_calc(int total_marks, char grade[3]){
    if(total_marks >= 80) strcpy(grade, "A+");
    else if(total_marks >= 75) strcpy(grade, "A");
    else if(total_marks >= 70) strcpy(grade, "A-");
    else if(total_marks >= 65) strcpy(grade, "B+");
    else if(total_marks >= 60) strcpy(grade, "B");
    else if(total_marks >= 55) strcpy(grade, "C+");
    else if(total_marks >= 50) strcpy(grade, "C");
    else if(total_marks >= 45) strcpy(grade, "D");
    else if(total_marks >= 40) strcpy(grade, "E");
    else strcpy(grade, "F");
}