#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e5 + 7, MOD = 1e9 + 7;
ll BIT[MAX], N, q;
void update(int idx, int val)
{
	for (int i = idx; i <= N; i += (i & -i)) {
		BIT[i] += val;
	}
}
ll query(int idx)
{
	ll res = 0;
	for (int i = idx; i >= 1; i -= (i & -i)) {
		res += BIT[i];
	}
	return res;
}
void solve() {
	cin >> N >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 0) {
			int l, r, val; cin >> l >> r >> val;
			l++, r++;
			update(l, val);
			update(r + 1, -val);
		}
		else {
			int l, r; cin >> l >> r;
			l++, r++;
			cout << "from 1 to " << r << " " << query(r) << endl;
			cout << "from 1 to " << l - 1 << " " << query(l - 1) << endl;
			cout << query(r) - query(l - 1) << endl;
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

	int t = 1, n, k; cin >> t;
	for (int tc = 1 ; tc <= t; tc++) {
		//if (t > 1)cout << "\n";
		cout << "Case " << (tc) << ":\n";
		solve();
	}
	return 0;
}