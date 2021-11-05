#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int go(ll curr, ll N) {
	if (curr > N) return 0;
	if (curr == N) return 1;
	return go(curr * 10, N) | go(curr * 20, N);
}
void solve() {
	ll N; cin >> N;
	if (go(1LL, N)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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