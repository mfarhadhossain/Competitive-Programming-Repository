#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	vector<int> v(n), cnt(107);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < 0)cnt[-v[i]]++;
		else cnt[v[i]]++;
	}
	int res = 0;
	if (cnt[0])res++;
	for (int i = 1; i <= 100; i++) {
		if (cnt[i] == 0)continue;

		if (cnt[i] > 1) {
			res += 2;
		}
		else {
			res++;
		}

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