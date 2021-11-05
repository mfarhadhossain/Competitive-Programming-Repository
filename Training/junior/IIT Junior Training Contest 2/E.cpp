#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n, k; cin >> n >> k;
	int kk = k;
	std::vector< pair<ll, ll> > v;
	std::vector<ll> duplicates;
	for (int i = 0; i < n; i++) {
		ll t, d;
		cin >> t >> d;
		v.push_back({d, t});
	}
	sort(v.rbegin(), v.rend());
	ll res = 0, distinct = 0;
	std::vector<bool> mark(n + 1);
	for (int i = 0; i < k; i++) {
		res += v[i].first;
		if (mark[v[i].second] == 0) {
			mark[v[i].second] = 1;
			distinct++;
		}
		else {
			duplicates.push_back(v[i].first);
		}
	}
	ll sum = res;
	res += distinct * distinct;
	for (int i = k; i < n; i++) {

		if (mark[v[i].second] == 0) {
			if (duplicates.size()) {

				sum -= duplicates.back();
				sum += v[i].first;
				distinct++;
				duplicates.pop_back();
				mark[v[i].second] = 1;
			}
		}
		res = max(res, sum + distinct * distinct);
	}
	cout << res << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	while (t--)solve();
	return 0;
}