#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void print(int x, int n) {
	if (x == 0) {
		return;
	}
	if (x & 1) {
		print(x / 2, n);
		if (x == n)
			cout << "1\n";
		else cout << "1";
	}
	else {

		print(x / 2, n);
		if (x == n)
			cout << "0\n";
		else cout << "0";
	}
}
void solve() {
	int n; cin >> n;
	print(n, n);
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}