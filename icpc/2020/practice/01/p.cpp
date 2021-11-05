#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ff first
#define ss second
//using namespace __gnu_pbds;
// #define endl "\n"
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
int complexity(string S) {
	map<char, int>M;
	for (auto x : S) {
		M[x]++;
	}
	return M.size();
}
void solve() {
	string s; cin >> s;
	std::vector<int> f(30);
	for (int i = 0; i < s.size(); i++) {
		f[s[i] - 'a']++;
	}
	vector< pair<int, int> > v;
	for (int i = 0; i < 26; i++) {
		if (f[i])
			v.push_back({f[i], i});
	}
	sort(v.rbegin(), v.rend());
	if (v.size() <= 2)cout << "0\n";
	else {
		cout << s.size() - v[0].first - v[1].first << endl;
	}
}
int main () {
// #ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
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