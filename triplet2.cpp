#include <bits/stdc++.h>
using namespace std;



int recur(int i,int m[],int r){
    
    if(i==r+1){
        return 0;
    }
    if(m[i]<0){
        return INT_MIN;
    }
    
    if(m[i+1]<0 || m[i+2]<0){
        return INT_MIN;
    }
    
    if(m[i]==0){
		if(i==r)
			return 0;
        i++;
    }
    
    int x[1001];
    int y[1001];
    for(int j=0;j<=r;j++){
        x[j]=m[j];
        y[j]=m[j];
    }
    
    m[i]=m[i]-3;
    x[i]--;
    x[i+1]--;
    x[i+2]--;
    return max(1+recur(i,m,r),max(1+recur(i,x,r),recur(i+1,y,r)));
    
    
}

int main() {
    int n,r;
    cin>>n>>r;
    vector<int> a(n);
    int m[1001];
    memset(m,0,sizeof(m));
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    int ans=recur(0,m,r);
    cout<<ans<<"\n";
	return 0;
}
