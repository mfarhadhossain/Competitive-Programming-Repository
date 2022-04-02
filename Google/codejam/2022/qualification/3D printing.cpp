#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	vector<int>c(3), y(3), m(3), k(3);
	int c_min = INT_MAX, y_min = INT_MAX, k_min = INT_MAX, m_min = INT_MAX;
	for (int i = 0; i < 3; i++) {
		cin >> c[i] >> y[i] >> m[i] >> k[i];
		c_min = min(c_min, c[i]);
		y_min = min(y_min, y[i]);
		m_min = min(m_min, m[i]);
		k_min = min(k_min, k[i]);
	}
	//cout<<c_min<<" "<<y_min<<" "<<m_min<<" "<<k_min<<endl;
	
	if (c_min + y_min + m_min + k_min < 1000000) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << c_min;
		int rem = 1000000 - c_min;
		int mn = min(rem, y_min);
		cout << ' '<<mn;
		rem -= mn;

		mn = min(rem, m_min);
		cout << ' '<<mn;
		rem -= mn;

		mn = min(rem, k_min);
		cout << ' '<<mn;
		rem -= mn;
		cout << "\n";
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}