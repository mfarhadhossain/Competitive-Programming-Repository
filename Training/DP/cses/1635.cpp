#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
const int MAX = 1e6, MOD = 1e9 + 7;
int n, x, a[111];
int go(int idx, int rem) {
	// if (rem == 0 && idx < n)
	// 	return 1;
	// if (rem < 0)
	// 	return 0;
	if (idx == n - 1) {
		if (rem == 0)
			return 1;
		return 0;
	}
	int ret = go(idx + 1, rem);

	for (int i = 0; i < n; i++) {
		if (rem - a[i] >= 0)
			ret += go(i, rem - a[i]);
		//ret += go(i, rem);
	}
	return ret % MOD;
}
void solve() {
	//memset(dp, -1, sizeof dp);
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << go(0, x) << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}