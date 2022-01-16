#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, m, r, c; cin >> n >> m >> r >> c;

	string g[n + 5];
	bool bad = true;
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
		g[i] = "#" + g[i];
		for (int j = 0; j <= m; j++) {
			if (g[i][j] == 'B') {
				bad = false;
				break;
			}
		}
	}
	if (g[r][c] == 'B') {
		cout << "0\n";
		return;
	}
	if (bad) {
		cout << "-1\n";
		return;
	}

	for (int i = 1; i <= m; i++) {
		if (g[r][i] == 'B') {
			cout << "1\n";
			return;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (g[i][c] == 'B') {
			cout << "1\n";
			return;
		}
	}
	cout << "2\n";
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