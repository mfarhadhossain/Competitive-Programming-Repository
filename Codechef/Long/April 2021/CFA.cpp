#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
std::vector<int> fun(string &a) {
	int z = 0, o = 0;
	std::vector<int> res;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '0')z++;
		if (a[i] == '1')o++;
		if (z == o)
			res.push_back(i + 1);
	}
	return res;
}
string gun(string &x) {
	//cout << x << endl;
	string y = x;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '0')
			y[i] = '1';
		else
			y[i] = '0';
	}
	//cout << y << endl;
	return y;
}
void solve() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	if (a == b) {
		cout << "YES\n";
		return;
	}
	string x = a, y = b;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	if (x != y) {cout << "NO\n"; return;}

	int z_a = 0, z_b = 0, o_a = 0, o_b = 0, gd = 0, bd = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0')z_a++;
		if (b[i] == '0')z_b++;
		if (a[i] == '1')o_a++;
		if (b[i] == '1')o_b++;

		if (z_a == o_a && z_b == o_b) {
			gd++;
		}
		if (z_a == o_a && z_b != o_b) {
			bd++;
		}
	}
	if (bd) {
		cout << "NO\n";
		return;
	}
	if (gd == 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] == '0')
				a[i] = '1';
			else if (a[i] == '1')
				a[i] = '0';
		}
		if (a == b)cout << "YES\n";
		else cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}