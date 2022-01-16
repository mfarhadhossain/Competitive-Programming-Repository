#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;

int distance(int r, int c, int x, int y) {
	return abs(r - x) + abs(c - y);
}
void solve() {
	int n, m, r, c; cin >> n >> m;
	vector<int>res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int d = max({distance(i, j, 1, 1), distance(i, j, n, m), distance(i, j, n, 1), distance(i, j, 1, m)});
			res.push_back(d);
		}
	}
	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++) {
		if (i)cout << " ";
		cout << res[i];
	}
	cout << endl;
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