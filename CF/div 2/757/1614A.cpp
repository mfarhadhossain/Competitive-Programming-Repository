#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n, l, r, k; cin >> n >> l >> r >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n && k > 0; i++) {

		if (v[i] >= l && v[i] <= r && k - v[i] >= 0) {
			res++;
			k -= v[i];
		}
	}
	cout << res << endl;
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}