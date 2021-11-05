#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n, k0, k1, w, b;
	cin >> n >> k0 >> k1;
	cin >> w >> b;

	int vertical_w = min(k0, k1);

	int horizontal_w = max(k0, k1) - min(k0, k1);
	horizontal_w /= 2;

	int tot_w = horizontal_w + vertical_w;

	int vertical_b = min(n - k0, n - k1);

	int horizontal_b = max(n - k0, n - k1) - min(n - k0, n - k1);
	horizontal_b /= 2;
	int tot_b = horizontal_b + vertical_b;

	if (tot_w >= w && tot_b >= b) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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