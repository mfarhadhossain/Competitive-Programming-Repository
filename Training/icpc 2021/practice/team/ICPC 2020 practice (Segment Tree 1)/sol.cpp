#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
bool isprime(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = n + 1; i < m; i++) {
		if (isprime(i) == 1) {
			cout << "NO\n";
			return;
		}
	}
	if (isprime(m) == 0)
		cout << "NO\n";
	else cout << "YES\n";
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