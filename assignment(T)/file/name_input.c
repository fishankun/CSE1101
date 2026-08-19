#include <stdio.h>
#include <string.h>

int main(){
    char name[50][100], sname[100];
    float cg[50];
    int i, is_sorted, n;
    FILE *fp;
    fp = fopen("name.txt", "r");
    for(i = 0; i < 5; i++){
        fscanf(fp, " %100[^\n]", name[i]);
        printf("%s\n", name[i]);
    }
    fclose(fp);

    fp = fopen("cgpa.txt", "r");
    for(i = 0; i < 5; i++){
        fscanf(fp, "%f", &cg[i]);
        printf("%.2f\n", cg[i]);
    }
    fclose(fp);

    n = 5;
    do{
        is_sorted = 1;
        for(i = 0; i < n - 1; i++){
            if(cg[i] < cg[i + 1]){
                float temp = cg[i];
                cg[i] = cg[i + 1];
                cg[i + 1] = temp;

                strcpy(sname, name[i]);
                strcpy(name[i], name[i + 1]);
                strcpy(name[i + 1], sname);
                is_sorted = 0;
            }
        }
        n--;
    }while(!is_sorted);

    for(i = 0; i < 5; i++){
        printf("%s\t%.3f\n", name[i], cg[i]);
    }

    fp = fopen("sorted result", "w");
    for(i = 0; i < 5; i++){
        fprintf(fp, "%s\t%.2f\n", name[i], cg[i]);
    }
    fclose(fp);
    return 0;
}