#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	string s[9];
	std::vector<int> diag1(20), diag2(20);
	int bad = 0;
	for (int i = 1; i <= 8; i++) {
		cin >> s[i];
		s[i] = "#" + s[i];
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cout << s[i][j];
			if (s[i][j] == '*') {
				for (int k = 1; k <= 8; k++) {
					if (k == j)continue;
					if (s[i][k] == '*') {
						bad = 1;
						break;
					}
				}
				if (bad)break;
				for (int k = 1; k <= 8; k++) {
					if (k == i)continue;
					if (s[k][j] == '*') {
						bad = 1;
						break;
					}
				}
				if (bad)break;
			}
		}
		cout << endl;
		if (bad)break;
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (s[i][j] == '*') {
				if ( diag1[i + j] == 1 || diag2[8 + i - j] == 1) {
					//cout << i + j << " i+j " << 8 + i - j << " 8+i-j\n";
					//cout << diag1[i + j] << " d1[i+j] " << diag2[8 + i - j] << " d2[8+i-j]\n";
					//cout << i << " " << j << endl;

					bad = 1;
					break;
				}
				diag1[i + j] = 1;
				diag2[8 + i - j] = 1;
			}
		}
		if (bad)break;
	}
	if (bad == 1 )cout << "invalid\n";
	else cout << "valid\n";
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}