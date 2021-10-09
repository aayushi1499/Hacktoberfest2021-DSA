#include<stdio.h>
int main()
{
    int t,n,i,a[1000],j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                printf("%d",k);
            }
            else if(k/2 != 0)
            {
                printf("%d",k+2);
            }
        }
    }
    return 0;
}