#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> v;
        for(int i=0;i<n;i++){
            double x = (arr[i].value*1.0)/(arr[i].weight*1.0);
            v.push_back({x,i});
        }
        sort(v.begin(), v.end(), greater<pair<double,int>>()); //STL predefined 
        int s=0;
        double ans=0;
        for(int i=0;i<v.size();i++){
            if(s+ arr[v[i].second].weight< W){
                ans += arr[v[i].second].value;
                s += arr[v[i].second].weight;
            }else{
                double x=(W-s)*1.0;
                ans +=  (x*v[i].first);
                break;
            }
        }
        return ans;
    }
        
};



int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}