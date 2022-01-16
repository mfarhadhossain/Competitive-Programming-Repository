#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
typedef pair<int, int> pii;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector< pii >g[MAX];
vector<int>res;
bool vs[MAX];
int n;
void clr() {
	for (int i = 1; i <= n; i++) {
		g[i].clear(); vs[i] = false;
	}
	res.clear();

}
void dfs(int u, int p, int col) {
	vs[u] = 1;
	for (auto x : g[u]) {
		int v = x.first;
		int edge_no = x.second;
		if (v != p && vs[v] == 0) {
			res[edge_no] = col + 2;
			dfs(v, u, col ^ 1);
		}
	}
}
void solve() {
	cin >> n;
	res.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() > 2) {
			cout << "-1\n";
			clr();
			return;
		}
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1) {
			root = i;
			break;
		}
	}

	dfs(root, 0, 0);


	for (int i = 1; i <= n - 1; i++) {
		if (i > 1)cout << " ";
		cout << res[i];
	}
	cout << endl;
	clr();
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}