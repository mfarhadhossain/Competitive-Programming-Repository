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
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	int len = r - l + 1;
	int rem = n - len;
	int min_sum = len * (len + 1) / 2;
	int max_sum = (n * (n + 1) / 2) - (rem * (rem + 1) / 2);

	//cout << "len = " << len << " rem = " << rem << " min_sum " << min_sum << " max_sum " << max_sum << endl;
	if (s<min_sum or s>max_sum) {
		cout << "-1\n";
		return;
	}
	std::vector<bool> taken(n + 1);
	std::vector<int> ar;

	for (int i = 1; i <= len; i++) {

		ar.push_back(i);
		taken[i] = 1;
	}

	int sum = min_sum;

	while (sum != s) {
		for (int i = 0; i < ar.size(); i++) {
			if ( taken[ar[i] + 1] == 0) {
				taken[ar[i]] = 0;
				ar[i] = ar[i] + 1;
				taken[ar[i]] = 1;
				sum++;
				break;
			}
		}
	}
	std::vector<int> res(n + 1);

	for (int i = l, j = 0; i <= r; i++, j++) {
		res[i] = ar[j];
	}
	ar.clear();

	for (int i = 1; i <= n; i++) {
		if (taken[i] == 0)
			ar.push_back(i);
	}
	for (int i = 1, j = 0; i <= n; i++) {
		if (i >= l && i <= r)
			continue;
		res[i] = ar[j];
		j++;
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
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