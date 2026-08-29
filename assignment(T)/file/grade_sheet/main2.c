#include <stdio.h>
#include <stdlib.h>

#define N 50
#define C 7

typedef struct Student {
    char name[100];
    int roll;
    float cgpa;
    struct Student *next;
} Student;

typedef struct {
    int roll;
    float final, mid, assignment, attendance, quiz;
} Marks;

float grade(float m){
    if(m >= 80) return 4;
    if(m >= 75) return 3.75;
    if(m >= 70) return 3.5;
    if(m >= 65) return 3.25;
    if(m >= 60) return 3;
    if(m >= 55) return 2.75;
    if(m >= 50) return 2.5;
    if(m >= 45) return 2.25;
    if(m >= 40) return 2;
    return 0;
}

int main(int argc, char *argv[]){
    Student s[N];
    Marks *m[C];
    FILE *fp;
    int i, j, roll;

    if(argc != 10) return 1;

    /* Read students */
    fp = fopen(argv[1], "rb");
    if(!fp) return 1;

    for(i = 0; i < N; i++){
        fread(s[i].name, sizeof(s[i].name), 1, fp);
        fread(&s[i].roll, sizeof(int), 1, fp);
        fread(&s[i].cgpa, sizeof(float), 1, fp);
    }
    fclose(fp);

    /* Read course files */
    for(i = 0; i < C; i++){
        m[i] = malloc(N * sizeof(Marks));
        fp = fopen(argv[i + 2], "rb");

        if(!fp) return 1;

        fread(m[i], sizeof(Marks), N, fp);
        fclose(fp);
    }

    /* Calculate CGPA */
    for(i = 0; i < N; i++){
        float sum = 0;

        for(j = 0; j < C; j++){
            float total = m[j][i].final + m[j][i].mid
                        + m[j][i].assignment
                        + m[j][i].attendance
                        + m[j][i].quiz;

            sum += grade(total) * (j == 1 ? 1.5 : 3);
        }

        s[i].cgpa = sum / 19.5;
    }

    /* Sort */
    for(i = 0; i < N - 1; i++)
        for(j = 0; j < N - i - 1; j++)
            if(s[j].cgpa < s[j + 1].cgpa){
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }

    /* Link students */
    for(i = 0; i < N - 1; i++)
        s[i].next = &s[i + 1];

    s[N - 1].next = NULL;

    /* Search and print */
    printf("Enter roll: ");
    scanf("%d", &roll);

    for(i = 0; i < N; i++)
        if(s[i].roll == roll){
            Student *p = &s[i];

            while(p){
                printf("%s\t%d\t%.2f\n",
                       p->name, p->roll, p->cgpa);
                p = p->next;
            }
            break;
        }

    /* Save */
    fp = fopen(argv[9], "wb");

    for(i = 0; i < N; i++){
        fwrite(s[i].name, sizeof(s[i].name), 1, fp);
        fwrite(&s[i].roll, sizeof(int), 1, fp);
        fwrite(&s[i].cgpa, sizeof(float), 1, fp);
    }

    fclose(fp);

    for(i = 0; i < C; i++)
        free(m[i]);

    return 0;
}