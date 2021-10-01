/*

Pictorial view of islands:
    
		_____________________
		| 1 | 1 | 0 | 1 | 0 |
		_____________________ 
		| 0 | 1 | 0 | 0 | 1 |
		_____________________ 
		| 1 | 0 | 1 | 1 | 0 |
		_____________________ 
		| 0 | 1 | 1 | 1 | 0 | 
		---------------------

You need to count all 1's (together or single) which signifies that it's an island, 0 means water
Note: Only top, down, left and right neighbours are considered in this program

		___________________________________________________
		|   |1|   |   |1|   |    0    |   <1>   |    0    |
		___________________________________________________
		|    0    |   |1|   |    0    |    0    |   /1\   |
		___________________________________________________
		|   [1]   |    0    |   {1}   |   {1}   |    0    |
		___________________________________________________
		|    0    |   {1}   |   {1}   |   {1}   |    0    | 
		---------------------------------------------------

    {}, <>, ||, /\, []  are just representation i'm using to show the different islands connected together
    
    Like in first row there are two 1's and in second row there's one 1 which together forms a island and is denoted by |1|
    Similarly, in 3rd row, there's only single island which is denoted by [1]
    
    Output: 5 islands
  
*/

#include<bits/stdc++.h>
using namespace std;
#define ln "\n";
#define TC() int t; cin >> t; while(t--)
#define IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

void dfs(int i, int j, int arr[4][5]){
	if(i < 0 || j < 0 || i == 4 || j == 5) return; // boundaries
	if(arr[i][j] == 0) return; //water

	arr[i][j] = 0; //visited

	dfs(i-1,j,arr); // top
	dfs(i,j-1,arr); // left
	dfs(i+1,j,arr); // bottom
	dfs(i,j+1,arr); // right
}

int main(){

	IO();
	int arr[4][5] = {
		{1,1,0,1,0},
		{0,1,0,0,1},
		{1,0,1,1,0},
		{0,1,1,1,0}
	};

	int islands = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			if(arr[i][j] == 1){
				islands++;
				dfs(i,j,arr);
			}
		}
	}
	cout << islands << endl;
	return 0;
}
