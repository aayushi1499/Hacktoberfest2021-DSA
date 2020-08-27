#include <iostream>
using namespace std;

int main() {
     int n,d;
        cin>>n>>d;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[(i+d)%n];
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
            
        }
        cout<<endl;

	//code
	return 0;
}
