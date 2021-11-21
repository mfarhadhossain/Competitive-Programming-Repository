#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const ll MOD = 1e9 + 7;
int n;
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
ll modOverflow(ll x) {
	x += MOD;
	x %= MOD;
	return x;
}
void solve() {
	cin >> n;
	map<int, int>map;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (map[x] == 0) {
			arr.push_back(x);
		}
		map[x]++;
	}
	ll tot = 0;
	vector<ll>cnt;
	for (int i = 0; i < arr.size(); i++) {
		ll xx = (BigMod(2, map[arr[i]], MOD) - 1);
		xx = modOverflow(xx);
		cnt.push_back(xx);
		tot = (tot % MOD + cnt.back() % MOD);
		tot %= MOD;
		tot = modOverflow(tot);
	}
	//cout<<"tot = "<<tot<<endl;
	ll res = 0;
	for (int i = 0; i < arr.size(); i++) {
		ll curr = tot - cnt[i];
		curr = modOverflow(curr);
		res += (curr * cnt[i]) % MOD;
		res %= MOD;
		res = modOverflow(res);
		//cout<<curr*cnt[i]<<" ";
	}
	res = (res * 500000004) % MOD;

	res = modOverflow(res);
	tot = tot + res;
	tot %= MOD;

	tot = modOverflow(tot);
	cout << tot << endl;
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
