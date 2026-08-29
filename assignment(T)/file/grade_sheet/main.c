#include <stdio.h>
#include <stdlib.h>

#define STUDENT_COUNT 50
#define COURSE_COUNT 7

typedef struct{
    char name[100];
    int roll;
    float cgpa;
} student_info;

typedef struct{
    int roll;
    float final;
    float mid_term;
    float assignment;
    float attendance;
    float quiz;
} marks;

int open_student_info(student_info *student, char *filename){
    FILE *fp = fopen(filename, "rb");
    if(!fp) return 0;

    for(int i = 0; i < STUDENT_COUNT; i++){
        fread(&student[i], sizeof(student_info), 1, fp);
    }

    fclose(fp);
    return 1;
}

void save_student_info(student_info *student, char *filename){
    FILE *fp = fopen(filename, "wb");
    for(int i = 0; i < STUDENT_COUNT; i++){
        fwrite(&student[i], sizeof(student_info), 1, fp);
    }

    fclose(fp);

    fp = fopen(filename, "w");
    for(int i = 0; i < STUDENT_COUNT; i++){
        fprintf(fp, "%s\t%d\t%.2f\n", student[i].name, student[i].roll, student[i].cgpa);
    }

    fclose(fp);
}

marks *result_reader(const char *filename){
    marks *m = malloc(STUDENT_COUNT * sizeof(marks));
    if(!m) return NULL;

    FILE *fp = fopen(filename, "rb");
    if(!fp){
        free(m);
        return NULL;
    }

    for(int i = 0; i < STUDENT_COUNT; i++){
        fread(&m[i], sizeof(marks), 1, fp);
    }

    fclose(fp);
    
    return m;
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

int main(int argc, char *argv[]){
    student_info student[STUDENT_COUNT];
    float total[COURSE_COUNT];
    float cg[COURSE_COUNT];
    float sum = 0;
    int i, j, is_sorted;
    marks *courses[COURSE_COUNT];

    if(!open_student_info(student, argv[1])) return 0;

    for(i = 0; i < COURSE_COUNT; i++) courses[i] = result_reader(argv[i + 2]);

    if(!courses[2] || !courses[3] || !courses[4] || !courses[5] || !courses[6] || !courses[7] || !courses[8]) return 0;

    for(i = 0; i < STUDENT_COUNT; i++){
        sum = 0;
        for(j = 0; j < COURSE_COUNT; j++){
            total[j] = courses[j][i].final + courses[j][i].mid_term + courses[j][i].assignment + courses[j][i].attendance + courses[j][i].quiz;

            if(j == 1){
                cg[j] = mark_compare(total[j]) * 1.5;
                sum += cg[j];
                continue; 
            }
            cg[j] = mark_compare(total[j]) * 3;
            sum += cg[j];
        }
        student[i].cgpa = sum / 19.5;
    }

    for(i = 0; i < COURSE_COUNT; i++) free(courses[i]);

    int n = STUDENT_COUNT - 1;
    do{
        is_sorted = 1;
        for(i = 0; i < n; i++){
            if(student[i].cgpa < student[i + 1].cgpa){
                student_info temp = student[i];
                student[i] = student[i + 1];
                student[i + 1] = temp;
                is_sorted = 0;
            }
        }
        n--;
    }while(!is_sorted);

    save_student_info(student, argv[9]);
    return 0;
}