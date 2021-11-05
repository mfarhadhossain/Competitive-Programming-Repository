/*
	ab + a - b
	= a(b+1)-b
	= a(b+1)-(b+1)+1
	= (b+1)(a-1) + 1
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;

	std::vector<ll> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	cout << max( (v[0] + 1) * (v[1] - 1) + 1 , (v[n - 2] + 1) * (v[n - 1] - 1) + 1 ) << endl;
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