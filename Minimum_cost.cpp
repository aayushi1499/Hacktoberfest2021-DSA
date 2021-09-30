#include<bits/stdc++.h>
using namespace std;
int minimumCost (int n, int m, vector<vector<int> > teams){
	sort(teams.begin(),teams.end(),[&](const vector<int>& a,const vector<int>& b)-> bool{
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    });
    long long dp[m];
    for(int i=0;i<teams.size();i++){
        bool f=false;
        int g=teams[i][1]-teams[i][0]+1;
        long long h=1e13;
        dp[i]=-1;
        if(teams[i][0]==1){
            dp[i]=g;
            continue;
        }
        for(int j=i-1;j>=0;j--){
            if(teams[j][1]-teams[i][0]>=-1){
                if(dp[j]!=-1){
                    long long val=dp[j]+g;
                    h=min(val,h);
                    f=true;
                }
            }
            else{
                break;
            }
        }
        if(f){
            dp[i]=h;
        }
    }
    long long ans=1e13;
    for(int i=0;i<m;i++){
        if(teams[i][1]==n && dp[i]!=-1){
            ans=min(ans,dp[i]);
        }
    }
    if(ans==1e13){
        return -1;
    }
    return ans;
}

int main(){
	ios::sync_with_studio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int t_i=0;t_i<T;t_i++){
		int n;
		cin>>n;
		int m;
		cin>>m;
		 vector<vector<int> > teams(m,vector<int>(2));
		 for(int i_teams=0;i_teams<m;i_teams++){
		 	for(int j_teams=0;j_teams<2;j_teams++){
		 		cin>>teams[i_teams][j_teams];
			 }
		 }
		 int out_;
		 out_ = minimumCost(n,m,teams);
		 cout<<out_;
		 cout<<"\n";
	}
}
