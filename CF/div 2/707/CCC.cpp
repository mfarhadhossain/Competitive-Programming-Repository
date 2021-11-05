#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 5e6 + 7, MOD = 1e9 + 7;
vector<pair<int, int> > vsum[MAX];
void solve() {
	int n; cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back({x, i});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int pos, sum = v[i].first + v[j].first;
			int x = v[i].second + 1;
			int y = v[j].second + 1;
			if (vsum[sum].size()) {
				auto xx = make_pair(x - 1, y - 1);
				pos = lower_bound(vsum[sum].begin(), vsum[sum].end(), xx) - vsum[sum].begin();

				for (int k = max(0, pos - 5); k < min(pos + 5, (int)vsum[sum].size()); k++) {

					int a = vsum[sum][k].first;
					int b = vsum[sum][k].second;
					if ( (a != x && b != y) && (a != y && b != x)) {
						cout << "YES\n";
						cout << x << " " << y << " " << a << " " << b << endl;
						return;
					}
				}
			}
			vsum[sum].push_back({x, y});
		}
	}
	cout << "NO\n";

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