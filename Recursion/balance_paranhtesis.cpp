#include <bits/stdc++.h>
using namespace std;

void balance(int open,int close,string op,vector<string> &v){
	if(open==0&&close==0){
		v.push_back(op);
		return;
	}
	if(open!=0){
		string op1=op;
		op1.push_back('(');
		balance(open-1,close,op1,v);
	}
	if(close>open){
		string op2=op;
		op2.push_back(')');
		balance(open,close-1,op2,v);
	}
	return;
	
}

void solve(){
	int n,open,close;
	string op="";
	vector<string> v;
	cin>>n;
	open=n;
	close=n;
	balance(open,close,op,v);
	for(auto u:v)
		cout<<u<<endl;
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
