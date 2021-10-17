//https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number3051/1/?track=dsa-workshop-1-arrays&batchId=308
/*
Given an array arr[] of size N, find the smallest positive number missing from the array.

 

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing
number is 6.
 

Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
 

Your Task:
You don't need to read input or print anything. The task is to complete the function findMissing() which takes arr and N as input parameters and returns the smallest positive missing number.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Function to find missing integer in array
    // arr: input array
    // n: size of array
    int findMissing(int arr[], int n) { 
        
        // Your code here
        int i,curpos;
        for(i=0;i<n;i++)
        {
            curpos=arr[i]-1;
            while(arr[i]>=1 && arr[i]<=n && arr[curpos]!=arr[i])
            {
                swap(arr[i],arr[curpos]);
                curpos=arr[i]-1;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i+1!=arr[i])
            return i+1;
        }
        return n+1;
    }
};

// { Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        cout<<ob.findMissing(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends