#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
ll fun(ll health,ll damage){
	ll ret = health/damage;
	if(health%damage)ret++;
	return ret;
}
void solve() {
	ll Hc, Dc; cin>> Hc >> Dc;
	ll Hm, Dm; cin>> Hm >> Dm;
	ll k,w,a; // w = weapon upgrade, a = armor
	cin>>k>>w>>a;

	for(ll w1 = 0 ;w1 <= k;w1++){
		ll a1 = k - w1;

		ll dead_carp = fun(Hc+a1*a,Dm);
		ll dead_mons = fun(Hm,Dc+w1*w);
		if(dead_carp>=dead_mons){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
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