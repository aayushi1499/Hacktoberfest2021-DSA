#include<bits/stdc++.h>
using namespace std;
class SortedStack{
public:
    stack<int> s;

        int n;
    void sort();
    };
void printStack(stack<int> s) //printStack function will display the elemnts of stack.
{
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    printf("\n");
}
int main(void){
int t; //variable declaration
cin>>t;
while(t--){
        SortedStack *ss = new SortedStack();
int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);

}
    return 0;
}
void SortedStack :: sort()

{
    stack<int> sc;
    while(!s.empty()){
        int temp= s.top();
        s.pop();
    while(!sc.empty() && sc.top()<temp){
        s.push(sc.top());
        sc.pop();
    }
    sc.push(temp);
    }

    while(!sc.empty()){
        int temp= sc.top();
        s.push(temp);
        sc.pop();
    }


}
