#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 998244353;
vector<int>g[2007];
int n,m,k,s,t,x;
ll dp[2007][2007][2];
ll dfs(int u,int len,int cnt_x){
	if(len == 0 ){
		if(u == t && cnt_x == 0){
			return 1;
		}
		return 0;
	}
	if(dp[u][len][cnt_x]!=-1)
		return dp[u][len][cnt_x];
	ll ret=0;
	for(auto v:g[u]){
		ret+=dfs(v,len-1,(cnt_x+ (x==v))%2)%MOD;
		ret%=MOD;
	}
	return dp[u][len][cnt_x] = ret%MOD;
}
int  main ()
{
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k>>s>>t>>x;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<dfs(s,k,0)<<endl;
	return 0;
}