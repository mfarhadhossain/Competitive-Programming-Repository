#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
ll distance(ll x, ll y) {
	if (x < y)swap(x, y);
	ll xx = x - y;
	return xx * 2;
}
void solve() {
	int n, l, r, k; cin >> n;
	vector< pair<int, int> >v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.rbegin(), v.rend());

	vector<ll>res(n + 1);
	ll sum = 0;
	res[0] = 0;
	ll curr_xplus = 1, curr_xminus = -1;
	for (int i = 0; i < n; i++) {
		if (i & 1) {

			res[v[i].second] = curr_xminus;
			curr_xminus--;
		}
		else {
			res[v[i].second] = curr_xplus;
			curr_xplus++;
		}
		sum += v[i].first * distance(res[v[i].second], 0);
	}
	cout << sum << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
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