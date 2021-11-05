#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
void print(std::vector<ll> v) {
	cout << v.size() << "\n";
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}
bool isprime(ll n) {
	ll x = sqrtl(n);

	for (ll i = 2; i <= x; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
std::vector<ll> brute(ll n) {
	int N = (1LL << n);
	std::vector<ll> res;
	int mx = 0;
	for (int mask = 0; mask < N; mask++) {
		std::vector<ll> v;
		for (int j = 0; j < n; j++) {
			if ((1LL << j)&mask) {
				v.push_back(j + 1);
			}
		}
		if (v.size()) {
			ll product = v[0];
			for (int j = 1; j < v.size(); j++) {
				product *= v[j];
				product %= n;
			}
			if (product == 1 && v.size() > mx) {
				mx = v.size();
				res = v;
			}
		}
	}
	return res;
}
void solve() {
	ll n;
	for (int xx = 2; xx <= 24; xx++) {
		n = xx; ll N = n - 1;
		std::vector<int> res;
		for (int i = 1; i <= N; i++) {
			if (gcd(i, n) == 1) {
				res.push_back(i);
			}
		}
		//cout << res.size() << endl;
		std::vector<ll> ret, temp;
		ll haha = 1;
		for (int x : res) {
			temp.push_back(x);
			haha = ((haha % n) * (x % n)) % n;
			if (haha == 1) {
				ret = temp;
			}
		}
		std::vector<ll> v = brute(n);
		if (ret != v) {
			cout << "for " << n << endl;
			cout << "brute: ";
			print(v);
			cout << "res: ";
			print(ret);
		}
	}

}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}