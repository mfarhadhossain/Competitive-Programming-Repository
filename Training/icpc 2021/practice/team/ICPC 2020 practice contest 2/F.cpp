#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
inline ll LPOW(ll a, ll e)
{
	ll num = 1;
	while (e)
	{
		if (e % 2)
		{
			num = num * a;
		}
		e /= 2;
		a = a * a;
	}
	return num;
}
ll multiples(ll n, ll x) {
	return n / x;
}

void gen(int n, int k, int ret) {
	int res = 0; //cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int d = pow(i * 1.0, 1.0 / (k * 1.0));

		if (i % d == 0 ) {
			res++;
		}
	}
	if (ret != res) {
		cout << n << "," << k << " gen = " << res << " solve = " << ret << endl;
		return;
	}
	else puts("");
}
void solve() {
	ll n, k; cin >> n >> k;
	ll ok = pow(n * 1.0, 1.0 / (k * 1.0));
	if (ok == 1 or k == 1) {
		cout << n << "\n";
		return;
	}
	ll left = 0, rgt = 1, res = 0;
	for (ll i = 1; i <= ok; i++) {
		rgt = LPOW(i + 1, k) - 1;
		rgt = min(rgt, n);
		//cout << left << " " << rgt << endl;
		ll ret = max(0LL, multiples(rgt, i) - multiples(left, i));
		res += ret;
		left = rgt;
	}
	cout << res << "\n";
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}