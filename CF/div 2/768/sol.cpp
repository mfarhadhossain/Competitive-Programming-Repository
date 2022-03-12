#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, k; cin >> n >> k;
	int res = 0;
	for (int i = 0, j = 1; i < n; i += 2, j += 2) {
		res += (i & j);
	}
	if (k > res) {
		cout << "-1\n";
		return;
	}

	n--;

	vector<int> f(n + 7), s(n + 7);
	vector<int> f_pos(n + 7), s_pos(n + 7);

	for (int i = 0; i <= n / 2; i++) {
		f[i] = i;
		s[i] = n ^ i;

		f_pos[f[i]] = i;
		s_pos[s[i]] = i;
	}
	int mid = n / 2;
	if (k >= 0 && k <= mid)
		swap(f[k], f[0]);
	else if (k < n)
		swap(s[s_pos[k]], f[0]);
	else {
		swap(s[s_pos[k]], f[0]);
		swap(s[1], s[0]);
		swap(s[1], s[2]);
	}

	for (int i = 0; i <= n / 2; i++) {
		cout << f[i] << " " << s[i] << endl;
	}
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