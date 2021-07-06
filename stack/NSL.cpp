#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<int> ans;
	stack<int> s;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		if(s.empty()){
			ans.push_back(-1);
		}
		else if(s.top()<arr[i]){
			ans.push_back(s.top());
		}
		else{
			while(!s.empty()&&s.top()>=arr[i]) s.pop();
			if(s.empty()){
				ans.push_back(-1);
			}
			else if(s.top()<arr[i]){
				ans.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
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
