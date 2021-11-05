#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
ll dp[33];
ll fibonacci(int n) {
	if (n == 1)return dp[n] = 0;
	if (n == 2)return dp[n] = 1;
	if (dp[n] != -1)return dp[n];
	return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
void solve() {
	ll n; cin >> n;
	memset(dp, -1, sizeof dp);
	cout << fibonacci(n) << '\n';
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