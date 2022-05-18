#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int dp[105][105][105];
int go(int l, int r, int max_id, vector<int>&dq) {
	if (l > r)return 0;
	if (dp[l][r][max_id] != -1)
		return dp[l][r][max_id];

	int score1 = 0, nmax_id1 = max_id;
	if (dq[l] >= dq[max_id])score1 = 1, nmax_id1 = l;

	int ret1 = go(l + 1, r, nmax_id1, dq) + score1;
	int score2 = 0, nmax_id2 = max_id;
	if (dq[r] >= dq[max_id])score2 = 1, nmax_id2 = r;
	int ret2 = go(l, r - 1, nmax_id2, dq) + score2;
	return dp[l][r][max_id] = max(ret1, ret2);
}
void solve() {
	memset(dp, -1, sizeof dp);

	int n; cin >> n;
	vector<int>dq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		dq.push_back(x);
	}
	dq.push_back(-1e9);
	cout << go(0, n - 1, n, dq) << endl;

}
int  main ()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}