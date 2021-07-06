#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<bool> visited(100001,false);

void dfs(int s){
	if(visited[s]) return;
	visited[s]=true;
	for(int i=0;i<(int)adj[s].size();i++)
		dfs(adj[s][i]);
}

void solve(){
	int n,m,x,y,c=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin>>x;
	dfs(x);
	for(int i=1;i<=n;i++)
		if(!visited[i])
			c++;
	cout<<c<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
