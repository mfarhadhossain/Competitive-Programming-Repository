#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int go(int i, int curr, int k, std::vector<int> &v) {
	if (i == v.size()) {
		return curr == k;
	}
	return go(i + 1, curr - v[i], k, v) | go(i + 1, curr + v[i], k, v);
}
void solve() {
	int n, k; cin >> n >> k;
	std::vector<int> v(n);

	for (int i = 0; i < n; i++)cin >> v[i];

	if (go(1, v[0], k, v)) {
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

	int t = 1; //cin >> t;
	while (t--)solve();
	return 0;
}