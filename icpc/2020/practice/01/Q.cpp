#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ff first
#define ss second
//using namespace __gnu_pbds;
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
bool possible(vector<int>&v, int x) {
	int n = v.size();
	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		if (v[i] + v[j] < x)
			return 0;
	}
	return 1;
}
void solve() {
	int n; cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//cout << v[n / 2 - 1] + v[n / 2] << endl;
	int l = 1, r = 2 * v[n - 1], res = 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (possible(v, m)) {
			//cout << m << " = possible\n";
			res = max(res, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	cout << res << endl;

}
int main () {
// #ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
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