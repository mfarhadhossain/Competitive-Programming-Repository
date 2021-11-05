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

typedef    pair<int, int> pii;
typedef    pair<int, pii> ppi;
typedef    pair<pii, int> pip;
typedef    long long int ll;
typedef    unsigned long long int ull;
typedef    pair<ll, ll> pll;
typedef    vector<int> VI;
typedef    vector<pii> Vii;
const int MAX = 1e6, MOD = 1e9 + 7;

//int res[100 + 5][100 + 5];
int query(int x) {
	cout << "? " << 1 << " " << x << endl;
	int sum;
	cin >> sum;
	cout << "zeroes = " << x - sum << endl;
	return x - sum;
}
void solve() {
	int n, t; cin >> n >> t;

	for (int i = 1; i <= t; i++) {

		int k; cin >> k;

		int l = 1, r = n, res = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(mid) >= k) {
				res = min(res, mid);
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << "! " << res << endl;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
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