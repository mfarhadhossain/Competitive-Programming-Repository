#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
bool possible(std::vector<ll> &s, ll x, ll steps) {
	int t = 1;

	for (int i = x - 1; i >= 0; i--) {
		if (t + s[i] > steps)
			return false;
		t++;
	}
	return true;
}
void solve() {
	ll n, m, a, b, df, steps;
	cin >> n >> m >> a >> b;
	if (a > b) {
		df = a - b;
		steps = n - b;
	}
	else {
		df = b - a;
		steps = b - 1;
	}
	std::vector<ll> s(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());

	ll l = 1 , r = min(m, df - 1) , res = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;

		if (possible(s, mid, steps)) {
			res = max(res, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
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

	int t; cin >> t;
	while (t--)solve();
	return 0;
}