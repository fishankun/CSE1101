#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define STRING_ELEMENTS 20

char words[STRING_ELEMENTS][20] = {
                        "ant",
                        "book",
                        "chair",
                        "apple",
                        "banana",
                        "dog",
                        "computer",
                        "fish",
                        "house",
                        "tree",
                        "pencil",
                        "car",
                        "school",
                        "mouse",
                        "bread",
                        "elephant",
                        "cup",
                        "window",
                        "phone",
                        "star"
                    };

void display(int attempts, int fail);
int random_word_selection(char ran_word[]);
char letter_guess();
int update_word(char ran_word[], char guess, int n);
void result(int success, int n);
int menu();

int main(){
    int attempt, fail, success, n, flag, i = 0, j, s;
    char guess;
    char blank[20];
    srand(time(NULL));

    printf("Welcome to Hangman!\n");
    printf("You will be given a word with missing letters.\n");
    printf("You have 6 attempts to guess the word.\n\n");

    while(menu()){
        char guessed_letters[100] = {0};
        printf("Let's begin!\n\n");
        attempt = 6;
        fail = 0;
        success = 0;
        i = 0;
        n = random_word_selection(blank);
        printf("The word is: %s\n", blank);
        display(attempt, fail);

        while(fail < 6){
            guess = letter_guess();
            guessed_letters[i] = guess;
            i++;
            flag = update_word(blank, guess, n);
            if(flag == 0){
                s = 1;
                for(j = 0; j < i - 1; j++){
                    if(guess == guessed_letters[j]){
                        printf("You have already guessed this letter. Try again.\n");
                        s = 0;
                        break;
                    }
                }
                if(s == 1){
                    fail++;
                    attempt--;
                }
            }
            printf("Guessed letters: ");

            for (j = 0; j < i; j++) {
                int duplicate = 0;

                for (int k = 0; k < j; k++) {
                    if (guessed_letters[j] == guessed_letters[k]) {
                    duplicate = 1;
                    break;
                    }
                }
                
                if (!duplicate)
                printf("%c ", guessed_letters[j]);
            }
            printf("\n\n");

            if(strcmp(words[n], blank) == 0){
                success = 1;
                break;
            }
            display(attempt, fail);
        }
        result(success, n);
    }
}

void display(int attempts, int fail){
    printf("Attempts Left: %d\n", attempts);

    printf("  +---+\n");
    printf("  |   |\n");
    if(fail >= 1) printf("  0   |\n");
    else printf("      |\n");

    if(fail >= 4) printf(" /|\\  |\n");
    else if(fail >= 3) printf(" /|   |\n");
    else if(fail >= 2) printf("  |   |\n");
    else printf("      |\n");

    if(fail >= 6) printf(" / \\  |\n");
    else if(fail >= 5) printf(" /    |\n");
    else printf("      |\n");

    printf("=========\n\n");
}

int random_word_selection(char ran_word[]){
    int n = rand() % STRING_ELEMENTS;
    strcpy(ran_word, words[n]);
    for(int i = 0; ran_word[i] != '\0'; i++){
        ran_word[i] = '_';
    }
    return n;
}

char letter_guess(){
    char guess;
    int buffer;
    do{
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        while((buffer = getchar()) != '\n');
        if((guess >= 'a' && guess <= 'z') || (guess >= 'A' && guess <= 'Z')) break;
        else printf("Invalid input. Try again.\n");
    }while(1);
    guess = tolower(guess);
    return guess;
}

int update_word(char ran_word[], char guess, int n){
    int flag = 0;
    for(int i = 0; words[n][i] != '\0'; i++){
        if(ran_word[i] == '_' && words[n][i] == guess){
            printf("You guessed it right\n");
            ran_word[i] = guess;
            flag = 1;
        }
    }
    if(!flag) printf("Incorrect guess.\n");
    printf("Current word: %s\n\n", ran_word);
    return flag;
}

void result(int success, int n){
    if(success)
        printf("Congratulations! You guessed the word correctly.\n");
    else
        printf("Sorry, you failed to guess the word.\n");

    printf("The correct word is: %s\n\n", words[n]);
}

int menu(){
    int choice;
    printf("1. Play Hangman (press 1)\n");
    printf("2. Exit (press 0)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) return 1;
    else return 0;
}