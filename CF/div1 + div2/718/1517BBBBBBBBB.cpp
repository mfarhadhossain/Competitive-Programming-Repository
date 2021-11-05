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
int a[105][105], res[105][105];
bool taken[105][105];
void solve() {
	int n, m; cin >> n >> m;
	std::vector< pair<int, pair<int, int> >> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			v.push_back({a[i][j], {i, j}});
			taken[i][j] = 0;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= m; i++) {
		int val = v[i - 1].first;
		int x = v[i - 1].second.first;
		int y = v[i - 1].second.second;
		res[x][i] = val;
		taken[x][y] = 1;
	}
	std::vector<int> row[n + 5];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (taken[i][j] == 0) {
				row[i].push_back(a[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (res[i][j] == 0) {
				res[i][j] = row[i].back();
				row[i].pop_back();
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j] << " ";
			res[i][j] = 0;
			taken[i][j] = 0;
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

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}