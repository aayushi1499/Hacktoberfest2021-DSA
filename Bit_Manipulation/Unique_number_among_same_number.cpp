#include <bits/stdc++.h>




int main(void)
{

        ll n;
        cin>>n;
        ll temp;
        cin>>temp;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            cin>>temp;
            ans=ans^temp; // trying to take XOR of all elements then we'll have only a single element which is unique becox
                          //  xor of 2 same number's is 0 so duplicates will be cancelled out we'll have only one unique number left
        }
        cout<<ans<<en;

  return 0;

}
