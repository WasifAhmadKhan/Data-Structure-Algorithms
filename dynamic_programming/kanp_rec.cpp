#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
/*
int knap(vector<int> &wt,vector<int> &value,int w,int n){
    static vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    if(w==0||n==0)
        return 0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n-1]<=w)
        return dp[n][w]= min(value[n-1]+knap(wt,value,w-wt[n-1],n-1),knap(wt,value,w,n-1));                
    else
        return dp[n][w]=knap(wt,value,w,n-1);
}
*/
void solve(){
    int n,w,max_prof;
    cin>>n;
    vector<int> wt(n),value(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>value[i];
    cin>>w;
   // max_prof=knap(wt,value,w,n);
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    for(int i=0;i<w+1;i++)dp[0][i]=INF;
    for(int i=1;i<n+1;i++)dp[i][0]=0;
    for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                    if(wt[i-1]<=j)
                        dp[i][j]=min(value[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                    else
                        dp[i][j]=dp[i-1][j];
            }
    }
    cout<<dp[n][w]<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++)
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

