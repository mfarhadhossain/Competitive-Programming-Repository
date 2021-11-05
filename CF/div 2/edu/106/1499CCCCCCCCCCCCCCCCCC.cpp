#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	ll n; cin >> n;
	std::vector<ll> c(n), odd(n), even(n);
	ll odd_sum = 0, even_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (i % 2 == 0) {
			if (i == 0) {
				even[i] = c[i];
				odd[i] = 0;
			}
			else {
				even[i] = even[i - 1] + c[i];
				odd[i] = odd[i - 1];
			}
		}
		else {
			if (i == 0) {
				odd[i] = c[i];
				even[i] = 0;
			}
			else {
				odd[i] = odd[i - 1] + c[i];
				even[i] = even[i - 1];
			}
		}
	}

	// cout << "odd array: ";
	// for (int i = 0; i < n; i++) {
	// 	cout << odd[i] << ' ';
	// }
	// cout << endl;
	// cout << "even array: ";
	// for (int i = 0; i < n; i++) {
	// 	cout << even[i] << ' ';
	// }
	// cout << endl;
	ll o = 0, e = 0, res = 1e18, odd_minimum = 1e18, even_minimum = 1e18, last = 1e18;


	for (int i = 0; i < n; i++) {
		ll ret = 0;
		//cout << "At pos " << i << ": ";
		if (i % 2 == 0) {
			even_minimum = min(even_minimum, c[i]);
			ret = (even[i] - even_minimum) + (n - e) * even_minimum;
			ret = ret + last;
			//cout << "even cost " << (even[i] - even_minimum) + (n - e) * even_minimum << ' ';
			//cout << "odd cost " << last << endl;

			last = (even[i] - even_minimum) + (n - e) * even_minimum;
			e++;
		}
		else {
			odd_minimum = min(odd_minimum, c[i]);
			ret = (odd[i] - odd_minimum) + (n - o) * odd_minimum;
			ret = ret + last;

			//cout << "even cost " << last << ' ';
			//cout << "odd cost " << (odd[i] - odd_minimum) + (n - o) * odd_minimum << endl;
			last = (odd[i] - odd_minimum) + (n - o) * odd_minimum;
			o++;
		}
		if (i)res = min(res, ret);
	}
	cout << res << endl;
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