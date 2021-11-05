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
bool isprime(ll n) {
	ll x = sqrtl(n);

	for (ll i = 2; i <= x; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
void solve() {
	ll n; cin >> n;
	ll N = n - 1;
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
	cout << ret.size() << endl;
	for (int x : ret) {
		cout << x << " ";
	}
	cout << endl;
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