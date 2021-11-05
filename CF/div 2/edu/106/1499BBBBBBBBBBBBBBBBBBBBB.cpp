#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
bool zero(string s) {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '1' && s[i - 1] == '1')
			return false;
	}
	return true;
}
bool one(string s) {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '0' && s[i - 1] == '0')
			return false;
	}
	return true;
}
bool sorted(string s) {
	if (s.size() <= 1)
		return true;
	string r = s;
	sort(s.begin(), s.end());
	return r == s;
}
void solve() {
	string s; cin >> s;
	if (sorted(s)) {
		cout << "YES\n";
		return;
	}
	string r = s;
	s.clear();
	int posL = 0, posR = 0;
	for (int i = 0; i < r.size(); i++) {
		if (r[i] == '1') {
			posL = i;
			break;
		}

	}
	for (int i =  r.size() - 1; i >= 0; i--) {
		if (r[i] == '0') {
			posR = i;
			break;
		}
	}
	for (int i = posL; i <= posR; i++) {
		s.push_back(r[i]);
	}
	if (zero(s) || one(s) || sorted(s)) {
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

	int t = 1; cin >> t;
	while (t--)solve();
	return 0;
}