#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MOD = 1e9 + 7;
inline ll BigMod(ll a, ll e, ll mod) {ll num = 1; while (e) {if (e % 2) {a %= mod; num %= mod; num = num * a; num %= mod;} e /= 2; a %= mod; a = a * a; a %= mod;} return num % mod;}
void solve() {
	int n, m; cin >> n >> m;
	ll final_orr = 0;
	for (int i = 0; i < m; i++) {
		int l, r, orr; cin >> l >> r >> orr;
		final_orr |= orr;
	}
	ll res = (BigMod(2LL, n - 1, MOD) * final_orr) % MOD;
	res += MOD;
	res %= MOD;
	cout << res << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}