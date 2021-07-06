#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;
vector<long long> lazy;

void update(int root,int root_low,int root_high,int low,int high,int val){
	if(lazy[root]!=0){
		tree[root]+=(root_high-root_low+1)*lazy[root];
		if(root_low!=root_high){
			lazy[2*root]+=lazy[root];
			lazy[2*root+1]+=lazy[root];
		}
		lazy[root]=0;
	}
	if(root_high<low||root_low>high) return;
	if(root_low>=low&&root_high<=high){
		tree[root]+=(root_high-root_low+1)*val;
		if(root_low!=root_high){
			lazy[2*root]+=val;
			lazy[2*root+1]+=val;
		}
		return;
	}
	int mid=(root_low+root_high)/2;
	update(root*2,root_low,mid,low,high,val);
	update(root*2+1,mid+1,root_high,low,high,val);
}
long long query(int root,int root_low,int root_high,int low,int high){
	if(lazy[root]!=0){
		tree[root]+=(root_high-root_low+1)*lazy[root];
		if(root_low!=root_high){
			lazy[2*root]+=lazy[root];
			lazy[2*root+1]+=lazy[root];
		}
		lazy[root]=0;
	}
	if(root_high<low||root_low>high) return 0;
	if(root_low>=low&&root_high<=high){
		return tree[root];
	}
	int mid=(root_low+root_high)/2;
	return query(root*2,root_low,mid,low,high)+query(root*2+1,mid+1,root_high,low,high);
	
}

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	while(__builtin_popcount(n)!=1){
		n++;
	}
	tree.resize(2*n);
	lazy.resize(2*n);
	for(int i=0;i<(int)arr.size();i++){
		tree[n+i]=arr[i];
	}
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int l,r,u;
			cin>>l>>r>>u;
			l--;r--;
			update(1,0,n-1,l,r,u);
		}
		else{
			int k;
			cin>>k;
			k--;
			cout<<query(1,0,n-1,k,k)<<"\n";
		}
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
