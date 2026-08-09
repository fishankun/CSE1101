#include <stdio.h>
#include <stdlib.h>

int main(){
    int row1, row2, col1, col2, i, j, a, b;
    printf("Enter row and column no. for 1st matrix: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter row and column no. for 2nd matrix: ");
    scanf("%d%d", &row2, &col2);
    if(col1 != row2){
        printf("Invalid Input\n");
        return 0;
    }

    int **mat1, **mat2;

    //scaning the first array
    mat1 = (int**)malloc(row1 * sizeof(int*));
    for(i = 0; i < row1; i++){
        *(mat1 + i) = (int*)malloc(col1 * sizeof(int));
    }
    printf("Enter the first matrix:\n");
    for(i = 0; i < row1; i++){
        for(j = 0; j < col1; j++){
            scanf("%d", *(mat1 + i) + j);
        }
    }

    //scanning the second array
    mat2 = (int**)malloc(row2 * sizeof(int*));
    for(i = 0; i < row2; i++){
        *(mat2 + i) = (int*)malloc(col2 * sizeof(int));
    }
    printf("Enter the second matrix:\n");
    for(i = 0; i < row2; i++){
        for(j = 0; j < col2; j++){
            scanf("%d", *(mat2 + i) + j);
        }
    }


    for(a = 0; a < row1; a++){
        for(b = 0; b < col2; b++){
            int sum = 0;
            for(i = 0; i < col1; i++){
                // mat[a][b] = *(*(mat + a) + b)
                // we are going to the a-th position of the row and taking its base address. then we go to the b-th position of that base address or the column.
                // then taking the value of that position.
                sum = sum + (*(*(mat1 + a) + i)) * (*(*(mat2 + i) + b));
            }
            printf("%d ", sum);
        }
        printf("\n");
    }



    for(i = 0; i < row1; i++){
        free(*(mat1 + i));
    }
    free(mat1);
    for(i = 0; i < row2; i++){
        free(*(mat2 + i));
    }
    free(mat2);
}