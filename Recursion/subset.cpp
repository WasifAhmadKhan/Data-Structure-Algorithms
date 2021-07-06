#include <bits/stdc++.h>
using namespace std;

unordered_set<string> ans;
void subset(string str1,string str2){
	if(str1.length()==0){
		ans.insert(str2);
		return;
	}
	string op1=str2;
	string op2=str2;
	string ip=str1;
	op2.push_back(ip[0]);

	ip.erase(ip.begin()+0);
	subset(ip,op1);
	subset(ip,op2);
	return;	
	
}

void solve(){
	string str1,str2="";
	cin>>str1;
	subset(str1,str2);
	for(auto a:ans){
		cout<<a<<endl;
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
