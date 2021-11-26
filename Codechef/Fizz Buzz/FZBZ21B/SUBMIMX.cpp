#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX = 1e5 + 10;
ll fun(ll x) {
	return x * (x + 1ll) / 2ll;
}
void solve() {
	ll n, m; cin >> n >> m;
	ll zero = n - m;
	ll one = m;
	if (zero == 0) {
		cout << "0\n";
		return;
	}
	if (one == 0) {
		cout << fun(zero) << endl;
		return;
	}
	if (one >= zero - 1) {
		cout << zero << endl;
		return;
	}
	//1<=one<zero-1
	ll quo = zero / (one + 1);

	ll rem = zero - quo * (one + 1);

	ll p = rem;

	ll q = (one + 1) - rem;

	ll res = p * fun(quo + 1) + q * fun(quo);
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