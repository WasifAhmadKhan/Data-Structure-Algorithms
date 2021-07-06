#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,sum=0,mn=INT_MAX;
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++){
         cin>>s[i];
         sum+=s[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<n+1;i++)dp[i][0]=true;
    for(int i=1;i<sum+1;i++)dp[0][i]=false;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(s[i-1]<=j)
                dp[i][j]=dp[i-1][j-s[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<(sum+1)/2;i++)
        if(dp[n][i])
            mn=min(mn,sum-2*i);
    cout<<mn<<endl;
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
