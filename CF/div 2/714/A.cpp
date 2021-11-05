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
	if (n == 1) {
		if (k == 0) {
			cout << "1\n";
			return;
		}
		else {

			cout << "-1\n";
			return;
		}
	}
	if (n == 2) {
		if (k == 0) {
			cout << "1 2\n";
			return;
		}
		else {

			cout << "-1\n";
			return;
		}
	}
	int pos = ((n - 1) / 2);

	if (k > pos) {
		cout << "-1\n";
		return;
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	std::vector<int> v(n);

	v[0] = 1;
	v[n - 1] = 2;

	int mx = n;
	int mn = mx - k + 1;
	for (int j = 1; j < n; j += 2) {
		v[j] = mx;
		if (mx == mn)break;
		mx--;
	}
	mn--;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = mn;
			mn--;
		}
	}
	for (int x : v)
		cout << x << " ";
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