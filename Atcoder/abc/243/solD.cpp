#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;
	ll X;
	string s;
	cin >> n >> X >> s;
	stack<char> stk;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') {
			if (stk.empty()) {
				X /= 2;
			}
			else {
				stk.pop();
			}
		}
		else {
			stk.push(s[i]);
		}
	}
	string st = "";
	while (!stk.empty()) {
		st.push_back(stk.top());
		stk.pop();
	}
	reverse(st.begin(), st.end());

	//cout<<st<<endl;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == 'L') {
			X *= 2;
		}
		else {
			X = X * 2 + 1;
		}
	}
	cout << X << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}