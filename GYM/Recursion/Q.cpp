#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int length(ll n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0)	return 1 + length(n / 2);
	return 1 + length(3 * n + 1);
}
void solve() {
	ll n; cin >> n;
	cout << length(n) << endl;
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