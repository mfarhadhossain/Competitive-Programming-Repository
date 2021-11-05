#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here

typedef    pair<int, int> pii;
typedef    pair<int, pii> ppi;
typedef    pair<pii, int> pip;
typedef    long long int ll;
typedef    unsigned long long int ull;
typedef    pair<ll, ll> pll;
typedef    vector<int> VI;
typedef    vector<pii> Vii;
const int MAX = 1e6, MOD = 1e9 + 7;

void solve() {
	int n, l, r; cin >> n >> l >> r;
	std::vector<int> L, R;
	map<int, int>cnt_l, cnt_r;
	for (int i = 1; i <= l; i++) {
		int x;
		cin >> x;
		cnt_l[x]++;
	}
	for (int i = 1; i <= r; i++) {
		int x;
		cin >> x;
		cnt_r[x]++;
	}
	// step 1: matching gula baad
	for (int i = 1; i <= n; i++) {
		if (cnt_l[i] && cnt_r[i]) {
			int mn = min(cnt_l[i], cnt_r[i]);
			cnt_l[i] -= mn;
			cnt_r[i] -= mn;
			//cout << "col " << i << " match " << mn << endl;
		}
	}
	int res = 0, ret = 1e9;

	int sz_L = 0;
	int sz_R = 0;
	for (int i = 1; i <= n; i++) {

		if (cnt_l[i] > 0) {
			sz_L += cnt_l[i];
		}
		if (cnt_r[i] > 0) {
			sz_R += cnt_r[i];
		}
	}
	if (sz_L == sz_R) {
		res += max(sz_R, sz_L);
		cout << res << endl;
		return;
	}
	//cout << sz_L << " " << sz_R << endl;
	if (sz_R != sz_L) { // step 2: left to right

		if (sz_L > sz_R) {
			int need = n / 2 - sz_R;
			for (int i = 1; i <= n; i++) {
				if (need == 0 or sz_L == sz_R)break;

				if (cnt_l[i] > 0) {

					int can = min(need, cnt_l[i] / 2);

					cnt_l[i] -= can * 2;
					res += can;
					need -= can;
					sz_L -= can;
					sz_R += can;
					sz_R -= can;
					sz_L -= can;
				}
				ret = min(ret, res + max(sz_R, sz_L));
			}

		}
		if (sz_R > sz_L) {

			int need = n / 2 - sz_L;
			//cout << "need = " << need << endl;
			for (int i = 1; i <= n; i++) {
				if (need == 0 or sz_R == sz_L)break;

				if (cnt_r[i] > 0) {

					int can = min(need, cnt_r[i] / 2);

					cnt_r[i] -= can * 2;
					res += can;
					need -= can;
					sz_R -= can;
					sz_L += can;
					sz_R -= can;
					sz_L -= can;
				}

				ret = min(ret, res + max(sz_R, sz_L));
			}
		}
	}
	//cout << sz_L << " " << sz_R << endl;
	// sz_L = 0;
	// sz_R = 0;
	// for (int i = 1; i <= n; i++) {

	// 	if (cnt_l[i] > 0) {
	// 		sz_L += cnt_l[i];
	// 	}
	// 	if (cnt_r[i] > 0) {
	// 		sz_R += cnt_r[i];
	// 	}
	// }

	ret = min(ret, res + max(sz_R, sz_L));
	cout << ret << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}