#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int n;
int dfs(int x) {
	if (x == 0)return 0;
	if (x < 0)return 1e9;
	int xx = x, mx = 0;
	while (x > 0) {
		int r = x % 10;
		mx = max(mx, r);
		x /= 10;
	}
	return 1 + dfs(xx - mx);
}
void solve() {
	cin >> n;
	cout << dfs(n) << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	while (t--)solve();
	return 0;
}