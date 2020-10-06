#include<bits/stdc++.h>
using namespace std;
int compare(const void * a, const void * b)// 1st method

{
    cout<<*(int*)a<<endl;
    cout<<*(int*)b<<endl;
    cout<<"Subtraction:"<<( *(int*)a - *(int*)b )<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    return ( *(int*)a - *(int*)b );
}
/*int compare(const void * a, const void * b){ //2nd method
    const int * x = (int *)a;
    const int * y = (int *)b;
    if(*x>*y){
        return 1;
    } else if (*x < *y){
    return -1;}
    else{
        return 0;
    }
}*/
int main(){

    int t,arr[100000],n,k,ta[100][100],size[100000];
cin>>t;
int test_case=t;
int j=0;
while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    qsort(arr,n,sizeof(int),compare);


    for(int i=0;i<n;i++){
     ta[j][i]=arr[i];
     }
     size[j]=n;
     j++;





}

for(int k=0;k<j;k++){
for(int i=0;i<size[k];i++ ){
    cout<<ta[k][i]<<" ";

}    cout<<endl;}

return 0;}




