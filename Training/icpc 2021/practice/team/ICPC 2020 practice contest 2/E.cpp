#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 3e5 + 7, MOD = 1e9 + 7;
int n, m, par[MAX], sz[MAX], edges[MAX];
void init() {
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1, edges[i] = 0;
}
int find_par(int x) {
	if (x == par[x])
		return x;
	return par[x] = find_par(par[x]);
}
void Union(int u, int v) {
	int par_u = find_par(u);
	int par_v = find_par(v);
	if (par_u != par_v) {
		if (sz[par_v] > sz[par_u]) {
			sz[par_v] += sz[par_u];
			par[par_u] = par_v;
		}
		if (sz[par_v] <= sz[par_u]) {
			sz[par_u] += sz[par_v];
			par[par_v] = par_u;
		}
	}
}
void solve() {
	cin >> n >> m;
	init();
	std::vector<int> x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		Union(x[i], y[i]);
	}
	std::vector<int> taken(n + 1);
	ll res = 0;

	for (int i = 0; i < m; i++) {
		edges[find_par(x[i])]++;
	}
	for (int i = 1; i <= n; i++) {
		if (taken[i])continue;

		taken[i] = 1;
		res += max(0LL, (ll)edges[i] - sz[i]);
	}
	cout << res << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}