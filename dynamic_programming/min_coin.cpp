#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,sum;
    cin>>n;
    vector<int> coin(n);
    for(int i=0;i<n;i++)cin>>coin[i];
    cin>>sum;
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<sum+1;i++) dp[0][i]=INT_MAX;
    for(int i=1;i<n+1;i++) dp[i][0]=0;
    for(int i=1;i<sum+1;i++){
        if(i%coin[0]==0)
            dp[1][i]=i/coin[0];
        else
            dp[1][i]=INT_MAX;
    }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j)
                dp[i][j]=min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][sum]<<endl;
    for(int i=0;i<n+1;i++){
         for(int j=0;j<sum+1;j++)
             cout<<dp[i][j]<<" ";
         cout<<endl;
     }

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
