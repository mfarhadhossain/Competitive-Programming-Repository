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
void solve() {
	ll n, cnt = 0; cin >> n;

	ll curr = 2050, LMAX = 1e18;
	while (curr < LMAX) {
		curr *= 10;
	}
	while (n > 0) {
		int g = 0;
		for (ll x = curr; x >= 2050; x /= 10) {
			if (n - x >= 0) {
				n -= x;
				cnt++;
				g = 1;
				break;
			}
		}
		if (g == 0)
		{
			cnt = -1;
			break;
		}
	}
	cout << cnt << endl;
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