#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,count=0,ans=0;
	cin>>n>>m;
	vector<int> arr(n);
	vector<int> hash(m+1,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		hash[arr[i]]++;
	}
	for(int i=0;i<=m;i++){
		ans+=hash[i]/3;
		if(hash[i]!=0) count++;
		else{
			if(count>=3)
				ans+=(count-3+1);
			count=0;
		}
	}
	if(count>=3)
		ans+=(count-3+1);
	cout<<ans<<"\n";
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
