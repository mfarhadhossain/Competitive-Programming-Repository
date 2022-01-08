#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	if (n == 1) {
		cout << (s + s) << endl;
		return;
	}
	if (s[0] <= s[1]) {
		cout << s[0] << s[0] << endl;
		return;
	}
	int d = s[0] - 'a' + 1;

	string res = "";

	for (int i = 0; i < n && d >= 1; i++) {
		int curr = s[i] - 'a' + 1;
		if ( curr < d) {
			res.push_back(s[i]);
			d = curr; // wtf how come
		}
		else if (curr == d) {
			res.push_back(s[i]);
		}
		else {
			break;
		}
	}
	string res2 = res;
	reverse(res2.begin(), res2.end());
	cout << res + res2 << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}