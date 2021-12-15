#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, mx = 0; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	int good = 1;
	for (int i = 1; i < n; i++) {
		if (v[0] != v[i]) {
			good = 0;
			break;
		}
	}
	if (good == 1) {
		cout << "0\n";
	}
	else if (mx == v[n - 1]) {
		cout << "1\n";
	}
	else {
		cout << "2\n";
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