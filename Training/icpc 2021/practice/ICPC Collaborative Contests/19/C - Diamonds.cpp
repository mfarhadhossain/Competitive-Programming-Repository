#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
int w[202],c[202],n,dp[202][202];
int go(int idx,int pr_idx){
	if(idx > n)
		return 0;
	if(dp[idx][pr_idx]!=-1)
		return dp[idx][pr_idx];
	int ret = go(idx+1,pr_idx);
	if((w[idx]>w[pr_idx] && c[idx]<c[pr_idx])){
		ret=max(ret, 1 + go(idx+1,idx));
	}
	return dp[idx][pr_idx] = ret;
}
void solve() {
	cin >> n;
	for(int i=0;i<n;i++){
		double x,y;
		cin >> x >> y;

		w[i+1] = x*100000;
		c[i+1] = y*100000;

	}
w[0]= -1e9, c[0] = 1e9;
	memset(dp,-1,sizeof dp);
	cout<<go(1,0)<<endl;
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