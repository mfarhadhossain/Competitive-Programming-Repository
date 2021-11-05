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
const int MAX = 505, MOD = 1e9 + 7;
int Dx[] = { -1, 0, 0, 1};
int Dy[] = { 0, 1, -1, 0};
int n, m, k;
ll daane[MAX][MAX], baame[MAX][MAX], nice[MAX][MAX], upore[MAX][MAX];
ll dp[MAX][MAX][22];
bool valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}
ll dfs(int i, int j, int step, int i1, int j1) {
	if (step == k) {
		if (i == i1 && j == j1)
			return dp[i][j][step] = 0;
		return dp[i][j][step] = 1e18;
	}
	//if (dp[i][j][step])return dp[i][j][step];

	ll ret = 1e18;
	// daane
	if (valid(i, j + 1))
		ret = min(ret, daane[i][j] + dfs(i, j + 1, step + 1, i1, j1));
	// baame
	if (valid(i, j - 1))
		ret = min(ret, baame[i][j] + dfs(i, j - 1, step + 1, i1, j1));
	// upor
	if (valid(i - 1, j))
		ret = min(ret, upore[i][j] + dfs(i - 1, j, step + 1, i1, j1));
	// nice
	if (valid(i + 1, j))
		ret = min(ret, nice[i][j] + dfs(i + 1, j, step + 1, i1, j1));
	return dp[i][j][step] = ret;
}
void solve() {
	cin >> n >> m >> k;

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		for (int kk = 1; kk <= k; kk++)
	// 			dp[i][j][kk] = -1LL;
	// 	}
	// }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 1; j++) {
			cin >> daane[i][j];
			baame[i][j + 1] = daane[i][j];
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> nice[i][j];
			upore[i + 1][j] = nice[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll ret = dfs(i, j, 0, i, j);
			if (ret == 1e18)ret = -1;
			cout << ret << " ";
		}
		cout << endl;
	}

}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
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