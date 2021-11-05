#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int a, b; cin >> a >> b;

	int n = a + b;

	string s; cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && s[n - i - 1] == '1') {
			cout << "-1\n";
			return;
		}
		if (s[i] == '1' && s[n - i - 1] == '0') {
			cout << "-1\n";
			return;
		}
		if (s[i] == '0')
			s[n - i - 1] = '0';
		if (s[i] == '1')
			s[n - i - 1] = '1';
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			a--;
		if (s[i] == '1')
			b--;
	}
	if ((a < 0 || b < 0)) {
		cout << "-1\n";
		return;
	}
	if (a % 2 && b % 2) {
		cout << "-1\n";
		return;
	}

	if (n & 1 && s[n / 2] == '?' ) {
		char ch = '0';
		if (a & 1) {
			ch = '0';
			a--;
		}
		else if (b & 1) {
			ch = '1';
			b--;
		}
		s[n / 2] = ch;
	}

	//cout << a << " " << b << " " << s << endl;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (a > 0) {
				s[i] = '0';
				s[n - i - 1] = '0';
				a -= 2;
			}
			else {

				s[i] = '1';
				s[n - i - 1] = '1';
				b -= 2;
			}
		}
	}
	//cout << a << " " << b << " " << s << endl;
	if ((a < 0 || b < 0)) {
		cout << "-1\n";
		return;
	}
	if (a % 2 && b % 2) {
		cout << "-1\n";
		return;
	}

	cout << s << endl;
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
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}