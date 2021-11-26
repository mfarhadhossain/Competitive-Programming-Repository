#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int cnt_w = 0, cnt_b = 0;
	s = "#" + s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'W' && s[i - 1] != 'W') {
			cnt_w++;
		}
		else if (s[i] == 'B' && s[i - 1] != 'B') {
			cnt_b++;
		}
	}
	//cout<<cnt_w<<" "<<cnt_b<<endl;

	cout << min(cnt_w, cnt_b) << endl;
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