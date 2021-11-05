#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	std::vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		v.push_back({l, 1});
		v.push_back({r, -1});
	}
	sort(v.begin(), v.end());

	int res = 0, curr = 0;

	for (int i = 0; i < v.size(); i++) {
		curr += v[i].second;
		res = max(res, curr);
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