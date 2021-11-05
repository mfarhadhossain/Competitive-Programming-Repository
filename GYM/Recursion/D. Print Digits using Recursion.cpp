#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void print(int x, int N) {
	if (x == 0) {
		if (x == N) {
			cout << "0\n";
		}
		return;
	}
	print(x / 10, N);
	if (x == N)cout << x % 10 << "\n";
	else cout << x % 10 << " ";
}
void solve() {
	int N; cin >> N;
	print(N, N);
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