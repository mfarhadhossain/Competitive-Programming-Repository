#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
int go(string &s, int n, int k, int idx, int last) {
	if (idx == n)
		return 0;
	int ret = 1e9;
	if (s[idx] == '*' && idx - last <= k) {
		ret = 1 + go(s, n, k, idx + 1, idx);
		ret = min(ret, go(s, n, k, idx + 1, last));
	}
	else if (s[idx] == '*' && idx - last > k)
		return 1e9;
	else ret = min(ret, go(s, n, k, idx + 1, last));
	return ret;
}
void solve() {
	int n, k; cin >> n >> k;

	string s; cin >> s;
	int pos = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*')
		{
			pos = i;
			s[i] = 'x';
			res++;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '*')
		{
			s[i] = 'x';
			res++;
			break;
		}
	}
	cout << res + go(s, n, k, pos, pos) << endl;
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
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}