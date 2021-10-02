#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(((a+b)<=d && (c<=e))||(b+c)<=d && (a<=e)||(a+c)<=d && (b<=e))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    }
	return 0;
}
