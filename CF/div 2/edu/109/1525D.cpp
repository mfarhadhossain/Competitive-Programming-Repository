#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
const int MAX = 5005, MOD = 1e9 + 7;

std::vector<int> A, B;
int dp[MAX][MAX];
int go(int idx, int cnt) {
	//cout << idx << " " << cnt << endl;

	if (idx == A.size()) {
		return 0;
	}
	if (cnt == B.size())
		return 1e9;

	if (dp[idx][cnt] != -1)
		return dp[idx][cnt];
	int ret = abs(A[idx] - B[cnt]) + go(idx + 1, cnt + 1);
	ret = min(ret, go(idx, cnt + 1));
	return dp[idx][cnt] = ret;
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == 1) {
			A.push_back(i);
		}
		else {
			B.push_back(i);
		}
	}
	if (A.size() > B.size())
		swap(A, B);

	memset(dp, -1, sizeof dp);

	int res = go(0, 0);
	cout << res << endl;
	A.clear();
	B.clear();
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