#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int mx = 0;
void gen(int cnt, int sum, std::vector<int> v) {
	if (cnt == 0 && sum == 0) {
		int g = 0;
		for (int x : v) {
			g = __gcd(g, x);
		}
		mx = max(mx, g);
		return;
	}
	for (int i = 1; i <= sum - cnt + 1; i++) {
		if ( sum - i >= 0) {
			v.push_back(i);
			gen(cnt - 1, sum - i, v);
			v.pop_back();
		}
	}
}
void solve() {
	ll n, m; cin >> n >> m;
	ll res = 1, sq = sqrt(m);
	for (ll i = 1; i <= sq; i++) {
		if (m % i == 0) {
			if (i * n <= m)
				res = max(res, i);
			if (n * (m / i) <= m)
				res = max(res, m / i);
		}
	}
	cout << res << endl;
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