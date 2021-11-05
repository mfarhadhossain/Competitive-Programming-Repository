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
map<int, std::vector<int>>mapp;
ll des(std::vector<int> v, std::vector<int> perm) {
	ll mx = v[perm[0]], mn = v[perm[0]];
	ll res = 0;
	for (int i = 1; i < v.size(); i++) {
		mx = max(mx, 1LL * v[perm[i]]);
		mn = min(mn, 1LL * v[perm[i]]);
		res += mx - mn;
	}
	mapp[res] = perm;
	return res;
}
void solve() {
	int n, x; cin >> n;
	std::vector<int>v(n), perm;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		perm.push_back(i);
	}
	ll mn = 1e18;
	std::vector<int> temp = perm;
	do {
		//cout << "for: ";
		//for (int x : perm)cout << v[x] << " ";
		//cout << endl;
		//for (int x : perm)cout << x << " ";
		//cout << endl;
		//cout << "fun = " << des(v, perm) << endl;
		mn = min(mn, des(v, perm));

	} while (next_permutation(perm.begin(), perm.end()));
	cout << "min = " << mn << endl;
	do {
		//cout << "for: ";
		//for (int x : perm)cout << v[x] << " ";
		//cout << endl;
		//for (int x : perm)cout << x << " ";
		//cout << endl;
		//cout << "fun = " << des(v, perm) << endl;
		if (mn == des(v, temp)) {
			for (int x : temp)cout << v[x] << " ";
			cout << endl;
		}

	} while (next_permutation(temp.begin(), temp.end()));


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