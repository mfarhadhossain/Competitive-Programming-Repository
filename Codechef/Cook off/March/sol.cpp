#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void gen() {

	ll res = 0, n, m, k; cin >> n >> m >> k;
	if (n == 1 or m == 1) {
		for (int i = 2 + k; i <= n + m + k; i ++) {
			res ^= (i);
		}
		cout << res << endl;

	}
	else if (n & 1) {
		ll top_left = 2 + k;
		ll top_right = 1 + m + k;
		ll bottom_left = 1 + n + k;
		ll bottom_right = n + m + k;

		for (ll i = bottom_left; i <= top_right; i++) {
			res ^= i;
		}
		for (ll i = bottom_left; i <= top_right; i++) {
			res ^= i;
		}

	}
	else {

	}
}
void solve() {
	ll res = 0, n, m, k; cin >> n >> m >> k;

	res = (2 + k) ^ (n + m + k);
	cout << res << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}