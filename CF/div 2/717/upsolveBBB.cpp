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
	int n, k, x = 0; cin >> n;
	std::vector<int> v(n), prefix_xor(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		x ^= v[i];
		if (i == 0) {
			prefix_xor[i] = v[i];
		}
		else {
			prefix_xor[i] = prefix_xor[i - 1] ^ v[i];
		}
	}
	if (x == 0) {
		cout << "YES\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		int x = prefix_xor[i];

		for (int j = i + 1; j < n - 1; j++) {
			int y = prefix_xor[j] ^ x;
			int z = prefix_xor[n - 1] ^ prefix_xor[j];
			//cout << "i " << i << " x " << x << " j = " << j << " y = " << y << endl;
			//cout << "z = " << z << endl;
			if (x == y && y == z) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
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