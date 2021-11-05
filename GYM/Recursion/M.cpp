#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
ll suffixsum(int i, int m, std::vector<ll> &v) {
	if (m == 0)
		return 0;
	return v[i] + suffixsum(i - 1, m - 1, v);
}
void solve() {
	int n, m; cin >> n >> m;
	std::vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << suffixsum(n - 1, m, v) << '\n';
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