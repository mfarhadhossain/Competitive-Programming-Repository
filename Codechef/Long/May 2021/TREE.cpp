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
const int MAX = 3e5 + 7, MOD = 1e9 + 7;
ll subtree[MAX], curr[MAX], n, X;
std::vector<int> g[MAX];
void dfs(int u, int p) {
	// if (g[u].size() == 1)
	// 	return 1;
	//std::vector< pair<ll, ll> > temp;
	for (int v : g[u]) {
		if (v == p)continue;
		//temp.push_back({subtree[v], -v});
		dfs(v, u);
	}

	std::vector< pair<ll, ll> > temp;
	for (int v : g[u]) {
		if (v == p)continue;
		temp.push_back({subtree[v], v});
	}
	sort(temp.rbegin(), temp.rend());
	ll ret = 0, id = 1;
	for (auto x : temp) {
		curr[x.second] = id++;
	}
	for (int v : g[u]) {
		if (v == p)continue;
		subtree[u] += (subtree[v] * curr[v]);
	}
	//subtree[u] = ret + 1;
}
void solve() {
	cin >> n >> X;
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		subtree[i] = 1;
		curr[i] = 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	subtree[1] %= MOD;
	ll res = ((X % MOD) * subtree[1] % MOD) % MOD;
	res += MOD;
	res %= MOD;
	cout << res << endl;

}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}