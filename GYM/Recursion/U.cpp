#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int knapsack(int i, int curr, std::vector<int> &v, std::vector<int> &w) {
	if (i == v.size())
		return 0;
	int ret = 0;
	if (curr - w[i] >= 0 ) {
		ret = v[i] + knapsack(i + 1, curr - w[i], v, w);
	}
	ret = max(ret, knapsack(i + 1, curr, v, w));
	return ret;
}
void solve() {
	int n, W;
	cin >> n >> W;
	std::vector<int> w(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cout << knapsack(0, W, v, w) << '\n';
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