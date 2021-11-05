#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	ll n; cin >> n;

	std::vector<int> a(n + 1), b(n + 1), tm(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> a[i + 1] >> b[i + 1];
	}
	for (int i = 0; i < n; i++) {
		cin >> tm[i + 1];
	}

	int curr = 0;

	for (int i = 1; i <= n; i++) {
		int ar_time = a[i] - b[i - 1] + tm[i];
		curr += ar_time;

		if (i == n)break;
		int wait = (b[i] - a[i]) / 2;

		if ((b[i] - a[i]) & 1)wait++;

		wait = max(b[i], curr + wait);
		curr = wait;
		//cout << curr << endl;
	}
	cout << curr << endl;

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