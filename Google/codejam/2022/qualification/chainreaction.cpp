#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 7, MOD = 1e9 + 7;
vector<int>g[MAX + 7];
void solve() {
	int n; cin >> n;
	vector<int>f(n + 5), p(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	vector<int>in(MAX + 7);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == 0)p[i] = MAX;
		g[i].push_back(p[i]);
		in[p[i]]++;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {

			// now find highest and second highest value of the path
		}
	}
	cout << res << endl;
	for (int i = 1; i <= n; i++)
		g[i].clear();
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}