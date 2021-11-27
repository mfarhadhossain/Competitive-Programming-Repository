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
ll brute(ll n) {
	ll df, mn = LLONG_MAX, nn, ii;
	for (ll i = n + 1; i <= 2000000; i++) {
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
	return ii;
}
ll solve(ll n) {
	//ll n; cin >> n;
	ll res = 0, df, mn = LLONG_MAX;

	df = __gcd(n + 1, n) - lcm(n + 1, n);
	if (df < 0)df = df * (-1);
	if (df < mn) {
		mn = df;
		res = n+1;
	}
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ll a = i;
			ll b = n / i;
			ll tmp = (a + 1) * b;
			df = __gcd(tmp, n) - lcm(tmp, n);
			if (df < 0)df = df * (-1);
			if (df < mn && tmp % n) {
				mn = df;
				res = tmp;
			}
			tmp = a * (b + 1);
			df = __gcd(tmp, n) - lcm(tmp, n);
			if (df < 0)df = df * (-1);
			if (df < mn && tmp % n) {
				mn = df;
				res = tmp;
			}

		}
	}
	//cout << res << endl;
	return res;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// for(int i=2;i<=100;i++){
	// 	int b = brute(i);
	// 	int s = solve(i);
	// 	if(s!=b){
	// 		cout<<"bad : "<<i<<endl;
	// 	}
	// 	else{
	// 		cout<<"g "<<i<<" "<<s<<endl;
	// 	}
	// }
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		ll n;cin>>n;
		cout<<brute(n)<<endl;
	}
	return 0;
}