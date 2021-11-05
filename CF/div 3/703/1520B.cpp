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
std::vector<int> res;
void gen(ll n) {
	if (n > 1e9)return;
	res.push_back(n);
	int r = n % 10;
	gen(n * 10 + r);
}
void solve() {
	int n, l, r; cin >> n;
	int ret = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] <= n)
			ret++;
	}
	cout << ret << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 9; i++)
		gen(i);
	//for (int x : res)cout << x << endl;
	sort(res.begin(), res.end());
	//cout << res.size() << endl;
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}