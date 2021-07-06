#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,sum;
    cin>>n;
    vector<int> coin(n);
    for(int i=0;i<n;i++) cin>>coin[i];
    cin>>sum;
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++)dp[i][0]=1;
    for(int i=1;i<sum+1;i++) dp[0][i]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j)
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][sum]<<endl;
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

