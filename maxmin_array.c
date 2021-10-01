#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,arr[5000],i,q;
    printf ("Enter the number of elements\n");
    scanf ("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    printf ("The array after using random function is \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    q=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]>q)
        {
            q=arr[i];
        }
    }
    printf ("The max number is %d\n",q);
    q=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]<q)
        {
            q=arr[i];
        }
    }
    printf ("The min number is %d\n",q);
    return 0;
}
