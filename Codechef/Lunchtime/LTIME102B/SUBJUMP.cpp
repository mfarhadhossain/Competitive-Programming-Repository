// O(n^2)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
int ar[MAX],suff_min_index[MAX];
//ll dp[MAX];
void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	// suff_min_index[n-1] = n-1;
	// int mn = ar[n-1],mn_index=n-1;
	// for(int i=n-1;i>=0;i--){
	// 	if(ar[i]<mn){
	// 		mn = ar[i];
	// 		mn_index = i;
	// 		suff_min_index[i]=suff_min_index[i+1];
	// 	}
	// 	else{

	// 		suff_min_index[i]=mn_index;
	// 	}
	// }
	 // for(int i=0;i<n;i++)
	 // 	cout<<suff_min_index[i]<<",";
	 // cout<<endl;
	vector<ll>dp(n+10,LLONG_MAX);
	dp[0]=0;
	for (int i = 0; i < n; i++) {
		//for (int j = i + 1; j < n; j++) {
		// if(suff_min_index[i]<n)
		// dp[suff_min_index[i]] = min(dp[suff_min_index[i]], 
		// 	((suff_min_index[i] - i + 1) *1LL* ar[i] - ar[suff_min_index[i]]) + dp[i]);

		for (int j = i + 1; j < max(n,i+11); j++) {
			dp[j] = min(dp[j], 
			((j - i + 1) *1LL* ar[i] - ar[j]) + dp[i]);
		}
		// for (int j = max(i+1,n-1-10); j < n; j++) {
		// 	dp[j] = min(dp[j], 
		// 	((j - i + 1) *1LL* ar[i] - ar[j]) + dp[i]);
		// }
		//}
		// cout<<"@ "<<i<<":\n";
		// for(int j=i+1;j<n;j++){
		// 	cout<<j<<" "<<dp[j]<<endl;
		// }
	}
	if (dp[n - 1] < 0)dp[n - 1] = 0;
	cout << dp[n - 1] << '\n';
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//cout.tie(0);
	
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}