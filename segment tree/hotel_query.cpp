#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

void update(int root,int root_low,int root_high,int low,int high,int val){
	if(root_low>=low&&root_high<=high){
		tree[root]-=val;
		return;
	}
	if(root_high<low||root_low>high) return;
	int mid=(root_low+root_high)/2;
	update(root*2,root_low,mid,low,high,val);
	update(root*2+1,mid+1,root_high,low,high,val);
	tree[root]=max(tree[2*root],tree[2*root+1]);
}
int query(int root,int root_low,int root_high,int val){
	if(tree[root]<val){
		return 0;
	}
	if(root_low==root_high){
		return root;
	}
	if(tree[root*2]>=val){
		int mid=(root_low+root_high)/2;
		return query(root*2,root_low,mid,val);
	}
	if(tree[root*2+1]>=val){
		int mid=(root_low+root_high)/2;
		return query(root*2+1,mid+1,root_high,val);
	}
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> h(n);
	vector<int> r(m);
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<m;i++) cin>>r[i];
	while(__builtin_popcount(n)!=1){
		n++;
	}
	tree.resize(2*n);
	for(int i=0;i<(int)h.size();i++){
		tree[n+i]=h[i];
	}
	for(int i=n-1;i>=1;i--){
		tree[i]=max(tree[2*i],tree[2*i+1]);
	}
	for(int i=0;i<m;i++){
		int t;
		t=query(1,0,n-1,r[i]);
		if(t==0){
			cout<<0<<" ";
			continue;
		}
		cout<<t-n+1<<" ";
		update(1,0,n-1,t-n,t-n,r[i]);
	}	
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
