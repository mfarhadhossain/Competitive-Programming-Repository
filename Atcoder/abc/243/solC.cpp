#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;

	vector< pair<pair<int, int>,int> >v(n);


	for (int i = 0; i < n; i++){
		cin >> v[i].ff.ff >> v[i].ff.ss;
		v[i].ss=i;
	}
	sort(v.begin(), v.end());

	string s; cin >> s;

	map<int, int> R;

	for (int i = 0; i < n; i++) {
		if (s[v[i].ss] == 'R') {
			R[v[i].ff.ss]++;
		}
		else {
			if (R[v[i].ff.ss]) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";
	return;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}