#include <iostream>
#include <climits> 
using namespace std;


long long int maxpair(long long int arr[],int n){
long long int result=0;
for(int i = 0; i < n;i++){
    for(int j = i+1;j<n;j++){
        if(arr[i]*arr[j]>result){
           result = arr[i]*arr[j];
    }
}
}
return result;
}

long long int maxpairfast(long long int arr[],int n){
int i,j;
long long int first,second;
first = second = 0;  
	   
	for (i = 0; i < n; i++)
	{
		if(arr[i] > first)
		{
			second = first;
			first = arr[i];
		}
		else if(arr[i] > second && arr[i] < first)
		{
			second = arr[i];
		}	
	}

return((long long) (first*second));
}
int main()
{
    int n,i;
    long long int arr[100];
   cin >> n;
    for(i =0;i<n;i++){
        cin>>arr[i];
    }
    long long result = maxpairfast(arr,n);
    cout << result <<"\n";
    return 0;
}
