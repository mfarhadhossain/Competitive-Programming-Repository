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
const int MAX = 1e5, MOD = 1e9 + 7;
int cost(string s) {
	int n = s.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (s[i] == s[j] && s[i + 1] == s[j + 1]) {
				res++;
			}
		}
	}
	return res;
}
int mn = 1e9;
std::vector<string> res[MAX];
void gen(int n, string s, int k) {
	if (n == 0) {
		int c = cost(s);
		if (c <= mn) {
			mn = c;
			res[mn].push_back(s);
			//return;
		}
		return;
	}
	for (int i = 0; i < k; i++) {
		char ch = (char)('a' + i);
		s.push_back(ch);
		gen(n - 1, s, k);
		s.pop_back();
	}
}
void solve() {
	mn = 1e9;
	int n, k; cin >> n >> k;
	// string s;
	// gen(n, s, k);
	// cout << "minimum cost = " << mn << endl;
	// for (int i = 0; i < res[mn].size(); i++) {
	// 	cout << res[mn][i] << ' ';
	// 	string x = res[mn][i];
	// 	std::vector<int> cnt(k + 1);
	// 	for (int j = 0; j < x.size(); j++) {
	// 		cnt[x[j] - 'a']++;
	// 	}
	// 	std::vector<int> v;
	// 	for (int j = 0; j < k; j++)
	// 		v.push_back(cnt[j]);
	// 	sort(v.begin(), v.end());
	// 	for (int y : v)
	// 		cout << y << ' ';
	// 	cout << endl;
	// }
	// for (int i = 0; i < MAX; i++)
	// 	res[i].clear();
	// solve();
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			cout << (char)('a');
		}
		cout << endl;
	}
	else if (n <= k) {
		for (int i = 0; i < n; i++) {
			cout << (char)('a' + i);
		}
		cout << endl;
	}
	else {
		// gen(n, s, k);
		// cout << "minimum cost = " << mn << endl;
		// for (int i = 0; i < res[mn].size(); i++) {
		// 	cout << res[mn][i] << ' ';
		// 	string x = res[mn][i];
		// 	std::vector<int> cnt(k + 1);
		// 	for (int j = 0; j < x.size(); j++) {
		// 		cnt[x[j] - 'a']++;
		// 	}
		// 	std::vector<int> v;
		// 	for (int j = 0; j < k; j++)
		// 		v.push_back(cnt[j]);
		// 	sort(v.begin(), v.end());
		// 	for (int y : v)
		// 		cout << y << ' ';
		// 	cout << endl;
		// }
		// for (int i = 0; i < MAX; i++)
		// 	res[i].clear();
		// solve();
	}
}
int main () {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}