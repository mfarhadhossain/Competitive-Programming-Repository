#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>v(n+1),dp(n+1,1e9);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	dp[0]=0;
	//dp[1]=abs(v[0]-v[1]);
	for(int i=1;i<n;i++){
		for(int j=1;j<=k&&i-j>=0;j++)
			dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
	}
	cout<<dp[n-1]<<endl;
}
int  main ()
{
	int t=1;//cin>>t;
	for(int tc=1;tc<=t;tc++)solve();
    return 0;
}