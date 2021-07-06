#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> h(100001);

void dfs(int i,int j){
	h[i]=h[j]+1;
	for(int u=0;u<(int)adj[i].size();u++){
		if(adj[i][u]!=j){
			dfs(adj[i][u],i);
		}
	}
	
}

void solve(){
	int n,x,y,c=0;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		c+=h[i];
	cout<<c<<endl;
		
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
