#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int x, y;
string s;
// pr 1 = C
// pr 2 = J
int dp[1005][5];
int dfs(int idx, int pr) {
	if (idx == s.size()) {
		return 0;
	}
	if (dp[idx][pr] != -1)
		return dp[idx][pr];
	int ret = 1e9;
	if (s[idx] == '?') {
		// J
		int c = 0;
		if (pr == 1)
			c = x;
		else
			c = 0;
		ret = min(ret, c + dfs(idx + 1, 2));
		// C
		if (pr == 2)
			c = y;
		else
			c = 0;
		ret = min(ret, c + dfs(idx + 1, 1));
	}
	else {

		int c, id = 0;

		if (pr == 1 && s[idx] == 'J')
			c = x, id = 2;
		else if (pr == 1 && s[idx] == 'C')
			c = 0, id = 1;
		else if (pr == 2 && s[idx] == 'J')
			c = 0, id = 2;
		else if (pr == 2 && s[idx] == 'C')
			c = y, id = 1;
		else if (pr == 0 && s[idx] == 'C')
			c = 0, id = 1;
		else if (pr == 0 && s[idx] == 'J')
			c = 0, id = 2;

		ret = min(ret, c + dfs(idx + 1, id));
	}

	return dp[idx][pr] = ret;
}
void solve() {
	cin >> x >> y >> s;
	memset(dp, -1, sizeof dp);
	cout << dfs(0, 0) << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}