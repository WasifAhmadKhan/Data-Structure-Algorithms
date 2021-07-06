#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> dp;
int eval_exp(string s,int i,int j,bool istrue){
	if(i>j)
		return 0;
	if(i==j){
		if(istrue==true)
			return s[i]=='T';
		else
			return s[i]=='F';
	}
	string key=to_string(i);
	key.append(" ");
	key.append(to_string(j));
	key.append(" ");
	key.append(to_string(istrue));
	if(dp.find(key)!=dp.end())
		return dp[key];
	int ans=0;
	for(int k=i+1;k<=j;k+=2){
		int lt=eval_exp(s,i,k-1,true);
		int lf=eval_exp(s,i,k-1,false);
		int rt=eval_exp(s,k+1,j,true);
		int rf=eval_exp(s,k+1,j,false);
		
		if(s[k]=='&'){
			if(istrue)
				ans+=lt*rt;
			else
				ans+=lt*rf+rt*lf+rf*lf;
		}
		if(s[k]=='|'){
			if(istrue)
				ans+=rt*lt+rt*lf+rf*lt;
			else
				ans+=rf*lf;
		}
		if(s[k]=='^'){
			if(istrue)
				ans+=rt*lf+rf*lt;
			else
				ans+=rt*lt+lf*rf;
		}
	}
	return dp[key]=ans;
}
		
void solve(){
	dp.clear();
	string x;
	cin>>x;
	int n=x.length();
	cout<<eval_exp(x,0,n-1,true)<<endl;	
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
