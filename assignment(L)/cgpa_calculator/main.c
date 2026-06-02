#include <stdio.h>

float grade(float x) {
    if (x >= 80) return 4.00;
    else if (x >= 75) return 3.75;
    else if (x >= 70) return 3.50;
    else if (x >= 65) return 3.25;
    else if (x >= 60) return 3.00;
    else if (x >= 55) return 2.75;
    else if (x >= 50) return 2.50;
    else if (x >= 45) return 2.25;
    else if (x >= 40) return 2.00;
    else return 0.00;
}

int main() {
    float sub[7], credits[7] = {3, 3, 3, 3, 3, 3, 1.5};
    char subjects[7][50] = {
        "CSE 1101",
        "CSE 1102",
        "STAT 1103",
        "MATH 1107",
        "GE 1105",
        "SE 1106",
        "CSE 1101L"
    };

    float total_points = 0, total_credits = 0;
    int valid = 1;

    printf("CGPA Calculator\n\n");

    for (int i = 0; i < 7; i++) {
        printf("%s: ", subjects[i]);
        scanf("%f", &sub[i]);

        if (sub[i] < 0 || sub[i] > 100) {
            valid = 0;
        }
    }

    if (!valid) {
        printf("\nInvalid input! Marks must be between 0 and 100.\n");
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        float gpa = grade(sub[i]);
        total_points += gpa * credits[i];
        total_credits += credits[i];
    }

    printf("\nYour CGPA is: %.2f\n", total_points / total_credits);

    return 0;
}
