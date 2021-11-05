#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ff first
#define ss second
//using namespace __gnu_pbds;
// #define endl "\n"
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
int n, m;
string g[505];
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
// down = 1
// right = 2
// up = 3
// left = 4
int go(int i, int j, int from, int pr) {
	cout << i << " " << j << endl;
	if (valid(i, j) == 0)return 1e9;
	if (i == n - 1 && j == m - 1)
		return 0;
	int d = g[i][j] - '0';
	int ret = 0;
	if (d == pr && from == 3) {

		ret = 1 + go(i + d, j, 1, d);
		ret = min(ret, 1 + go(i, j + d, 2, d));
		//ret = min(ret, 1 + go(i - d, j, 3, d));
		ret = min(ret, 1 + go(i, j - d, 4, d));
	}
	else if (d == pr && from == 1) {

		//ret = 1 + go(i + d, j, 1, d);
		ret = min(ret, 1 + go(i, j + d, 2, d));
		ret = min(ret, 1 + go(i - d, j, 3, d));
		ret = min(ret, 1 + go(i, j - d, 4, d));
	}
	else if (d == pr && from == 2) {

		ret = 1 + go(i + d, j, 1, d);
		//ret = min(ret, 1 + go(i, j + d, 2, d));
		ret = min(ret, 1 + go(i - d, j, 3, d));
		ret = min(ret, 1 + go(i, j - d, 4, d));
	}
	else if (d == pr && from == 4) {

		ret = 1 + go(i + d, j, 1, d);
		ret = min(ret, 1 + go(i, j + d, 2, d));
		ret = min(ret, 1 + go(i - d, j, 3, d));
		//ret = min(ret, 1 + go(i, j - d, 4, d));
	}
	else {
		ret = 1 + go(i + d, j, 1, d);
		ret = min(ret, 1 + go(i, j + d, 2, d));
		ret = min(ret, 1 + go(i - d, j, 3, d));
		ret = min(ret, 1 + go(i, j - d, 4, d));
	}
	return ret;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	cout << go(0, 0, 0, 0) << endl;
}
int main () {
// #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
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