#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k,n;
    map<int,int> first;
    cin>>k;
    vector<int> coin(k);
    for(int i=0;i<k;i++)cin>>coin[i];
    cin>>n;
    vector<int> c(n+1);
    c[0]=0;
    for(int i=1;i<=n;i++){
            c[i]=INT_MAX;
            for(auto j:coin){
                if(i-j>=0&&c[i-j]+1<c[i]){
                c[i]=c[i-j]+1;
                first[i]=j;
                }
            }
    }
    if(c[n]==INT_MAX)
        cout<<"NOT Possible"<<endl;
    else{
        cout<<c[n]<<end;
        while(n>0){
            cout<<first[n]<<" ";
            n-=first[n];
        }
        cout<<endl;
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
