#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll MAX = 1e12 + 10;
// bool good(ll x,ll base){
// 	while(x){
// 		if(x)
// 	}
// }
void solve() {
	ll n; cin >> n;
	set<ll>v;
	v.insert(1);
	for (ll i = 2; i <= 1000000; i++) {
		//cout<<"for "<<i<<" base: ";
		ll curr = 0, b = 1;
		while (curr <= n) {
			curr += b;
			b *= i;
			if (curr > i + 1 && curr < n) {
				v.insert(curr);
			}
		}
		//cout<<endl;
	}
	ll res = 0;
	//sort(v.begin(),v.end());
	for (auto x : v) {
		if (x >= n)break;
		res += x;
		cout << x << endl;
	}
	cout << res << endl;
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