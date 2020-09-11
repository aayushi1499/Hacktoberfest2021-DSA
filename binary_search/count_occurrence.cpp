#include<bits/stdc++.h> 
using namespace std; 
int main()
{
	int arr[]={10,2,6,8,6,0};
	int n,count=0;
	cin>>n;
	int m = sizeof(arr) / sizeof(arr[0]);
    // cout<<m<<endl;
	for(int i=0;i<m;i++){
		if(n == arr[i])
			count++;
	}
	cout<<count;
	return 0;
}
