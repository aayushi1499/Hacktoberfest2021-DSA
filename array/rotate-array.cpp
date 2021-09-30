#include<bits/stdc++.h>
using namespace std;

void Rotate(int arr[],int n){
         int temp = 0;
    temp = arr[n-1];
    for(int i=n-1;i>=0;i--){
        arr[i] =arr[i-1];
    }
    arr[0] = temp;
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];        
    }
    rotate(a, n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
