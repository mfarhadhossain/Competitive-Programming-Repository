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
const int MAX = 1e6, MOD = 1e9 + 7;
int res[505][505], n, cnt;
bool valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= n;
}
void dfs(int i, int j, int val) {
	//cout << i << "," << j << " val " << val << " cnt = " << cnt << endl;
	if (valid(i, j) == 0 or cnt == 0 or res[i][j])return;
	if (cnt > 0) {
		res[i][j] = val;
		cnt--;
	}
	else return;
	dfs(i, j - 1, val);
	dfs(i + 1, j, val);
}
void solve() {
	cin >> n;
	std::vector<int> perm(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> perm[i];
	}

	for (int i = 1; i <= n; i++) {
		cnt = perm[i];
		dfs(i, i, perm[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << res[i][j] << " ";
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