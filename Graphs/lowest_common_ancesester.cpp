#include <bits/stdc++.h>
using namespace std;

int const MAX_N=10000;
int const LOG = 14;
vector<int> adj[MAX_N];
vector<vector<int>> up(MAX_N,vector<int>(LOG));
vector<int> depth(MAX_N);

void dfs(int a){
	for(int b : adj[a]){
		up[b][0]=a;
		depth[b]=depth[a]+1;
		for(int j=0;j<LOG;j++){
			up[b][j] = up[ up[b][j-1] ][j-1];
		}
		dfs(b);
	}
}
int get_lcs(int a,int b){
	if(depth[a]<depth[b]){
		swap(a,b);
	}
	int k=depth[a]-depth[b];
	for(int j=LOG-1;j>=0;j--){
		if(k&(1<<j)){
			a=up[a][j];
		}
	}
	if(a==b){
		return a;
	}
	for(int j=LOG-1;j>=0;j--){
		if(up[a][j]!=up[b][j]){
			a=up[a][j];
			b=up[b][j];
		}
	}
	return up[a][0];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q,l,r;
	cin>>n;
	for(int i=0;i<n;i++){
		int cnt;
		cin>>cnt;
		for(int j=0;j<cnt;j++){
			int c;
			cin>>c;
			adj[i].push_back(c);
		}
	}
	dfs(0);
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<get_lcs(l,r)<<endl;
	}
	return 0;
}
