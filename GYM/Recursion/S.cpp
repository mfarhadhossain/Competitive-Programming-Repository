#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
double average(int i, std::vector<ll> &v) {
	if (i == v.size())
		return 0.0;
	double curr = v[i];
	curr = curr / ((int)(v.size())) * 1.0;
	return (double)(curr + average(i + 1, v));
}
void solve() {
	int n; cin >> n;
	std::vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << fixed << setprecision(6) << average(0, v) << '\n';
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