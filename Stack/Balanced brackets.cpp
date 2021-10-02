#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    string str;
    getline(cin,str);
    for(int i=0 ; i<str.length(); i++)
    {
        char ch=str[i];
        if(ch == ')')
        {
            if(st.top()== '(')
            {
                cout<<true;
                return 0;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }

    cout<<false;
}