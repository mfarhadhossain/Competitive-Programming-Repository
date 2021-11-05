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
void solve() {
	int n, x, s = 0; cin >> n >> x;
	std::vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		s += w[i];
	}
	if (s == x) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	std::vector<bool> taken(n + 1);
	std::vector<int> ret;
	int res = 0;
	while (true) {
		int f = 0;
		for (int i = 0; i < n; i++) {
			if (taken[i]) continue;
			if (w[i] + res == x)continue;
			taken[i] = 1;
			f = 1;
			ret.push_back(i);
			res += w[i];
		}
		if (f == 0)
			break;
	}
	for (int x : ret) {
		cout << w[x] << " ";
	}
	cout << endl;
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
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