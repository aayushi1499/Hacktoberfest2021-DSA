#include <bits/stdc++.h>

using namespace std;
int main()
{

	unordered_set<int> s;

	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.insert(9);
	unordered_set<int>::iterator it;

	cout << s.size();
	if (s.find(3) == s.end())
	{
		cout << "Not found";
	}
	else
	{
		cout << "found";
	}
}