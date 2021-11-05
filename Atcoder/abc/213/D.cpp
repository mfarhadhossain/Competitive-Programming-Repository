#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
// starts here
const int MAX = 2e5 + 7, MOD = 1e9 + 7;
std::vector<int> g[MAX], res;
void dfs(int u, int p) {
	res.push_back(u);
	for (auto v : g[u]) {
		if (v != p) {
			dfs(v, u);
			res.push_back(u);
		}
	}
}
void solve() {
	int n, u, v; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	dfs(1, 0);
	for (int i = 0; i < res.size(); i++) {
		if (i)cout << " ";
		cout << res[i];
	}
	cout << "\n";
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