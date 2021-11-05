#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
bool ispalindrome(int i, int j, std::vector<int> &v) {
	if (i == j - 1)
		return v[i] == v[j];
	if (i == j)
		return true;
	if (v[i] != v[j])
		return false;
	return ispalindrome(i + 1, j - 1, v);
}
void solve() {
	int n; cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	if (ispalindrome(0, n - 1, v)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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