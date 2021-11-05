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
	int n; cin >> n;
	map<ll, int> cache;
	std::vector<ll> v(n + 3);
	ll tot = 0;
	for (int i = 1; i <= n + 2; i++) {
		cin >> v[i];
		tot += v[i];
		cache[v[i]] = i;
	}
	int x_id = -1, y_id = -1, f = 0;
	for (int i = 1; i <= n + 2; i++) {

		ll rem = (tot - v[i]) ;
		if (rem & 1)continue;
		rem /= 2;
		if (cache[rem] && cache[rem] != i) {
			x_id = i;
			y_id = cache[rem];
			f = 1;
			//cout << "rem = " << rem << " x_id " << x_id << " y_id " << y_id << endl;
			break;
		}
	}
	if (f == 0) {
		cout << "-1\n";
		return;
	}

	for (int i = 1; i <= n + 2; i++) {
		if (i != x_id && i != y_id) {
			cout << v[i] << ' ';
		}
	}
	cout << endl;
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