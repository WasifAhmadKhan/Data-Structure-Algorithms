#include <bits/stdc++.h>
using namespace std;

int bs_floor(vector<int> &arr,int start,int end,int e){
	int mid,res=-1;
	while(start<=end){
		mid=(start+end)/2;
	if(arr[mid]==e)
		return mid;
	else if(arr[mid]<e)
		start=mid+1;
	else if(arr[mid]>e){
		res=mid;
		end=mid-1;
	}
}
return res;
	
}

void solve(){
	int n,m,left,right,t,p1,p2,p3,temp;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	if((m+n)%2==0)
		t=2;
	else
		t=1;
	p1=0;p2=(m+n)-1;
	while(p1<=p2){
		p3=(p1+p2)/2;
		//cout<<p1<<" "<<p2<<endl;
		if(p3<n){
			temp=a[p3];
			int lt=bs_floor(b,0,m-1,a[p3]);
			if(lt==-1)
				left=p3+m;
			else
				left=p3+lt;
			right=(m+n)-left-1;
		}
		else{
			temp=b[p3-n];
				int lt=bs_floor(a,0,n-1,b[p3-n]);
			if(lt==-1)
				left=(p3-n)+n;
			else
				left=(p3-n)+lt;
			right=(m+n)-left-1;
		}
		//cout<<left<<" "<<right<<endl;
		if(t==1){
			if(left==right){
				cout<<temp<<endl;
				break;
			}
			else if(left>right)
				p2=p3-1;
			else
				p1=p3+1;
			}
			if(t==2){
			if(abs(left-right)==1){
				cout<<temp<<endl;
				break;
			}
			else if(left>right)
				p2=p3-1;
			else
				p1=p3+1;
			}
		}
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
