#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree <
//                     T,
//                     null_type,
//                     greater<T>,
//                     rb_tree_tag,
//                     tree_order_statistics_node_update >;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	std::vector<ll> a(n);
	ll s = 0, mx = -1e18;
	bool pos = false, zero = false, nega = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			s += a[i];
			pos = true;
		}
		if (a[i] == 0) {
			zero = true;
		}
		if (a[i] < 0) {
			nega = true;
			mx = max(mx, a[i]);
		}
	}
	if (pos == false) {
		if (zero == true) {
			cout << "0 0\n";
			return;
		}
		cout << mx << " 0\n";
		return;
	}
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			l = i;
			break;
		}
	}
	int r = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > 0) {
			r = i;
			break;
		}
	}
	int res = 0, neg = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] < 0 && neg == 0) {
			res++;
			neg = 1;
		}
		if (a[i] > 0 && neg) {
			neg = 0;
		}
	}
	cout << s << " " << res << endl;

}
int main () {
    cout<<"life is sad";
//// #ifndef ONLINE_JUDGE
//	//freopen("input.txt", "r", stdin);
//// 	//freopen("output.txt", "w", stdout);
//// #endif
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int t = 1; cin >> t;
//	//scanf("%d", &t);
//	for (int tc = 1; tc <= t; tc++) {
//		//cout << "Case #" << tc << ": ";
//		cout << "Case " << tc << ": ";
//		solve();
//	}
	return 0;
}
