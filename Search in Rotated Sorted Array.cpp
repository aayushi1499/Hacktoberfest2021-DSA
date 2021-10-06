#include<iostream>

int findPivot(vector<int> A)
{
    int s=0,e=A.size()-1,last=A[e];
    while(s <= e)
    {
        int mid=s+(e-s)/2;
        if(A[mid] > last)
            s=mid+1;
        else if (A[mid] <= last)
        {
            if(mid == 0 || A[mid-1] >= last)
                return mid;
            else
                e=mid-1;
        }
    }
    return -1;
}

int search(vector<int>& A, int x) 
{
    int last = A[A.size()-1];
    int pivot = findPivot(A);
    cout<<pivot;
    vector<int>::iterator it;
    if(x <= last) {
        it = lower_bound(A.begin()+pivot, A.end(), x);
    }
    else {
        it = lower_bound(A.begin(), A.begin()+pivot-1,x);
    }
    
    if(*it == x) return it - A.begin();
    return -1;
}
int main()
{
    vector<int>A{4,5,6,7,0,1,2};
    cout<<search(A,0);
}
