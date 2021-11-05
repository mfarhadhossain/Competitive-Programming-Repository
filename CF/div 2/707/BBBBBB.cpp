#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;

	std::vector<int> v(n), res(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int soak = 0;
	for (int i = n - 1; i >= 0; i--) {
		soak = max(soak, v[i]);
		if (soak > 0) {
			soak--;
			res[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
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