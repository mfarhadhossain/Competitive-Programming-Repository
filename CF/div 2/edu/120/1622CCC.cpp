#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
ll n, k;
bool possible(vector<ll>&v, ll minimum, ll sum) {
	if (sum <= k)return true;
	ll step = 0;
	for (int i = n - 1 ; i >= 1 && sum > k; i--) {
		if (v[i] > minimum) {
			sum -= v[i];
			sum += minimum;
			step++;
		}
	}
	if (sum <= k) return true;
	return false;
}
ll calc(vector<ll>&v, ll minimum, ll sum) {
	if (sum <= k)return 0;
	ll step = 0;
	for (int i = n - 1 ; i >= 1 && sum > k; i--) {
		if (v[i] > minimum) {
			sum -= v[i];
			sum += minimum;
			step++;
		}
	}
	if (sum <= k) return step;
	return 1e18;
}
void solve() {
	cin >> n >> k;
	vector<ll>v(n);
	ll sum = 0, res = 1e18;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum <= k) {
		cout << "0\n";
		return;
	}
	sort(v.begin(), v.end());

	res = min(res,sum-k);
	ll lo = LLONG_MIN/10, hi = v[0];
	while (hi - lo > 5) {
		ll mid = (lo + hi) / 2;
		ll d = v[0] - mid;
		if (possible(v, mid, sum - d)) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	for (ll i = min(v[0], hi + 1000); i >= lo - 1000; i--) {
		ll d = v[0] - i;
		//if(possible(v,i,sum-d))
		res = min(res, d + calc(v, i, sum - d));
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