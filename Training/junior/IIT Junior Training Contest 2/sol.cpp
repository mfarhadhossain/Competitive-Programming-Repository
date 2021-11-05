#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;

	std::vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	std::set<ll> diff;


	for (int i = 1; i < n; i++) {
		diff.insert(v[i] - v[i - 1]);
	}

	if (diff.size() == 1) {
		cout << "0\n";
		return;
	}
	if (diff.size() != 2) {
		cout << "-1\n";
		return;
	}
	if (diff.size() == 2) {
		std::vector<ll> val;
		for (auto x : diff) {
			val.push_back(x);
		}
		ll m = val[1] - val[0];
		ll c = val[1];

		if (c > m) {
			cout << "-1\n";
			return;
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= m) {
				cout << "-1\n";
				return;
			}
		}
		cout << m << " " << c << endl;
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}