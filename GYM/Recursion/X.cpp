#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e9 + 7;
int go(int i, int j, int n, int m, std::vector<std::vector<int>> &ar) {
	if (i >= n || j >= m)
		return -MAX;
	if (i == n - 1 && j == m - 1) {
		return ar[i][j];
	}
	return ar[i][j] + max(go(i + 1, j, n, m, ar), go(i, j + 1, n, m, ar));
}
void solve() {
	int n, m; cin >> n >> m;
	std::vector<std::vector<int>> ar;
	for (int i = 0; i < n; i++) {
		std::vector<int> temp;
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			temp.push_back(x);
		}
		ar.push_back(temp);
	}
	cout << go(0, 0, n, m, ar) << '\n';
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