#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	std::vector<int> t(n), x(n), y(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	int curr_x = 0 , curr_y = 0 , prev = 0;
	for (int i = 0; i < n; i++) {
		int d = abs(x[i] - curr_x) + abs(y[i] - curr_y);
		int time = t[i] - prev;
		int r = time % d;
		if ( d > time) {
			cout << "No\n";
			return;
		}
		if (r & 1) {
			cout << "No\n";
			return;
		}
		prev = t[i];
		curr_x = x[i];
		curr_y = y[i];
	}
	cout << "Yes\n";
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