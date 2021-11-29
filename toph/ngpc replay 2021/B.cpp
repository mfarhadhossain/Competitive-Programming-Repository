#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
ll pw[MAX];
ll fun(ll odd, ll even, ll n) {
	if(odd==0)return 0;
	//cout<<"o "<<odd<<" e "<<even<<endl;
	ll tot = (pw[odd-1]*(pw[even]))%MOD;
	return tot;
}
void solve() {
	int n, odd = 0, even = 0, q; cin >> n >> q;
	vector<int>v(n + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i] % 2)odd++;
		else even++;

		pw[i] = (pw[i - 1] * 2) % MOD;
		pw[i] %= MOD;
	}
	//cout<<fun(odd, even, n)<<endl;
	for (int i = 0; i < q; i++) {
		int x, tmp; cin >> x >> tmp;

		if (tmp % 2 == 0 && v[x] % 2) {
			even++;
			odd--;
		}
		else if (tmp % 2 && v[x] % 2 == 0) {
			odd++;
			even--;
		}

		v[x] = tmp;

		cout << fun(odd, even, n) << endl;
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}