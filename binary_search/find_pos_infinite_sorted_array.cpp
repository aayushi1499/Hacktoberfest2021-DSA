#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int start,int end,int target)
{
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]>target)
        {
            end=mid+1;
        }
        else
        {
            start=mid-1;
        }
    }
   if(arr[mid]==target)
   {
       return mid;
   }
   else
   {
       return -1;
   }
}

int find_pos(int arr[],int n,int target)
{
    int start=0;
    int end=1;
    while(arr[end]<=target)
    {
        start=end+1;
        end=end*2+1;
    }
    int pos=binary_search(arr,start,end,target);
    cout<<pos;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int target;
    cin>>target;
    find_pos(arr,n,target);
  }
return 0;
}