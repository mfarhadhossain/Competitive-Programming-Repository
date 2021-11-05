#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {

}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; //cin >> n;
	while (cin >> n && n) {
		std::vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		string ss;
		cin >> ss;
		int len = ss.size();
		char dictionary[len + 1];
		strcpy(dictionary, ss.c_str());
		int mx = 0;
		std::vector<int> cnt(n);
		for (int i = 0; i < n; i++) {
			char pattern[v[i].size() + 1];
			strcpy(pattern, v[i].c_str());
			char *temp = dictionary;
			while (temp = strstr(temp, pattern)) {
				temp ++;
				cnt[i]++;
			}
			mx = max(mx, cnt[i]);
		}
		cout << mx << endl;
		for (int i = 0; i < n; i++) {
			if (mx == cnt[i]) {
				cout << v[i] << endl;
			}
		}
	}
	// int t = 1; cin >> t;
	// for (int tc = 1; tc <= t; tc++) {
	// 	cout << "Case #" << tc << ": ";
	// 	solve();
	// }
	return 0;
}