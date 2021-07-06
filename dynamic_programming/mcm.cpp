#include <bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
int mcm(vector<int> &a,int i,int j){
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int mn=INT_MAX;
	for(int k=i;k<j;k++){
		int temp=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
		mn=min(mn,temp);	
	}
	return dp[i][j]=mn;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<mcm(a,1,n-1)<<endl;
	
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
