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
ll dp[2005][2005];

ll go(std::vector<ll> &v, int l, int r) {
	if (l == r)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	return dp[l][r] = v[r] - v[l] + min(go(v, l + 1, r), go(v, l, r - 1));
}
void solve() {
	int n, x; cin >> n;
	std::vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	memset(dp, -1, sizeof dp);
	sort(v.begin(), v.end());
	cout << go(v, 0, n - 1) << endl;

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