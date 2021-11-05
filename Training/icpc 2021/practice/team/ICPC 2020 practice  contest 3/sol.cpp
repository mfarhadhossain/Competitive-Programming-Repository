#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
bool dominates(int la, int ca, int lb, int cb) { // B dominates A
	return (lb < la && cb <= ca) or (lb <= la && cb < ca);
}
void solve() {
	int n, res = 0; cin >> n;
	int curr_l = 1e9 + 7 , curr_b = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if (dominates(x, y, curr_l, curr_b) == false) {
			curr_l = x;
			curr_b = y;
			res++;
		}
		else if (dominates(curr_l, curr_b, x, y) == true) {
			curr_l = x;
			curr_b = y;
			res = 1;
		}
		cout << res << endl;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ":\n";
		solve();
	}
	return 0;
}