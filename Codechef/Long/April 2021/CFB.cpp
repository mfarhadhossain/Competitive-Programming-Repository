#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	std::vector<int> zero(n);
	for (int i = 0; i < n; i++) {
		if (i) zero[i] = zero[i - 1];
		if (a[i] == '0') {
			zero[i]++;
		}
	}
	bool possible = true;
	int rev = 0;
	for (int i = n - 1; i >= 0; i--) {
		int zero_count = zero[i];
		int one_count = (i + 1) - zero_count;
		//cout << "At " << i << ": zero = " << zero_count << " one = " << one_count << endl;
		if (rev % 2 == 0) {

			if (a[i] != b[i]) {
				if (zero_count != one_count) {
					possible = 0;
					//break;
				}
				rev++;
			}
		}
		else {
			if ( a[i] == b[i]) {
				if (zero_count != one_count) {
					possible = 0;
					//break;
				}
				rev++;
			}
		}
	}
	if (possible == true) {
		cout << "YES\n";
		return;
	}
	else {
		cout << "NO\n";
		return;
	}
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
		solve();
	}
	return 0;
}