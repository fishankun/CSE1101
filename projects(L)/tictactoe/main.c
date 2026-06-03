#include <stdio.h>
/*
BSSE Roll: 1801

Tic Tac Toe
Human (X) vs Computer (O)

Bot strategy:
1. Win if possible
2. Block opponent from winning
3. Block opponent's fork
4. Take center
5. Take corner
6. Take edge
*/

char p1 = '1', p2 = '2', p3 = '3', p4 = '4', p5 = '5', p6 = '6', p7 = '7', p8 = '8', p9 = '9';
void board(int move, char symbol);
int bot();
int checker();
int block_or_win(char symbol);
int scan();
int is_occupied(int move);
int fork_block();

int main(){
    int i, move, replay = 1; 
    while(replay != 0){
        int turn = 0, result = 0; //reset variables for new game

        printf("===============================================\n");
        printf("            WELCOME TO TIC TAC TOE             \n");
        printf("===============================================\n\n");
        printf("           Prepare for an epic duel!           \n\n");
        printf("        You are Player X   |   Bot is O        \n");
        printf("===============================================\n\n");
        board(0, 'X');

        //Who will start first?
        while(turn != 1 && turn != 2){
            printf("But who will start first? (1 for player, 2 for bot): ");
            scanf("%d", &turn);
            if(turn != 1 && turn != 2) printf("Invalid input, please enter 1 for player or 2 for bot.\n");
            }
        if(turn == 2) printf("Bot starts first.\n\n");
        else printf("Player starts first.\n\n");

        for(i = 1; i <= 9; i++){
            if(turn == 1){
                move = scan();
                board(move, 'X');
                turn = 2; //player has made their first move, now bot will start
            }
            else if(turn == 2){
                printf("Bot's turn:\n");
                move = bot();
                printf("Bot chose position %d.\n", move);
                board(move,'O');
                turn = 1; //bot has made its first move, now player will start
            }
            printf("\n");
            result = checker();

            if(result == 1){
                printf("===============================================\n");
                printf("        *** PLAYER WINS! CONGRATS! ***         \n");
                printf("===============================================\n\n");
                break;
            }
            else if(result == 2){
                printf("===============================================\n");
                printf("        *** BOT WINS! BETTER LUCK! ***         \n");
                printf("===============================================\n\n");
                break;
            }
        }
        if(result == 0){
            printf("===============================================\n");
            printf("             *** IT'S A DRAW! ***              \n");
            printf("===============================================\n\n");
        }
        printf("Do you want to play again? (any key for yes, 0 for no): ");
        scanf("%d", &replay);
        
        // Reset board
        if(replay != 0){
            p1='1'; p2='2'; p3='3';
            p4='4'; p5='5'; p6='6';
            p7='7'; p8='8'; p9='9';
            printf("===============================================\n\n\n");
        }
    }
    return 0;
}

int scan(){
    int i, move, s = 0;
    for(i = 1; i > 0; i++){
        printf("Player's turn - enter a position(1-9):\n");
        scanf("%d", &move);
        s = is_occupied(move);
        if(move >= 1 && move <= 9 && s == 0) break;
        else if(move >= 1 && move <= 9 && s == 1) printf("Position already occupied, try again.\n");
        else printf("Invalid input, enter a position between 1 to 9.\n");
    }
    return move;
}
int is_occupied(int move){
    if(move == 1){
        if(p1 != '1') return 1;
        else return 0;
    }
    else if(move == 2){
        if(p2 != '2') return 1;
        else return 0;
    }
    else if(move == 3){
        if(p3 != '3') return 1;
        else return 0;
    }
    else if(move == 4){
        if(p4 != '4') return 1;
        else return 0;
    }
    else if(move == 5){
        if(p5 != '5') return 1;
        else return 0;
    }
    else if(move == 6){
        if(p6 != '6') return 1;
        else return 0;
    }
    else if(move == 7){
        if(p7 != '7') return 1;
        else return 0;
    }
    else if(move == 8){
        if(p8 != '8') return 1;
        else return 0;
    }
    else if(move == 9){
        if(p9 != '9') return 1;
        else return 0;
    }
    else return 1;
}
void board(int move, char symbol){
    if(move == 1 && p1 == '1') p1 = symbol;
    else if(move == 2 && p2 == '2') p2 = symbol;
    else if(move == 3 && p3 == '3') p3 = symbol;
    else if(move == 4 && p4 == '4') p4 = symbol;
    else if(move == 5 && p5 == '5') p5 = symbol;
    else if(move == 6 && p6 == '6') p6 = symbol;
    else if(move == 7 && p7 == '7') p7 = symbol;
    else if(move == 8 && p8 == '8') p8 = symbol;
    else if(move == 9 && p9 == '9') p9 = symbol;

    printf("Current Board:\n");
    printf(" %c | %c | %c \n", p1, p2, p3);
    printf("---|---|---\n");   
    printf(" %c | %c | %c \n", p4, p5, p6);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", p7, p8, p9);
    printf("\n");
}
int bot(){
    int move = 0;
    //can the bot win?
    move = block_or_win('O');
    if(move != 0) return move;

    //should the bot block?
    move = block_or_win('X');
    if(move != 0) return move;

    //should the bot block a fork?
    move = fork_block();
    if(move != 0) return move;
    
    if(move == 0){
        //first take the center
        if(p5 == '5') return 5;
        //then take the corners
        else if(p1 == '1') return 1;
        else if(p3 == '3') return 3;
        else if(p7 == '7') return 7;
        else if(p9 == '9') return 9;
        //then the edges
        else if(p2 == '2') return 2;
        else if(p4 == '4') return 4;
        else if(p6 == '6') return 6;
        else if(p8 == '8') return 8;
    }
    return 0;  
}
int checker(){
    int s = 0;
    if(p1 == 'X' && p2 == 'X' && p3 == 'X') s = 1;
    else if(p4 == 'X' && p5 == 'X' && p6 == 'X') s = 1;
    else if(p7 == 'X' && p8 == 'X' && p9 == 'X') s = 1;
    else if(p1 == 'X' && p4 == 'X' && p7 == 'X') s = 1;
    else if(p2 == 'X' && p5 == 'X' && p8 == 'X') s = 1;
    else if(p3 == 'X' && p6 == 'X' && p9 == 'X') s = 1;
    else if(p1 == 'X' && p5 == 'X' && p9 == 'X') s = 1;
    else if(p3 == 'X' && p5 == 'X' && p7 == 'X') s = 1;
    
    else if(p1 == 'O' && p2 == 'O' && p3 == 'O') s = 2;
    else if(p4 == 'O' && p5 == 'O' && p6 == 'O') s = 2;
    else if(p7 == 'O' && p8 == 'O' && p9 == 'O') s = 2;
    else if(p1 == 'O' && p4 == 'O' && p7 == 'O') s = 2;
    else if(p2 == 'O' && p5 == 'O' && p8 == 'O') s = 2;
    else if(p3 == 'O' && p6 == 'O' && p9 == 'O') s = 2;
    else if(p1 == 'O' && p5 == 'O' && p9 == 'O') s = 2;
    else if(p3 == 'O' && p5 == 'O' && p7 == 'O') s = 2;

    return s;
}
int block_or_win(char symbol){
    if(p5 == symbol){
        if(p1 == symbol && p9 == '9') return 9;
        else if(p2 == symbol && p8 == '8') return 8;
        else if(p3 == symbol && p7 == '7') return 7;
        else if(p4 == symbol && p6 == '6') return 6;
        else if(p6 == symbol && p4 == '4') return 4;
        else if(p7 == symbol && p3 == '3') return 3;
        else if(p8 == symbol && p2 == '2') return 2;
        else if(p9 == symbol && p1 == '1') return 1;
    }

    if(p2 == symbol){
        if(p1 == symbol && p3 == '3') return 3;
        else if(p3 == symbol && p1 == '1') return 1;
    }
    if(p4 == symbol){
        if(p1 == symbol && p7 == '7') return 7;
        else if(p7 == symbol && p1 == '1') return 1;
    }
    if(p6 == symbol){
        if(p9 == symbol && p3 == '3') return 3;
        else if(p3 == symbol && p9 == '9') return 9;
    }
    if(p8 == symbol){
        if(p7 == symbol && p9 == '9') return 9;
        else if(p9 == symbol && p7 == '7') return 7;
    }

    if(p1 == symbol &&p3 == symbol && p2 == '2') return 2;
    else if(p1 == symbol && p7 == symbol && p4 == '4') return 4;
    else if(p1 == symbol && p9 == symbol && p5 == '5') return 5;
    else if(p2 == symbol && p8 == symbol && p5 == '5') return 5;
    else if(p3 == symbol && p7 == symbol && p5 == '5') return 5;
    else if(p4 == symbol && p6 == symbol && p5 == '5') return 5;
    else if(p9 == symbol && p7 == symbol && p8 == '8') return 8;
    else if(p9 == symbol && p3 == symbol && p6 == '6') return 6;
    return 0;
}
int fork_block(){
    if(p5 == 'O'){
        if((p1 == 'X' && p9 == 'X') || (p3 == 'X' && p7 == 'X')){
            if(p2 == '2') return 2;
            else if(p8 == '8') return 8;
        }
        else if(p8 == 'X' && p6 == 'X'){
            if(p3 == '3') return 3;
        }
        else if(p8 == 'X' && p1 == 'X'){
            if(p4 == '4') return 4;
        }
        else if(p8 == 'X' && p3 == 'X'){
            if(p6 == '6') return 6;
        }
        else if(p6 == 'X' && p7 == 'X'){
            if(p8 == '8') return 8;
        }
    }
    return 0;
}