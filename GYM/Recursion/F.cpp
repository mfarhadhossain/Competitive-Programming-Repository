#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void print(int idx, std::vector<int> v) {
	if (idx == v.size())
		return;
	print(idx + 1, v);
	if ( idx % 2 == 0) {
		if (idx == 0)
			cout << v[idx] << '\n';
		else
			cout << v[idx] << ' ';
	}
}
void solve() {
	int n; cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	print(0, v);
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