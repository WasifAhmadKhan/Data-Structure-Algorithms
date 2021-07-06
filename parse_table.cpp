#include <bits/stdc++.h>
using namespace std;
int const MAX_N = 200005;
int const LOG = 18;
int arr[MAX_N];
int m[MAX_N][LOG];
int bin_log[MAX_N];

int query(int L, int R){
	int len =R-L+1;
	int k=bin_log[len];
	return min(m[L][k],m[R-(1<<k)+1][k]);
	
}

void solve(){
	int n,q;
	cin>>n>>q;
	bin_log[1]=0;
	for(int i=2;i<=n;i++){
		bin_log[i]=bin_log[i/2]+1;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
		m[i][0]=arr[i];
	}
	for(int k=1;k<LOG;k++){
		for(int i=0;i+(1<<k)-1<n;i++){
			m[i][k]=min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;r--;
		cout<<query(l,r)<<endl;
	}	
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
