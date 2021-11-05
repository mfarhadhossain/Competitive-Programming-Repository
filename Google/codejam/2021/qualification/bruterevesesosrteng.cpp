#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
ll mx, mn = 1e9;
ll fun(std::vector<int> &L, int n) {
	ll res = 0;
	for (int steps = 1; steps <= n - 1; steps++) {
		int mn = 1e9, idx, i = steps - 1;
		for (int j = i; j < n; j++) {
			if (L[j] < mn) {
				mn = L[j];
				idx = j;
			}
		}
		reverse(L.begin() + i, L.begin() + idx + 1);
		res += (idx - i + 1);
	}
	return res;
}
void print(std::vector<int> L, int n) {

	for (int i = 0; i < n; i++) {
		if (i)cout << ' ';
		cout << L[i];
	}
	cout << endl;
}
void solve() {
	int n, c; cin >> n >> c;
	std::vector<int> L(n);
	for (int i = 0; i < n; i++) {
		L[i] = i + 1;
	}
	do {
		std::vector<int> temp = L;
		int cost = fun(temp, n);
		if ( cost == c) {
			print(L, n);
			return;
		}
	} while (next_permutation(L.begin(), L.end()));
	cout << "IMPOSSIBLE\n";
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}