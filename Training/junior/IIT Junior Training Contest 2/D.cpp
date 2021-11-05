#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	std::vector<int> h(n);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int res = 0;

	while (true) {

		int bad = 0;
		for (int i = 0; i < n; i++) {
			if (h[i] != 0) {
				bad = 1;
				break;
			}
		}
		if (bad == 0)
			break;

		int st = 0 , en = 0;

		for (int i = 0; i < n; i++) {
			if (h[i]) {
				st = i;
				break;
			}
		}
		for (int i = st; i < n; i++) {
			if (h[i]) {
				en = i;
			}
			else break;
		}
		int mn = 1e9;
		for (int i = st; i <= en; i++) {
			mn = min(mn, h[i]);
		}
		for (int i = st; i <= en; i++) {
			h[i] -= mn;
		}
		res += mn;
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