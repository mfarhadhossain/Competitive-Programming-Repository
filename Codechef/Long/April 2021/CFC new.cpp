#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
bool isbalanced(string &x) {
	stack<char>stk;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '(') {
			stk.push('(');
		}
		else {
			if (stk.empty()) {
				return 0;
			}
			stk.pop();
		}
	}
	if (stk.size())return 0;
	return 1;
}
string fun(string s, string pat1) {
	string pat2 = pat1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (pat1[i] == '(')
				pat2[i] = ')';
			else if (pat1[i] == ')')
				pat2[i] = '(';
		}
	}
	return pat2;
}
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int one = 0 , zero = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')one++;
		else zero++;
	}
	if (zero & 1 or one & 1) {
		cout << "NO\n";
		return;
	}
	string a = s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')continue;
		cnt++;
		if (cnt <= one / 2) {
			a[i] = '(';
		}
		else a[i] = ')';
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')continue;
		cnt++;
		if (cnt & 1) {
			a[i] = '(';
		}
		else a[i] = ')';
	}
	string b = fun(s, a);
	/ if (isbalanced(a) && isbalanced(b)) {
		cout << "YES\n";
		cout << a << endl;
		cout << b << endl;
	}
	else {
		cout << "NO\n";
		return;
	}
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