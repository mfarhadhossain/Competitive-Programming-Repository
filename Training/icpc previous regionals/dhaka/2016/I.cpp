#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
inline ll BigMod(ll a, ll e, ll mod)
{
	ll num = 1;
	while (e)
	{
		if (e % 2)
		{
			a %= mod;
			num %= mod;
			num = num * a;
			num %= mod;
		}
		e /= 2;
		a %= mod;
		a = a * a;
		a %= mod;
	}
	return num % mod;
}
ll fibo[MAX], res[MAX];
ll solve() {
	ll n, k, m; cin >> n >> k >> m;

	fibo[1] = 2;
	fibo[2] = 3;
	res[1] = BigMod(k, fibo[1], m);
	res[2] = BigMod(k, fibo[2], m);

	for (int i = 3; i <= n; i++) {
		fibo[i] = (fibo[i - 1] % m + fibo[i - 2] % m) % m;
		res[i] = (res[i - 1] * res[i - 2]) % m;
	}
	return res[n];
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {

		cout << "Case " << tc << ": " << solve() << endl;
	}
	return 0;
}