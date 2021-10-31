// KADANE's Algorithm to find the max sum of subarray
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n], sum=0,mx=INT_MIN;
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++){
        if(sum < 0) sum=0;
        sum += arr[i];
        mx = max(mx, sum);
    }
    cout << mx << endl;
    return 0;
}