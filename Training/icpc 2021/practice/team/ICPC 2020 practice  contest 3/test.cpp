#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	multiset< pair<int, int> > mul;

	mul.insert({3, 1});
	mul.insert({8, 2});

	auto it = mul.upper_bound({5, 0});

	cout << *(it).first << " " << *(it->second) << endl;

}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}