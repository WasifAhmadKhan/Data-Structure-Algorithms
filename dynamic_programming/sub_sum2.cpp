#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,sum,msum=0;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){ cin>>v[i]; msum+=v[i];}
	cin>>sum;
	vector<bool> dp(msum+1);
	dp[0]=true;
	for(int x : v){
		for(int i=msum-x;i>=0;i--)
			if(dp[i]) dp[i+x]=true;
	}
	if(dp[sum]) cout<<"true\n";
	else cout<<"false\n";
	
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
