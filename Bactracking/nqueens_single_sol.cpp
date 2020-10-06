#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int N;
int board[100][100];
int counts=0;
int flag=0;



/* A utility function to print solution */
void printSolution()
{
    static int k = 1;
    counts=k++;

    if(flag==0){
            printf("%d-\n",counts);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
        if(board[i][j]==1){
                printf("Q ");

        }else{
            printf("x ");

        }}
            //printf(" %d ", board[i][j]);
        printf("\n");
        flag++;
    }}
    else{
        return;
    }
    printf("\n");


}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isattack(int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* A recursive utility function to solve N
Queen problem */


bool nqueen(int n,int col)
{
    /* base case: If all queens are placed
    then return true */
    if (col == N)
    {
        printSolution();
        return true;
    }

    /* Consider this column and try placing
    this queen in all rows one by one */
    bool res = false;
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */

        if ( isattack(i, col) )
        {
            /* Place this queen in board[i][col] */
            //printf("\nboard[%d][%d]",i,col);
            board[i][col] = 1;


            // Make result true if any placement
            // is possible
            res = nqueen(n, col + 1) || res;

            /* If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] */
            //printf("\nThe board emptied is board[%d][%d]",i,col);
            board[i][col] = 0; // BACKTRACK
        }
    }

    /* If queen can not be place in any row in
        this column col then return false */
    return res;
}


/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
void solveNQ()
{
    int i,j;
    //memset(board, 0, sizeof(board));
    printf("Enter the value of N for NXN chessboard:");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }
    clock_t start,end;
    start = clock();
    if (nqueen(N,0) == false)
    {
        printf("Solution does not exist");
        return ;
    }

    end =clock();

    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC));

    printf("Time taken by program is: %lf",time_taken,setprecision(5));

        //cout << "Time taken by program is : " << fixed
         //<< time_taken << setprecision(5);

    return ;

}


// driver program to test above function
int main()
{

    solveNQ();
    printf("\nCount-%d",counts);

    return 0;

}
