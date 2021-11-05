#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
ll mx, mn = 1e9;
void solve() {
	int n; cin >> n;
	std::vector<int> L(n);

	cout << "for ";
	for (int i = 0; i < n; i++) {
		cin >> L[i];
		//cout << L[i] << " ";
	}
	//puts("");
	ll res = 0;
	for (int steps = 1; steps <= n - 1; steps++) {
		/*cout << "before reversing: ";
		for (auto x : L)cout << x << " ";
		cout << endl;*/
		int mn = 1e9, idx, i = steps - 1;
		for (int j = i; j < n; j++) {
			if (L[j] < mn) {
				mn = L[j];
				idx = j;
			}
		}
		reverse(L.begin() + i, L.begin() + idx + 1);
		res += (idx - i + 1);
		// cout << "after reversing: ";
		// for (auto x : L)cout << x << " ";
		// cout << endl;
	}

	cout << "res = " << res << endl;
	mx = max(mx, res);
	mn = min(mn, res);
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}