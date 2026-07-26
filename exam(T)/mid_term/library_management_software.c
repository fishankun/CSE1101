#include <stdio.h>
#include <string.h>

char books[20][100];
int b_status[20];
int student_status[50] = {0};
int b_number = 0;

void add_book();
void borrow_book();
void return_book();
void search();
int menu();

int main(){
    int i, option;
    for(i = 0; i < 20; i++) b_status[i] = 1;

    printf("Welcome to the Library Management Software.\n");

    while((option = menu()) != 0){
        switch(option){
            case 1: add_book();
                    break;
            case 2: borrow_book();
                    break;
            case 3: return_book();
                    break;
            case 4: search();
                    break;
            default: printf("Invalid Option.\n");
                    break;
        }
    }
    return 0;
}

void add_book(){
    if(b_number == 20){
        printf("Library is full.\n");
        return;
    }
    printf("Enter the book name: ");
    scanf(" %[^\n]", books[b_number]);
    b_number++;

    printf("Book list:\n");
    for(int i = 0; i < b_number; i++) printf("%s\n", books[i]);
}

void borrow_book(){
    int roll, i, flag = 0;
    char book[100];
    
    printf("Enter your roll: ");
    scanf("%d", &roll);
    if(roll < 1 || roll > 50){
        printf("Invalid roll.\n");
        return;
    }

    printf("Enter the book name you want to borrow: ");
    scanf(" %[^\n]", book);

    for(i = 0; i < b_number; i++){
        if((strcmp(books[i], book) == 0) && student_status[roll - 1] == 0 && b_status[i] == 1){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("Operation successful.\n");
        student_status[roll - 1] = i + 1;
        b_status[i] = 0;
    }
    else printf("Error. Try again.\n");
}

void return_book(){
    int roll, i, flag = 0;
    char book[100];
    
    printf("Enter your roll: ");
    scanf("%d", &roll);
    if(roll < 1 || roll > 50){
        printf("Invalid roll.\n");
        return;
    }

    printf("Enter the book name you want to return: ");
    scanf(" %[^\n]", book);

    for(i = 0; i < b_number; i++){
        if((strcmp(books[i], book) == 0) && student_status[roll - 1] == i + 1){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("Successfully returned.\n");
        student_status[roll - 1] = 0;
        b_status[i] = 1;
    }
    else printf("Error. Try again.\n");
}

void search(){
    int roll, book_index;
    
    printf("Enter the roll: ");
    scanf("%d", &roll);
    if(roll < 1 || roll > 50){
        printf("Invalid roll.\n");
        return;
    }

    book_index = student_status[roll - 1];

    if(book_index != 0) printf("Yes, Roll %d borrowed a book.\nBook name: %s\n", roll, books[book_index - 1]);
    else printf("No book found.\n");
}

int menu(){
    int option;
    printf("Menu:\n");
    printf("1. Add a new book.\n2. Borrow a book.\n");
    printf("3. Return a book.\n4. Search by roll.\n");
    printf("Press 0 to exit: ");

    scanf("%d", &option);
    return option;
}