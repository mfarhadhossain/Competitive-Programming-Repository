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
void solve() {
	int n, k; cin >> n >> k;

	std::vector<string> v(n);
	int safe_high = -1, broken_low = -1;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> v[i];
		if (v[i] == "SAFE") {
			if (safe_high == -1)safe_high = a[i];
			else safe_high = max(safe_high, a[i]);
		}
		else {
			if (broken_low == -1)broken_low = a[i];
			else broken_low = min(broken_low, a[i]);
		}
	}
	vector<int>floor(k + 1);
	if (safe_high != -1)
		for (int i = 1; i <= safe_high; i++) {
			floor[i] = 1;
		}
	if (broken_low != -1)
		for (int i = broken_low; i <= k; i++) {
			floor[i] = 2;
		}
	int res1;
	for (int i = 2; i <= k; i++) {
		if (floor[i] == 2 or floor[i] == 0) {
			res1 = i;
			break;
		}

	}
	int res2;
	for (int i = k - 1; i >= 1; i--) {
		if (floor[i] == 1 or floor[i] == 0) {
			res2 = i;
			break;
		}
	}
	cout << res1 << " " << res2 << endl;
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