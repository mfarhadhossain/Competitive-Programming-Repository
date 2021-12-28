#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool ok(int x1, int y1, int x2, int y2) {
	if (x1 == x2 or y1 == y2) return true;
	return false;
}
void solve() {
	int n, m, rb, cb, rd, cd;
	cin >> n >> m >> rb >> cb >> rd >> cd;

	int dr = 1 , dc = 1, res = 0;

	while (ok(rb, cb, rd, cd) == 0) {
		if (rb == n && dr == 1) {
			dr = -1;
		}
		else if (rb == 1 && dr == -1) {
			dr = 1;
		}

		if (cb == m && dc == 1) {
			dc = -1;
		}
		else if (cb == 1 && dc == -1) {
			dc = 1;
		}
		rb += dr;
		cb += dc;
		res++;
	}
	cout << res << endl;
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