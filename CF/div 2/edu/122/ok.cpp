#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MX = 1007, MOD = 1e9 + 7;
int dp[1005][20005], dp2[2005];
int go(int idx, ll rem_k, vector<int>&b, vector<int>&c) {
	if (idx == b.size()) {
		if(rem_k>=0) return 0;
		return -1e9;
	}
	if (dp[idx][rem_k] != -1)
		return dp[idx][rem_k];
	int ret = go(idx + 1, rem_k, b, c);
	if (rem_k - b[idx] >= 0)
		ret = max(ret , c[idx] + go(idx + 1, rem_k - b[idx], b, c));
	return dp[idx][rem_k] = ret;
}
void solve() {
	memset(dp, -1, sizeof dp);

	ll n, k; cin >> n >> k;

	vector<int> b(n), c(n);

	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	ll res = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		b[i] = dp2[b[i]];
		sum += b[i];
	}
	cout << go(0, (ll)min(k, sum), b, c) << endl;
}
void calculatesteps() {
	for (int i = 0; i < 1010; i++)
		dp2[i] = INT_MAX;

	dp2[1] = 0;
	dp2[2] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			int x = i + i / j;
			if (x < 1010)
				dp2[x] = min(dp2[i] + 1, dp2[x]);
		}
	}
}
int  main ()
{
	calculatesteps();
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}