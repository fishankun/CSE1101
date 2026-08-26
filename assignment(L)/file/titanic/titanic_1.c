#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp = fopen("titanic.csv", "r");
    int m_total = 0, f_total = 0, m_alive = 0, f_alive = 0;
    int comma = 0;
    int in_quotes = 0;   // are we inside a "..." field right now?
    int survived = 0;
    char c;
    char str[100];
    int si = 0;          // write position inside str

    fscanf(fp, " %[^\n]", str);  // skip the header line
    str[0] = '\0';

    while((c = fgetc(fp)) != EOF){

        if(c == '"'){
            in_quotes = !in_quotes;   // toggle, don't store the quote itself
            continue;
        }

        if(c == ',' && !in_quotes){
            // field number 'comma' just finished, its text is in str
            if(comma == 1) survived = (strcmp(str, "1") == 0);
            if(comma == 4){
                if(strcmp(str, "male") == 0){
                    m_total++;
                    if(survived) m_alive++;
                }
                else if(strcmp(str, "female") == 0){
                    f_total++;
                    if(survived) f_alive++;
                }
            }
            comma++;
            si = 0;
            str[0] = '\0';
            continue;
        }

        if(c == '\n'){
            // end of row, reset everything for the next one
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

    printf("Male: %d%%\n", m_alive * 100 / m_total);
    printf("Female: %d%%\n", f_alive * 100 / f_total);
    printf("Total: %.2f%%", 100.0 * (m_alive + f_alive) / (m_total + f_total));

    return 0;
}