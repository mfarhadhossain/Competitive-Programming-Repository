#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	string s; cin >> s;
	string res = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':' && res == "http") {
			res.push_back('s');
		}
		res.push_back(s[i]);
	}
	cout << res << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}