#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {

        stack<char> st; 
        for(auto i:s) 
        {
            if(i=='(')
                st.push('(');
            else
            {
                if(st.empty())return false;
                else st.pop();
            }


        }
        return st.empty();
}
int main()
{
    string s;
    cin>>s;
    cout<<isValid(s);


    // ((())) valid = true
    //())) valid = false

}
