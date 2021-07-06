#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m,n;
    string x,y;
    cin>>x>>y;
    m=x.length();
    n=y.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<m+1;i++) dp[i][0]=0;
    for(int i=0;i<n+1;i++) dp[0][i]=0;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
    cout<<dp[m][n]<<endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

