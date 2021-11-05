#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int lcm(int x, int y) {
	int quo = x * y;
	return quo / __gcd(x, y);
}
void solve2(int n) {
	std::vector<int> a(n);
	int l = 0;
	int mn = n;
	std::vector<int> b;
	for (int i = 1; i <= n - 1; i++) {
		int j = i;
		int k = n - (i + j);
		if (i + j + k != n)continue;
		if (k <= 0)continue;
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
		//cout << " lcm = " << l << endl;

	}
	cout << "minimum lcm = " << mn << endl;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;
//solve();
}
bool ipower(int x) {
	return __builtin_popcount(x) == 1;
}
void solve1() {
	int n, k; cin >> n >> k;
	//solve2(n);

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

			int sq = sqrt(n);
			int a = 0, b = 0;
			for (int i = 2; i <= 2 * sq; i += 2) {

				int rem = n - i;
				if (rem <= 0)break;

				int xx = rem / 2;
				if (rem % i == 0 && xx % i == 0) {
					a = i, b = xx;
					//break;
				}
			}

			cout << a << " " << b << " " << b << endl;
		}
	}
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

	int t = 1; cin >> t;
	while (t--)solve1();
	return 0;
}