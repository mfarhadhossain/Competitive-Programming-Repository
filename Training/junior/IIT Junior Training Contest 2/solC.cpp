#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e5, MOD = 1e9 + 7;
std::multiset< pair<int, int> > adj[MAX + 7];
void solve() {

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	int can = m / 2;

	if (m & 1)can++;

	map<int, int> cnt;


	//std::vector<vector<int>> v;
	for (int i = 1; i <= m; i++) {
		int k, f; cin >> k;
		//std::vector<int> temp;
		for (int j = 1; j <= k; j++) {
			cin >> f;
			//temp.push_back(f);
			cnt[f]++;

			adj[f].insert(make_pair(k, i));
		}
		//v.push_back(temp);
	}

	std::vector<pair<int, int>> ar;
	for (int i = 1; i <= n; i++) {
		if (cnt[i])
			ar.push_back({cnt[i], i});
	}
	sort(ar.begin(), ar.end());

	std::vector<int> res(m + 1 , -1);


	// for (int i = 0; i < ar.size(); i++) {
	// 	cout << ar[i].first << "," << ar[i].second << endl;
	// }
	for (int i = 0; i < ar.size(); i++) {

		int id = ar[i].second;
		//cout << "friend id " << id << ": ";
		int khelbe = min(can, ar[i].first);

		if (khelbe == 0)
			continue;

		for (auto x : adj[id]) {
			int day = x.second;
			//cout << "day " << day << " size " << x.first << endl;
			if (res[day] != -1)continue;

			res[day] = id;
			khelbe--;
			if (khelbe == 0) {
				break;
			}
		}
	}

	// for (int i = 1; i <= m; i++) {
	// 	cout << res[i] << " ";
	// }
	// cout << endl;

	for (int i = 1; i <= m; i++) {
		if (res[i] == -1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= m; i++) {
		cout << res[i] << ' ';
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