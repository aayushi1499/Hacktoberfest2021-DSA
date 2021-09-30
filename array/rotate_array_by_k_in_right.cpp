#include <bits/stdc++.h>
using namespace std;
 
 void reversed(vector<int>& a,int start,int end){
        while(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
         reverse(nums.begin(),nums.end());
        reversed(nums,0,k-1);
        reversed(nums,k,n-1);
        
    }
int main(){
    vector<int> v{1,2,3,4,5,6};
    int k;
    cin>>k;
    rotate(v,k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

