#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int n,k;
string g[55];
int dp[55][55][5][5];
int go(int x,int y,int dir,int curr){
	if(curr>k)return 0;
	if(x>=n or y>=n)return 0;
	if(g[x][y]=='H')return 0;
	if(x==n-1 and y==n-1)return 1;

	if(dp[x][y][dir][curr]!=-1)
		return dp[x][y][dir][curr];
	int ret=0;
	if(dir == 0){ // 0,0
		ret=go(x+1,y,1,0);//down
		ret+=go(x,y+1,2,0);//right
	}
	else if(dir==1){
		ret+=go(x+1,y,1,curr);// no dir change
		ret+=go(x,y+1,2,curr+1); // down to right
	}
	else if(dir==2){
		ret+=go(x+1,y,1,curr+1);// right to down
		ret+=go(x,y+1,2,curr); // no dir change
	}
	return dp[x][y][dir][curr] = ret;
}
void solve() {
	memset(dp,-1,sizeof dp);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>g[i];
	cout<<go(0,0,0,0)<<endl;
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