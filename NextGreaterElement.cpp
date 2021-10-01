#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

void printNGE(vector<int>& nums) {
        stack<int> st;
        int i,n;
        n=nums.size();
        vector<int> result(n,-1);
        n=nums.size();
        // for(i=n-2;i>=0;i--)
        // {
        //     st.push(nums[i]);
        // }
        for(i=n-1;i>=0;i--)
        {
            
            while(st.empty()==false && st.top()<=nums[i])
            {
                st.pop();
            }
           
            if(st.empty()==true)
                result[i]=-1;
            else
                result[i]=st.top();
            st.push(nums[i]);
        }
        for(i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }

        // return result;
    }
 
int main()
{
    vector<int> arr = {11, 13, 21, 3};
    int n = arr.size();
    printNGE(arr);
    return 0;
}
