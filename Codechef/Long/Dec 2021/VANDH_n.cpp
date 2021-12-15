#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector< pair<int, string>>res;
bool ok(int n, int m, string &s) {
	int hill = 0, valley = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '1' && s[i - 1] == '0' && s[i + 1] == '0')
			hill++;
		if (s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1')
			valley++;
	}
	return hill == n && valley == m;
}
void solve() {
	int n, m; cin >> n >> m;
	int n_ = n, m_ = m;
	string s = "0";
	for (int i = 0; i < n; i++) {
		s.push_back('1');
		s.push_back('0');
	}
	m -= (n - 1);
	if (m > 0) {
		s = "1" + s;
		m--;
	}
	
	if (m >0 ) {
		s.push_back('1');
		m--;
	}

	while (m > 0) {
		s += "101";
		m--;
	}
	//cout<<m<<endl;
	//cout<<s<<endl;
	if (m < 0) {
		int bad = abs(m);
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if (i == 0)tmp.push_back(s[i]);
			else if (i == s.size() - 1)tmp.push_back(s[i]);
			else if (bad > 0 && s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1') {
				tmp.push_back('0');
				tmp.push_back('0');
				bad--;
				//if(m==0)break;
			}
			else tmp.push_back(s[i]);
		}
		s = tmp;
	}
	cout << s.size() << endl;
	cout << s << endl;
	//s.pop_back();
	//cout<<ok(n_,m_,s)<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}