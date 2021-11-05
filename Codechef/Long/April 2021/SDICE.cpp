#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	ll n; cin >> n;
	if (n == 1) {
		cout << 21 - 1 << endl;
	}
	else if (n == 2) {
		cout << 21 * 2 - (1 + 2 + 1 + 2) << endl;
	}
	else if (n == 3) {

		cout << 21 * 3 - (1 + 2 + 3 + 1 + 2 + 1) << endl;
	}
	else if (n == 4) {

		cout << 21 * 4 - (1 + 2 + 3 + 1 + 2 + 3 + 1 + 2 + 1) << endl;
	}
	else {
		cout << 21 * n - (n * (n - 1) / 2) << endl;
	}
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}