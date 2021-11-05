#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define endl "\n"
//template<typename T>
// using ordered_set = tree <
//                     T,
//                     null_type,
//                     less<T>,
//                     rb_tree_tag,
//                     tree_order_statistics_node_update >;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	string g[n + 1];
	for (int i = 0; i < n; i++)
		cin >> g[i];
	std::vector<int> x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == '*') {
				x.push_back(i);
				y.push_back(j);
			}
		}
	}

	int x1 = x[0];
	int y1 = y[0];

	int x3 = x[1];
	int y3 = y[1];

	int x2 = x[0];
	int y2 = y[1];

	int x4 = x[1];
	int y4 = y[0];

	g[x1][y1] = '*';
	g[x2][y2] = '*';
	g[x3][y3] = '*';
	g[x4][y4] = '*';

	if (y[0] == y[1]) {
		if (y[0] == 0) {
			g[x[0]][n - 1] = '*';
			g[x[1]][n - 1] = '*';
		}
		else {
			g[x[0]][0] = '*';
			g[x[1]][0] = '*';
		}

	}
	else if (x[0] == x[1]) {

		if (x[0] == n - 1) {
			g[0][y[0]] = '*';
			g[0][y[1]] = '*';
		}
		else {
			g[n - 1][y[0]] = '*';
			g[n - 1][y[1]] = '*';
		}
	}
	for (int i = 0; i < n; i++)
		cout << g[i] << endl;
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