#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,max_node;	
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	max_node=*max_element(v.begin(),v.end());
	vector<int> sum_node(max_node+1,0);
	for(int i=0;i<n;i++){
		if(v[i]!=-1){
			sum_node[v[i]]+=i;
		}
	}
	auto it=max_element(sum_node.begin(),sum_node.end());
	int index=it-sum_node.begin();
	cout<<index<<endl;
	
	
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
