#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e6 + 10;
void solve() {
	int m; cin >> m;
	vector<int>bad(MAX);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		
		for (int j = x; j < MAX; j += x)
			bad[j]++;
	}
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << m - bad[x] << endl;
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin>>t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}
