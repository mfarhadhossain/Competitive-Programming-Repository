#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int fib[30];
map<int, int>mark;
void solve() {
	string s; cin >> s;
	int sum = 0, idx = 0;
	for (int i = 2; i < s.size(); i++) {
		if ( (int)(s[i] - 'A') != ((int)(s[i - 1] - 'A') + (int)(s[i - 2] - 'A')) % 26 ) {
			cout << "NO\n";
			//solve();
			return;
		}
	}
	cout << "YES\n";
	//solve();
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}