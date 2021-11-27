#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;
ll lcm(ll x, ll y) {
	ll g = __gcd(x, y);
	x/=g;
	y/=g;
	return x*y;
}
void brute() {
	ll n; cin >> n;
	ll df, mn = LLONG_MAX, nn, ii;
	for (ll i = n + 1; i <= 1e6; i++) {
		if (i % n) {
			df = __gcd(i, n) - lcm(i, n);
			if (df < 0)df = df * (-1);
			if (df < mn) {
				mn = df;
				nn = n;
				ii = i;
			}
		}
	}
	cout << mn << " " << nn << " " << ii << endl;
}
void solve() {
	ll n; cin >> n;
	ll res = 0, df, mn = LLONG_MAX;

	df =  lcm(n + 1, n) - __gcd(n + 1, n);
	if (df < mn) {
		mn = df;
		res = n+1;
	}
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ll a = i;
			ll b = n / i;
			ll tmp = (a + 1) * b;
			df = lcm(tmp, n)-__gcd(tmp, n);
			if (df < mn && tmp % n) {
				mn = df;
				res = tmp;
			}
			tmp = a * (b + 1);
			df =  lcm(tmp, n) -__gcd(tmp, n);
			if (df < mn && tmp % n) {
				mn = df;
				res = tmp;
			}

		}
	}
	cout << res << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){

		solve();
		brute();
	}
	return 0;
}