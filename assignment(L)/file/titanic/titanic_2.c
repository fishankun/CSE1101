#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int age_cat(int age){
    if(1 <= age && age <= 18) return 1;
    else if(19 <= age && age <= 40) return 2;
    else if(41 <= age) return 3;
    else return 0;
}
int main(){
    FILE *fp = fopen("titanic.csv", "r");
    FILE *wf = fopen("titanic_age.csv", "w");

    int comma = 0;
    int in_quotes = 0;   // are we inside a "..." field right now?
    int age;
    char c;
    char str[100];
    int si = 0;          // write position inside str

    fscanf(fp, " %[^\n]", str);  // skip the header line
    fprintf(wf, "%s,AgeCategory\n", str);
    fgetc(fp);
    str[0] = '\0';

    while((c = fgetc(fp)) != EOF){
        if(c != '\n') fprintf(wf, "%c", c);

        if(c == '"'){
            in_quotes = !in_quotes;   // toggle, don't store the quote itself
            continue;
        }

        if(c == ',' && !in_quotes){
            // field number 'comma' just finished, its text is in str
            if(comma == 5) age = atoi(str);
            comma++;
            si = 0;
            str[0] = '\0';
            continue;
        }

        if(c == '\n'){
            // end of row, reset everything for the next one
            fprintf(wf,",%d\n", age_cat(age));
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
    fclose(wf);

    return 0;
}