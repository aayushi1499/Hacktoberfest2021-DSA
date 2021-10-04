#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

// returns the minimum path sum in a grid
int minPathSum(vector<vector<int>>& grid) {
	int inf = INT_MAX;
	int n = grid.size(), m = grid[0].size();
	int dp[n][m + 2];
	for (int i = 0; i < n; i++) {
		dp[i][0] = inf;
		dp[i][m + 1] = inf;
	}
	dp[n - 1][m] = grid[n - 1][m - 1];

	for (int j = m - 1; j > 0; j--)
		dp[n - 1][j] = grid[n - 1][j - 1] + dp[n - 1][j + 1];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = m; j > 0; j--) {
			dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j - 1];
		}
	}
	return dp[0][1];
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>> grid = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};
	int ans = minPathSum(grid);
	cout << "Min path sum of the given grid is: " << ans << "\n";

	return 0;
}
