#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n, c; cin >> n >> c;

	if (c < n - 1 or c > (n * (n + 1) / 2)) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<int>rev, res;
	for (int i = 1; i <= n; i++) res.push_back(i);
	for (int i = 1; i <= n - 1; i++) {
		int rem = n - (i + 1);
		int mx = n - i + 1;
		mx = min(mx, c - rem);
		rev.push_back(mx);
		c -= mx;
	}
	reverse(rev.begin(), rev.end());
	for (int i = 0; i < n; i++) {
		if (i)cout << ' ';
		cout << rev[i];
	}
	puts("");
	for (int steps = 1, idx = 0; steps <= n - 1; steps++, idx++) {
		cout << "\nbefore:\n";
		for (int i = 0; i < n; i++) {
			if (i)cout << ' ';
			cout << res[i];
		}
		int st = n - rev[idx];
		reverse(res.begin() + st, res.begin() + st + rev[idx]);
		cout << "\nAfter:\n";
		for (int i = 0; i < n; i++) {
			if (i)cout << ' ';
			cout << res[i];
		}

	}
	for (int i = 0; i < n; i++) {
		if (i)cout << ' ';
		cout << res[i];
	}
	puts("");
}
int main () {
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);


	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
