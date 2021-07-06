#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,t,c,x,y;
	cin>>n>>m>>t>>c;
	vector<int> adj[1000];
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin>>x>>y;
	for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
	vector<bool> visited(n+1);
	vector<int> path(n+1);
	queue<int> q;
	path[x]=0;
	bool ans=false;
	visited[x]=true;
	q.push(x);
	while(!q.empty()){
		if(ans) break;
		int s=q.front();q.pop();
		for(int i=0;i<(int)adj[s].size();i++){
			if(visited[adj[s][i]]) continue;
			visited[adj[s][i]]=true;
			path[adj[s][i]]=s;
			if(adj[s][i]==y){
				ans=true;
				break;
			}
			q.push(adj[s][i]);
		}
	}
	vector<int> temp;
	while(path[y]!=0){
		temp.push_back(y);
		y=path[y];
	}
	temp.push_back(x);
	cout<<(int)temp.size()<<endl;
	for(int i=(int)temp.size()-1;i>=0;i--)
		cout<<temp[i]<<" ";
	cout<<endl;
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
