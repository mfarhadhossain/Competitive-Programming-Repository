#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
	std::vector<int> v(n);
	for (int i = 1; i <= n; i++)
		cin >> v[i - 1];

	std::vector<int> temp;
	temp = v;
	sort(temp.begin(), temp.end());

	if (temp == v) {
		cout << "0\n";
		return;
	}
	if (v[0] == 1 or v[n - 1] == n) {
		cout << "1\n";
		return;
	}
	if (v[n - 1] == 1 and v[0] == n) {

		cout << "3\n";
		return;
	}
	cout << "2\n";
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