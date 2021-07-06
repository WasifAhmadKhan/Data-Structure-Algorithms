#include <bits/stdc++.h>
using namespace std;

int buck[10000];

void solve(){
	int n,m;
	memset(buck,0,sizeof(buck));
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		buck[arr[i]]++;
	}
	m=*max_element(arr.begin(),arr.end());
	int j=0;
	for(int i=0;i<=m;i++){
		for(int k=0;k<buck[i];k++){
			arr[j]=i;
			j++;
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<"\n";
	
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
