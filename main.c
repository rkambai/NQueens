#include <stdio.h>
#include <stdlib.h>

int nQueens(int** board, int N, int col);
int isSafe(int** board,int N, int row, int col);
void printSolution(int** board, int N);
void removeLast(int** board, int BSize, int col);

int main()
{
    int **board;
    int BSize;

    int i,j;

    printf("Enter the size of chessBoard:\n");
    scanf("%d",&BSize);

    board = (int **)malloc(BSize*sizeof(int *));
    for(i=0;i<BSize;i++)
        board[i] = (int *)malloc(BSize*sizeof(int));

    for(i=0;i<BSize;i++)
       for(j=0;j<BSize;j++)
           board[i][j] = 0;

    printf("solutions %d ", nQueens(board, BSize, 0));

    return 0;
}

int nQueens(int** board, int BSize, int col)
{
 //Write your code here
 //Safe Place checking is provide below, you are free to use it.
    int row = 0;
    int res = 0;
    for (row = 0;row<BSize;row++)
    {
        if(isSafe(board,BSize,row,col) == 1)
        {
            board[row][col] = 1;

            if (col == BSize-1)
            {
                removeLast(board, BSize, col);
                removeLast(board, BSize, col-1);
                return res+1;
            }

            res += nQueens(board, BSize, col+1);

        }

    }
    removeLast(board, BSize, col);
    if (col > 0)
        removeLast(board, BSize, col-1);
    return res;

}

void removeLast(int** board, int BSize, int col)
{
    int i = 0;
    for (i=BSize-1; i>-1;i--)
    {
        if (board[i][col] == 1)
        {
            board[i][col] = 0;
        }
    }
}
//Safe checking
int isSafe(int** board,int BSize, int row, int col)
{
    int i, j;

    // Horicatal check
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Upper left diagonal check
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Lower left diagonal check
    for (i = row, j = col; j >= 0 && i < BSize; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void printSolution(int** board, int BSize)
{
    int i,j;
    for (i = 0; i < BSize; i++) {
        for (j = 0; j < BSize; j++){
            if(board[i][j]==1)
                printf(" Q ");
            else
                printf(" + ");
        }
        printf("\n");
    }
    printf("\n");
}
