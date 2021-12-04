#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
ll fx(ll x) {
	ll s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}
ll gx(ll x) {
	ll m = 1;
	while (x) {
		m *= ((x % 10) + 1);
		x /= 10;
	}
	return m;
}
void solve() {
	multiset< ll > mul;
	multiset< pair<ll,pair<ll, ll>> > bob;
	multiset< pair<ll,pair<ll, ll>>, greater<pair<ll,pair<ll, ll>>> > alice;
	int q; cin >> q;
	while (q--) {

		int type; cin >> type;
		if (type == 1) {
			ll x; cin >> x;
			ll point = fx(x) * gx(x);


			if (mul.empty()) {
				mul.insert(point);
				alice.insert({x, {-point,point}});
				bob.insert({x, {point,point}});
			}
			else {
				auto it = mul.upper_bound(point);
				auto it_p = it;
				if (it != mul.begin()) {
					it_p = prev(it);
				}
				ll p1 = abs(*it - point);
				ll p2 = abs(*it_p - point);

				ll mn = min(p1, p2);

				mul.insert(point);

				alice.insert({x, {-mn,point}} );
				bob.insert({x, {mn,point}} );
			}
		}
		else if (type == 2) {
			if (alice.empty()) {
				cout << "-1\n";
				continue;
			}
			pair<ll,pair<ll, ll>> it = *alice.begin();
			cout << (-it.second.first) << endl;
			alice.erase(alice.find(it));
			bob.erase(bob.find({it.first, {-it.second.first,it.second.second}}));
			mul.erase(mul.find(it.second.second));
		}
		else {
			if (bob.empty()) {
				cout << "-1\n";
				continue;
			}

			pair<ll,pair<ll, ll>> it = *bob.begin();
			cout << (it.second.first) << endl;
			bob.erase(bob.find(it));
			alice.erase(alice.find({it.first, {-it.second.first,it.second.second}}));
			mul.erase(mul.find(it.second.second));
		}
	}
}
int  main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case " << tc << ":\n";
		solve();
	}
	return 0;
}