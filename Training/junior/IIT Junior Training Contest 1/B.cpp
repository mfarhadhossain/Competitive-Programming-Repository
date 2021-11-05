#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	ll n, x; cin >> n >> x;
	vector< ll > ar(n);
	vector< pair<ll, pair<ll, ll> >> br;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (i > j)br.push_back({ar[i] + ar[j], {j, i}});
			else br.push_back({ar[i] + ar[j], {i, j}});
		}
	}
	sort(br.begin(), br.end());
	for (int i = 0; i < br.size(); i++) {
		ll need = x - br[i].first;
		if (need <= 0)continue;

		pair< ll , pair<ll, ll> > xx;
		xx = make_pair(need, make_pair(0, 0));
		int pos = lower_bound(br.begin(), br.end(), xx) - br.begin();

		if (pos == n)continue;

		for (int j = max(0, pos - 2); j < min( (int)br.size(), pos + 2); j++) {
			if (br[j].first == need && (br[j].second.first != br[i].second.first && br[j].second.second != br[i].second.second
			                            && (br[j].second.first != br[i].second.second && br[j].second.second != br[i].second.first))) {
				cout << br[i].second.first + 1 << " ";
				cout << br[i].second.second + 1 << " ";
				cout << br[j].second.first + 1 << " ";
				cout << br[j].second.second + 1 << "\n";
				return;
			}
		}

	}
	cout << "-1\n";
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