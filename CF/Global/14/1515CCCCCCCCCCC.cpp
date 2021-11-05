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

void solve() {

	priority_queue<pll> h;// MaxHeap
	priority_queue< pll, std::vector<pll>, greater<pll> > PQ; // MinHeap
	int n, m, x; cin >> n >> m >> x;
	for (int i = 0; i < n; i++) {
		ll xx;
		cin >> xx;
		h.push({xx, i + 1});
	}
	for (int i = 1; i <= m; i++) {
		PQ.push(make_pair(0, i));
	}
	std::vector<int> res(n + 1);
	while (!h.empty()) {
		auto u = h.top();
		h.pop();
		auto upor = PQ.top();
		PQ.pop();

		res[u.second] = upor.second;
		PQ.push({upor.first + u.first, upor.second});
	}
	std::vector<ll> final(m + 1);

	while (!PQ.empty()) {
		auto xx = PQ.top();
		PQ.pop();
		final[xx.second] = xx.first;
	}
	ll mx = -1e18;
	ll mn = 1e18;
	for (int i = 1; i <= m; i++) {
		//cout << final[i] << ' ';
		mn = min(mn, final[i]);
		mx = max(mx, final[i]);
	}
	// cout << "mn = " << mn << endl;
	// cout << "mX = " << mx << endl;
	if (mx - mn > x) {
		cout << "NO\n";
		return;
	}
	// for (int i = 1; i <= m; i++) {
	// 	cout << final[i] << ' ';
	// }
	// cout << endl;
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
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