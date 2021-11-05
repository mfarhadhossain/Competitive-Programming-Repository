#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void go(int i, int left_max, std::vector<int> &v) {
	if (i == v.size())return;
	left_max = max(left_max, v[i]);
	if (i == v.size() - 1) cout << left_max << '\n';
	else cout << left_max << ' ';
	go(i + 1, left_max, v);
}
void solve() {

	int n; cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	go(0, -MOD, v);
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