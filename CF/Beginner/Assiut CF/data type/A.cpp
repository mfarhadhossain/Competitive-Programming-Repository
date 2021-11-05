#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
#define pi acos(-1.0)
void solve() {
	ll n, k; cin >> n >> k;
	ll a; cin >> a;
	ll g = gcd(a, n);
	a /= g;
	n /= g;
	g = gcd(a, k);
	a /= g;
	k /= g;
	if (a > 1) {
		cout << "double\n";
	}
	else if (n * k > 2147483647) {
		cout << "long long\n";
	}
	else {
		cout << "int\n";
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}