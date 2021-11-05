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
const int MAX = 1e6, MOD = 1e9 + 7;
bool is_sqaure(ll x) {
	if (x == 0)
		return false;
	ll sq = sqrtl(x);
	if (sq * sq == x)
		return true;
	return false;
}
void solve() {
	ll n, x, s = 0; cin >> n;
	if (n & 1) {

		cout << "NO\n";
		return;
	}
	if (n % 2 == 0 and is_sqaure(n / 2)) {
		cout << "YES\n";
		return;
	}
	if (n % 4 == 0 and is_sqaure(n / 4)) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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