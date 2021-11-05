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
void solve() {
	int n; cin >> n;
	std::vector< pair<string, int>> operations(n);
	for (int i = 0; i < n; i++) {
		cin >> operations[i].ff >> operations[i].ss;
	}
	int res = 0;
	for (int i = 1; i <= 100; i++) {
		//cout << i << " debug\n";
		ll curr = i;
		for (int j = 0; j < n; j++) {
			if (operations[j].ff == "ADD") {
				curr += operations[j].ss;
			}
			if (operations[j].ff == "SUBTRACT") {
				curr -= operations[j].ss;

			}
			if (operations[j].ff == "MULTIPLY") {

				curr *= operations[j].ss;
			}
			if (operations[j].ff == "DIVIDE") {
				if (curr % operations[j].ss) {
					res++;
					break;
				}
				curr /= operations[j].ss;
			}
			if (curr < 0) {
				res++;
				break;
			}
		}
	}
	cout << res << endl;
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