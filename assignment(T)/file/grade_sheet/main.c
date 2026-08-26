#include <stdio.h>
#include <stdlib.h>

#define STUDENT_COUNT 50

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

int open_student_info(student_info *student){
    FILE *fp = fopen("student_info.txt", "rb");
    if(!fp) return 0;

    for(int i = 0; i < 50; i++){
        fread(&student[i], sizeof(student_info), 1, fp);
    }

    fclose(fp);
    return 1;
}

void save_student_info(student_info *student){
    FILE *fp = fopen("student_info_out.txt", "wb");
    for(int i = 0; i < STUDENT_COUNT; i++){
        fwrite(&student[i], sizeof(student_info), 1, fp);
    }

    fclose(fp);

    fp = fopen("student_info_out_text.txt", "w");
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

int main(){
    student_info student[STUDENT_COUNT];
    float total[7];
    float cg[7];
    float sum = 0;
    int i, j, is_sorted;

    if(!open_student_info(student)) return 0;

    marks *cse1101 = result_reader("cse1101.txt");
    marks *cse1101l = result_reader("cse1101l.txt");
    marks *cse1102 = result_reader("cse1102.txt");
    marks *stat1103 = result_reader("stat1103.txt");
    marks *ge1105 = result_reader("ge1105.txt");
    marks *se1106 = result_reader("se1106.txt");
    marks *math1107 = result_reader("math1107.txt");

    if(!cse1101 || !cse1101l || !cse1102 || !stat1103 || !ge1105 || !se1106 || !math1107) return 0;

    for(i = 0; i < STUDENT_COUNT; i++){
        total[0] = cse1101[i].final + cse1101[i].mid_term + cse1101[i].assignment + cse1101[i].attendance + cse1101[i].quiz;
        total[1] = cse1101l[i].final + cse1101l[i].mid_term + cse1101l[i].assignment + cse1101l[i].attendance + cse1101l[i].quiz;
        total[2] = cse1102[i].final + cse1102[i].mid_term + cse1102[i].assignment + cse1102[i].attendance + cse1102[i].quiz;
        total[3] = stat1103[i].final + stat1103[i].mid_term + stat1103[i].assignment + stat1103[i].attendance + stat1103[i].quiz;
        total[4] = ge1105[i].final + ge1105[i].mid_term + ge1105[i].assignment + ge1105[i].attendance + ge1105[i].quiz;
        total[5] = se1106[i].final + se1106[i].mid_term + se1106[i].assignment + se1106[i].attendance + se1106[i].quiz;
        total[6] = math1107[i].final + math1107[i].mid_term + math1107[i].assignment + math1107[i].attendance + math1107[i].quiz;

        sum = 0;
        for(j = 0; j < 7; j++){
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

    free(cse1101);
    free(cse1101l);
    free(cse1102);
    free(stat1103);
    free(ge1105);
    free(se1106);
    free(math1107);

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

    save_student_info(student);

    return 0;
}