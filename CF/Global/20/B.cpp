#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	string s; cin >> s;
	int n = s.size();

	// BAA, ABA, ABBA
	if (s[0] == 'B' or s[n - 1] == 'A') {
		cout << "NO\n";
		return;
	}
	// no of B is greater than A
	int count_a = 0, count_b = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'A')
			count_a++;
		if (s[i] == 'B')
			count_b++;
		if (count_b > count_a) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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