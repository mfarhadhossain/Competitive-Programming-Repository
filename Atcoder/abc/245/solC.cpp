#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5 + 10, MOD = 1e9 + 7;
ll n,k;
int dp[MAX][2];
int go(int idx,int prv,vector<ll>&a,vector<ll>&b){
	if(idx==a.size()){
		return 1;
	}
	if(dp[idx][prv]!=-1)
		return dp[idx][prv];
	int ret=0;
	if(prv==0){ // ager tay a[i-1]
		if( abs(a[idx]-a[idx-1]) <=k ){
			ret=go(idx+1,0,a,b);
		}
		if( abs(b[idx]-a[idx-1]) <=k ){
			ret|=go(idx+1,1,a,b);
		}
	}
	else{ // ager tay b[i-1]
		if( abs(a[idx]-b[idx-1]) <=k ){
			ret|=go(idx+1,0,a,b);
		}
		if( abs(b[idx]-b[idx-1]) <=k ){
			ret|=go(idx+1,1,a,b);
		}
	}
	return dp[idx][prv] = ret;
}
void solve() {
	memset(dp,-1,sizeof dp);
	cin>>n>>k;
	vector<ll>a(n),b(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int ret = go(1,0,a,b) or go(1,1,a,b);
	if(ret)cout<<"Yes\n";
	else cout<<"No\n";
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}