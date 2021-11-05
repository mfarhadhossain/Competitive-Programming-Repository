#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n, mx = 0; cin >> n;
	std::vector<int> x(n), y(n), h(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> h[i];
		mx = max(mx, h[i]);
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			int H = 0;
			for (int k = 0; k < n; k++) {
				int d = abs(x[k] - i) + abs(y[k] - j);
				if (h[k]) {
					H = d + h[k]; break;
				}
			}
			int bad = 0;
			for (int k = 0; k < n; k++) {
				int d = abs(x[k] - i) + abs(y[k] - j);
				if (h[k] != max(0, H - d)) {
					bad = 1;
					break;
				}
			}
			if (bad == 0) {
				cout << i << " " << j << " " << H << endl;
				return;
			}

		}
	}
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