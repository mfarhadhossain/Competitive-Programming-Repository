#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int ways(int s, int e) {
	if (s > e)
		return 0;
	if (s == e)
		return 1;
	return ways(s + 1, e) + ways(s + 2, e) + ways(s + 3, e);
}
void solve() {
	int s, e; cin >> s >> e;
	cout << ways(s, e) << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	while (t--)solve();
	return 0;
}