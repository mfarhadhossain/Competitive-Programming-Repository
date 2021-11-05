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
const int MAX = 1e5 + 7, MOD = 1e9 + 7;
int n;
std::vector<int> g[MAX];
ll res[MAX], mem[MAX];
void dfs(int u, int p) {
	res[u] = 1;
	mem[u] = 1;

}
void solve() {
	cin >> n;
	for (int i = 1; i < n = n - 1; i++) {
		int u, v,; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout << res[1] << endl;
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		res[i] = 0;

	}
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