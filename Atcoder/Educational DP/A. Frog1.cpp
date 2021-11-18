#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
void solve(){
	int n;cin>>n;
	vector<int>v(n+1),dp(n+1);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	dp[0]=v[0];
	dp[1]=abs(v[1]-v[0]);

	for(int i=2;i<n;i++){
		dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]), dp[i-2]+abs(v[i]-v[i-2]));
	}
	cout<<dp[n-1]<<endl;
}
int  main ()
{
	int t=1;//cin>>t;
	for(int tc=1;tc<=t;tc++)
		solve();
    return 0;
}