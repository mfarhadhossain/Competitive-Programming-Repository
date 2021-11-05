#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int fun(int x) {
	if (x < 10)return x;
	int n = x, s = 0;
	while (n) {
		s += n % 10;
		n /= 10;
	}
	return fun(s);
}
void solve() {
	int n, s = 0;;
	cin >> n;

	cout << fun(n) << endl;
	//solve();
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}