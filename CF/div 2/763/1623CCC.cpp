#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool possible(vector<ll>&tmp, ll x) {
	int n = tmp.size();
	vector<ll>bap(n), dada(n);
	for (int i = n - 1; i >= 2; i--) {
		ll dite_parbo = min(tmp[i], tmp[i] + bap[i] + dada[i] - x);
		if (dite_parbo < 0)return false;
		ll d = dite_parbo / 3;
		bap[i - 1] += d;
		dada[i - 2] += 2 * d;
	}
	for (int i = 0; i < n; i++) {
		if (tmp[i] + bap[i] + dada[i] < x)return false;
	}
	return true;
}
void solve() {
	int n; cin >> n;
	ll res = 1, lo = LLONG_MAX , hi = LLONG_MIN;
	vector<ll>h(n);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		lo = min(lo, h[i]);
		hi = max(hi, h[i]);
	}
	res = lo;
	while (lo <= hi) {
		ll md = (lo + hi) / 2;

		if (possible(h, md)) {
			lo = md + 1;
			res = max(res, md);
		}
		else {
			hi = md - 1;
		}
	}
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