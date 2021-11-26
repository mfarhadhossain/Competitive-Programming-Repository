#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int x, y, k; cin >> x >> y >> k;
	if ( x % k == 0 and y % k == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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