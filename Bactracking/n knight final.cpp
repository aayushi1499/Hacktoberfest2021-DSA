// C implementation of the approach
#include <bits/stdc++.h>
#include<time.h>
#define SIZE 500
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
using namespace std;
int board[SIZE][SIZE];
// Function to return the maximum number of
// knights that can be placed on the given
// chessboard such that no two
// knights attack each other
int max_knight(int m, int n)
{
    int i, j;
    // Check for corner case #1
    // If row or column is 1
    if (m == 1 || n == 1)
    {
        if( m > n)
            for( i=m; i>=0 ; i--) board[i][0]=1;
        else
            for( i=n; i>=0 ; i--) board[0][i]=1;
        // If yes, then simply print total blocks
        // which will be the max of row or column
        return max(m, n);
    }

    // Check for corner case #2
    // If row or column is 2
    else if (m == 2 || n == 2) {

        // If yes, then simply calculate
        // consecutive 2 rows or columns
        int c = 0;
        c = (max(m, n) / 4) * 4;
        //if c= 0 , only two consecutive blocks having knights

        if (max(m, n) % 4 == 1) {
            c += 2;
        }
        else if (max(m, n) % 4 > 1) {
            c += 4;
        }

         if( m > n)
             for( j=0; j<n; j++)
                for(i=0;i<m;i+=2)
                {
                    board[i++][j]=1;
                    board[i][j]=1;
                    i++;
                }
        else
            for( i=0; i<m; i++)
                for(j=0;j<n;j+=2)
                {
                    board[i][j++]=1;
                    board[i][j]=1;
                    j++;
                }

        return c;
    }

    // For general case, just print the
    // half of total blocks
    else
    {
        for(i = 0; i<m;i++)
        {
            j = (i%2 == 1)? 1:0;
            for(j; j<n; j+=2)
            {
                board[i][j] = 1;
            }
        }
        return (((m * n) + 1) / 2);
    }
}


int main()
{
    int n, m ;
    int r;
    printf("Enter the value of m and n\n");
    scanf("%d%d",&m,&n);

    r=max_knight(m, n);


    printf("Maximum number of knights that can be placed on a chessboard are %d\n",r);


    // Printing Chessboard

                for(int i = 0; i<m; i++)
                {
                    printf("\t");
                    for(int j = 0; j<n; j++)
                    {
                        if(board[i][j]==1) {
                            printf("K ");
                        }
                        else {
                            printf("_ ");
                        }
                    }
                    printf("\n");
                }

    return 0;
}
