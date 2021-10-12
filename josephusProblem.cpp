#include "bits/stdc++.h"
using namespace std;
int josephus(int n,int k){
	if (n==0) return 0;
	return (josephus(n-1,k)+k)%n;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}
