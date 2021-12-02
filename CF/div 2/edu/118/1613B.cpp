#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n; cin >> n;

	vector<int>v(n);
	map<int, int>bad;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		bad[v[i]] = 1;
	}
	sort(v.rbegin(), v.rend());

	vector< pair<int, int> > res;

	int cnt = n / 2;
	for (int i = 0; i < n; i++) {
		if (res.size() >= cnt)
			break;

		for (int j = i + 1; j < n; j++) {
			if (bad[v[i] % v[j]] == 0)
				res.push_back({v[i], v[j]});


			if (res.size() >= cnt)
				break;
		}

		if (res.size() >= cnt)
			break;
	}
	for (auto x : res)
		cout << x.first << " " << x.second << endl;
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