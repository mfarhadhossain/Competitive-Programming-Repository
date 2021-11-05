#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n, m; cin >> n >> m;

	std::vector<int> v(n);

	map<int, int>cnt;

	int res = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] %= m;

		cnt[v[i]]++;
	}
	std::vector<bool> vis(m + 1);
	for (int i = 0; i < m; i++) {
		if (vis[i] || cnt[i] == 0)continue;
		vis[i] = 1;
		if (i == 0) {
			if (cnt[i]) {
				res++;
			}
		}
		else {
			int j = m - i;
			vis[j] = 1;
			if (cnt[i] == 0) {
				res += cnt[j];
			}
			else if (cnt[j] == 0) {
				res += cnt[i];
			}
			else {
				if (cnt[i] == cnt[j]) {
					res++;
				}
				else if (cnt[i] > cnt[j]) {
					int df = max(0, cnt[i] - (cnt[j]));
					res += df;
				}
				else {
					int df = max(0, cnt[j] - (cnt[i]));
					res += df;
				}
			}
		}

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

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}