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
bool haha;
void solve(int idx, string &s, string a, string b) {
	if (idx == s.size()) {
		if (isbalanced(a) && isbalanced(b)) {
			cout << a << endl;
			cout << b << endl;
			haha = true;
		}
		return;
	}
	if (s[idx] == '1')
	{
		solve(idx + 1, s, a + "(", b + "(");
		solve(idx + 1, s, a + ")", b + ")");
	}
	else {

		solve(idx + 1, s, a + "(", b + ")");
		solve(idx + 1, s, a + ")", b + "(");
	}
}
bool matches(string pat1, string pat2, string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			if (pat1[i] != pat2[i]) {
				return 0;
			}
		}
		else if (s[i] == '0') {
			if (pat1[i] == pat2[i]) {
				return 0;
			}
		}
	}
	return true;
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
void gen() {
	int n; cin >> n;
	string s; cin >> s;
	string pat1 = "", pat2 = "";
	for (int i = 1; i <= n; i++) {

		if (i <= n / 2)
			pat2.push_back('(');
		else
			pat2.push_back(')');
		if (i & 1) {
			pat1.push_back('(');
		}
		else {
			pat1.push_back(')');
		}
	}

	string pat3 = fun(s, pat1);
	if (isbalanced(pat3)) {
		cout << "YES\n";
		cout << pat1 << endl;
		cout << pat3 << endl;
		return;
	}
	pat3 = fun(s, pat2);
	if (isbalanced(pat3)) {
		cout << "YES\n";
		cout << pat2 << endl;
		cout << pat3 << endl;
		return;
	}
	cout << "NO\n";
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
		gen();
	}
	return 0;
}