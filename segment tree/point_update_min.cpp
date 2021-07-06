#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

int query(int root,int root_low,int root_high,int low,int high){
	if(low<=root_low&&root_high<=high){
		return tree[root];
	}
	else if(low>root_high||high<root_low){
		return INT_MAX;
	}
	int mid=(root_low+root_high)/2;
	return min(query(root*2,root_low,mid,low,high),query(root*2+1,mid+1,root_high,low,high));
}
void update(int root,int root_low,int root_high,int low,int high,int val){
	if(low<=root_low&&root_high<=high){
		tree[root]=val;
		return;
	}
	else if(low>root_high||high<root_low){
		return;
	}
	int mid=(root_low+root_high)/2;
	update(root*2,root_low,mid,low,high,val);
	update(root*2+1,mid+1,root_high,low,high,val);
	tree[root]=min(tree[root*2],tree[root*2+1]);
}
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	while(__builtin_popcount(n)!=1){
		arr.push_back(0);
		n++;
	}
	tree.resize(2*n);
	for(int i=0;i<n;i++){
		tree[n+i]=arr[i];
	}
	for(int i=n-1;i>=1;i--){
		tree[i]=min(tree[2*i],tree[2*i+1]);
	}
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int i,u;
			cin>>i>>u;
			i--;
			update(1,0,n-1,i,i,u);
		}
		else{
			int low,high;
			cin>>low>>high;
			low--;high--;
			cout<<query(1,0,n-1,low,high)<<"\n";
		}
	}
	
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
