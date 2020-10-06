#include <iostream>
#include <cstring>
#include<stdio.h>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int N;
int visited[10][10];
int counts=0;
int flag=0;
// N x N chessboard
//#define N 5

// Below arrays details all 8 possible movements for a knight.
// It is important to avoid changing sequence of below arrays
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2  };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}

// Recursive function to perform the Knight's tour using backtracking
void KnightTour(int x, int y, int pos)
{
	// mark current square as visited
	visited[x][y] = pos;

	// if all squares are visited, print the solution
	if (pos >= N*N)
	{   static int k=1;
        k++;
	    if(flag==0){

        //printf("%d-\n",k++);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << visited[i][j] << " ";
			cout << endl;
			flag++;
		}cout << endl;}

		counts=k;
		// backtrack before returning
		visited[x][y] = 0;
		return;
	}

	// check for all 8 possible movements for a knight
	// and recur for each valid movement
	for (int k = 0; k < 8; k++)
	{
		// Get the new position of Knight from current
		// position on chessboard
		int newX = x + row[k];//representing row
		int newY = y + col[k];//representing column

		// if new position is a valid and not visited yet
		if (isValid(newX, newY) && !visited[newX][newY])
			KnightTour(newX, newY, pos + 1);
	}

	// backtrack from current square and remove it from current path
	visited[x][y] = 0;
}

int main()
{    int x,y;
	// visited[][] serves two purpose -
	// 1. It keep track of squares involved the Knight's tour.
	// 2. It stores the order in which the squares are visited
	//int visited[N][N];
    printf("Enter the value of N for Knight-Tour Problem\n");
    scanf("%d",&N);
	// initialize visited[][] by 0 (unvisited)
	memset(visited, 0, sizeof visited); //memset returns visited,pointer to the destination string
	printf("\nEnter the x,y coordinates\n");
	scanf("%d%d",&x,&y);
	if(x>N || y>N){
        printf("Not a valid entry\n");}
    else{


	int pos = 1;

	// start knight tour from corner square (0, 0)
    clock_t start,end;
    start = clock();
	KnightTour(x, y, pos);
    end =clock();

    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC));

        cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
	if(counts>=1){
	printf("\nCount-%d",counts-1);}
	else{
        printf("\nSolution does not exist\n");
	}}

	return 0;
}

