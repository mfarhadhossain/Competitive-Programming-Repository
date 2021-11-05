#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m,target;
string g[5005];
ll dp[1<<12][5][5001];
ll go(int idx,int cnt,ll mask){
	if(cnt==3){
		if(mask==target)
			return 1;
		return 0;
	}
	if(idx==n)
	    return 0;
	if(dp[mask][cnt][idx]!=-1)
		return dp[mask][cnt][idx];
	ll curr=0;
	ll ret = go(idx+1,cnt,mask);
	for(int i=0;i<m;i++){
		if(g[idx][i]=='y'){
			curr|=(1LL<<i);
		}
	}
	ret+=go(idx+1,cnt+1,mask|curr);
	return dp[mask][cnt][idx] = ret;
}
void solve(){
	cin >> n >> m;
	target=1LL<<m;
	target--;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++){
		cin >> g[i];
	}
	cout<<go(0,0,0)<<endl;
}
int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}