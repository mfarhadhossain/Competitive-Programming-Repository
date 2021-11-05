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
int n, a[105], tot, dp[105][2000 * 101];
int go(int idx, int sum) {
	if (idx == n) {
		if (sum == tot - sum) {
			return 1;
		}
		return 0;
	}
	if (dp[idx][sum] != -1)
		return dp[idx][sum];
	int ret = go(idx + 1, sum + a[idx]) or go(idx + 1, sum);
	return dp[idx][sum] = ret;
}
void solve() {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; tot += a[i];
	}
	int bad = go(0, 0);
	if (bad == 0) {
		cout << "0\n";
	}
	else {
		cout << "1\n";
		int done = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] & 1) {
				cout << i + 1 << "\n";
				done = 1;
				return;
			}
		}
		if (done == 0) {
			// all elements are even
			int good = 0;
			while (true) {
				good = 0;
				for (int i = 0; i < n; i++) {
					a[i] /= 2;
					if (a[i] & 1) {
						good = i + 1;
						break;
					}
				}
				if (good)break;
			}
			cout << good << endl;
		}
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