#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n, m; cin >> n >> m;

	string g[n + 5];
	for (int i = 0; i < n; i++)
		cin >> g[i];
	pair<int, int> curr(0, 0);
	int res = 0;
	while (curr != make_pair(n - 1, m - 1) ) {
		//cout << curr.first << " " << curr.second << endl;
		if (g[curr.first][curr.second] == '*') {
			res++;
		}
		int mn = 100, x_ = 0, y_ = 0;
		for (int i = curr.first; i < n; i++) {
			for (int j = curr.second; j < m; j++) {
				if ( curr == make_pair(i, j))continue;

				if (g[i][j] == '*') {
					int d = i - curr.first + j - curr.second;
					if (d < mn) {
						mn = d;
						x_ = i, y_ = j;
					}
				}
			}
		}
		if (mn == 100) {
			break;
		}
		curr = {x_, y_};
	}
	if (g[n - 1][m - 1] == '*')res++;
	cout << res << endl;
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}