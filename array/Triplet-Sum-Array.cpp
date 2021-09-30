#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool find3Numbers(int A[], int n, int X)
        {
            sort(A, A + n);
            for(int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while(j < k)
            if(A[i] + A[j] + A[k] == X)
            return true;
            else if(A[i] + A[j] + A[k] < X)
            j++;
            else k--;
            }
            return false;
        }
}asy;
int main(void)
{
    int n,x;
    cin>>n>>x;
    int arr[x];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<asy.find3Numbers(arr,n,x);

}