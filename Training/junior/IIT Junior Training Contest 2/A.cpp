#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int res = MAX, n, T; cin >> n >> T;
	while (n--) {
		int c, t; cin >> c >> t;
		if (t <= T && res > c) {
			res = c;
		}
	}
	if (res == MAX)cout << "TLE\n";
	else cout << res << "\n";
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