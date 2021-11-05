#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
bool ipower(int x) {
	return __builtin_popcount(x) == 1;
}
void solve3(int n) {
	if (n % 3 == 0) {
		cout << n / 3 << " " << n / 3 << " " << n / 3 << endl;
		return;
	}
	if (n & 1) {
		int rem = n - 1;
		rem /= 2;

		cout << 1 << " " << rem << " " << rem << endl;
	}
	else {

		if (ipower(n)) {

			int quo = n / 2;

			int rem = n - quo;

			cout << rem / 2 << " " << rem / 2 << " " << quo << endl;
			return;


		}
		else {
			int a = 0, b = 0;
			int st = n / 2;
			if (st & 1)st--;
			for (int i = st ; i >= 2 ; i -= 2) {
				int j = n - 2 * i;
				if (j <= 0)continue;

				if ( j + 2 * i == n && i % j == 0) {
					a = j, b = i;
					break;
				}
			}

			cout << a << " " << b << " " << b << endl;
		}
	}
}
void solve() {

	int n, k; cin >> n >> k;

	if (k == 3)solve3(n);
	else {
		int rem = k - 3;

		while (rem > 0) {
			cout << "1 ";
			rem--;
		}
		solve3(n - (k - 3));
	}
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