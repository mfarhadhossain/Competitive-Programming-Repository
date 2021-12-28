#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5 + 10, MOD = 1e9 + 7;
int dp[MAX][30];
void solve() {
	int l, r; cin >> l >> r;

	int res = MOD;

	for (int i = 0; i < 30; i++) {
		if (dp[r][i] == 0)continue;
		int ret = dp[r][i] - dp[l - 1][i];
		res = min(res, (r - l + 1) - ret);
	}
	cout << res << endl;
}
bool on(int x, int i) {
	return x & (1 << i);
}
int  main ()
{
	for (int i = 1; i <= 200000; i++) {
		for (int j = 0; j < 20; j++) {
			if ( on(i, j) ) {
				dp[i][j] = 1;
			}
			dp[i][j] += dp[i - 1][j];
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}