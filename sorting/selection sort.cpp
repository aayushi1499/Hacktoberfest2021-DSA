#include<bits/stdc++.h>
using namespace std;
int selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++){
        int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }


    }
    int temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    }
}
int main(){
int arr[10],n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
selection_sort(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";

}
return 0;
}
