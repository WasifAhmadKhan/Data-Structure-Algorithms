#include <bits/stdc++.h>
using namespace std;

void merge_arr(vector<int> &arr1,vector<int> &arr2,int last,bool isempty){
	if(isempty==true&&arr2.size()==0)
		return;
	if(isempty==true){
		while(arr2.size()!=0){
			arr1.push_back(arr2[0]);
			arr2.erase(arr2.begin()+0);
		}
		return;
	}
	if(arr2.size()==0){
		int temp=arr1[0];
		while(temp!=last){
			arr1.push_back(arr1[0]);
			arr1.erase(arr1.begin()+0);
			temp=arr1[0];
		}	
		arr1.push_back(arr1[0]);
		arr1.erase(arr1.begin()+0);
		return;
	}
	if(arr1[0]<=arr2[0]){
		if(arr1[0]==last){
			arr1.push_back(arr1[0]);
			arr1.erase(arr1.begin()+0);
			merge_arr(arr1,arr2,last,true);
		}
		else{
			arr1.push_back(arr1[0]);
			arr1.erase(arr1.begin()+0);
			merge_arr(arr1,arr2,last,false);
		}
	}
	else{
		arr1.push_back(arr2[0]);
		arr2.erase(arr2.begin()+0);
		merge_arr(arr1,arr2,last,false);
	}
	return;
}


void solve(){
	int n,m,last;
	cin>>n>>m;
	vector<int> arr1(n);
	vector<int> arr2(m);
	for(int i=0;i<n;i++) cin>>arr1[i];
	for(int i=0;i<m;i++) cin>>arr2[i];
	last = arr1[n-1];
	merge_arr(arr1,arr2,last,false);
	for(int i=0;i<n+m;i++) cout<<arr1[i]<<" ";
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
