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
void gen(int n, int m, string s) {
	//cout<<s<<endl;
	if (s.size() > 13) {
		return;
	}
	if (ok(n, m, s)) {
		//cout<<s<<endl;
		res.push_back({s.size(), s});
	}
	s.push_back('0');
	gen(n, m, s);
	s.pop_back();
	s.push_back('1');
	gen(n, m, s);
}
string brute(int hill, int valley) {
	string s = "1";
	gen(hill, valley, s);
	s = "0";
	gen(hill, valley, s);
	sort(res.begin(), res.end());
	return res[0].second;
}
string on(int n, int m) {
	//int n, m; cin >> n >> m;
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
	//cout << s.size() << endl;
	return s;
}
void solve() {
	int hill, valley; //cin>>hill>>valley;
	for (hill = 1; hill <= 10; hill++)
		for (valley = 1; valley <= 10; valley++) {
			res.clear();
			string s1 = brute(hill, valley);
			string s2 = on(hill, valley);
			if(s1.size()!=s2.size()){
				cout<<hill<<" "<<valley<<endl;
				cout<<"bad = "<<s2<<endl;
				cout<<"good = "<<s1<<endl;
			}
		}
}
int  main ()
{
	solve();
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	// int t = 1; cin >> t;
	// for (int tc = 1; tc <= t; tc++)
	// 	solve();
	return 0;
}