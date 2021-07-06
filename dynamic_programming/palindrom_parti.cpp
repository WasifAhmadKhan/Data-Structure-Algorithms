#include <bits/stdc++.h>
using namespace std;
static int dp[1001][1001];

bool ispalind(string s, int i,int j){
	if(i==j)
		return true;
	if(i>j)
		return true;
	while(i<j){
		if(s[i]!=s[j])
			return false;
		else{
			j--;
			i++;
		}
	}
	return true;
}

int palin(string s,int i,int j){
	if(i>=j)
		return 0;
	if(ispalind(s,i,j))
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int ans=INT_MAX;
	for(int k=i;k<j;k++){
		if(ispalind(s,i,k)){
			int temp ,right;
			if(dp[k+1][j]!=-1)
				right=dp[k+1][j];
			else{
				right=palin(s,k+1,j);
				dp[k+1][j]=right;
			}
			temp=right+1;
			ans=min(ans,temp);
		}
	}
	return dp[i][j]=ans;				
}



void solve(){
	memset(dp,-1,sizeof(dp));
	string s;
	cin>>s;
	cout<<palin(s,0,s.length()-1)<<endl;
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
