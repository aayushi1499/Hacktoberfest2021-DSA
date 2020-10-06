#include<bits/stdc++.h>
using namespace std;
int temp,t;
int main(){
int arr[]={39,9,45,63,18,81,108,54,72,36};
int n=sizeof(arr)/sizeof(arr[0]);
for(int i=1;i<n;i++){
        t=i;

    for(int j=i-1;j>=0;j--){

        if(arr[t]<arr[j]){
            temp=arr[t];
            arr[t]=arr[j];
            arr[j]=temp;
            t--;

        }




    }
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
