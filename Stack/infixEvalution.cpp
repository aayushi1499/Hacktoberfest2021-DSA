#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int precedence(char op) {
	if (op == '+')
		return 1;
	if (op == '-')
		return 1;
	if (op == '*')
		return 2;
	if (op == '/')
		return 2;

	return -1;
}

int operation(int v1, int v2, char op) {
	if (op == '+')
		return v1 + v2;
	if (op == '-')
		return v1 - v2;
	if (op == '*')
		return v1 * v2;
	if (op == '/')
		return v1 / v2;

	return -1;
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	getline(cin, s);

	vector<int> stackInt;
	vector<int> stackOp;
	int n = s.size();


	for (int i = 0; i < n; i++) {

		if (s[i] == ' ') {
			continue;
		}

		if (s[i] == '(') {
			stackOp.push_back('(');
		} else if (s[i] == ')') {
			while (stackOp.back() != '(') {
				char ch = stackOp.back();
				stackOp.pop_back();
				int v2 = stackInt.back();
				stackInt.pop_back();
				int v1 = stackInt.back();
				stackInt.pop_back();

				int val = operation(v1, v2, ch);
				stackInt.push_back(val);

			}
			stackOp.pop_back();
		} else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			while (!stackOp.empty() and (stackOp.back() != '(') and precedence(stackOp.back()) >= precedence(s[i])) {
				char ch = stackOp.back();
				stackOp.pop_back();
				int v2 = stackInt.back();
				stackInt.pop_back();
				int v1 = stackInt.back();
				stackInt.pop_back();

				int val = operation(v1, v2, ch);
				stackInt.push_back(val);


			}
			stackOp.push_back(s[i]);

		} else {
			stackInt.push_back(s[i] - '0');
		}
	}

	while (!stackOp.empty()) {
		char ch = stackOp.back();
		stackOp.pop_back();
		int v2 = stackInt.back();
		stackInt.pop_back();
		int v1 = stackInt.back();
		stackInt.pop_back();

		int val = operation(v1, v2, ch);
		stackInt.push_back(val);
		//cout<<val<<"\n";
	}

	cout << stackInt.back() << "\n";
}

int32_t main()
{
	clock_t begin = clock();
	c_p_c();
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}