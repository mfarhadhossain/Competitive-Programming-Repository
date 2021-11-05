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
int n, k, a[22], dp[1LL << 21];
int go(int mask) {
	if (__builtin_popcount(mask) == n)
		return 0;
	if (dp[mask] != -1)
		return dp[mask];
	std::vector<int> rem;
	for (int i = 0; i < n; i++) {
		if (mask & (1LL << i))continue;
		rem.push_back(i);
	}
	// int sz = rem.size();
	// int ret = 1e9;
	// for (int i = 0; i < (1LL << sz); i++) {
	// 	std::vector<int> option;
	// 	for (int j = 0; j < sz; j++) {
	// 		if (i & (1LL << j)) {
	// 			option.push_back(rem[j]);
	// 			//cout << rem[j] << ' ';
	// 		}
	// 	}
	// 	if (option.size() == 0)continue;
	// 	//cout << endl;
	// 	int dummy_mask = mask;
	// 	int bad = 0, tot = 0;
	// 	for (int j = 0; j < option.size(); j++) {
	// 		tot += a[option[j]];
	// 		int x = option[j];
	// 		dummy_mask |= (1LL << x);
	// 		if (tot > k) {
	// 			bad = 1;
	// 			break;
	// 		}

	// 	}
	// 	if (bad == 0)
	// 		ret = min(ret, 1 + go(dummy_mask));
	// }
	return dp[mask] = ret;
}
void solve() {
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << go(0) << endl;
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