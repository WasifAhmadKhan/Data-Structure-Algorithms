#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,x,y;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<bool> visited(m+1);
	vector<int> distance(n+1);
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int> q;
	visited[1]=true;
	distance[1]=0;
	q.push(1);
	while(!q.empty()){
		int s=q.front();q.pop();
		for(int i=0;i<(int)adj[s].size();i++){
			if(visited[adj[s][i]]) continue;
			visited[adj[s][i]]=true;
			distance[adj[s][i]]=1+distance[s];
			q.push(adj[s][i]);
		}
	}
	cout<<distance[n]<<endl;
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
