#include <bits/stdc++.h>
using namespace std;
int cycle_sum(vector<int> &v,vector<int> &visited,int start){
		int x,y,sum=0;
		if(visited[start])
			return -1;
		visited[start]=1;
		x=start;y=start;
		do{
			if(visited[v[x]]==2||v[x]==-1)
				return -1;
			else{
				x=v[x];
			}
			if(visited[v[y]]==2||v[y]==-1)
				return -1;
			else{
				y=v[y];
			}
				if(visited[v[y]]==2||v[y]==-1)
				return -1;
			else{
				y=v[y];
			}
		}while(x!=y);
		x=start;
		while(x!=y){
			x=v[y];
			y=v[y];
		}
		sum=x;
		int t=v[x];
		visited[x]=1;
		while(t!=x){
			visited[t]=2;
			sum+=t;
			t=v[t];
		}
		return sum;
	}
void solve(){
	int n,temp,ans=INT_MIN;	
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int max_node=*max_element(v.begin(),v.end());
	vector<int> visited(max_node+1,0);
	for(int i=0;i<n;i++){
		temp=cycle_sum(v,visited,i);
		ans=max(ans,temp);
	}
	cout<<ans<<endl;
	
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
