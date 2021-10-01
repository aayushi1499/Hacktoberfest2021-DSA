#include <bits/stdc++.h>

using namespace std;


int main(void)
{

        int n;
        cin>>n;
        // now checking a number is even or not 
        // basically trying to check last digit 



        // let's take an example n=5
        // in binary we represent it as 00101
        // and we are doing xor of 00101 ^ 00001
        // it means we are doing xor of last value of n with 1 
        //becoz every number is odd if it has 1 at last of it's binary form
        // so if it's true thanit's odd else even 




        if(n&1)
        {
            cout<<"ODD\n";
            return 0;
        }
        cout<<"Even\n";


  return 0;

}
