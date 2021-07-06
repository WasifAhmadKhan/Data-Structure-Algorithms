#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> dp;
bool scramble(string a,string b){
	if(a.compare(b)==0)
		return true;
	if(a.length()<=1)
		return false;
	string key=a;
	key.append(" ");
	key.append(b);
	if(dp.find(key)!=dp.end())
		return dp[key];
	int n=a.length();
	bool ans=false;
	for(int i=1;i<n;i++){
		bool cond1=scramble(a.substr(0,i),b.substr(n-i,i))&&scramble(a.substr(i,n-i),b.substr(0,n-i));
		bool cond2=scramble(a.substr(0,i),b.substr(0,i))&&scramble(a.substr(i,n-i),b.substr(i,n-i));
		if(cond1||cond2){
			ans = true;
			break;
		}
	}
	return dp[key]=ans;
	
}

void solve(){
	dp.clear();
	string x,y;
	cin>>x>>y;
	if(x.length()!=y.length())
		cout<<false<<endl;
	if(x.empty()&&y.empty())
		cout<<true<<endl;
	else
		cout<<scramble(x,y)<<endl;
	
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
