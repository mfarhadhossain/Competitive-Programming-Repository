#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
pair<int, int> reduce(int r, int b) {
	int g = __gcd(r, b);
	if (g == 0) {
		return {0, 1};
	}

	return {r / g, b / g};
}
void solve() {
	int r, b; cin >> r >> b;
	auto res = reduce(r * (r - 1), (r + b) * (r + b - 1));
	cout << res.first << "/" << res.second << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}