#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e9, MIN = -(1e9 + 7), MOD = 1e9 + 7;
int findmax(int i, std::vector<int> v) {
	if (i == v.size())
		return MIN;
	return max(v[i], findmax(i + 1, v));
}
void solve() {
	int n; cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << findmax(0, v) << '\n';
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