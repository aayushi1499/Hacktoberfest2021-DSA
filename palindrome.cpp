#include<iostream>
using namespace std;
int main(){
	int n,r,sum=0,flag;
	cout << "enter the number";
	cin >> n;
	flag = n;
	while(flag>0){
		r = flag%10;
		sum = sum*10 + r;
		flag = flag/10;
	}
	
	if(sum==flag){
		cout << "yes it is plaindrome";
	}
	else{
	
	cout <<"no";
}
	return 0;
}
