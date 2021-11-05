#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void sum(int i, int j, int n, int m, std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b) {
	if (i >= n)
		return;

	if (j == m - 1) {

		cout << a[i][j] + b[i][j] << '\n';
		sum(i + 1, 0, n, m, a, b);
	}
	else {

		cout << a[i][j] + b[i][j] << ' ';
		sum(i, j + 1, n, m, a, b);
	}
}
void solve() {
	int n, m; cin >> n >> m;
	std::vector<vector<int>> a, b;
	for (int i = 0; i < n; i++) {
		std::vector<int> temp;
		for (int j = 0; j < m; j++)
		{
			int x; cin >> x;
			temp.push_back(x);
		}
		a.emplace_back(temp);
	}
	for (int i = 0; i < n; i++) {
		std::vector<int> temp;
		for (int j = 0; j < m; j++)
		{
			int x; cin >> x;
			temp.push_back(x);
		}
		b.emplace_back(temp);
	}
	sum(0, 0, n, m, a, b);
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