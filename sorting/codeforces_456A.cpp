#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i = 0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(), arr.end());
    int i = n-2;
    bool flag = 0;
    while(i >= 0){
        if(arr[i].second > arr[i+1].second){
            flag = 1;
            break;
        }
        i--;
    }
    if(flag) cout<<"Happy Alex"<<endl;
    else cout<<"Poor Alex"<<endl;
}


// this is the solution for problem 456A on codeforces
// problem : https://codeforces.com/problemset/problem/456/A
// Contributor : priyanshukaushal
