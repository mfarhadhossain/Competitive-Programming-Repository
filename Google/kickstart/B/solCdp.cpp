#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
#define PI acos(-1.0)
ll dp[405][405][405];
ll go(int l, int r, int last, vector<ll>&v, ll D) {
	if (l > r) {
		return 0;
	}
	if (dp[l][r][last] != -1)
		return dp[l][r][last];

	ll cost1 = min(max(v[last], v[l]) - min(v[last], v[l]),
	               min(v[last], v[l]) + D - max(v[last], v[l]));
	ll cost2 = min(max(v[last], v[r]) - min(v[last], v[r]),
	               min(v[last], v[r]) + D - max(v[last], v[r]));
	ll ret1 = cost1 + go(l + 1, r, l, v, D);
	ll ret2 = cost2 + go(l, r - 1, r, v, D);

	return dp[l][r][last] = min(ret1, ret2);
}
void solve() {
	memset(dp, -1, sizeof dp);
	ll N, D; cin >> N >> D;

	vector<ll> v(N + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];
	ll res = go(0, N - 1, N, v, D);
	cout << res << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ":";
		solve();
	}
	return 0;
}