#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
ll ar[MAX],sp[MAX],n;
ll dp[MAX][2];
ll go(int idx,int parity){
	if(idx==n){
		return 0;
	}
	if(dp[idx][parity]!=-1)
		return dp[idx][parity];
	ll ret=LLONG_MIN,q=1;
	if(parity){
		q=-1;
	}
	if(sp[idx]==1){
		ret=q*ar[idx] + go(idx+1,parity^1);
	}
	else{
		ret=max(ret,q*ar[idx]+go(idx+1,parity^1));
		ret=max(ret,go(idx+1,parity));
	}
	return dp[idx][parity] = ret;
}
void solve() {
	memset(dp,-1,sizeof dp);
    cin>>n;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cin>>sp[i];
	}
	cout<<go(0,0)<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}