#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int r) {
	// random 0 -> r - 1
	int p = (int)rng() % r;
	if (p < 0) p += r;
	return p;
}

int random(int l, int r) {
	// Generate random number l -> r
	return random(r - l + 1) + l;
}
string fun(int x) {
	if (x % 3 == 0) {
		return "HOME";
	}
	if (x % 3 == 1) {
		return "AWAY";
	}
	if (x % 3 == 2) {
		return "DRAW";
	}
	return "SKIP";
}
void solve() {
	std::vector<double> v(20);
	for (int i = 0; i < 8; i++) {
		cin >> v[i];
	}
	cout << fun(random(0, MOD)) << endl;
	for (int i = 0; i < 16; i++) {
		cin >> v[i];
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}