#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	vector<int>l(n + 1), r(n + 1);
	vector<vector<bool>>vis(n + 1, vector<bool>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		vis[l[i]][r[i]] = 1;
	}
	vector<int>res(n + 1);
	for (int i = 0; i < n; i++) {
		if (l[i] == r[i]) {
			res[i] = l[i];
		}
		else {

			for (int j = l[i]; j <= r[i]; j++) {
				if ( ( l[i] == j or vis[l[i]][j - 1]) and (j == r[i] or vis[j + 1][r[i]])) {
					res[i] = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << l[i] << " " << r[i] << " " << res[i] << endl;
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