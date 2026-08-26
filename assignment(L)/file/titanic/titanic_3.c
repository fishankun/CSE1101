#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("titanic_age.csv", "r");
    int is_male = 0, iclass = 0, iage_cat = 0;
    int in_quotes = 0, survived = 0, comma = 0;
    char c, str[100];
    int si = 0;          // write position inside str
    int total[4][4][2] = {0}, alive[4][4][2] = {0};

    fscanf(fp, " %[^\n]", str);  // skip the header line
    fgetc(fp);
    str[0] = '\0';

    while((c = fgetc(fp)) != EOF){

        if(c == '"'){
            in_quotes = !in_quotes;   // toggle, don't store the quote itself
            continue;
        }

        if(c == ',' && !in_quotes){
            // field number 'comma' just finished, its text is in str
            if(comma == 1) survived = (strcmp(str, "1") == 0);
            else if(comma == 2) iclass = atoi(str);
            else if(comma == 4){
                if(strcmp(str, "male") == 0) is_male = 1;
                else if(strcmp(str, "female") == 0) is_male = 0;
            }
            
            comma++;
            si = 0;
            str[0] = '\0';
            continue;
        }

        if(c == '\n'){
            // end of row, reset everything for the next one
            iage_cat = atoi(str);
            total[iclass][iage_cat][is_male]++;
            if(survived) alive[iclass][iage_cat][is_male]++;
            comma = 0;
            si = 0;
            str[0] = '\0';
            continue;
        }

        // this is where we are taking string input
        if(si < (int)sizeof(str) - 1){
            str[si++] = c;
            str[si] = '\0';
        }
    }
    fclose(fp);

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Pclass", "Age Category", "Male Survived", "Female Survived");
    int p, q;
    for(p = 1; p < 4; p++){
        printf("%-20d\t%-20s\t%-.2lf%%\t\t\t%-.2lf%%\n", p, "Unknown", 100.00 * alive[p][0][1] / total[p][0][1], 100.00 * alive[p][0][0] / total[p][0][0]);

        for(q = 1; q < 4; q++){
            printf("%-20d\t%-20d\t%-.2lf%%\t\t\t%-.2lf%%\n", p, q, 100.00 * alive[p][q][1] / total[p][q][1], 100.00 * alive[p][q][0] / total[p][q][0]);
        }
    }
    return 0;
}