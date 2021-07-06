#include <bits/stdc++.h>
using namespace std;

void solve(){
	int m,n;
	string a,b,s;
	cin>>a>>b;
	m=a.length();
	n=b.length();
	vector<vector<int>> dp(m+1,vector<int>(n+1));
	for(int i=0;i<m+1;i++)dp[i][0]=0;
	for(int i=0;i<n+1;i++)dp[0][i]=0;
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(a[i-1]==b[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int i=m,j=n;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]){
			s.push_back(a[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i][j-1]>dp[i-1][j])
			j--;
			else
			i--;
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
				
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
