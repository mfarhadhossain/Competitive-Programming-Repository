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
const int MAX = 1e6, MOD = 1e9 + 7;
std::vector<int> sure, maybe;
int h, w;
string g[2005];
bool valid(int i, int j) {
	return (i >= 0 && i < h && j >= 0 && j < w);
}
pair<int, int> fun1(pair<int, int> X, pair<int, int> Y) {
	int df1 = X.first - X.second;
	int df2 = Y.first - Y.second;
	if (df1 > df2)return X;
	if (df1 < df2)return Y;
	if (X.first > Y.first)
		return X;
	return Y;
}
pair<int, int> fun2(pair<int, int> X, pair<int, int> Y) {
	int df1 = X.first - X.second;
	int df2 = Y.first - Y.second;
	if (df1 < df2)return X;
	if (df1 > df2)return Y;
	if (X.first < Y.first)
		return X;
	return Y;
}
pair<int, int> go(int i, int j, int turn) {
	if (i == h - 1 && j == w - 1) {
		if (i == 0 && j == 0)
			return {0, 0};
		if (g[i][j] == '-') {
			if (turn == 0)return { -1, 0};
			return {0, -1};
		}
		if (g[i][j] == '+') {
			if (turn == 0)return {1, 0};
			return {0, 1};
		}
	}
	int sc = 0;
	pair<int, int>ret(0, 0);
	if (i != 0 && j != 0) {
		if (g[i][j] == '-')sc--;
		if (g[i][j] == '+')sc++;
	}
	if (turn == 0) { // Takahashi
		if (valid(i + 1, j)) {
			ret = go(i + 1, j, turn ^ 1);
			ret.first += sc;
		}
		if (valid(i, j + 1)) {
			auto ret2 = go(i, j + 1, turn ^ 1);
			ret2.first += sc;

			ret = fun1(ret, ret2);
		}
	}
	else { // Aoki

		if (valid(i + 1, j)) {
			ret = go(i + 1, j, turn ^ 1);
			ret.second += sc;
		}
		if (valid(i, j + 1)) {
			auto ret2 = go(i, j + 1, turn ^ 1);
			ret2.second += sc;
			ret = fun2(ret, ret2);
		}
		//ret *= -1;
	}

	cout << "@ (" << i << "," << j << ") " << ret.first << " " << ret.second << endl;
	return ret;
}
void solve() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> g[i];
	}
	auto ret = go(0, 0, 0);
	cout << ret.first << " " << ret.second << endl;
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