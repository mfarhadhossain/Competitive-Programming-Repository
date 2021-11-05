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
void solve() {
	int n, x; cin >> n;
	string s; cin >> s;
	std::vector<int>T, M;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			T.push_back(i);
		}
		else {
			M.push_back(i);
		}
	}
	int need = n / 3, bad = 0, cnt = 0;
	if (T.size() != need * 2 or M.size() != need) {
		cout << "NO\n";
		return;
	}
	std::vector<int> temp;
	while (need--) {
		temp.push_back(T.back());
		T.pop_back();
	}
	for (int i = 0, j = M.size() - 1; i < temp.size(); i++, j--) {
		if (temp[i] < M[j]) {
			bad = 1;
			break;
		}
	}
	if (bad == 1) {
		cout << "NO\n";
		return;
	}
	while (T.size()) {
		if (T.back() > M.back()) {
			bad = 1;
			break;
		}
		T.pop_back();
		M.pop_back();
	}
	if (bad == 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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