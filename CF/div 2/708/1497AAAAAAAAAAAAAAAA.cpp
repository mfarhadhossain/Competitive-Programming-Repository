#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	std::vector<int> v;
	map<int, int>cnt;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
		if (cnt[x] == 1) {
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());

	while (true) {
		int g = 1;
		for (int i = 0; i < n; i++) {
			if (cnt[v[i]]) {
				g = 0;
				cnt[v[i]]--;
				cout << v[i] << ' ';
			}
		}
		if (g)break;
	}
	cout << endl;
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