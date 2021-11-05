#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define endl "\n"
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

//int res[100 + 5][100 + 5];
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	ll sheep = 0;
	std::vector<ll> pos;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			sheep++;
			pos.push_back(i + 1);
			//cout << i + 1 << " ";
		}
	}
	if (sheep == 0) {
		cout << "0\n";
		return;
	}
	//cout << "?\n";
	int median = sheep / 2;
	ll res = 1e9;
	for (int i = max(1LL, pos[median] - 25); i <= min( (ll)n - sheep + 1, pos[median] + 25LL); i++) {
		ll ret = 0;
		if ( i > n - sheep + 1)break;

		for (int j = 0; j < sheep; j++) {
			ret += abs(pos[j] - (i + j));
		}
		res = min(res, ret);
	}
	if (sheep % 2 == 0)
		for (int i = max(1LL, pos[median - 1] - 25); i <= min( (ll)n - sheep + 1, pos[median - 1] + 25LL); i++) {
			ll ret = 0;
			if ( i > n - sheep + 1)break;

			for (int j = 0; j < sheep; j++) {
				ret += abs(pos[j] - (i + j));
			}
			res = min(res, ret);
		}

	cout << res << endl;
	// //cout << endl;
	// // cout << sheep << endl;
	// // cout << n - sheep + 1 << endl;
	// // cout << (n - sheep + 1)*sheep << endl;
	// int res2 = 1e9;
	// for (int i = 1; i <= n - sheep + 1; i++) {
	// 	int ret = 0;
	// 	cout << "starts at " << i << ": ";
	// 	for (int j = 0; j < sheep; j++) {
	// 		ret += abs(pos[j] - (i + j));
	// 	}
	// 	cout << "cost = " << ret << endl;
	// 	res2 = min(res2, ret);
	// }
	// cout << "res = " << res2 << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
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