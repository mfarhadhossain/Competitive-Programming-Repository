#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int bits(int x) {
	if (x == 0)return 0;
	return 1 + bits(x / 2);
}
void solve() {
	ll C; cin >> C;
	ll b = bits(C);
	b = 1LL << b;
	b = b - 1;

	b /= 2;

	ll a = C ^ b;
	a = a * b;
	cout << a << endl;
}
// ll solve2(int C) {

// 	int d = bits(C);

// 	d = 1LL << d;
// 	ll mx = 0;
// 	for (int i = 1; i < d; i++) {
// 		ll a = i;
// 		ll b = a ^ C;

// 		mx = max(mx, a * b);

// 	}
// 	return mx;
// }
int main () {
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}