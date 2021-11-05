#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
std::vector<int> sure, maybe;
int o = 0, ns = 0;
int go(int s_mask, int m_mask, int tot) {
	//cout << s_mask << " " << m_mask << endl;
	if (tot == 4) {
		if (__builtin_popcount(s_mask) == o)
			return 1;
		return 0;
	}
	if (tot > 4) {
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < o; i++) {
		ret += go(s_mask | (1 << i), m_mask, tot + 1);
	}
	for (int i = 0; i < ns; i++) {
		ret += go(s_mask, m_mask | (1 << i), tot + 1);
	}
	//cout << ret << endl;
	return ret;
}
void solve() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'o') {o++;}
		else if (s[i] == '?') {
			ns++;
		}
	}
	if (o > 4)cout << "0\n";
	else {
		cout << go(0, 0, 0) << endl;
	}
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}