#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int arr[5000];

int findmax(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int findmin(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
void rmaxmin(int n,int m,int *max,int *min)
{
    int mid,gmax,gmin,hmax,hmin;
    if(n==m)
    {
        *max=arr[n];
        *min=arr[n];
    }
    else if(n==(m-1))
    {
        if(arr[n]<arr[m])
        {
            *max=arr[m];
            *min=arr[n];
        }
        else
        {
            *max=arr[n];
            *min=arr[m];
        }
    }
    else
    {
    mid=(n+m)/2;
    rmaxmin(n,mid,&gmax,&gmin);
    rmaxmin(mid+1,m,&hmax,&hmin);
    *max=findmax(gmax,hmax);
    *min=findmin(gmin,hmin);
    }

}

int main()
{

int max,min,n,m;
    int q,i,j;
    printf("Enter the number if elements\n");
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        arr[i]=rand();
    }
    printf("Array stored due to random functions\n");
    for(i=0;i<q;i++)
    {
        printf("%d\n",arr[i]);
    }
    rmaxmin(0,q-1,&max,&min);
    printf ("the max element in the given array is %d\n",max);
    printf ("the min element in the given array is %d\n",min);
}
