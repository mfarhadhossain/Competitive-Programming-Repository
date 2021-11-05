#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, x; cin >> n >> x;

	vector< pair<int, int> > ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first;
		ar[i].second = i;
	}

	sort(ar.begin(), ar.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int need = x - ar[i].first - ar[j].first;

			if (need <= 0)continue;
			int pos = lower_bound(ar.begin(), ar.end(), make_pair(need, 0)) - ar.begin();


			if (pos == n || ar[i].second == ar[pos].second || ar[j].second == ar[pos].second)continue;

			if (ar[pos].first == need) {
				cout << ar[i].second + 1 << " " << ar[j].second + 1 << " " << ar[pos].second + 1 << endl;
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