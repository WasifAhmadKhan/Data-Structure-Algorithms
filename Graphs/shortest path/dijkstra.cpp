#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,x,y,w;
	cin>>n>>m;
	vector<pair<int,int>> adj[n+1];
	vector<int> distance(n+1,INT_MAX);
	vector<bool> visited(n+1,false);
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
	}
	priority_queue<pair<int,int>> q;
	distance[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int s=q.top().second;q.pop();
		if(visited[s]) continue;
		visited[s]=true;
		for(auto u: adj[s]){
			y=u.first;w=u.second;
			distance[y]=min(distance[y],distance[s]+w);
			q.push({-distance[y],y});
		}
	}
	for(int i=2;i<=n;i++)
		cout<<distance[i]<<" ";
	cout<<endl;
		
	
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
		solve();
	
	return 0;
}
