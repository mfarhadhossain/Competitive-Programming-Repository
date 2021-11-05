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
	int n, k; cin >> n >> k;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];

	while (k > 0) {
		int g = 0;
		for (int i = 0; i < n; i++) {
			int can = min(v[i], k);
			if (can) {
				k -= can;
				g = 1;
				v[n - 1] += can;
				v[i] -= can;
				break;
			}
		}
		if (g == 0)
			break;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
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