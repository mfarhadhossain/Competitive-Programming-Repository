#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
ll dp[33][33];
ll nCr(ll n, ll r) {
	if (r > n)
		return 0LL;
	if (n == r || r == 0)
		return dp[n][r] = 1LL;
	if (dp[n][r] != -1)
		return dp[n][r];
	return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}
void solve() {
	memset(dp, -1, sizeof dp);
	int n, r; cin >> n >> r;

	cout << nCr(n, r) << '\n';
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	while (t--)solve();
	return 0;
}