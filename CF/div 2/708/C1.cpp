#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int lcm(int x, int y) {
	int quo = x * y;
	return quo / __gcd(x, y);
}
void solve() {
	int n = 3; cin >> n;
	std::vector<int> a(n);
	int l = 0;
	int mn = n;
	std::vector<int> b;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; i + j < n; j++) {
			int k = n - (i + j);
			if (i + j + k != n)continue;
			a[0] = i;
			a[1] = j;
			a[2] = k;
			//cout << i << " " << j << " " << k;
			l = 0;
			for (int i1 = 0; i1 < 3; i1++) {
				//cin >> a[i];
				if (i1 == 0) {
					l = a[i1];
				}
				else l = lcm(a[i1], l);

			}
			if (l < mn) {
				mn = l;
				b = a;
			}
		}
	}
	cout << "minimum lcm = " << mn << endl;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;
	solve();
}
void gen() {
	int n, k; cin >> n >> k;

	if (n & 1) {
		int rem = n - 1;
		rem /= 2;

		cout << 1 << " " << rem << " " << rem << endl;
	}
	else {

		if (n % 3 == 0) {
			cout << n / 3 << " " << n / 3 << " " << n / 3 << endl;
			return;
		}

		int quo = n / 2;

		// way1
		// quo quo rem


	}
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

	int t = 1; //cin >> t;
	while (t--)gen();
	return 0;
}