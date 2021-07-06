#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,x,y,w;
	cin>>n>>m;
	vector<tuple<int,int,int>> edges;
	vector<int> distance(n+1,INT_MAX);
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		edges.push_back({x,y,w});
	}
	distance[1]=0;
	for(int i=1;i<n-1;i++){
		for(auto e: edges){
			tie(x,y,w)=e;
			distance[y]=min(distance[y],distance[x]+w);
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
